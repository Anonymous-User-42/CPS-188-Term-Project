#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int main(void) 
{    
	printf("Question 3:\n");
	
    int years; 
    char place[50]; 
    char ages[50]; 
    char gender[20];  
    float percent;  
    char *sp, *vp; 

    char line[900];
    FILE *fp; 
    fp= fopen("statscan_diabetes.csv", "r"); 
     
    if(fp==NULL){ 
        printf("Something went wrong\n"); 
        return 1;
    } 

    fgets(line,900,fp); // read and ignore first line

    float sum = 0.0;
    int count = 0;
    for(int i = 0; i < 42; i++){ 
        fgets(line, 900, fp); // read next line
              
        sp=strtok(line, "\""); 
        years= atoi(sp); 
  
        sp=strtok(NULL, ",");    
        strcpy(place, sp);   
 
        sp=strtok(NULL, ",");  
        sp=strtok(NULL, ",");   
        strcpy(ages,sp); 
               
        sp=strtok(NULL, ",");  
        strcpy(gender,sp); 
  
        sp=strtok(NULL, ","); //indicators skipped 
        sp=strtok(NULL, ","); //Characteristics skipped 
        sp=strtok(NULL, ","); //UOM skipped 
        sp=strtok(NULL, ","); //UOM_ID skipped 
        sp=strtok(NULL, ","); //Scalar Factor skipped 
        sp=strtok(NULL, ","); //Scalar ID skipped 
        sp=strtok(NULL, ","); //Vector skipped   
        sp=strtok(NULL, ","); 
        sp=strtok(NULL, ","); 
        vp=strtok(sp, "\"");
        percent= atof(vp);

        sum += percent;
        count++;
    } 

    float average = sum / count;
    printf("The National average is: %.1f", average);

    return 0;
}
