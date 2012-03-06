// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Defines global variables.
var commands = TaskManagerCommands;
var taskmanager = undefined;  // This will be instantiated in main.js.

/**
 * Invoked when a range of items has changed.
 */
function taskChanged(start, length, tasks) {
  var task = {type: 'change', start: start, length: length, tasks: tasks};

  if (taskmanager) taskmanager.processTaskChange(task);
}

// Cached list of enabled columns to prevent frequent access to localStorage.
var cachedEnabledColumns;

/**
 * Returns the dictionary which contains the list of columns and whether each
 * column is enabled or not.
 */
function getEnabledColumns() {
  // Use the cache after the second time since access to localStorage is slow.
  if (cachedEnabledColumns)
    return cachedEnabledColumns;

  var json = window.localStorage.getItem(ENABLED_COLUMNS_KEY);
  try {
    cachedEnabledColumns = JSON.parse(json) || {};
  } catch (e) {
    cachedEnabledColumns = {};
  }
  for (var i = 0; i < DEFAULT_COLUMNS.length; i++) {
    if (typeof(cachedEnabledColumns[DEFAULT_COLUMNS[i][0]]) == 'undefined')
      cachedEnabledColumns[DEFAULT_COLUMNS[i][0]] = DEFAULT_COLUMNS[i][3];
  }
  return cachedEnabledColumns;
}

/**
 * Returns whether the given column (at |columnId|) is enabled or not.
 */
function isColumnEnabled(columnId) {
  return (getEnabledColumns())[columnId];
}

/**
 * Sets whether the given column is enabled or not.
 */
function setColumnEnabled(columnId, newChecked) {
  commands.setUpdateColumn(columnId, newChecked);
  cachedEnabledColumns[columnId] = newChecked;
  var json = JSON.stringify(cachedEnabledColumns);
  window.localStorage.setItem(ENABLED_COLUMNS_KEY, json);
}

// Enable the taskmanager model before the loading of scripts.
(function () {
  for (var i = 0; i < DEFAULT_COLUMNS.length; i++) {
    var columnId = DEFAULT_COLUMNS[i][0];
    if (isColumnEnabled(columnId))
      commands.setUpdateColumn(columnId, true);
  }
  commands.enableTaskManager();
  commands.setUpdateColumn('canInspect', true);
  commands.setUpdateColumn('canActivate', true);
})();
