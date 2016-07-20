// bslmf_util.h                                                       -*-C++-*-
#ifndef INCLUDED_BSLMF_UTIL
#define INCLUDED_BSLMF_UTIL

#ifndef INCLUDED_BSLS_IDENT
#include <bsls_ident.h>
#endif
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide low-level functions on 'bslmf' types.
//
//@REVIEW_FOR_MASTER:
//
//@CLASSES:
//  bslmf::Util: utility class providing low-level functionality
//
//@DESCRIPTION: This component defines a utility 'struct', 'bslmf::Util', that
// serves as a namespace for a suite of functions that supply low-level
// functionality for implementing portable generic facilities such as might
// be found in the C++ standard library.
//
// TBD: put in a note that we only put this in because we needed a way to
//      distinguish movable ref vs anything else for C++03
//      otherwise identical to std::forawrd
//
///Usage
///-----
// TBD...

#ifndef INCLUDED_BSLSCM_VERSION
#include <bslscm_version.h>
#endif

#ifndef INCLUDED_BSLMF_MOVABLEREF
#include <bslmf_movableref.h>
#endif

#ifndef INCLUDED_BSLMF_REMOVEREFERENCE
#include <bslmf_removereference.h>
#endif

#ifndef INCLUDED_BSLS_COMPILERFEATURES
#include <bsls_compilerfeatures.h>
#endif

namespace BloombergLP {

namespace bslmf {

                      // ===========
                      // struct Util
                      // ===========

struct Util {
    // This struct provides ...
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    template <class TYPE>
    static TYPE&& forward(typename bsl::remove_reference<TYPE>::type&  t);
    template <class TYPE>
    static TYPE&& forward(typename bsl::remove_reference<TYPE>::type&& t);
#else
    template <class TYPE>
    static const TYPE& forward(const TYPE& t);
    template <class TYPE>
    static MovableRef<TYPE> forward(MovableRef<TYPE> t);
#endif // BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
        // Correctly forward the specified 't' argument based on the current
        // compilation environment.
};

// ============================================================================
//                        INLINE FUNCTION DEFINITIONS
// ============================================================================

// CLASS METHODS
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
template <class TYPE>
inline
TYPE&& Util::forward(typename bsl::remove_reference<TYPE>::type& t)
{
    return static_cast<TYPE&&>(t);
}

template <class TYPE>
inline
TYPE&& Util::forward(typename bsl::remove_reference<TYPE>::type&& t)
{
    return static_cast<TYPE&&>(t);
}

#else

template <class TYPE>
inline
const TYPE& Util::forward(const TYPE& t)
{
    return t;
}

template <class TYPE>
inline
bslmf::MovableRef<TYPE> Util::forward(bslmf::MovableRef<TYPE> t)
{
    return t;
}
#endif // BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES

}  // close package namespace
}  // close enterprise namespace

#endif

// ----------------------------------------------------------------------------
// Copyright 2016 Bloomberg Finance L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------- END-OF-FILE ----------------------------------
