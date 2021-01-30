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
    strcpy(column,"E8");
    for (int i=0;i<47;i++) {              //find the Colum wanted
        if (strcasecmp(Colum[i],column)==0) {
            break;
            
        }
        numCol = numCol+1;

    }
    if(numCol == 47) numCol--;
    
    printf("%d\n",numCol);     
    printf("%s\n",column);           
    
    
    char* scorerow;
    char* score[47];
    double numscore[numrow];
    int numblank=0;
    for(int i=1; i<=numrow;i++) {
        scorerow = row[i];
        for(int j=0;j<47;j++) {
            score[j] = strsep(&scorerow,",");
        }
        if (strlen(score[numCol])==0) {
            numscore[i]=-1000;            
            numblank++;
        }
        
        else    numscore[i] = atoi(score[numCol]);
        printf("%d. %s\n",i,score[numCol]);
        
    }
    
    
    //printf("numblank %d\n",numblank);
    
    
    
        
        

    
    //printf("%d\n",atoi(score[46]));
    /*double avg = sum/(numrow-numblank);
    printf("%lf\n",sum);
    printf("%lf\n",avg);*/

    int comparenum = 90;
    int count=0;
    for(int i=1;i<=numrow;i++) {
        if (numscore[i]>=comparenum){
            count++;
        }
    }
    //printf("%d\n",count);
    
   
    
    

    
 


    return 0; 
}