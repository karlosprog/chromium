// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_WEBUI_CHROMEOS_UI_ACCOUNT_TWEAKS_H_
#define CHROME_BROWSER_UI_WEBUI_CHROMEOS_UI_ACCOUNT_TWEAKS_H_
#pragma once

#include "base/values.h"
#include "base/compiler_specific.h"
#include "chrome/browser/ui/webui/chrome_web_ui_data_source.h"

namespace chromeos {

/**
 * Fills given dictionary with account status data (whether current user is
 * owner/guest, id of the owner).
 * @param localized_strings non-null dictionary that will be filled.
 */
void AddAccountUITweaksLocalizedValues(
    base::DictionaryValue* localized_strings);

/**
 * Fills given data source with account status data (whether current user is
 * owner/guest, id of the owner).
 * @param source non-null ui data source which localized values dictionary will
 * be filled.
 */
void AddAccountUITweaksLocalizedValues(ChromeWebUIDataSource* source);

}  // namespace chromeos

#endif  // CHROME_BROWSER_UI_WEBUI_CHROMEOS_UI_ACCOUNT_TWEAKS_H_
