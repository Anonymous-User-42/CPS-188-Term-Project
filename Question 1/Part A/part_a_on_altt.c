

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*  Defining program macros */

#define ARRAY_SIZE 500
#define LINE_SIZE 250

/*  Initializing UDF's in program use   */

FILE* file_o(void);
void file_c(FILE* file);

/*  Initializing struct datatypes for CSV data  */

typedef struct
{
    //  int year;
    char year[10];
    char province[35];
    char age_group[15];
    char sex[10];
    //  int values;
    char values[10];
}datatypes;

void main(void)
{
    FILE* f = file_o();
    
    char string[ARRAY_SIZE];

    int line = 0;
    int data_count = 0;

    datatypes data_set[LINE_SIZE];  /*  Struct array to store values from CSV   */

    int init = 0;
    while (fgets(string, ARRAY_SIZE, f))
    {
        line++;
        data_count = 0;
        if (line == 1)
        {
            continue;   /*  Parsing the first line as line 1 encompasses labels and headers which are of no relavance   */
        }
        char* data_value = strtok(string, ","); /*  Seperating the line string into subsequent smaller string based on comma seperation */
        while (data_count)
        {
            if (data_count == 0)
            {
                strcpy(data_set[init].year, data_value);
            }
            if (data_count == 1)
            {
                strcpy(data_set[init].province, data_value);
            }
            if (data_count == 3)
            {
                strcpy(data_set[init].age_group, data_value);
            }
            if (data_count == 4)
            {
                strcpy(data_set[init].sex, data_value);
            }
            if (data_count == 13)
            {
                strcpy(data_set[init].values, data_value);
            }
            data_value = strtok(NULL, ",");
            data_count++;
        }
        init++;
    }

    file_c(f);

    for (int i = 0; i <= line; i++)
    {
        printf("%s %s %s %s %s\n", data_set[i].year, data_set[i].province, data_set[i].age_group, data_set[i].sex, data_set[i].values);
    }

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

