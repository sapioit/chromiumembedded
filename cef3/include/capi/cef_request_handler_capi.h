// Copyright (c) 2013 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//

#ifndef CEF_INCLUDE_CAPI_CEF_REQUEST_HANDLER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_REQUEST_HANDLER_CAPI_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "include/capi/cef_base_capi.h"


///
// Callback structure used for asynchronous continuation of authentication
// requests.
///
typedef struct _cef_auth_callback_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Continue the authentication request.
  ///
  void (CEF_CALLBACK *cont)(struct _cef_auth_callback_t* self,
      const cef_string_t* username, const cef_string_t* password);

  ///
  // Cancel the authentication request.
  ///
  void (CEF_CALLBACK *cancel)(struct _cef_auth_callback_t* self);
} cef_auth_callback_t;


///
// Callback structure used for asynchronous continuation of quota requests.
///
typedef struct _cef_quota_callback_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Continue the quota request. If |allow| is true (1) the request will be
  // allowed. Otherwise, the request will be denied.
  ///
  void (CEF_CALLBACK *cont)(struct _cef_quota_callback_t* self, int allow);

  ///
  // Cancel the quota request.
  ///
  void (CEF_CALLBACK *cancel)(struct _cef_quota_callback_t* self);
} cef_quota_callback_t;


///
// Implement this structure to handle events related to browser requests. The
// functions of this structure will be called on the thread indicated.
///
typedef struct _cef_request_handler_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Called on the IO thread before a resource request is loaded. The |request|
  // object may be modified. To cancel the request return true (1) otherwise
  // return false (0).
  ///
  int (CEF_CALLBACK *on_before_resource_load)(
      struct _cef_request_handler_t* self, struct _cef_browser_t* browser,
      struct _cef_frame_t* frame, struct _cef_request_t* request);

  ///
  // Called on the IO thread before a resource is loaded. To allow the resource
  // to load normally return NULL. To specify a handler for the resource return
  // a cef_resource_handler_t object. The |request| object should not be
  // modified in this callback.
  ///
  struct _cef_resource_handler_t* (CEF_CALLBACK *get_resource_handler)(
      struct _cef_request_handler_t* self, struct _cef_browser_t* browser,
      struct _cef_frame_t* frame, struct _cef_request_t* request);

  ///
  // Called on the IO thread when a resource load is redirected. The |old_url|
  // parameter will contain the old URL. The |new_url| parameter will contain
  // the new URL and can be changed if desired.
  ///
  void (CEF_CALLBACK *on_resource_redirect)(struct _cef_request_handler_t* self,
      struct _cef_browser_t* browser, struct _cef_frame_t* frame,
      const cef_string_t* old_url, cef_string_t* new_url);

  ///
  // Called on the IO thread when the browser needs credentials from the user.
  // |isProxy| indicates whether the host is a proxy server. |host| contains the
  // hostname and |port| contains the port number. Return true (1) to continue
  // the request and call cef_auth_callback_t::cont() when the authentication
  // information is available. Return false (0) to cancel the request.
  ///
  int (CEF_CALLBACK *get_auth_credentials)(struct _cef_request_handler_t* self,
      struct _cef_browser_t* browser, struct _cef_frame_t* frame, int isProxy,
      const cef_string_t* host, int port, const cef_string_t* realm,
      const cef_string_t* scheme, struct _cef_auth_callback_t* callback);

  ///
  // Called on the IO thread when JavaScript requests a specific storage quota
  // size via the webkitStorageInfo.requestQuota function. |origin_url| is the
  // origin of the page making the request. |new_size| is the requested quota
  // size in bytes. Return true (1) and call cef_quota_callback_t::cont() either
  // in this function or at a later time to grant or deny the request. Return
  // false (0) to cancel the request.
  ///
  int (CEF_CALLBACK *on_quota_request)(struct _cef_request_handler_t* self,
      struct _cef_browser_t* browser, const cef_string_t* origin_url,
      int64 new_size, struct _cef_quota_callback_t* callback);

  ///
  // Called on the IO thread to retrieve the cookie manager. |main_url| is the
  // URL of the top-level frame. Cookies managers can be unique per browser or
  // shared across multiple browsers. The global cookie manager will be used if
  // this function returns NULL.
  ///
  struct _cef_cookie_manager_t* (CEF_CALLBACK *get_cookie_manager)(
      struct _cef_request_handler_t* self, struct _cef_browser_t* browser,
      const cef_string_t* main_url);

  ///
  // Called on the UI thread to handle requests for URLs with an unknown
  // protocol component. Set |allow_os_execution| to true (1) to attempt
  // execution via the registered OS protocol handler, if any. SECURITY WARNING:
  // YOU SHOULD USE THIS METHOD TO ENFORCE RESTRICTIONS BASED ON SCHEME, HOST OR
  // OTHER URL ANALYSIS BEFORE ALLOWING OS EXECUTION.
  ///
  void (CEF_CALLBACK *on_protocol_execution)(
      struct _cef_request_handler_t* self, struct _cef_browser_t* browser,
      const cef_string_t* url, int* allow_os_execution);

  ///
  // Called on the browser process IO thread before a plugin is loaded. Return
  // true (1) to block loading of the plugin.
  ///
  int (CEF_CALLBACK *on_before_plugin_load)(struct _cef_request_handler_t* self,
      struct _cef_browser_t* browser, const cef_string_t* url,
      const cef_string_t* policy_url, struct _cef_web_plugin_info_t* info);
} cef_request_handler_t;


#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_REQUEST_HANDLER_CAPI_H_
