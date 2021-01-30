/* Yichen Huang  
The function used in the program is to get the format code
The second function is used to print the line number of the begining and the end



*/
#include <stdio.h>
#include <string.h>

// Get the format code
void GetFormatCode (char* justified, int* numLines) {
    printf("Enter a formatting code:\n");
    scanf("%c%d",&*justified,&*numLines);
}
// Line Number Printer
void PrintLineNumber (int numLines) {
        for (int i=1;i<=numLines;i++) {
        if (i>9) {
            printf("%d",i%10);
        }
        else {
            printf("%d",i);
        }
    }
    printf("\n");
}
// Dots Counter
int GetSumDot(char Text[],int length,int sumdots) {
    // the number of dots for 'A' (at 0) through 'Z' (at 25)
    int dotsUpper[26]={
    16, 19, 13, 18, 18, 14, 16,
    17, 11, 12, 14, 11, 21, 19,
    16, 15, 18, 18, 15, 11, 15,
    13, 20, 11, 11, 15
    };
    // the number of dots for 'a' (at 0) through 'z' (at 25)
    int dotsLower[26]={
    12, 14,  9, 14, 14, 12, 18,
    14,  9, 10, 12, 10, 16, 12,
    12, 14, 14,  8, 13, 10, 12,
    9, 14,  9, 16, 13
    };
    int i;
    int letternum;
    for(i=0;i<length;i++) {
        if ((Text[i]>=65) && (Text[i]<=90)) {
            letternum = Text[i] - 65;
            sumdots = sumdots+dotsUpper[letternum];
        }
        else if ((Text[i]>=97)&&(Text[i]<=122)) {
            letternum = Text[i] - 97;
            sumdots = sumdots + dotsLower[letternum];
        }
    }
    return sumdots;
}



int main (void) {

    char justified ='0';
    int numLines;
    const int numWord = 1000;
    const int wordLength = 100;
    char word[numWord][wordLength];
    int count=0;
    int sumdots =0;

    //get FormatCode
    GetFormatCode (&justified, &numLines);
    //Get text
    printf("Enter a paragraph, ending with <CTRL-D>: \n");
        while (1) {
            scanf("%s",word[count]);
            if (feof(stdin)) break;
            count++;
        }
        strcpy(word[count+1],"End");
        
        
        
    //Print the line number
    PrintLineNumber (numLines);
    
    //count dot
    for (int i=0;i<count;i++) {
        char Text[1000];
        strcpy (Text, word[i]);
        int length = strlen(Text);
        sumdots =  GetSumDot(Text,length,sumdots);
        
    }
    // Format Printing 
    int numspace =0;
    int newlines =0;
    //Left
    if (justified == 'L') {
        newlines =1;
        int lengthremain = numLines;
        for (int i=count-1;i>=0;i--) {
            
            if (lengthremain > strlen(word[(count-1)-i])) {
                
                printf("%s ",word[(count-1)-i]);
                lengthremain = lengthremain - (strlen(word[(count-1)-i])+1);
                if (i>0) numspace = numspace + 1;

            }
            else if (lengthremain == strlen(word[(count-1)-i])) {
                printf("%s",word[(count-1)-i]);
                printf("\n");
                lengthremain = numLines;
                newlines = newlines+1;
            }
            else if (lengthremain < strlen(word[(count-1)-i])) {
                printf("\n");
                lengthremain = numLines;
                newlines = newlines+1;
                numspace = numspace-1;
            
                i=i+1;
            }
        
        }
        printf("\n");
    }
    //Right
    else if (justified == 'R') {
            int stringlength =0;
            int wordcount =0;
            int spaceremain =0;
        for(int i=0;i<count;i++) {
            
            stringlength = stringlength + strlen(word[i])+1;

            
            if (stringlength == numLines) {
                int j;
                for(j=wordcount;j<=i;j++) {
                    printf(" %s",word[j]);
                    numspace = numspace +1;
                    
                }
                wordcount = j;
                i=j-1;
                printf("\n");
                newlines = newlines +1;
                spaceremain = spaceremain + 1;
                stringlength =0;
                spaceremain =0;
                

            }
        
            else if (stringlength > numLines) {
                if (stringlength -1 == numLines) {
                    int j;
                    for ( j=wordcount;j<=i;j++) {
                        printf("%s ",word[j]);
                        numspace = numspace +1;
                    }
                    printf("\n");
                    numspace = numspace -1;
                    i=j-1;
                    wordcount =j;
                    newlines = newlines +1;
                    stringlength =0;
                    spaceremain =0;
                }
                else {
                    stringlength = stringlength - strlen(word[i]);
                    spaceremain = numLines - stringlength +1;
                    numspace = numspace + spaceremain;
                    for(int j=0;j<spaceremain;j++) {
                        printf(" ");
                    }
                    int k;
                    for(k=wordcount; k<i;k++) {
                        printf(" %s",word[k]);
                        numspace = numspace +1;
                    }
                    printf("\n");
                    wordcount=k;
                    newlines = newlines + 1;
                    stringlength =0;
                    spaceremain =0;
                    i=k-1;
                }

                
            }
            else if (strcmp(word[i+2],"End")==0) {
                spaceremain = numLines - stringlength;
                numspace = numspace + spaceremain;
                for (int j=0; j<spaceremain;j++) {
                    printf(" ");
                }
                for (int k=wordcount;k<count;k++) {
                    printf(" %s",word[k]);
                    numspace = numspace +1;
                }
                printf("\n");
                newlines = newlines +1;
                
            }
            




        }
        

    }
    // Center
    else if (justified =='C') {
            int stringlength =0;
            int wordcount =0;
            int spaceremain =0;
        for(int i=0;i<count;i++) {
            
            stringlength = stringlength + strlen(word[i])+1;

            
            if (stringlength == numLines) {
                int j;
                for(j=wordcount;j<=i;j++) {
                    printf("%s ",word[j]);
                    numspace = numspace +1;
                }
                numspace = numspace-1;
                wordcount = j;
                i=j-1;
                printf("\n");
                newlines = newlines +1;
                spaceremain = spaceremain + 1;
                stringlength =0;
                spaceremain =0;
                

            }
        
            else if (stringlength > numLines) {
                if (stringlength -1 == numLines) {
                    int j;
                    for ( j=wordcount;j<=i;j++) {
                        printf("%s ",word[j]);
                        numspace = numspace + 1;
                    }
                    numspace = numspace -1;
                    printf("\n");
                    i=j-1;
                    wordcount =j;
                    newlines = newlines +1;
                    stringlength =0;
                    spaceremain =0;
                }
                else {
                    stringlength = stringlength - strlen(word[i]);
                    spaceremain = numLines - stringlength -1;
                    numspace = numspace + spaceremain/2;
                    for(int j=0;j<spaceremain/2;j++) {
                        printf(" ");
                    }
                    int k;
                    for(k=wordcount; k<i;k++) {
                        printf(" %s",word[k]);
                        numspace = numspace +1;
                    }
                    printf("\n");
                    wordcount=k;
                    newlines = newlines + 1;
                    stringlength =0;
                    spaceremain =0;
                    i=k-1;
                }

                
            }
            else if (strcmp(word[i+2],"End")==0) {
                spaceremain = numLines - stringlength-1;
                numspace = numspace + spaceremain/2;
                for (int j=0; j<spaceremain/2;j++) {
                    printf(" ");
                }
                for (int k=wordcount;k<count;k++) {
                    printf(" %s",word[k]);
                    numspace = numspace +1;
                }
                printf("\n");
                newlines = newlines +1;
                
            }
            




        }
    }

    
    PrintLineNumber (numLines);

    printf("Dots printed: %d\n",sumdots);
    printf("Spaces printed: %d\n",numspace);
    printf("Newlines printed: %d\n",newlines);

    return 0;
}