// Author:   Tong Qin               qintonguav@gmail.com
// 	         Shaozu Cao 		    saozu.cao@connect.ust.hk

#ifndef DB981FF7_BD7C_4266_AEC8_28BDB95A98C6
#define DB981FF7_BD7C_4266_AEC8_28BDB95A98C6

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

namespace loc_utils {
class TicToc {
 public:
  TicToc();
  TicToc(bool _disp);
  ~TicToc();

  void tic() { start = std::chrono::steady_clock::now(); }

  void toc(std::string _about_task) {
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    double elapsed_ms = elapsed_seconds.count() * 1000;

    if (disp_) {
      std::cout.precision(3);  // 10 for sec, 3 for ms
      std::cout << _about_task << ": " << elapsed_ms << " msec." << std::endl;
    }
  }

  double TimeUsed(){
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    double elapsed_ms = elapsed_seconds.count() * 1000;
    return elapsed_ms;
  }

  static double getSec() {
    auto cur = std::chrono::system_clock::now().time_since_epoch();
    auto cur_ms = std::chrono::duration_cast<std::chrono::milliseconds>(cur).count();
    return static_cast<double>(cur_ms) / 1000.0f;
  }

  static double getUSec() {
    auto cur = std::chrono::high_resolution_clock::now().time_since_epoch();
    auto cur_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(cur).count();
    return static_cast<double>(cur_ns) / 1000.0f;
  }

 private:
  std::chrono::time_point<std::chrono::steady_clock> start, end;
  bool disp_ = true;
};
}  // namespace loc_utils
#endif /* DB981FF7_BD7C_4266_AEC8_28BDB95A98C6 */
