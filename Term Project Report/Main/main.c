

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*  Defining program macros */

#define ARRAY_SIZE 500
#define LINE_SIZE 250
#define STRING_SIZE 50

/*  Initializing UDF's in program use   */

FILE* file_o(void);
void file_c(FILE* file);

/*  Initializing struct datatypes for CSV data  */

typedef struct {
  char year[10];
  char province[35];
  char age_group[15];
  char sex[10];
  char values[5];
} datatypes;

void main(void)
{
    FILE* f = file_o();

    file_c(f);
}

/*  Defining all subsequent UDF's utilized in the program   */

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

