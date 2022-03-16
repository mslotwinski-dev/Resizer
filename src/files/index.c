#include "./index.h"

void ExecuteFile(char* path, int* sizes) {
  FILE *source, *target;
  int i;

  source = fopen(path, "rb");

  if (source == NULL) {
    Print(Error, InvalidFile);
  }

  fseek(source, 0, SEEK_END);
  int length = ftell(source);

  fseek(source, 0, SEEK_SET);
  target = fopen("dist/512x512.png", "wb"); 

  if( target == NULL ) { fclose(source); } //exit(EXIT_FAILURE);

  for(i = 0; i < length; i++){
      fputc(fgetc(source), target);
  }

  printf("File copied successfully.\n"); 
  fclose(source); 
  fclose(target);
}