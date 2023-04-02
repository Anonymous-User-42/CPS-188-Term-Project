

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
  char province[50];
  char age_group[20];
  char sex[10];
  char values[10];
  char temp_str[10];
} datatypes;

void main(void) {

  FILE* f = file_o();

  datatypes data_set[ARRAY_SIZE];

  char line[LINE_SIZE];
  
  int line_count = 0;
  int token_count = 0;
  while (feof(f) != true)
  {
    if (line_count == 0)
    {
      fgets(line, LINE_SIZE, f);
      line_count++;
      continue;
    }
    fgets(line, LINE_SIZE, f);
    line_count++;

    int token_count = 0;
    char* token = strtok(line, ",");
    strcpy(data_set[line_count].year, token);
    //token_count++;

    while(token != NULL)
    {
      //  printf("Token: %s\n", token);
      token = strtok(NULL, ",");
      token_count++;

      if (token_count == 2)
      {
        //strcpy(data_set[line_count].province, token);
      }
      else if (token_count == 3)
      {
        strcpy(data_set[line_count].age_group, token);
      }
      else if (token_count == 4)
      {
        strcpy(data_set[line_count].sex, token);
      }
      else if (token_count == 13)
      {
        strcpy(data_set[line_count].values, token);
      }
      else if (token_count == 14)
      {
        strcpy(data_set[line_count].temp_str, token);
      }
      

    }

      //printf("%d\n", token_count);
    }

    for (int i = 0; i < 220; i++)
    {
      char tok2[10];
      char tok3[10];
      strcpy(tok2, data_set[i].values);
      strcpy(tok3, &tok2[1]);
      double v = atof(tok3);
      //printf("%.3lf %s\n", v, data_set[i].values);
    }
    
	double sum_2015 = 0, sum_2016 = 0, sum_2017 = 0, sum_2018 = 0, sum_2019 = 0, sum_2020 = 0, sum_2021 = 0;
	double avg_2015 = 0, avg_2016 = 0, avg_2017 = 0, avg_2018 = 0, avg_2019 = 0, avg_2020 = 0, avg_2021 = 0;
	int c_2015 = 0, c_2016 = 0, c_2017 = 0, c_2018 = 0, c_2019 = 0, c_2020 = 0, c_2021 = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
		char tok2[10];
		char tok3[10];
		strcpy(tok2, data_set[i].year);
      	strcpy(tok3, &tok2[1]);
      	double year = atof(tok3);
		
		if (strcmp(data_set[i].year,"\"2015\""))
		{
			c_2015++;
			char tok2[10];
      		char tok3[10];
      		strcpy(tok2, data_set[i].values);
      		strcpy(tok3, &tok2[1]);
      		double v = atof(tok3);
			if (v == 0)
			{
				c_2015--;
			}
			
			sum_2015 += v;
		}
		if (year == 2016)
		{
			c_2016++;
			char tok2[10];
      		char tok3[10];
      		strcpy(tok2, data_set[i].values);
      		strcpy(tok3, &tok2[1]);
      		double v = atof(tok3);
			if (v == 0)
			{
				c_2016--;
			}
			
			sum_2016 += v;
		}
		if (year == 2017)
		{
			c_2017++;
			char tok2[10];
      		char tok3[10];
      		strcpy(tok2, data_set[i].values);
      		strcpy(tok3, &tok2[1]);
      		double v = atof(tok3);
			if (v == 0)
			{
				c_2017--;
			}
			
			sum_2017 += v;
		}
		if (year == 2018)
		{
			c_2018++;
			char tok2[10];
      		char tok3[10];
      		strcpy(tok2, data_set[i].values);
      		strcpy(tok3, &tok2[1]);
      		double v = atof(tok3);
			if (v == 0)
			{
				c_2018--;
			}
			
			sum_2018 += v;
		}
		if (year == 2019)
		{
			c_2019++;
			char tok2[10];
      		char tok3[10];
      		strcpy(tok2, data_set[i].values);
      		strcpy(tok3, &tok2[1]);
      		double v = atof(tok3);
			if (v == 0)
			{
				c_2019--;
			}
			
			sum_2019 += v;
		}
		if (year == 2020)
		{
			c_2020++;
			char tok2[10];
      		char tok3[10];
      		strcpy(tok2, data_set[i].values);
      		strcpy(tok3, &tok2[1]);
      		double v = atof(tok3);
			if (v == 0)
			{
				c_2020--;
			}
			
			sum_2020 += v;
		}
		if (year == 2021)
		{
			c_2021++;
			char tok2[10];
      		char tok3[10];
      		strcpy(tok2, data_set[i].values);
      		strcpy(tok3, &tok2[1]);
      		double v = atof(tok3);
			if (v == 0)
			{
				c_2021--;
			}
			
			sum_2021 += v;
		}
		
		
    }printf("2015 Average: %.3lf\n", sum_2015 / c_2015);printf("2016 Average: %.3lf\n", sum_2016 / c_2016);printf("2017 Average: %.3lf\n", sum_2017 / c_2017);printf("2018 Average: %.3lf\n", sum_2018 / c_2018);printf("2019 Average: %.3lf\n", sum_2019 / c_2019);printf("2020 Average: %.3lf\n", sum_2020 / c_2020);printf("2021 Average: %.3lf\n", sum_2021 / c_2021);
    

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

