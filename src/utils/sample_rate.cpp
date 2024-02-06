#include "utils/sample_rate.h"

using namespace loc_utils;

SampleRate::SampleRate() {
  count_ = 0;
  sample_count_ = 0;
  rate_ = 1;
}
SampleRate::SampleRate(double rate) {
  count_ = 0;
  sample_count_ = 0;
  SetRate(rate);
}
SampleRate::~SampleRate() {}
