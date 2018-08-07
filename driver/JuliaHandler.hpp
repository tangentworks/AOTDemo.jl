#ifndef _JULIA_HANDLER_HPP__
#define _JULIA_HANDLER_HPP__

#include <string>

#include "julia.h"


class JuliaHandler
{
public:
  JuliaHandler() = delete;
  JuliaHandler(JuliaHandler&) = delete;
  JuliaHandler(JuliaHandler&&) = delete;
  JuliaHandler(const std::string libFileName)
  {
    libsupport_init();
    jl_options.image_file = libFileName.c_str();
    jl_options.compile_enabled = JL_OPTIONS_COMPILE_ON;
    jl_options.startupfile = JL_OPTIONS_STARTUPFILE_OFF;
    jl_options.use_precompiled = JL_OPTIONS_USE_PRECOMPILED_YES;
    julia_init(JL_IMAGE_JULIA_HOME);
  }

  ~JuliaHandler()
  {
    close();
  }

  int close()
  {
    int ret{ 0 };
    jl_atexit_hook(ret);
    return ret;
  }
};

#endif // _JULIA_HANDLER_HPP__
