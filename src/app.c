#include <stdio.h>
#include "./cli/index.h"
#include "./log/index.h"

int main(int argc, char *argv[]) {
  PrintHello();

  if(argc == 1) {
    Print(Error, NoFile);
  }

  return 0;
}