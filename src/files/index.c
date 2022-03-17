#include "./index.h"
#include "./sizes.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb/stb_image_resize.h"

void ExecuteFile(char* path) {
  mkdir("dist");

  int width, height, comp;
  unsigned char *img = stbi_load(path, &width, &height, &comp, 0);

  if (img == NULL) {
    Print(Error, InvalidFile);
  }

  for (int i = 0; i < (sizeof(Sizes) / sizeof(int)); i++) {
    unsigned int size = Sizes[i];
    char *c_path = CreatePath(size);

    unsigned char *resized = malloc(width * height * comp);

    stbir_resize_uint8(img, width, height, 0, resized, size, size, 0, comp);

    stbi_write_png(c_path, size, size, comp, resized, size * comp);
  }

  Print(Success, CreatedFiles);

  stbi_image_free(img);
}
