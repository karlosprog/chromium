// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ppapi/cpp/var.h"

#include <stdio.h>
#include <string.h>

#include <algorithm>

#include "ppapi/c/pp_var.h"
#include "ppapi/c/ppb_var.h"
#include "ppapi/cpp/instance.h"
#include "ppapi/cpp/logging.h"
#include "ppapi/cpp/module.h"
#include "ppapi/cpp/module_impl.h"

// Define equivalent to snprintf on Windows.
#if defined(_MSC_VER)
#  define snprintf sprintf_s
#endif

namespace pp {

namespace {

template <> const char* interface_name<PPB_Var_1_1>() {
  return PPB_VAR_INTERFACE_1_1;
}
template <> const char* interface_name<PPB_Var_1_0>() {
  return PPB_VAR_INTERFACE_1_0;
}

// Technically you can call AddRef and Release on any Var, but it may involve
// cross-process calls depending on the plugin. This is an optimization so we
// only do refcounting on the necessary objects.
inline bool NeedsRefcounting(const PP_Var& var) {
  return var.type > PP_VARTYPE_DOUBLE;
}

// This helper function detects whether PPB_Var version 1.1 is available. If so,
// it uses it to create a PP_Var for the given string. Otherwise it falls back
// to PPB_Var version 1.0.
PP_Var VarFromUtf8Helper(const char* utf8_str, uint32_t len) {
  if (has_interface<PPB_Var_1_1>()) {
    return get_interface<PPB_Var_1_1>()->VarFromUtf8(utf8_str, len);
  } else if (has_interface<PPB_Var_1_0>()) {
    return get_interface<PPB_Var_1_0>()->VarFromUtf8(Module::Get()->pp_module(),
                                                     utf8_str,
                                                     len);
  } else {
    return PP_MakeNull();
  }
}

}  // namespace

Var::Var() {
  memset(&var_, 0, sizeof(var_));
  var_.type = PP_VARTYPE_UNDEFINED;
  needs_release_ = false;
}

Var::Var(Null) {
  memset(&var_, 0, sizeof(var_));
  var_.type = PP_VARTYPE_NULL;
  needs_release_ = false;
}

Var::Var(bool b) {
  var_.type = PP_VARTYPE_BOOL;
  var_.padding = 0;
  var_.value.as_bool = PP_FromBool(b);
  needs_release_ = false;
}

Var::Var(int32_t i) {
  var_.type = PP_VARTYPE_INT32;
  var_.padding = 0;
  var_.value.as_int = i;
  needs_release_ = false;
}

Var::Var(double d) {
  var_.type = PP_VARTYPE_DOUBLE;
  var_.padding = 0;
  var_.value.as_double = d;
  needs_release_ = false;
}

Var::Var(const char* utf8_str) {
  uint32_t len = utf8_str ? static_cast<uint32_t>(strlen(utf8_str)) : 0;
  var_ = VarFromUtf8Helper(utf8_str, len);
  needs_release_ = (var_.type == PP_VARTYPE_STRING);
}

Var::Var(const std::string& utf8_str) {
  var_ = VarFromUtf8Helper(utf8_str.c_str(),
                            static_cast<uint32_t>(utf8_str.size()));
  needs_release_ = (var_.type == PP_VARTYPE_STRING);
}

Var::Var(const Var& other) {
  var_ = other.var_;
  if (NeedsRefcounting(var_)) {
    if (has_interface<PPB_Var_1_0>()) {
      needs_release_ = true;
      get_interface<PPB_Var_1_0>()->AddRef(var_);
    } else {
      var_.type = PP_VARTYPE_NULL;
      needs_release_ = false;
    }
  } else {
    needs_release_ = false;
  }
}

Var::~Var() {
  if (needs_release_ && has_interface<PPB_Var_1_0>())
    get_interface<PPB_Var_1_0>()->Release(var_);
}

Var& Var::operator=(const Var& other) {
  // Early return for self-assignment. Note however, that two distinct vars
  // can refer to the same object, so we still need to be careful about the
  // refcounting below.
  if (this == &other)
    return *this;

  // Be careful to keep the ref alive for cases where we're assigning an
  // object to itself by addrefing the new one before releasing the old one.
  bool old_needs_release = needs_release_;
  if (NeedsRefcounting(other.var_)) {
    // Assume we already has_interface<PPB_Var_1_0> for refcounted vars or else
    // we couldn't have created them in the first place.
    needs_release_ = true;
    get_interface<PPB_Var_1_0>()->AddRef(other.var_);
  } else {
    needs_release_ = false;
  }
  if (old_needs_release)
    get_interface<PPB_Var_1_0>()->Release(var_);

  var_ = other.var_;
  return *this;
}

bool Var::operator==(const Var& other) const {
  if (var_.type != other.var_.type)
    return false;
  switch (var_.type) {
    case PP_VARTYPE_UNDEFINED:
    case PP_VARTYPE_NULL:
      return true;
    case PP_VARTYPE_BOOL:
      return AsBool() == other.AsBool();
    case PP_VARTYPE_INT32:
      return AsInt() == other.AsInt();
    case PP_VARTYPE_DOUBLE:
      return AsDouble() == other.AsDouble();
    case PP_VARTYPE_STRING:
      if (var_.value.as_id == other.var_.value.as_id)
        return true;
      return AsString() == other.AsString();
    case PP_VARTYPE_OBJECT:
    case PP_VARTYPE_ARRAY:
    case PP_VARTYPE_DICTIONARY:
    default:  // Objects, arrays, dictionaries.
      return var_.value.as_id == other.var_.value.as_id;
  }
}

bool Var::AsBool() const {
  if (!is_bool()) {
    PP_NOTREACHED();
    return false;
  }
  return PP_ToBool(var_.value.as_bool);
}

int32_t Var::AsInt() const {
  if (is_int())
    return var_.value.as_int;
  if (is_double())
    return static_cast<int>(var_.value.as_double);
  PP_NOTREACHED();
  return 0;
}

double Var::AsDouble() const {
  if (is_double())
    return var_.value.as_double;
  if (is_int())
    return static_cast<double>(var_.value.as_int);
  PP_NOTREACHED();
  return 0.0;
}

std::string Var::AsString() const {
  if (!is_string()) {
    PP_NOTREACHED();
    return std::string();
  }

  if (!has_interface<PPB_Var_1_0>())
    return std::string();
  uint32_t len;
  const char* str = get_interface<PPB_Var_1_0>()->VarToUtf8(var_, &len);
  return std::string(str, len);
}

std::string Var::DebugString() const {
  char buf[256];
  if (is_undefined()) {
    snprintf(buf, sizeof(buf), "Var(UNDEFINED)");
  } else if (is_null()) {
    snprintf(buf, sizeof(buf), "Var(NULL)");
  } else if (is_bool()) {
    snprintf(buf, sizeof(buf), AsBool() ? "Var(true)" : "Var(false)");
  } else if (is_int()) {
    snprintf(buf, sizeof(buf), "Var(%d)", static_cast<int>(AsInt()));
  } else if (is_double()) {
    snprintf(buf, sizeof(buf), "Var(%f)", AsDouble());
  } else if (is_string()) {
    char format[] = "Var<'%s'>";
    size_t decoration = sizeof(format) - 2;  // The %s is removed.
    size_t available = sizeof(buf) - decoration;
    std::string str = AsString();
    if (str.length() > available) {
      str.resize(available - 3);  // Reserve space for ellipsis.
      str.append("...");
    }
    snprintf(buf, sizeof(buf), format, str.c_str());
  } else if (is_array_buffer()) {
    snprintf(buf, sizeof(buf), "Var(ARRAY_BUFFER)");
  } else if (is_object()) {
    snprintf(buf, sizeof(buf), "Var(OBJECT)");
  }
  return buf;
}

}  // namespace pp
