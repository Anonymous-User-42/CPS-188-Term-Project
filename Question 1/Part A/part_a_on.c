

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*  Defining program macros */

#define ARRAY_SIZE 500
#define LINE_SIZE 250

/*  Initializing UDF's in program use   */

FILE* file_o(void);
void file_c(FILE* file);
int rlines(FILE* file, datatypes array[LINE_SIZE]);
datatypes data_points(FILE* file, datatypes array[LINE_SIZE]);

/*  Initializing struct datatypes for CSV data  */

typedef struct
{
    int year;
    char province[35];
    char age_group[15];
    char sex[10];
    //  char values[5];
    int values;
}datatypes;

void main(void)
{
    FILE* f = file_o();
    
    char string[ARRAY_SIZE];
    while(!feof(f))
    {
        fgets(string, ARRAY_SIZE,f);
        printf("%s\n", string);
    }
    
    datatypes data_set[LINE_SIZE];

    int line_read = rlines(f, data_set);

    data_set[LINE_SIZE] = data_points(f, data_set);

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

int rlines(FILE* file, datatypes array[LINE_SIZE])  /*  UDF for determining the number of lines read from the CSV files */
{
    int lines = 0;
    int data_values = 0;
    int temp;
    while(!feof(file))
    {
        if (data_values > 1)
        {
            data_values = fscanf(file, "%d, %35[^,], %15[^,], %8[^,], %d", &array[lines].year, array[lines].province, array[lines].age_group, array[lines].sex, &array[lines].values);
        }
        else if (data_values < 1)
        {
            data_values = fscanf(file, "", temp);
        }
    }
    return lines;
}

datatypes data_points(FILE* file, datatypes array[LINE_SIZE])   /*  UDF for scanning and addressing the CSV data points into a set of pre-defined struct arrays */
{
    int lines = 0;
    int data_values = 0;
    int temp;
    while(!feof(file))
    {
        if (data_values > 1)
        {
            data_values = fscanf(file, "%d, %35[^,], %15[^,], %8[^,], %d", &array[lines].year, array[lines].province, array[lines].age_group, array[lines].sex, &array[lines].values);
        }
        else if (data_values < 1)
        {
            data_values = fscanf(file, "", temp);
        }
    }
    return array[LINE_SIZE];
}

/*typedef struct datatypes
{
    int year;
    char province[50];
    char age_group[25];
    char sex[10];
    char values[5];
};*/
