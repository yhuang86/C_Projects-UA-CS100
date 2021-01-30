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
        numrow++;                     //count row number(numrow)
    }
    fclose(fp);
    /*for(int i=0;i<numrow;i++) {
        printf("%s",row[i]);
    }*/
    char* specify;
    specify = row[0];
    char *Colum[47];

    for(int i=0;i<47;i++) {
        Colum[i] = strsep(&specify,",");
    }
    /*for(int i=0;i<47;i++) {
        printf("%d. %s\n",i,Colum[i]);
    }*/

    //int numcolfirst =0;
    //int numcollast =1;
    char first[50];
    char last[50];
    strcpy(first,"Stormy");
    strcpy(last,"Beaufort");



    char* scorerow;
    char* score[47];
    int namerow=0;
    //double numscore[numrow];
    char firstname[numrow][50];
    char lastname[numrow][50];
    for(int i=1; i<=numrow;i++) {
        scorerow = row[i];
        for(int j=0;j<47;j++) {
            score[j] = strsep(&scorerow,",");
        }
        strcpy(firstname[i],score[0]);
        strcpy(lastname[i],score[1]);
        //printf("%d. %s %s\n",i,firstname[i],lastname[i]);
        if ((strcasecmp(firstname[i],first)==0)&&(strcasecmp(lastname[i],last)==0)) {
            namerow=i;
        }
        
    }
    //printf("%d\n",namerow);

    if (namerow==0) {
        return -1;
    }
    
    numrow=0;
    fp = fopen("case1.csv", "r");
    while (1) {                         //store in the row[][]
        fgets(row[numrow],300,fp);
        if (feof(fp)) break;
        numrow++;                     //count row number(numrow)
    }
    fclose(fp);
    
   // printf("%s ",row[namerow]);
    
    char* studentscore;
    studentscore = row[namerow];
    char* specificscore[47];

    for (int i=0;i<47;i++) {
        specificscore[i] = strsep(&studentscore,",");
    }
    /*for(int i=0;i<47;i++) {
        printf("%d. %s\n",i,specificscore[i]);
    }*/
    
    //Quiz
    double quiz[11];
    int numquiz=0;
    //Lab
    double lab[11];
    int numlab=0;
    //Book
    double Book[10];
    int numbook=0;
    //Project
    double project[6];
    //Exam
    double exam[8];

    for(int i=0;i<47;i++) {
        if (Colum[i][0]=='Q') {
            
            quiz[numquiz]= atof(specificscore[i]);
            numquiz++;
            
        }
        else if (Colum[i][0]=='L') {
            
            lab[numlab]= atof(specificscore[i]);

            numlab++;
        }
        else if (Colum[i][0]=='B') {
            
            Book[numbook]=atof(specificscore[i]);
            numbook++;
        }
        else if (Colum[i][0]=='P') {
            if (Colum[i][1]=='1') {
                project[0] = atof(specificscore[i]);
            }
            else if (Colum[i][1]=='2') {
                project[1] = atof(specificscore[i]);
            }
            else if (Colum[i][1]=='3') {
                project[2] = atof(specificscore[i]);
            }
            else if (Colum[i][1]=='4') {
                project[3] = atof(specificscore[i]);
            }
            else if (Colum[i][1]=='5') {
                project[4] = atof(specificscore[i]);
            }
            else if (Colum[i][1]=='6') {
                project[5] = atof(specificscore[i]);
            }

        }
        else if (Colum[i][0]=='E') {
            if (Colum[i][1]=='1') {
                exam[0]=atof(specificscore[i]);
            }
            else if (Colum[i][1]=='2') {
                exam[1]=atof(specificscore[i]);
            }
            else if (Colum[i][1]=='3') {
                exam[2]=atof(specificscore[i]);
            }
            else if (Colum[i][1]=='4') {
                exam[3]=atof(specificscore[i]);
            }
            else if (Colum[i][1]=='5') {
                exam[4]=atof(specificscore[i]);
            }
            else if (Colum[i][1]=='6') {
                exam[5]=atof(specificscore[i]);
            }
            else if (Colum[i][1]=='7') {
                exam[6]=atof(specificscore[i]);
            }
            else if (Colum[i][1]=='8') {
                exam[7]=atof(specificscore[i]);
            }
            
        }
    }
    
    //Grade Quiz

    double minquiz;             //find minimum
    for (int i=0;i<11;i++) {
        if (i==0) {
            minquiz = quiz[i];
        }
        else {
            if (minquiz > quiz[i]) {
                minquiz = quiz[i];
            }
        }

    }
    

    double sumquiz=0;             //sumquiz
    for (int i=0;i<11;i++) {
        sumquiz = sumquiz + quiz[i];
    }
    sumquiz = sumquiz - minquiz;
    double quizscore = sumquiz * 0.1;

    //grade lab
    double sumlab;
    for(int i=1;i<11;i++) {
        
        sumlab = sumlab + lab[i];
    }
    double labscore = sumlab * 0.01;

    //grade Book
    double sumbook=0;
    for (int i=0;i<10;i++) {
       sumbook = sumbook + Book[i];
    }
    double bookscore = sumbook * 0.01;

    //grade project
    double projectscore = 0;
    projectscore = project[0] * 0.02 + (project[1]+project[2])*0.04 +(project[3]+project[4]+project[5])*0.05 ;
 

    //grade exam
    double examscore =0;
    examscore = (exam[0]+exam[1]+exam[2]+exam[3]+exam[4]+exam[5]) * 0.1 + (exam[6] + exam[7]) * 0.1;
    
    //total 
    double grade=0;
   
    grade = quizscore + bookscore + labscore + projectscore + examscore;
    printf("%lf\n",grade);
    
    
    return 0;
}