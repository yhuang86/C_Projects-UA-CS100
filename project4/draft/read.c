#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
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
    strcpy(column,"P4");
    for (int i=0;i<47;i++) {              //find the Colum wanted
        if (strcasecmp(column,Colum[i])==0) {
            break;
            
        }
        numCol++;

    }
    if(numCol == 47) numCol--;
    printf("%d\n",numCol);     
    printf("%s\n",column);           
    

    char* scorerow;
    char* score[47];
    double numscore[numrow];
    int numblank=0;
    int haveZero=0;
    int blankrow[numrow];
    for(int i=1; i<numrow;i++) {
        scorerow = row[i];
        for(int j=0;j<47;j++) {
            score[j] = strsep(&scorerow,",");
        }
        if (strlen(score[numCol])==0) {
            blankrow[numblank] = i;
            numblank++;
        }
        if (strcmp(score[numCol],"0")==0) {
            haveZero = 1;
        }

        numscore[i] = atoi(score[numCol]);
    }

    printf("numblank %d\n",numblank);
    printf("Have 0? %d\n",haveZero);
    for(int i=0;i<numblank;i++) {
        printf("blank row %d\n",blankrow[i]);
    }
    //double sum=0.0;
    for(int i=1; i<numrow;i++) {
        printf("%d %lf\n",i,numscore[i]);
        //sum+=numscore[i];

    }
    //double minscore;

    

    /*double maxscore=0;
    for(int i=1;i<numrow;i++) {
        if (numscore[i]!=0) {
            if (maxscore < numscore[i]) {
                maxscore = numscore[i];
            }

        }
    }
    double minscore=maxscore;
    for(int i=1;i<numrow;i++) {
        if (numscore[i]!=0) {
            if (minscore > numscore[i]) {
                minscore = numscore[i];
            }

        }
    }
    printf("%lf\n",minscore);
    */
    

    
 


    return 0; 
}