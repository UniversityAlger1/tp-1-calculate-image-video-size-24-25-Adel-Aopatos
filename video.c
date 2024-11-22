#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {

   if (w <= 0 || h <= 0 || durationMovie <= 0 || durationCredits <= 0 || fps <= 0)
   {
      return 0;
   }

   float sizeColorImg= (w * h * 3 * 8 * fps * durationMovie);

   float sizebinaryImg= (w * h * fps * durationCredits);

   float sizeBits= sizebinaryImg + sizeColorImg ;

   if (strcmp(unit, "bt") == 0) {
        return sizeBits; //bits
    } else if (strcmp(unit, "ko") == 0) {
        return sizeBits / 1024; //kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return sizeBits / (1024 * 1024); //megabits
    } else if (strcmp(unit, "go") == 0) {
        return sizeBits / (1024 * 1024 * 1024); //gigabits
    } else {

        return -1;
    }

   return 0;
}
