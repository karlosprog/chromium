// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_CHROMEOS_SYSTEM_KEY_EVENT_LISTENER_H_
#define CHROME_BROWSER_CHROMEOS_SYSTEM_KEY_EVENT_LISTENER_H_
#pragma once

#include <gdk/gdk.h>

#include "base/memory/singleton.h"
#include "base/message_loop.h"
#include "chrome/browser/chromeos/wm_message_listener.h"

typedef union _XEvent XEvent;

namespace chromeos {

class AudioHandler;

// SystemKeyEventListener listens for volume related key presses from GDK, then
// tells the AudioHandler to adjust volume accordingly.  Start by just calling
// instance() to get it going.

// TODO(davej): Remove WmMessageListener::Observer once volume key handling has
// been removed from the window manager since those keys take precedence.

class SystemKeyEventListener : public WmMessageListener::Observer,
                               public MessageLoopForUI::Observer {
 public:
  class CapsLockObserver {
   public:
    virtual void OnCapsLockChange(bool enabled) = 0;
  };
  static SystemKeyEventListener* GetInstance();

  // WmMessageListener::Observer:
  virtual void ProcessWmMessage(const WmIpc::Message& message,
                                GdkWindow* window);

  void Stop();

  void AddCapsLockObserver(CapsLockObserver* observer);
  void RemoveCapsLockObserver(CapsLockObserver* observer);

 private:
  // Defines the delete on exit Singleton traits we like.  Best to have this
  // and const/dest private as recommended for Singletons.
  friend struct DefaultSingletonTraits<SystemKeyEventListener>;

  SystemKeyEventListener();
  virtual ~SystemKeyEventListener();

#if defined(TOUCH_UI)
  // MessageLoopForUI::Observer overrides.
  virtual EventStatus WillProcessXEvent(XEvent* xevent) OVERRIDE;
#else
  // This event filter intercepts events before they reach GDK, allowing us to
  // check for system level keyboard events regardless of which window has
  // focus.
  static GdkFilterReturn GdkEventFilter(GdkXEvent* gxevent,
                                        GdkEvent* gevent,
                                        gpointer data);

  // MessageLoopForUI::Observer overrides.
  virtual void WillProcessEvent(GdkEvent* event) OVERRIDE {}
  virtual void DidProcessEvent(GdkEvent* event) OVERRIDE {}
#endif

  // Tell X we are interested in the specified key/mask combination.
  // CapsLock and Numlock are always ignored.
  void GrabKey(int32 key, uint32 mask);

  void OnVolumeMute();
  void OnVolumeDown();
  void OnVolumeUp();
  void OnCapsLock(bool enabled);

  // Displays the volume bubble for the current volume and muting status.
  // Also hides the brightness bubble if it's being shown.
  void ShowVolumeBubble();

  // Returns true if the event was processed, false otherwise.
  virtual bool ProcessedXEvent(XEvent* xevent);

  int32 key_volume_mute_;
  int32 key_volume_down_;
  int32 key_volume_up_;
  int32 key_f8_;
  int32 key_f9_;
  int32 key_f10_;
  int32 key_left_shift_;
  int32 key_right_shift_;

  bool stopped_;

  // Are we waiting for a Shift key press event to toggle Caps Lock (i.e. the
  // last key press event was regarding the other Shift key)?
  bool waiting_for_shift_for_caps_lock_;

  bool caps_lock_is_on_;
  ObserverList<CapsLockObserver> caps_lock_observers_;

  // Base X ID for events from the XKB extension.
  int xkb_event_base_;

  // AudioHandler is a Singleton class we are just caching a pointer to here,
  // and we do not own the pointer.
  AudioHandler* const audio_handler_;

  DISALLOW_COPY_AND_ASSIGN(SystemKeyEventListener);
};

}  // namespace chromeos

#endif  // CHROME_BROWSER_CHROMEOS_SYSTEM_KEY_EVENT_LISTENER_H_
