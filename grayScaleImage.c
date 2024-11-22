#include "config/grayScaleImage.h"
// Parameters:
//   w: width of the image
//   h: height of the image
// Return value
//   grayScale size of the image Bitmap (in byte)
float grayScaleImage(int w, int h) {
   if ( w <= 0 || h <= 0)
   {
      return 0;
   }
   
   return (w*h);
}
