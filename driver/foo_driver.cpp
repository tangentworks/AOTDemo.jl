#include <string.h>
#include <stdint.h>
#include <iostream>

#include "JuliaHandler.hpp"
#include "foo.h"

#ifndef _WINDOWS
#define FOO_LIB_NAME "foo_AOT\0"
#else
#define FOO_LIB_NAME "foo_AOT.dll\0"
#endif

JuliaHandler juliaHandler(FOO_LIB_NAME);

extern "C"
{
extern int jl_FOO_bar(foo::Data *data, const size_t dataLen);
extern int jl_FOO_baz(foo::Data *data, const size_t dataLen, const wchar_t* logPath);
}

namespace foo
{

FOO_API int FOO_bar(Data *data, const size_t dataLen)
{
  auto r = jl_FOO_bar(data, dataLen);
  return r;
}

FOO_API int FOO_baz(Data *data, const size_t dataLen, const wchar_t* logPath)
{
  auto r = jl_FOO_baz(data, dataLen, logPath);
  return r;
}

} // namespace foo
