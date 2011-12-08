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

#ifndef _XMLREADER_CPPTOC_H
#define _XMLREADER_CPPTOC_H

#ifndef BUILDING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed DLL-side only")
#else // BUILDING_CEF_SHARED

#include "include/cef.h"
#include "include/cef_capi.h"
#include "libcef_dll/cpptoc/cpptoc.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class CefXmlReaderCppToC
    : public CefCppToC<CefXmlReaderCppToC, CefXmlReader, cef_xml_reader_t>
{
public:
  CefXmlReaderCppToC(CefXmlReader* cls);
  virtual ~CefXmlReaderCppToC() {}
};

#endif // BUILDING_CEF_SHARED
#endif // _XMLREADER_CPPTOC_H

