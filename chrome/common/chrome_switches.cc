// Copyright (c) 2009 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/common/chrome_switches.h"

#include "base/base_switches.h"

namespace switches {

// Can't find the switch you are looking for? try looking in
// base/base_switches.cc instead.

// Suppresses hang monitor dialogs in renderer processes.
const wchar_t kDisableHangMonitor[]            = L"disable-hang-monitor";

// Completely disables UMA metrics system.
const wchar_t kDisableMetrics[]                = L"disable-metrics";

// Enables the recording of metrics reports but disables reporting.
// In contrast to kDisableMetrics, this executes all the code that a normal
// client would use for reporting, except the report is dropped rather than sent
// to the server. This is useful for finding issues in the metrics code during
// UI and performance tests.
const wchar_t kMetricsRecordingOnly[]          = L"metrics-recording-only";

// Causes the browser process to throw an assertion on startup.
const wchar_t kBrowserAssertTest[]             = L"assert-test";

// Causes the renderer process to throw an assertion on launch.
const wchar_t kRendererAssertTest[]            = L"renderer-assert-test";

// Causes the browser process to crash on startup.
const wchar_t kBrowserCrashTest[]              = L"crash-test";

// Causes the renderer process to crash on launch.
const wchar_t kRendererCrashTest[]             = L"renderer-crash-test";

// Causes the renderer process to display a dialog on launch.
const wchar_t kRendererStartupDialog[]         = L"renderer-startup-dialog";

// Causes the plugin process to display a dialog on launch.
const wchar_t kPluginStartupDialog[]           = L"plugin-startup-dialog";

// Specifies a command that should be used to launch the plugin process.  Useful
// for running the plugin process through purify or quantify.  Ex:
//   --plugin-launcher="path\to\purify /Run=yes"
const wchar_t kPluginLauncher[]                = L"plugin-launcher";

// The value of this switch tells the app to listen for and broadcast
// testing-related messages on IPC channel with the given ID.
const wchar_t kTestingChannelID[]              = L"testing-channel";

// The value of this switch specifies which page will be displayed
// in newly-opened tabs.  We need this for testing purposes so
// that the UI tests don't depend on what comes up for http://google.com.
const wchar_t kHomePage[]                      = L"homepage";

// Causes the process to run as renderer instead of as browser.
const wchar_t kRendererProcess[]               = L"renderer";

// Causes the process to run as a renderer zygote.
const wchar_t kZygoteProcess[]                 = L"zygote";

// Path to the exe to run for the renderer and plugin subprocesses.
const wchar_t kBrowserSubprocessPath[]         = L"browser-subprocess-path";

// Causes the process to run as a plugin subprocess.
const wchar_t kPluginProcess[]                 = L"plugin";

// Causes the process to run as a worker subprocess.
const wchar_t kWorkerProcess[]                 = L"worker";

// Causes the process to run as a NativeClient's sel_ldr subprocess.
const wchar_t kNaClProcess[]                   = L"nacl";

// Causes the process to run as a utility subprocess.
const wchar_t kUtilityProcess[]                = L"utility";

// Causes the process to run as a profile import subprocess.
const wchar_t kProfileImportProcess[]          = L"profile-import";

// Runs the renderer and plugins in the same process as the browser
const wchar_t kSingleProcess[]                 = L"single-process";

// Runs each set of script-connected tabs (i.e., a BrowsingInstance) in its own
// renderer process.  We default to using a renderer process for each
// site instance (i.e., group of pages from the same registered domain with
// script connections to each other).
const wchar_t kProcessPerTab[]                 = L"process-per-tab";

// Runs a single process for each site (i.e., group of pages from the same
// registered domain) the user visits.  We default to using a renderer process
// for each site instance (i.e., group of pages from the same registered
// domain with script connections to each other).
const wchar_t kProcessPerSite[]                = L"process-per-site";

// Runs plugins inside the renderer process
const wchar_t kInProcessPlugins[]              = L"in-process-plugins";

// Runs the renderer outside the sandbox.
const wchar_t kNoSandbox[]                     = L"no-sandbox";

// Disables the alternate window station for the renderer.
const wchar_t kDisableAltWinstation[]          = L"disable-winsta";

// Runs the plugin processes inside the sandbox.
const wchar_t kSafePlugins[]                   = L"safe-plugins";

// Excludes these plugins from the plugin sandbox.
// This is a comma-separated list of plugin library names.
const wchar_t kTrustedPlugins[]                = L"trusted-plugins";

// Runs the security test for the sandbox.
const wchar_t kTestSandbox[]                   = L"test-sandbox";

// Specifies the user data directory, which is where the browser will look
// for all of its state.
const wchar_t kUserDataDir[]                   = L"user-data-dir";

// Specifies the plugin data directory, which is where plugins (Gears
// specifically) will store its state.
const wchar_t kPluginDataDir[]                 = L"plugin-data-dir";

// Use a specific disk cache location, rather than one derived from the
// UserDatadir.
const wchar_t kDiskCacheDir[]                  = L"disk-cache-dir";

// Forces the maximum disk space to be used by the disk cache, in bytes.
const wchar_t kDiskCacheSize[]                 = L"disk-cache-size";

// Forces the maximum disk space to be used by the media cache, in bytes.
const wchar_t kMediaCacheSize[]                = L"media-cache-size";

// Whether the multiple profiles feature based on the user-data-dir flag is
// enabled or not.
const wchar_t kEnableUserDataDirProfiles[]     = L"enable-udd-profiles";

// Specifies the path to the user data folder for the parent profile.
const wchar_t kParentProfile[]                 = L"parent-profile";

// Specifies that the associated value should be launched in "application" mode.
const wchar_t kApp[]                           = L"app";

// Specifies if the dom_automation_controller_ needs to be bound in the
// renderer. This binding happens on per-frame basis and hence can potentially
// be a performance bottleneck. One should only enable it when automating
// dom based tests.
const wchar_t kDomAutomationController[]       = L"dom-automation";

// Tells the plugin process the path of the plugin to load
const wchar_t kPluginPath[]                    = L"plugin-path";

// A string used to override the default user agent with a custom one.
const wchar_t kUserAgent[]                     = L"user-agent";

// Specifies the flags passed to JS engine
const wchar_t kJavaScriptFlags[]               = L"js-flags";

// The Country we should use.  This is normally obtained from the operating
// system during first run and cached in the preferences afterwards.  This is a
// string value, the 2 letter code from ISO 3166-1.
const wchar_t kCountry[]                       = L"country";

// Will add kWaitForDebugger to every child processes. If a value is passed, it
// will be used as a filter to determine if the child process should have the
// kWaitForDebugger flag passed on or not.
const wchar_t kWaitForDebuggerChildren[]       = L"wait-for-debugger-children";

// Will filter log messages to show only the messages that are prefixed
// with the specified value
const wchar_t kLogFilterPrefix[]               = L"log-filter-prefix";

// Force logging to be enabled.  Logging is disabled by default in release
// builds.
const wchar_t kEnableLogging[]                 = L"enable-logging";

// Force logging to be disabled.  Logging is enabled by default in debug
// builds.
const wchar_t kDisableLogging[]                = L"disable-logging";

// Sets the minimum log level. Valid values are from 0 to 3:
// INFO = 0, WARNING = 1, LOG_ERROR = 2, LOG_FATAL = 3.
const wchar_t kLoggingLevel[]                  = L"log-level";

// Make plugin processes log their sent and received messages to LOG(INFO).
const wchar_t kLogPluginMessages[]             = L"log-plugin-messages";

// Dump any accumualted histograms to the log when browser terminates (requires
// logging to be enabled to really do anything).  Used by developers and test
// scripts.
const wchar_t kDumpHistogramsOnExit[]          = L"dump-histograms-on-exit";

// enable remote debug / automation shell on the specified port
const wchar_t kRemoteShellPort[]               = L"remote-shell-port";

// Runs un-installation steps that were done by chrome first-run.
const wchar_t kUninstall[]                     = L"uninstall";

// Number of entries to show in the omnibox popup.
const wchar_t kOmniBoxPopupCount[]             = L"omnibox-popup-count";

// The value of this switch tells the app to listen for and broadcast
// automation-related messages on IPC channel with the given ID.
const wchar_t kAutomationClientChannelID[]     = L"automation-channel";

// Indicates the last session should be restored on startup. This overrides
// the preferences value and is primarily intended for testing. The value of
// this switch is the number of tabs to wait until loaded before
// 'load completed' is sent to the ui_test.
const wchar_t kRestoreLastSession[]            = L"restore-last-session";

// Chrome supports a playback and record mode.  Record mode saves *everything*
// to the cache.  Playback mode reads data exclusively from the cache.  This
// allows us to record a session into the cache and then replay it at will.
const wchar_t kRecordMode[]                    = L"record-mode";
const wchar_t kPlaybackMode[]                  = L"playback-mode";

// Don't record/playback events when using record & playback.
const wchar_t kNoEvents[]                      = L"no-events";

// Support a separate switch that enables the v8 playback extension.
// The extension causes javascript calls to Date.now() and Math.random()
// to return consistent values, such that subsequent loads of the same
// page will result in consistent js-generated data and XHR requests.
// Pages may still be able to generate inconsistent data from plugins.
const wchar_t kNoJsRandomness[]                = L"no-js-randomness";

// Make Windows happy by allowing it to show "Enable access to this program"
// checkbox in Add/Remove Programs->Set Program Access and Defaults. This
// only shows an error box because the only way to hide Chrome is by
// uninstalling it.
const wchar_t kHideIcons[]                     = L"hide-icons";

const wchar_t kShowIcons[]                     = L"show-icons";

// Make Chrome default browser
const wchar_t kMakeDefaultBrowser[]            = L"make-default-browser";

// Use a specified proxy server, overrides system settings. This switch only
// affects HTTP and HTTPS requests.
const wchar_t kProxyServer[]                   = L"proxy-server";

// Don't use a proxy server, always make direct connections. Overrides any
// other proxy server flags that are passed.
const wchar_t kNoProxyServer[]                 = L"no-proxy-server";

// Specify a list of hosts for whom we bypass proxy settings and use direct
// connections. Ignored if --proxy-auto-detect or --no-proxy-server are
// also specified.
// TODO(robertshield): Specify host format.
const wchar_t kProxyBypassList[]               = L"proxy-bypass-list";

// Force proxy auto-detection.
const wchar_t kProxyAutoDetect[]               = L"proxy-auto-detect";

// Use the pac script at the given URL
const wchar_t kProxyPacUrl[]                   = L"proxy-pac-url";

// Use WinHTTP to fetch and evaluate PAC scripts. Otherwise the default is
// to use Chromium's network stack to fetch, and V8 to evaluate.
const wchar_t kWinHttpProxyResolver[]          = L"winhttp-proxy-resolver";

// Chrome will support prefetching of DNS information.  Until this becomes
// the default, we'll provide a command line switch.
extern const wchar_t kDnsLogDetails[]          = L"dns-log-details";
extern const wchar_t kDnsPrefetchDisable[]     = L"dns-prefetch-disable";

// Enables support to debug printing subsystem.
const wchar_t kDebugPrint[]                    = L"debug-print";

// Prints the pages on the screen.
const wchar_t kPrint[] = L"print";

// Browser flag to disable the web inspector for all renderers.
const wchar_t kDisableDevTools[]               = L"disable-dev-tools";

// Enable web inspector for all windows, even if they're part of the browser.
// Allows us to use our dev tools to debug browser windows itself.
const wchar_t kAlwaysEnableDevTools[]          = L"always-enable-dev-tools";

// Enable experimental timeline API.
const wchar_t kEnableExtensionTimelineApi[]    =
    L"enable-extension-timeline-api";

// Used to set the value of SessionRestore::num_tabs_to_load_. See
// session_restore.h for details.
const wchar_t kTabCountToLoadOnSessionRestore[]=
    L"tab-count-to-load-on-session-restore";

// Enable dynamic loading of the Memory Profiler DLL, which will trace
// all memory allocations during the run.
const wchar_t kMemoryProfiling[]               = L"memory-profile";

// Adds a "Purge memory" button to the Task Manager, which tries to dump as much
// memory as possible.  This is mostly useful for testing how well the
// MemoryPurger functionality (which is normally triggered on Suspend) works.
//
// NOTE: This is only implemented for Views.
const wchar_t kPurgeMemoryButton[]             = L"purge-memory-button";

// By default, cookies are not allowed on file://. They are needed in for
// testing, for example page cycler and layout tests.  See bug 1157243.
const wchar_t kEnableFileCookies[]             = L"enable-file-cookies";

// Start the browser maximized, regardless of any previous settings.
const wchar_t kStartMaximized[]                = L"start-maximized";

// Spawn threads to watch for excessive delays in specified message loops.
// User should set breakpoints on Alarm() to examine problematic thread.
// Usage:   -enable-watchdog=[ui][io]
// Order of the listed sub-arguments does not matter.
const wchar_t kEnableWatchdog[]                = L"enable-watchdog";

// Display the First Run experience when the browser is started, regardless of
// whether or not it's actually the first run.
const wchar_t kFirstRun[]                      = L"first-run";

// Bypass the First Run experience when the browser is started, regardless of
// whether or not it's actually the first run. Overrides kFirstRun in case
// you're for some reason tempted to pass them both.
const wchar_t kNoFirstRun[]                    = L"no-first-run";

#if defined(OS_POSIX)
// Bypass the error dialog when the profile lock couldn't be attained.
// This switch is used during automated testing.
const wchar_t kNoProcessSingletonDialog[]      = L"no-process-singleton-dialog";
#endif

// Enable histograming of tasks served by MessageLoop. See about:histograms/Loop
// for results, which show frequency of messages on each thread, including APC
// count, object signalling count, etc.
const wchar_t kMessageLoopHistogrammer[]       = L"message-loop-histogrammer";

// Perform importing from another browser. The value associated with this
// setting encodes the target browser and what items to import.
const wchar_t kImport[]                        = L"import";

// Change the DCHECKS to dump memory and continue instead of displaying error
// dialog. This is valid only in Release mode when --enable-dcheck is
// specified.
const wchar_t kSilentDumpOnDCHECK[]            = L"silent-dump-on-dcheck";

// Normally when the user attempts to navigate to a page that was the result of
// a post we prompt to make sure they want to. This switch may be used to
// disable that check. This switch is used during automated testing.
const wchar_t kDisablePromptOnRepost[]         = L"disable-prompt-on-repost";

// Disable pop-up blocking.
const wchar_t kDisablePopupBlocking[]          = L"disable-popup-blocking";

// Don't execute JavaScript (browser JS like the new tab page still runs).
const wchar_t kDisableJavaScript[]             = L"disable-javascript";

// Don't enforce the same-origin policy.  (Used by people testing their sites.)
const wchar_t kDisableWebSecurity[]            = L"disable-web-security";

// Prevent Java from running.
const wchar_t kDisableJava[]                   = L"disable-java";

// Prevent plugins from running.
const wchar_t kDisablePlugins[]                = L"disable-plugins";

// Prevent images from loading.
const wchar_t kDisableImages[]                 = L"disable-images";

// Enable remote web font support. SVG font should always work whether
// this option is specified or not.
const wchar_t kEnableRemoteFonts[]             = L"enable-remote-fonts";

// Use the low fragmentation heap for the CRT.
const wchar_t kUseLowFragHeapCrt[]             = L"use-lf-heap";

// Runs the Native Client inside the renderer process.
const wchar_t kInternalNaCl[]                  = L"internal-nacl";

#ifndef NDEBUG
// Debug only switch to specify which gears plugin dll to load.
const wchar_t kGearsPluginPathOverride[]       = L"gears-plugin-path";
#endif

// Enable the fastback page cache.
const wchar_t kEnableFastback[]                = L"enable-fastback";

// Disable syncing bookmarks to a Google Account.
const wchar_t kDisableSync[]                   = L"disable-sync";

// Use the SyncerThread implementation that matches up with the old pthread
// impl semantics, but using Chrome synchronization primitives.  The only
// difference between this and the default is that we now have no timeout on
// Stop().  Should only use if you experience problems with the default.
const wchar_t kSyncerThreadTimedStop[]         = L"syncer-thread-timed-stop";

// Use the old pthreads SyncerThread implementation.
// Should only use if you experience problems with the default.
const wchar_t kSyncerThreadPthreads[]          = L"syncer-thread-pthreads";

// Enable support for SDCH filtering (dictionary based expansion of content).
// Optional argument is *the* only domain name that will have SDCH suppport.
// Default is  "-enable-sdch" to advertise SDCH on all domains.
// Sample usage with argument: "-enable-sdch=.google.com"
// SDCH is currently only supported server-side for searches on google.com.
const wchar_t kSdchFilter[]                    = L"enable-sdch";

// Enable user script support.
const wchar_t kEnableUserScripts[]             = L"enable-user-scripts";

// Disable extensions.
const wchar_t kDisableExtensions[]             = L"disable-extensions";

// Frequency in seconds for Extensions auto-update.
const wchar_t kExtensionsUpdateFrequency[]     = L"extensions-update-frequency";

// Load an extension from the specified directory.
const wchar_t kLoadExtension[]                 = L"load-extension";

// Package an extension to a .crx installable file from a given directory.
const wchar_t kPackExtension[]                 = L"pack-extension";

// Optional PEM private key is to use in signing packaged .crx.
const wchar_t kPackExtensionKey[]              = L"pack-extension-key";

// Show extensions on top with toolbar.
const wchar_t kShowExtensionsOnTop[]           = L"show-extensions-on-top";

// Load an NPAPI plugin from the specified path.
const wchar_t kLoadPlugin[]                    = L"load-plugin";

// directory to locate user scripts in as an over-ride of the default
const wchar_t kUserScriptsDir[]                = L"user-scripts-dir";

// Causes the browser to launch directly in incognito mode.
const wchar_t kIncognito[]                     = L"incognito";

// Turns on the accessibility in the renderer.  Off by default until
// http://b/issue?id=1432077 is fixed.
const wchar_t kEnableRendererAccessibility[]   =
    L"enable-renderer-accessibility";

// Pass the name of the current running automated test to Chrome.
const wchar_t kTestName[]                      = L"test-name";

// On POSIX only: the contents of this flag are prepended to the renderer
// command line. Useful values might be "valgrind" or "xterm -e gdb --args".
const wchar_t kRendererCmdPrefix[]             = L"renderer-cmd-prefix";

// On POSIX only: the contents of this flag are prepended to the utility
// process command line. Useful values might be "valgrind" or "xterm -e gdb
// --args".
const wchar_t kUtilityCmdPrefix[]              = L"utility-cmd-prefix";

// On Windows only: use the old WinInet-based ftp implemetation.
const wchar_t kWininetFtp[]                    = L"wininet-ftp";

// Enable Native Web Worker support
const wchar_t kEnableNativeWebWorkers[]        = L"enable-native-web-workers";

// Causes the worker process allocation to use as many processes as cores.
const wchar_t kWebWorkerProcessPerCore[]       = L"web-worker-process-per-core";

// Causes workers to run together in one process, depending on their domains.
// Note this is duplicated in webworkerclient_impl.cc
const wchar_t kWebWorkerShareProcesses[]       = L"web-worker-share-processes";

// Enables the bookmark menu.
const wchar_t kBookmarkMenu[]                  = L"bookmark-menu";

// Enables experimental features for Spellchecker. Right now, the first
// experimental feature is auto spell correct, which corrects words which are
// misppelled by typing the word with two consecutive letters swapped. The
// features that will be added next are:
// 1 - Allow multiple spellcheckers to work simultaneously.
// 2 - Allow automatic detection of spell check language.
// TODO(sidchat): Implement the above fetaures to work under this flag.
const wchar_t kExperimentalSpellcheckerFeatures[] =
    L"experimental-spellchecker-features";

// Enables StatsTable, logging statistics to a global named shared memory table.
const wchar_t kEnableStatsTable[]              = L"enable-stats-table";

// Replaces the audio IPC layer for <audio> and <video> with a mock audio
// device, useful when using remote desktop or machines without sound cards.
// This is temporary until we fix the underlying problem.
//
// TODO(scherkus): remove --disable-audio when we have a proper fallback
// mechanism.
const wchar_t kDisableAudio[]                  = L"disable-audio";

// Replaces the buffered data source for <audio> and <video> with a simplified
// resource loader that downloads the entire resource into memory.
//
// TODO(scherkus): remove --simple-data-source when our media resource loading
// is cleaned up and playback testing completed.
const wchar_t kSimpleDataSource[]              = L"simple-data-source";

// Some field tests may rendomized in the browser, and the randomly selected
// outcome needs to be propogated to the renderer.  For instance, this is used
// to modify histograms recorded in the renderer, or to get the renderer to
// also set of its state (initialize, or not initialize components) to match the
// experiment(s).
// The argument is a string-ized list of experiment names, and the associated
// value that was randomly selected.  In the recent implementetaion, the
// persistent representation generated by field_trial.cc and later decoded, is a
// list of name and value pairs, separated by slashes. See field trial.cc for
// current details.
const wchar_t kForceFieldTestNameAndValue[]    = L"force-fieldtest";

// Allows the new tab page resource to be loaded from a local HTML file. This
// should be a path to the HTML file that you want to use for the new tab page.
// It is used for manually testing new versions of the new tab page only,
// performance will be poor.
const wchar_t kNewTabPage[]                    = L"new-tab-page";

// Switches back to the old new tab page.
const wchar_t kOldNewTabPage[]                 = L"old-new-tab-page";

// Enables the backend service for web resources, used in the new tab page for
// loading tips and recommendations from a JSON feed.
const wchar_t kDisableWebResources[]           = L"disable-web-resources";

// Whether we should prevent the new tab page from showing the first run
// notification.
const wchar_t kDisableNewTabFirstRun[]         = L"disable-new-tab-first-run";

// Disables the default browser check. Useful for UI/browser tests where we want
// to avoid having the default browser info-bar displayed.
const wchar_t kNoDefaultBrowserCheck[]         = L"no-default-browser-check";

// Enables the Privacy Blacklist with the specified data file.
// The file contains data from all imported blacklists.
const wchar_t kPrivacyBlacklist[]              = L"privacy-blacklist";

// Enables the benchmarking extensions.
const wchar_t kEnableBenchmarking[]            = L"enable-benchmarking";

// The prefix used when starting the zygote process. (i.e. 'gdb --args')
const wchar_t kZygoteCmdPrefix[]               = L"zygote-cmd-prefix";

// Enables using ThumbnailStore instead of ThumbnailDatabase for setting and
// getting thumbnails for the new tab page.
const wchar_t kThumbnailStore[]                = L"thumbnail-store";

// Experimental. Shows a dialog asking the user to try chrome. This flag
// is to be used only by the upgrade process.
const wchar_t kTryChromeAgain[]                = L"try-chrome-again";

// The file descriptor limit is set to the value of this switch, subject to the
// OS hard limits. Useful for testing that file descriptor exhaustion is handled
// gracefully.
const wchar_t kFileDescriptorLimit[]           = L"file-descriptor-limit";

// On Windows, converts the page to the currently-installed monitor profile.
// This does NOT enable color management for images. The source is still assumed
// to be sRGB.
const wchar_t kEnableMonitorProfile[]          = L"enable-monitor-profile";

// Disable WebKit's XSSAuditor.  The XSSAuditor mitigates reflective XSS.
const wchar_t kDisableXSSAuditor[]             = L"disable-xss-auditor";

#if defined(OS_POSIX)
// A flag, generated internally by Chrome for renderer and other helper process
// command lines on Linux and Mac.  It tells the helper process to enable crash
// dumping and reporting, because helpers cannot access the profile or other
// files needed to make this decision.
const wchar_t kEnableCrashReporter[]           = L"enable-crash-reporter";
#endif

// Enables the new Tabstrip on Windows.
const wchar_t kEnableTabtastic2[]              = L"enable-tabtastic2";

// Number of tabs to pin on startup. This is not use if session restore is
// enabled.
const wchar_t kPinnedTabCount[]                = L"pinned-tab-count";

// Enables the showing of an info-bar instructing user they can search directly
// from the omnibox.
const wchar_t kSearchInOmniboxHint[]           = L"search-in-omnibox-hint";

// Enable local storage.  Still buggy.
const wchar_t kEnableLocalStorage[]            = L"enable-local-storage";

// Enable session storage.  Still buggy.
const wchar_t kEnableSessionStorage[]          = L"enable-session-storage";

// Allows debugging of sandboxed processes (see zygote_main_linux.cc).
const wchar_t kAllowSandboxDebugging[]         = L"allow-sandbox-debugging";

// Enable the seccomp sandbox (Linux only)
const wchar_t kEnableSeccompSandbox[]          = L"enable-seccomp-sandbox";

// Triggers a pletora of diagnostic modes.
const wchar_t kDiagnostics[]                   = L"diagnostics";

// Disables the custom JumpList on Windows 7.
const wchar_t kDisableCustomJumpList[]         = L"disable-custom-jumplist";

// Enables HTML5 DB support.
const wchar_t kEnableDatabases[]               = L"enable-databases";

// Enable ApplicationCache. Still mostly not there.
const wchar_t kEnableApplicationCache[]        = L"enable-application-cache";

// Override the default server used for profile sync.
const wchar_t kSyncServiceURL[]                = L"sync-url";

#if defined(OS_CHROMEOS)
// The name of the pipe over which the Chrome OS login manager will send
// single-sign-on cookies.
const wchar_t kCookiePipe[]                    = L"cookie-pipe";

// Enable the redirection of viewable document requests to the Google
// Document Viewer.
const wchar_t kEnableGView[]                   = L"enable-gview";
#endif

// Enable experimental support for cached byte-ranges.
const wchar_t kEnableByteRangeSupport[]        = L"enable-byte-range-support";

// Explicitly allow additional ports using a comma separated list of port
// numbers.
const wchar_t kExplicitlyAllowedPorts[]        = L"explicitly-allowed-ports";

// Activate (make foreground) myself on launch.  Helpful when Chrome
// is launched on the command line (e.g. by Selenium).  Only needed on Mac.
const wchar_t kActivateOnLaunch[]              = L"activate-on-launch";

// Enable experimental WebGL support.
const wchar_t kEnableExperimentalWebGL[]       = L"enable-webgl";

// Enabled desktop notifications.
const wchar_t kEnableDesktopNotifications[]    =
    L"enable-desktop-notifications";

}  // namespace switches
