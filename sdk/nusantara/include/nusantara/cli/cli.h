#pragma once

#include "nusantara/core/core.h"
class Cli {
 public:
  void input(nstd::konst<nstd::bulat>& argc, nstd::karakter* argv[]);

 private:
  void showInfo();
  void showVersi();
};