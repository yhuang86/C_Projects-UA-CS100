#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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


int main () {
    FILE *fp1;
    fp1 = fopen("testP1.ppm","r");
    ImagePPM *pImagePPM=malloc(sizeof(ImagePPM));
    fscanf(fp1,"%s %d %d %d",pImagePPM->magic,&pImagePPM->width,&pImagePPM->height,&pImagePPM->max_value);
    //printf("%s %d %d %d\n",pImagePPM->magic,pImagePPM->width,pImagePPM->height,pImagePPM->max_value);
    pImagePPM->pixels = malloc(sizeof(Pixel *) * pImagePPM->height);
    for(int i=0;i<pImagePPM->height;i++) {
        pImagePPM->pixels[i] = malloc(sizeof(Pixel) * pImagePPM->width);
    }
    for(int i=0;i<pImagePPM->height;i++) {
        for(int j=0;j<pImagePPM->width;j++) {
            fscanf(fp1, "%d %d %d", &pImagePPM->pixels[i][j].red,&pImagePPM->pixels[i][j].green,&pImagePPM->pixels[i][j].blue);
        }
    }
    /*for(int i=0;i<pImagePPM->height;i++) {
        for(int j=0;j<pImagePPM->width;j++) {
            printf("%d %d %d   ",pImagePPM->pixels[i][j].red,pImagePPM->pixels[i][j].green,pImagePPM->pixels[i][j].blue);
        }
        printf("\n");
    }*/

    //extract red
    char str[20];
    printf("Enter the Colour:");
    scanf("%s",str);
    if (strcmp(str,"red")==0) {
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
        for(int i=0;i<pImagePGM->height;i++) {
            for(int j=0;j<pImagePGM->width;j++) {
                printf("%d ",pImagePGM->pixels[i][j]);
            }
            printf("\n");
        }

    }
    else if (strcmp(str,"green")==0) {
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
        for(int i=0;i<pImagePGM->height;i++) {
            for(int j=0;j<pImagePGM->width;j++) {
                printf("%d ",pImagePGM->pixels[i][j]);
            }
            printf("\n");
        }

    }
    else if (strcmp(str,"blue")==0) {
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
        for(int i=0;i<pImagePGM->height;i++) {
            for(int j=0;j<pImagePGM->width;j++) {
                printf("%d ",pImagePGM->pixels[i][j]);
            }
            printf("\n");
        }

    }
    else if(strcmp(str,"average")==0) {
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
                 pImagePGM->pixels[i][j] = (int)avg;
            }
        }
        for(int i=0;i<pImagePGM->height;i++) {
            for(int j=0;j<pImagePGM->width;j++) {
                printf("%d ",pImagePGM->pixels[i][j]);
            }
            printf("\n");
        }

    }
    else if (strcmp(str,"ligntening")==0) {
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
                pImagePGM->pixels[i][j] = (int)lightning;

            }
        }
         for(int i=0;i<pImagePGM->height;i++) {
            for(int j=0;j<pImagePGM->width;j++) {
                printf("%d ",pImagePGM->pixels[i][j]);
            }
            printf("\n");
        }


    }
    else if (strcmp(str,"luminosity")==0) {
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
                pImagePGM->pixels[i][j] = (int)luminosity;
            }
        }
        for(int i=0;i<pImagePGM->height;i++) {
            for(int j=0;j<pImagePGM->width;j++) {
                printf("%d ",pImagePGM->pixels[i][j]);
            }
            printf("\n");
        }
        

    }
    
    


    

    
    return 0;
}
