#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    fp = fopen("case1.csv", "r");
    if (fp == NULL) {
        printf("Unable to open file %s for reading\n","data1");
        return 1;
    }
    char row[100][300];
    int numrow=0;
    while (1) {                         //store in the row[][]
        fgets(row[numrow],300,fp);
        if (feof(fp)) break;
        numrow++;                       //count row number(numrow)
    }
    fclose(fp);

    /*for (int i=0;i<numrow;i++) {
        printf("%s ",row[i]);
    }
    printf("\n");*/

    char* specify;
    specify = row[0];
    char *Colum[47];

    for(int i=0;i<47;i++) {
        Colum[i] = strsep(&specify,",");
    }
    /*for(int i=0;i<47;i++) {
        printf("%d. %s\n",i,Colum[i]);
    }*/

    int numCol=0;
    char column[6];
    strcpy(column,"E8");
    for (int i=0;i<47;i++) {              //find the Colum wanted
        if (strcasecmp(Colum[i],column)==0) {
            break;
            
        }
        numCol = numCol+1;

    }
    if(numCol == 47) numCol--;
    
    /*printf("%d\n",numCol);     
    printf("%s\n",column);  */

    char* scorerow;
    char* score[47];
    double numscore[numrow];
    int numblank=0;
    for(int i=1; i<=numrow-1;i++) {
        scorerow = row[i];
        for(int j=0;j<47;j++) {
            score[j] = strsep(&scorerow,",");
        }
        if (strlen(score[numCol])==0) {
            numscore[i]=-1000;            
            numblank++;
        }
        
        else    numscore[i] = atof(score[numCol]);
        printf("%d. %s\n",i,score[numCol]);
        
    }
    printf("%d\n",numrow);

    double minscore;
    for(int i=1;i<numrow;i++) {
        if (i==1) {
            minscore = numscore[i];
        }
        else {
            if (minscore > numscore[i]) {
                minscore = numscore[i];
            }
        }
    }
    printf("%lf\n",minscore);

    return 0;
}