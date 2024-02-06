#ifndef DC45BA01_DF50_4EED_A7DE_83BDC9E5C998
#define DC45BA01_DF50_4EED_A7DE_83BDC9E5C998
#define HUMAN_READABLE (0)

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "log/logging.h"
// #include <stdio.h>

// #include <boost/filesystem.hpp>



// /// 一次打印日志不能超过512B,超过会报错
#ifndef DEBUG_LOG
#define MLOG_DEBUG(...)
#else
#define MLOG_DEBUG(...)         \
  {                             \
    char data[512];             \
    sprintf(data, __VA_ARGS__); \
    DLOG(INFO) << data;         \
  }
#endif

#define MLOG_SEVERITY(severity, ...) \
  {                                  \
    char data[512];                  \
    sprintf(data, __VA_ARGS__);      \
    LOG(severity) << data;           \
  }

#define MLOG_INFO(...) MLOG_SEVERITY(INFO, __VA_ARGS__)
#define MLOG_WARN(...) MLOG_SEVERITY(WARNING, __VA_ARGS__)
#define MLOG_ERROR(...) MLOG_SEVERITY(ERROR, __VA_ARGS__)
#define MLOG_FATAL(...) MLOG_SEVERITY(FATAL, __VA_ARGS__)

#define MAX_SAVE_DAYS 7





#endif /* DC45BA01_DF50_4EED_A7DE_83BDC9E5C998 */
