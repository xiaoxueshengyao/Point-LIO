
#ifndef PERCEPTION_PERF_TEST_H
#define PERCEPTION_PERF_TEST_H

#include <chrono>
#include <iomanip>
#include <iostream>

#include "logging.h"

namespace loc_utils {

using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;

class Timer {
 public:
  Timer();

  // no-thread safe.
  void Start() { start_time_ = std::chrono::high_resolution_clock::now(); };

  double End(const std::string &msg, double cond_sec = -1.0) {
    end_time_ = std::chrono::high_resolution_clock::now();
    auto dur_time = std::chrono::duration<double>(end_time_ - start_time_).count();
    if (cond_sec < 0 || dur_time > cond_sec) {
      std::cout << "[TimeDebug]" << std::fixed << std::setprecision(6) << msg << " elapsed_time: " << dur_time << " s"
                << std::endl;
      MLOG_INFO("%s elapsed time: %f s", msg.c_str(), dur_time);
    }
    start_time_ = end_time_;
    // return elapsed_time;
    return dur_time;
  };

 private:
  TimePoint start_time_;
  TimePoint end_time_;

  // DISALLOW_COPY_AND_ASSIGN(Timer);
};

class PerfTestWrapper {
 public:
  explicit PerfTestWrapper(const std::string &msg);

  ~PerfTestWrapper();

 private:
  Timer timer_;
  std::string msg_;
};
#ifdef PERF_TEST
#define PERF_TEST_FUNCTION(function_name) PerfTestWrapper _timer_wrapper_(function_name)

#define PERF_TEST_START() \
  Timer _timer_;          \
  _timer_.Start()

#define PERF_TEST_END(msg)            _timer_.End(msg)
#define PERF_TEST_END_COND(msg, cond) _timer_.End(msg, cond);
#define PERF_TEST_CUR(msg) \
  std::cout << std::fixed << std::setprecision(6) << msg << std::chrono::high_resolution_clock::now();
#else
#define PERF_TEST_FUNCTION(function_name)
#define PERF_TEST_START()
#define PERF_TEST_END(msg)
#define PERF_TEST_CUR(msg)
#define PERF_TEST_END_COND(msg, cond)
#endif
}  // namespace loc_utils
#endif  // PERCEPTION_PERF_TEST_H

