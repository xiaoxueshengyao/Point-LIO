#ifndef EA503EB8_2C96_4761_A56E_608CEE446A51
#define EA503EB8_2C96_4761_A56E_608CEE446A51

#include <cstdint>
#include <limits>

namespace loc_utils {
class SampleRate {
 public:
  SampleRate();
  SampleRate(double rate);
  ~SampleRate();
  void SetRate(double rate) {
    if (rate > 0) {
      rate_ = rate;
    } else {
      rate_ = 1;
    }
  }
  // 第一次要求返回true,然后安装采样率进行返回;
  bool Sample() {
    auto ret = static_cast<std::int32_t>(count_ / rate_);
    ++count_;
    if (ret >= sample_count_) {
      ++sample_count_;
      if (count_ >= std::numeric_limits<std::int32_t>::max() - rate_ - 1 ||
          sample_count_ >= std::numeric_limits<std::int32_t>::max() - 1) {
        count_ = 1;
        sample_count_ = 1;
      }
      return true;
    }
    return false;
  }

 private:
  double rate_;
  std::int32_t count_, sample_count_;
};
}  // namespace loc_utils

#endif /* EA503EB8_2C96_4761_A56E_608CEE446A51 */
