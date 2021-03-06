// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ash/test/launcher_view_test_api.h"

#include "ash/launcher/launcher_button.h"
#include "ash/launcher/launcher_view.h"
#include "base/message_loop.h"
#include "ui/views/animation/bounds_animator.h"
#include "ui/views/controls/button/image_button.h"
#include "ui/views/view_model.h"

namespace {

// A class used to wait for animations.
class TestAPIAnimationObserver : public views::BoundsAnimatorObserver {
 public:
  TestAPIAnimationObserver() {}
  virtual ~TestAPIAnimationObserver() {}

  // views::BoundsAnimatorObserver overrides:
  virtual void OnBoundsAnimatorDone(views::BoundsAnimator* animator) OVERRIDE {
    MessageLoop::current()->Quit();
  }

 private:
  DISALLOW_COPY_AND_ASSIGN(TestAPIAnimationObserver);
};

}  // namespace

namespace ash {
namespace test {

LauncherViewTestAPI::LauncherViewTestAPI(internal::LauncherView* launcher_view)
    : launcher_view_(launcher_view) {
}

LauncherViewTestAPI::~LauncherViewTestAPI() {
}

int LauncherViewTestAPI::GetButtonCount() {
  return launcher_view_->view_model_->view_size();
}

internal::LauncherButton* LauncherViewTestAPI::GetButton(int index) {
  // App list button is not a LauncherButton.
  if (index == GetButtonCount() - 1)
    return NULL;

  return static_cast<internal::LauncherButton*>(
      launcher_view_->view_model_->view_at(index));
}

int LauncherViewTestAPI::GetLastVisibleIndex() {
  return launcher_view_->last_visible_index_;
}

bool LauncherViewTestAPI::IsOverflowButtonVisible() {
  return launcher_view_->overflow_button_->visible();
}

void LauncherViewTestAPI::SetAnimationDuration(int duration_ms) {
  launcher_view_->bounds_animator_->SetAnimationDuration(duration_ms);
}

void LauncherViewTestAPI::RunMessageLoopUntilAnimationsDone() {
  if (!launcher_view_->bounds_animator_->IsAnimating())
    return;

  scoped_ptr<TestAPIAnimationObserver> observer(new TestAPIAnimationObserver());
  launcher_view_->bounds_animator_->AddObserver(observer.get());

  // This nested loop will quit when TestAPIAnimationObserver's
  // OnBoundsAnimatorDone is called.
  MessageLoop::current()->Run();

  launcher_view_->bounds_animator_->RemoveObserver(observer.get());
}

}  // namespace test
}  // namespace ash
