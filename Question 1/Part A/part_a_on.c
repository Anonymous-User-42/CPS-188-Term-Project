

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE* file_o(void);
void file_c(FILE* file);

void main(void)
{
    FILE* f = file_o();

    file_c(f);
}

FILE* file_o(void)   /*  UDF for file opening    */
{
    char temp[100];
    FILE* file; /*  Initializing file storage variable  */
    file = fopen("statscan_diabetes.csv", "r"); /*  Defining the address path of file to be opened and read    */
    fscanf(file, "%d", temp);  /*  Scanning the defined file and storing it at address of Var(temp)    */
    return file;    /*  Returning the file type variable    */
}

void file_c(FILE* file) /*  UDF for file closing    */
{
    fclose(file);   /*  Closing the already opened file */
}

