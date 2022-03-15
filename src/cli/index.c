#include "./index.h"
#include "../config/config.h"
#include "../log/index.h"

void PrintHello() {
  printf(CYAN ">>> Image Resizer <<<" RESET "\n");
}

void PrintVersion() {
  printf("%i.%i.%i", config.version[0], config.version[1], config.version[2]);
}
