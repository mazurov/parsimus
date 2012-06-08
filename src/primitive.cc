// ============================================================================
// Include files
// ============================================================================
#include "parsimus.h"
#include "parsim.h"
// ============================================================================
// STD & STL
// ============================================================================
#include <string>
// ============================================================================
#define PARSERS_DEF_FOR_SINGLE(Type)\
  bool parsimus::parse(const std::string& input, Type& result, parse_error* err) {\
    parsim::parse_error err_origin;\
    bool status = parsim::parse_(input, result, &err_origin);\
    if (!status && (err != NULL)){\
      err->pos = err_origin.pos;\
      err->tag = err_origin.tag;\
      err->found = err_origin.found;\
    }\
    return status;\
  }
// ============================================================================

PARSERS_DEF_FOR_SINGLE(bool)
PARSERS_DEF_FOR_SINGLE(char)
PARSERS_DEF_FOR_SINGLE(unsigned char)
PARSERS_DEF_FOR_SINGLE(signed char)
PARSERS_DEF_FOR_SINGLE(int)
PARSERS_DEF_FOR_SINGLE(short)
PARSERS_DEF_FOR_SINGLE(unsigned short)
PARSERS_DEF_FOR_SINGLE(unsigned int)
PARSERS_DEF_FOR_SINGLE(long)
PARSERS_DEF_FOR_SINGLE(unsigned long)
PARSERS_DEF_FOR_SINGLE(long long)
PARSERS_DEF_FOR_SINGLE(unsigned long long)
PARSERS_DEF_FOR_SINGLE(double)
PARSERS_DEF_FOR_SINGLE(float)
PARSERS_DEF_FOR_SINGLE(long double)
PARSERS_DEF_FOR_SINGLE(std::string)


