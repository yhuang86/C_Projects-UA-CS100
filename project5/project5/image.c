#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "image.h"
// Given a filename of a ppm image, read in the image and
// store it in the ImagePPM structure. Return the address ofs
// the ImagePPM structure if the file can be opened or
// NULL otherwise. 
ImagePPM *readPPM(char *filename){
FILE *fp1;
fp1 = fopen(filename, "r");
ImagePPM *pImagePPM=malloc(sizeof(ImagePPM));
fscanf(fp1,"%s %d %d %d",pImagePPM->magic,&pImagePPM->width,&pImagePPM->height,&pImagePPM->max_value);
    pImagePPM->pixels = malloc(sizeof(Pixel *) * pImagePPM->height);
    for(int i=0;i<pImagePPM->height;i++) {
        pImagePPM->pixels[i] = malloc(sizeof(Pixel) * pImagePPM->width);
    }
    for(int i=0;i<pImagePPM->height;i++) {
        for(int j=0;j<pImagePPM->width;j++) {
            fscanf(fp1, "%d %d %d", &pImagePPM->pixels[i][j].red,&pImagePPM->pixels[i][j].green,&pImagePPM->pixels[i][j].blue);
        }
    }
fclose(fp1);

return pImagePPM;
}
// Write out a pgm image stored in a ImagePGM structure into
// the specified file. Return 1 if writing is successful or
// 0 otherwise.
int writePGM(ImagePGM *pImagePGM, char *filename) {
    FILE *fp2;
    fp2 = fopen(filename,"w");
    fprintf(fp2,"%s\n",pImagePGM->magic);
    fprintf(fp2,"%d %d %d\n",pImagePGM->width,pImagePGM->height,pImagePGM->max_value);
    for(int i=0;i<pImagePGM->height;i++) {
        for(int j=0;j<pImagePGM->width;j++) {
            fprintf(fp2,"%d ",pImagePGM->pixels[i][j]);
        }
        fprintf(fp2,"\n");
    }
    fprintf(fp2,"\n");
    if (fp2 != NULL) {
        fclose (fp2);
        return 1;
    }
    else return 0;
    
}

// Convert a ppm image into a pgm image.
// grayscale = R
ImagePGM *extractRed(ImagePPM *pImagePPM) {
    ImagePGM *pImagePGM=malloc(sizeof(ImagePGM));
    strcpy(pImagePGM->magic,"P2");
    pImagePGM->height = pImagePPM->height;
    pImagePGM->width = pImagePPM->width;
    pImagePGM->max_value = pImagePPM->max_value;
    pImagePGM->pixels = malloc(sizeof(int *) * pImagePGM->height);
    for(int i=0;i<pImagePGM->height;i++) {
        pImagePGM->pixels[i] = malloc(sizeof(int) * pImagePGM->width);
    }
    for(int i=0;i< pImagePGM->height;i++) {
        for(int j=0;j< pImagePGM->width;j++) {
            pImagePGM->pixels[i][j] = pImagePPM->pixels[i][j].red;
        }
    }
    return pImagePGM;
}
// grayscale = G
ImagePGM *extractGreen(ImagePPM *pImagePPM) {
    ImagePGM *pImagePGM=malloc(sizeof(ImagePGM));
    strcpy(pImagePGM->magic,"P2");
    pImagePGM->height = pImagePPM->height;
    pImagePGM->width = pImagePPM->width;
    pImagePGM->max_value = pImagePPM->max_value;
    pImagePGM->pixels = malloc(sizeof(int *) * pImagePGM->height);
    for(int i=0;i<pImagePGM->height;i++) {
    pImagePGM->pixels[i] = malloc(sizeof(int) * pImagePGM->width);
    }
    for(int i=0;i< pImagePGM->height;i++) {
        for(int j=0;j< pImagePGM->width;j++) {
            pImagePGM->pixels[i][j] = pImagePPM->pixels[i][j].green;
        }
    }
    return pImagePGM;
}
// grayscale = B
ImagePGM *extractBlue(ImagePPM *pImagePPM) {
    ImagePGM *pImagePGM=malloc(sizeof(ImagePGM));
    strcpy(pImagePGM->magic,"P2");
    pImagePGM->height = pImagePPM->height;
    pImagePGM->width = pImagePPM->width;
    pImagePGM->max_value = pImagePPM->max_value;
    pImagePGM->pixels = malloc(sizeof(int *) * pImagePGM->height);
    for(int i=0;i<pImagePGM->height;i++) {
        pImagePGM->pixels[i] = malloc(sizeof(int) * pImagePGM->width);
    }
    for(int i=0;i< pImagePGM->height;i++) {
        for(int j=0;j< pImagePGM->width;j++) {
            pImagePGM->pixels[i][j] = pImagePPM->pixels[i][j].blue;
        }
    }
    return pImagePGM;
}
// grayscale = (R + G + B) / 3
ImagePGM *computeAverage(ImagePPM *pImagePPM) {
    ImagePGM *pImagePGM=malloc(sizeof(ImagePGM));
    strcpy(pImagePGM->magic,"P2");
    pImagePGM->height = pImagePPM->height;
    pImagePGM->width = pImagePPM->width;
    pImagePGM->max_value = pImagePPM->max_value;
    pImagePGM->pixels = malloc(sizeof(int *) * pImagePGM->height);
    for(int i=0;i<pImagePGM->height;i++) {
        pImagePGM->pixels[i] = malloc(sizeof(int) * pImagePGM->width);
    }
    for(int i=0;i< pImagePGM->height;i++) {
        for(int j=0;j< pImagePGM->width;j++) {
            double avg;
            avg = ((double)(pImagePPM->pixels[i][j].red + pImagePPM->pixels[i][j].blue + pImagePPM->pixels[i][j].green))/3.0;
            double value = round (avg);
            pImagePGM->pixels[i][j] = (int)value;
        }
    }
    return pImagePGM;
}
// grayscale = (max(R, G, B) + min(R, G, B)) / 2
ImagePGM *computeLightness(ImagePPM *pImagePPM) {
    ImagePGM *pImagePGM=malloc(sizeof(ImagePGM));
    strcpy(pImagePGM->magic,"P2");
    pImagePGM->height = pImagePPM->height;
    pImagePGM->width = pImagePPM->width;
    pImagePGM->max_value = pImagePPM->max_value;
    pImagePGM->pixels = malloc(sizeof(int *) * pImagePGM->height);
    for(int i=0;i<pImagePGM->height;i++) {
        pImagePGM->pixels[i] = malloc(sizeof(int) * pImagePGM->width);
    }
    int min;
    int max;
    int pixels[3];
    for(int i=0;i< pImagePGM->height;i++) {
        for(int j=0;j< pImagePGM->width;j++) {
            pixels[0]= pImagePPM->pixels[i][j].red;
            pixels[1]= pImagePPM->pixels[i][j].green;
            pixels[2]= pImagePPM->pixels[i][j].blue;
            for(int k=0;k<3;k++) {
                if (k==0) {
                    min = pixels[k];
                    max = pixels[k];
                }
                else {
                    if (min > pixels[k]) {
                        min = pixels[k];
                    }
                    if (max < pixels[k]) {
                        max = pixels[k];
                    }
                }
            }
            double lightning;
            lightning = ((double)(min + max))/2.0;
            double value = round (lightning);
            pImagePGM->pixels[i][j] = (int)value;
        }
    }
    return pImagePGM;
}
// grayscale = 0.21 R + 0.72 G + 0.07 B
ImagePGM *computeLuminosity(ImagePPM *pImagePPM) {
    ImagePGM *pImagePGM=malloc(sizeof(ImagePGM));
    strcpy(pImagePGM->magic,"P2");
    pImagePGM->height = pImagePPM->height;
    pImagePGM->width = pImagePPM->width;
    pImagePGM->max_value = pImagePPM->max_value;
    pImagePGM->pixels = malloc(sizeof(int *) * pImagePGM->height);
    for(int i=0;i<pImagePGM->height;i++) {
        pImagePGM->pixels[i] = malloc(sizeof(int) * pImagePGM->width);
    }
    for(int i=0;i< pImagePGM->height;i++) {
        for(int j=0;j< pImagePGM->width;j++) {
            double luminosity;
            luminosity = (0.21)*((double)(pImagePPM->pixels[i][j].red))+ (0.72)*((double)(pImagePPM->pixels[i][j].green))+ (0.07)*((double)(pImagePPM->pixels[i][j].blue));
            double value = round(luminosity);
            pImagePGM->pixels[i][j] = (int)value;
        }
    }
    return pImagePGM;
}
// based on https://www.johndcook.com/blog/2009/08/24/algorithms-convert-color-grayscale/

// Free the space used by a ppm image.
void freeSpacePPM(ImagePPM *pImagePPM) {
    free(pImagePPM);
}
// Free the space used by a pgm image.
void freeSpacePGM(ImagePGM *pImagePGM) {
    free(pImagePGM);
}