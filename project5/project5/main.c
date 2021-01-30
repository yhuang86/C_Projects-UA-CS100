#include <stdio.h>
#include <string.h>

#include "image.h"

char *methods[6] = { "red", "green", "blue", "average", "lightness", "luminosity"};

// return -1 for an invalid method
int getMethodID(char *method)
{
	for (int i=0; i<6; i++) {
		if (strcmp(method, methods[i])==0) return i;
	}
	return -1;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <method> ppm_filename pgm_filename\n", argv[0]);
        printf("Valid methods:\n");
		for (int i=0; i<6; i++) {
			printf("\t%s\n", methods[i]);
		}
        return 1;
    }

	int method_id=getMethodID(argv[1]);
	if (method_id<0) {
        printf("Invalid method: %s\n", argv[1]);
		return 2;
	}

    ImagePPM *pImagePPM;
    pImagePPM = readPPM(argv[2]);
    if (pImagePPM == NULL) {
        printf("Unable to read file: %s\n", argv[2]);
        return 3;
    }

    ImagePGM *pImagePGM;
	switch (method_id) {
	case 0: // red
        pImagePGM = extractRed(pImagePPM);
		break;
	case 1: // green
        pImagePGM = extractGreen(pImagePPM);
		break;
	case 2: // blue
        pImagePGM = extractBlue(pImagePPM);
		break;
	case 3: // average
        pImagePGM = computeAverage(pImagePPM);
		break;
	case 4: // lightness
        pImagePGM = computeLightness(pImagePPM);
		break;
	case 5: // luminosity
        pImagePGM = computeLuminosity(pImagePPM);
		break;
    }

    int result = writePGM(pImagePGM, argv[3]);
	if (result==0) {
        printf("Unable to write file: %s\n", argv[3]);
	}

	freeSpacePPM(pImagePPM);
	freeSpacePGM(pImagePGM);

    return 0;
}
