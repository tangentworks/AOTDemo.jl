#ifndef FOO_H
#define FOO_H

#ifndef _WINDOWS
#define __stdcall
#endif

#ifndef __cplusplus
#include <wchar.h>
#endif

#include "foo_data.h"

#ifdef _WINDLL//_USRDLL
#ifdef FOO_EXPORTS
#define FOO_API __declspec(dllexport)
#else
#define FOO_API __declspec(dllimport)
#endif
#else
#define FOO_API
#endif

#ifdef __cplusplus
extern "C" {
  namespace foo
  {
#endif

    FOO_API int __stdcall FOO_bar(struct Data* data, const size_t dataLen);
    FOO_API int __stdcall FOO_baz(struct Data* data, const size_t dataLen, const wchar_t* logPath);

#ifdef __cplusplus
} // namespace foo
} // extern "C"
#endif


#endif // FOO_H
