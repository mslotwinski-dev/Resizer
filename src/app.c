#include <stdio.h>
#include "./cmd/index.h"

int main(int argc, char *argv[]) {
  sayHello();

  printf("%s \n", argv[1]);
}