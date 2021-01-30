/*  Name: Yichen Huang 
    ***Overview of the task : The function here will firstly read the file and identify the specific Colum, get the colum number
    and grab every score from every row, and compare them for the min and max or add them to calculate the average or calculate the
    average score.*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Given a csv file, return the minimum of the specified column, excluding blanks
double getMin(char csvfile[], char column[]){
    FILE *fp;
    fp = fopen(csvfile, "r");
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

    int numCol=0;

    for (int i=0;i<47;i++) {              //find the Colum wanted
        if (strcasecmp(column,Colum[i])==0) {
            break;
            
        }
        numCol++;

    }
    if(numCol == 47) numCol--;

    char* scorerow;
    char* score[47];
    double numscore[numrow];
    int numblank=0;
    for(int i=1; i<numrow;i++) {
        scorerow = row[i];
        for(int j=0;j<47;j++) {
            score[j] = strsep(&scorerow,",");
        }
        if (strlen(score[numCol])==0) {
            numscore[i] = 1000;
            numblank++;
        }
        else {
            numscore[i] = atoi(score[numCol]);
        }
    }
    
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
    return minscore;
}
// Given a csv file, return the maximum of the specified column, excluding blanks
double getMax(char csvfile[], char column[]) {
     FILE *fp;
    fp = fopen(csvfile, "r");
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

    int numCol=0;

    for (int i=0;i<47;i++) {              //find the Colum wanted
        if (strcasecmp(column,Colum[i])==0) {
            break;
            
        }
        numCol++;

    }
    if(numCol == 47) numCol--;

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
            numblank++;
        }
        else {
            numscore[i] = atof(score[numCol]);
        }
    }
    
    double maxscore;
    for(int i=1;i<=numrow;i++) {
        if (i==1) {
            maxscore = numscore[i];
        }
        else {
            if (maxscore < numscore[i]) {
                maxscore = numscore[i];
            }
        }
    }
    return maxscore;
}
// Given a csv file, return the average of the specified column, excluding blanks
double getAvg(char csvfile[], char column[]) {
     FILE *fp;
    fp = fopen(csvfile, "r");
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

    int numCol=0;

    for (int i=0;i<47;i++) {              //find the Colum wanted
        if (strcasecmp(column,Colum[i])==0) {
            break;
            
        }
        numCol++;

    }
    if(numCol == 47) numCol--;

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
            numblank++;
        }
        else {
            numscore[i] = atof(score[numCol]);
        }
    }
    double sum=0.0;
    for(int i=1; i<=numrow;i++) {
        sum+=numscore[i];

    }
    double avg = sum/(numrow-numblank);
    return avg;
}
// Given a csv file, return the number of students with their column value >= threshold, excluding blanks
int getCount(char csvfile[], char column[], double threshold) {
         FILE *fp;
    fp = fopen(csvfile, "r");
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

    int numCol=0;

    for (int i=0;i<47;i++) {              //find the Colum wanted
        if (strcasecmp(column,Colum[i])==0) {
            break;
            
        }
        numCol++;

    }
    if(numCol == 47) numCol--;

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
        else {
            numscore[i] = atoi(score[numCol]);
        }
    }
        int count=0;
    for(int i=1;i<=numrow;i++) {
        if (numscore[i]>=threshold){
            count++;
        }
    }
    return count;
}
// Given a csv file, return the weighted average of the specified student
// or -1.0 if there is no such student.
// A blank cell is viewed as 0
double getGrade(char csvfile[], char first[], char last[]){
        FILE *fp;
    fp = fopen(csvfile, "r");
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
    double grade =0;

    if (namerow==0) {
        return grade = -1;
    }
    
    numrow=0;
    fp = fopen(csvfile, "r");
    while (1) {                         //store in the row[][]
        fgets(row[numrow],300,fp);
        if (feof(fp)) break;
        numrow++;                     //count row number(numrow)
    }
    fclose(fp);
    
    //printf("%s ",row[namerow]);
    
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

    double minquiz =0;             //find minimum
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
    double sumlab=0;
    for(int i=1;i<11;i++) {
        
        sumlab = sumlab + lab[i];
    }
    double labscore =0;
    labscore = sumlab * 0.01;

    //grade Book
    double sumbook=0;
    for (int i=0;i<10;i++) {
       sumbook = sumbook + Book[i];
    }
    double bookscore =0;
    bookscore = sumbook * 0.01;

    //grade project
    double projectscore = 0;
    projectscore = project[0] * 0.02 + (project[1]+project[2])*0.04 +(project[3]+project[4]+project[5])*0.05 ;
 

    //grade exam
    double examscore =0;
    examscore = (exam[0]+exam[1]+exam[2]+exam[3]+exam[4]+exam[5]) * 0.1 + (exam[6] + exam[7]) * 0.1;
    
    //total 
    
    
   
    grade = quizscore + bookscore + labscore + projectscore + examscore;
    
    return grade;
}             