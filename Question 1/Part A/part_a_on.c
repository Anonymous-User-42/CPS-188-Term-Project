

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE* file_o(void);
void file_c(FILE* file);

typedef struct datatypes;

void main(void)
{
    FILE* f = file_o();
    
    char string[500];
    for (int i = 0; i < 10; i++)
    {
        fgets(string, 500,f);
        printf("%s\n", string);
    }
    
    file_c(f);
}

FILE* file_o(void)   /*  UDF for file opening    */
{
    char temp[100];
    FILE* file; /*  Initializing file storage variable  */
    file = fopen("statscan_diabetes.csv", "r"); /*  Defining the address path of file to be opened and read    */
    if (NULL == file)   /*  Fail Safe mechanism for program file opening    */
    {
        printf("Error: File Open cannot proceed\n");
        exit;   /*  Program exits and ends if the fail-safe breaks  */
    }
    fscanf(file, "%s", temp);  /*  Scanning the defined file and storing it at address of Var(temp)    */
    return file;    /*  Returning the file type variable    */
}

void file_c(FILE* file) /*  UDF for file closing    */
{
    fclose(file);   /*  Closing the already opened file */
}

typedef struct datatypes
{
    int year;
    char province[50];
    char age_group[25];
    char sex[10];
    char values[5];
};
