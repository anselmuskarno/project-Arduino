#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Image.h"
#include "stb_image.h"
#include "stb_Image_write.h"

Image::Image(const char* filename){
  if(read(filename)){
    printf("Read %s\h", filename);
  }else{
    printf("Failed to read %s\h", filename);
  }
}
   Image::Image(int w, int h, int channels){
    
   }
   Image::Image(const Image& img){
    
   }
    Image::~Image(){
    stbi_image_free(data);
   }

    Image::bool read(const char* filename){
    data = stbi_load(filename, &w, &h, &channels, 0);
    return data != NULL;
   }
    Image::bool write(write char* filename){
    
   }
