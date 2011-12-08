// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/web_urlrequest_client_cpptoc.h"
#include "libcef_dll/ctocpp/request_ctocpp.h"
#include "libcef_dll/ctocpp/web_urlrequest_ctocpp.h"


// STATIC METHODS - Body may be edited by hand.

CefRefPtr<CefWebURLRequest> CefWebURLRequest::CreateWebURLRequest(
    CefRefPtr<CefRequest> request, CefRefPtr<CefWebURLRequestClient> client)
{
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: request; type: refptr_same
  DCHECK(request.get());
  if (!request.get())
    return NULL;
  // Verify param: client; type: refptr_diff
  DCHECK(client.get());
  if (!client.get())
    return NULL;

  // Execute
  cef_web_urlrequest_t* _retval = cef_web_urlrequest_create(
      CefRequestCToCpp::Unwrap(request),
      CefWebURLRequestClientCppToC::Wrap(client));

  // Return type: refptr_same
  return CefWebURLRequestCToCpp::Wrap(_retval);
}



// VIRTUAL METHODS - Body may be edited by hand.

void CefWebURLRequestCToCpp::Cancel()
{
  if (CEF_MEMBER_MISSING(struct_, cancel))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->cancel(struct_);
}


CefWebURLRequest::RequestState CefWebURLRequestCToCpp::GetState()
{
  if (CEF_MEMBER_MISSING(struct_, get_state))
    return WUR_STATE_UNSENT;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_weburlrequest_state_t _retval = struct_->get_state(struct_);

  // Return type: simple
  return _retval;
}



#ifndef NDEBUG
template<> long CefCToCpp<CefWebURLRequestCToCpp, CefWebURLRequest,
    cef_web_urlrequest_t>::DebugObjCt = 0;
#endif

