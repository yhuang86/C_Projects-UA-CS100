#ifndef _IMAGE_H_
#define _IMAGE_H_

typedef struct _pixel {
    int red;
    int green;
    int blue;
} Pixel;

typedef struct _imagePPM {
	char magic[3];  // magic identifier, "P3" for PPM
    int width;      // number of columns
    int height;     // number of rows
    int max_value;  // maximum intenrsity of RGB components
    Pixel **pixels; // the actual color pixel data
} ImagePPM;

typedef struct _imagePGM {
	char magic[3];  // magic identifier, "P2" for PGM
    int width;      // number of columns
    int height;     // number of rows
    int max_value;  // maximum grayscale intensity
    int **pixels;   // the actual grayscale pixel data
} ImagePGM;

// Given a filename of a ppm image, read in the image and
// store it in the ImagePPM structure. Return the address ofs
// the ImagePPM structure if the file can be opened or
// NULL otherwise. 
ImagePPM *readPPM(char *filename);
// Write out a pgm image stored in a ImagePGM structure into
// the specified file. Return 1 if writing is successful or
// 0 otherwise.
int writePGM(ImagePGM *pImagePGM, char *filename);

// Convert a ppm image into a pgm image.
// grayscale = R
ImagePGM *extractRed(ImagePPM *pImagePPM);
// grayscale = G
ImagePGM *extractGreen(ImagePPM *pImagePPM);
// grayscale = B
ImagePGM *extractBlue(ImagePPM *pImagePPM);
// grayscale = (R + G + B) / 3
ImagePGM *computeAverage(ImagePPM *pImagePPM);
// grayscale = (max(R, G, B) + min(R, G, B)) / 2
ImagePGM *computeLightness(ImagePPM *pImagePPM);
// grayscale = 0.21 R + 0.72 G + 0.07 B
ImagePGM *computeLuminosity(ImagePPM *pImagePPM);
// based on https://www.johndcook.com/blog/2009/08/24/algorithms-convert-color-grayscale/

// Free the space used by a ppm image.
void freeSpacePPM(ImagePPM *pImagePPM);
// Free the space used by a pgm image.
void freeSpacePGM(ImagePGM *pImagePGM);

#endif
