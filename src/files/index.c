#include "./index.h"
#include "./sizes.h"

void ExecuteFile(char* path) {
  FILE *source, *target;

  source = fopen(path, "rb");
  if (source == NULL) {
    Print(Error, InvalidFile);
  }

  fseek(source, 0, SEEK_END);
  int length = ftell(source);
  fseek(source, 0, SEEK_SET);

  mkdir("dist");
  for (int i = 0; i < (sizeof(Sizes) / sizeof(int)); i++) {
    int g;

    char path[STRING_SIZE] = "dist/";
    char size_to_string[STRING_SIZE];
    snprintf( size_to_string, STRING_SIZE, "%d", Sizes[i] );

    strcat(path, size_to_string);
    strcat(path, "x");
    strcat(path, size_to_string);
    strcat(path, ".png");


    target = fopen(path, "wb"); 

      if( target == NULL ) { fclose(source); }

      for(g = 0; g < length; g++){
          fputc(fgetc(source), target);
      }

      fclose(target);
  }

  Print(Success, CreatedFiles);
  fclose(source); 
}
