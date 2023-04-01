

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  char age_group[20];
  char sex[10];
  char values[10];
  char temp_str[10];
} datatypes;

void main(void)
{
    FILE* f = file_o(); /*  Initializing File Operations    */

    datatypes data_set[ARRAY_SIZE];
    char line[LINE_SIZE];

    int line_count = 0; /*  Initializing Line Counter Variable to count Lines in the File   */

    while (!feof(f))    /*  Initializing start of CORE program base function    */
    {
        if (line_count == 0)
        {
            fgets(line, LINE_SIZE, f);
            line_count++;
            continue;   /*  Parsing the first line as line 1 encompasses labels and headers which are of no relavance   */
        }
        fgets(line, LINE_SIZE, f);
        line_count++;   /*  Line Counter Variable Update    */

        int token_count = 0;    /*  Initializing Token Counter Variable to count the tokens after String Tokenization   */
        char* token = strtok(line, ",");    /*  Seperating the line string into subsequent smaller string based on Comma Seperation & Tokenizing a slice of string after "," delimiter as a parameter   */
        strcpy(data_set[line_count].year, token);   /*  Assigning a string value for the Year from this base iteration of Var(token) [NO CONDITION REQUIRED - FIRST FIED ENTRY IN FILE] */
        //token_count++;  /*  Token Counter Variable Update   */

        while(token != NULL)
        {
            token = strtok(NULL, ",");
            token_count++;  /*  Token Counter Variable Update   */

            /*if (token_count == 1)
            {
                strcpy(data_set[line_count].province, token);   //  Assigning a string value for Province from this iteration of Var(token) if conditional satisfied
            }*/
            if (token_count == 3)
            {
                strcpy(data_set[line_count].age_group, token);  /*  Assiging a string value of Age Goup from this iteration of Var(token) if conditional is satisfied   */
            }
            else if (token_count == 4)
            {
                strcpy(data_set[line_count].sex, token);    /*  Assigning a string value of Sex from this iteration of Var(token) if conditional is satisfied   */
            }
            else if (token_count == 13)
            {
                strcpy(data_set[line_count].values, token); /*  Assigning a string value of Values (Raw Percentage Floats) from this iterationm of Var(token) if condition is satisfied */
            }
            else if (token_count == 14)
            {
                strcpy(data_set[line_count].temp_str, token);   /*  Assigning a string temp trash value of string literal's after Var(values) to disregard "\"" delimiter from being concatenated into Values string [CONDITION IS ALWAYS SATISFIED - TOTAL TOKEN COUNT IS 19 - temp_str HAS FREE malloc(20) per cycle allocation]  */
            }
        }
    }   /*  End of CORE program base function   */

    file_c(f);  /*  Terminating File Operations */

    float sum_federal = 0;
    int federal_iterator_counter = 0;

    for (int i = 2; i < 44; i++, federal_iterator_counter++)
    {
      char add_val_f[10];
      char stg_val_f[10];
      strcpy(add_val_f, data_set[i].values);
      strcpy(stg_val_f, &add_val_f[1]);
      double values_federal = atof(stg_val_f);
      //printf("%.2lf\n",values_federal);
      sum_federal =+ values_federal;
    } double avg_federal = (sum_federal) / (federal_iterator_counter); printf("Federal Average: %.2lf\n", avg_federal);
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

