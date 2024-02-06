
#include "utils/tictoc.h"

using namespace loc_utils;

TicToc::TicToc() { tic(); }

TicToc::TicToc(bool _disp) {
  disp_ = _disp;
  tic();
}

TicToc::~TicToc() {}