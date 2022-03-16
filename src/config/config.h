#pragma once
#include "../libs.h"

struct ConfigStruct {
  int version[3];
};

struct ConfigStruct Config = {
  .version = {1, 0, 1}
};