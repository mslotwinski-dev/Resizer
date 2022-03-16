#include "./libs.h"
#include "./config/config.h"
#include "./files/index.h"

int main(int argc, char *argv[]) {
  printf(CYAN ">>> Image Resizer <<<" RESET "\n");

  if(argc <= 1) {
    Print(Error, NoFile);
  }

  if (!strcmp(argv[1],"--version")) {
    printf("%i.%i.%i", Config.version[0], Config.version[1], Config.version[2]);
    return 1;
  }

  ExecuteFile(argv[1]);

  return 0;
}