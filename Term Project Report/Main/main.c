

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*  Defining program macros */

#define ARRAY_SIZE 500
#define LINE_SIZE 250
#define STRING_SIZE 50
#define SPACERS 3
#define SUB_SPACERS 2

/*  Initializing UDF's in program use   */

void credits(void);
FILE* file_o(void);
void file_c(FILE* file);
void spacer(void);
void sub_spacer(void);
void avg_province(void);
void avg_year(void);
void year_avg(double f_2015, double f_2016, double f_2017, double f_2018, double f_2019, double f_2020, double f_2021, double q_2015, double q_2016, double q_2017, double q_2018, double q_2019, double q_2020, double q_2021, double o_2015, double o_2016, double o_2017, double o_2018, double o_2019, double o_2020, double o_2021, double a_2015, double a_2016, double a_2017, double a_2018, double a_2019, double a_2020, double a_2021, double b_2015, double b_2016, double b_2017, double b_2018, double b_2019, double b_2020, double b_2021);
void avg_age(void);
void age_avg(double f_35, double f_50, double f_65, double q_35, double q_50, double q_65, double o_35, double o_50, double o_65, double a_35, double a_50, double a_65, double b_35, double b_50, double b_65);

/*  Initializing struct datatypes for CSV data  */

typedef struct {    /*  Struct to store every Parameter in a line as an array of tokens with respect to their induvidual fields */
  char year[10];
  char province[35];
  char age_group[20];
  char sex[10];
  char values[10];
  char temp_str[10];
} datatypes;    /*  Struct DataType Variable name defined as "datatypes"    */

void main(void)
{
	credits();

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

    /*          Question 1          */printf("|------------------------------------------------------------------------------------------Question 1------------------------------------------------------------------------------------------|\n");

	spacer();
	/*		Province Wise Averages		*/avg_province();
	spacer();

    /*  Initializing Sum & Iterating Counter Variables for Province Averages Calculation	*/

    //  float sum_province - Variable to store the sum of the Value Data Points subsequently in every iteration
    //  province_iterator_counter - Variable to calculate the number of iterations performed in the for loop

    /*  Federal Variables   */

    float sum_federal = 0;
    int federal_iterator_counter = 0;

    /*  Quebec Variables    */

    float sum_quebec = 0;
    int quebec_iterator_counter = 0;

    /*  Ontario Variables   */

    float sum_ontario = 0;
    int ontario_iterator_counter = 0;

    /*  Alberta Variables   */

    float sum_alberta = 0;
    int alberta_iterator_counter = 0;

    /*  British Columbia Variables	*/

    float sum_british_columbia = 0;
    int british_columbia_iterator_counter = 0;

    /*  Federal Average Calculator  */

    for (int i = 2; i < 44; i++, federal_iterator_counter++)
    {
      char add_val_f[10];   /*  Initializing char variable to copy char pointer to char variable type   */
      char stg_val_f[10];   /*  Initializing char variable to store char to char recieved from char pointer */
      strcpy(add_val_f, data_set[i].values);    /*  Copying to char variable from char pointer variable */
      strcpy(stg_val_f, &add_val_f[1]); /*  Storing the char variable in another char variable to manipulate string literals    */
      double values_federal = atof(stg_val_f);  /*  Converting the stored char variable to a float type varaible data type for mathematical computational maniupulation */
      if (values_federal == 0)
      {
        federal_iterator_counter--; /*  Fail-Safe Mechanism for not counting the iterations in the iterating counter factor if the condition is met [CONDITION IS ONLY SATISFIED IF THE atof FUNCTION RETURN 0, IFF THE Var(char) = NULL]   */
      }
      //printf("%.2lf\n",values_federal);   /*  Fail-Safe in Testing phase to verify succinctity of the values being read from atof function    */
      sum_federal += values_federal;    /*  Calculation of Summa function of all data points being read that are not NULL   */
    } double avg_federal = (sum_federal) / (federal_iterator_counter); printf("Federal Average: %.3lf\n", avg_federal); /*  Calculation of the Average function from the previous Summa function and iterator counter function as inputs    */

    /*  Quebec Average Calculator   */

    for (int i = 44; i < 86; i++, quebec_iterator_counter++)
    {
      char add_val_q[10];   /*  Initializing char variable to copy char pointer to char variable type   */
      char stg_val_q[10];   /*  Initializing char variable to store char to char recieved from char pointer */
      strcpy(add_val_q, data_set[i].values);    /*  Copying to char variable from char pointer variable */
      strcpy(stg_val_q, &add_val_q[1]); /*  Storing the char variable in another char variable to manipulate string literals    */
      double values_quebec = atof(stg_val_q);  /*  Converting the stored char variable to a float type varaible data type for mathematical computational maniupulation */
      if (values_quebec == 0)
      {
        quebec_iterator_counter--; /*  Fail-Safe Mechanism for not counting the iterations in the iterating counter factor if the condition is met [CONDITION IS ONLY SATISFIED IF THE atof FUNCTION RETURN 0, IFF THE Var(char) = NULL]   */
      }
      //printf("%.2lf\n",values_quebec);   /*  Fail-Safe in Testing phase to verify succinctity of the values being read from atof function    */
      sum_quebec += values_quebec;    /*  Calculation of Summa function of all data points being read that are not NULL   */
    } double avg_quebec = (sum_quebec) / (quebec_iterator_counter); printf("Quebec Average: %.3lf\n", avg_quebec);

    /*  Ontario Average Calculator  */

    for (int i = 86; i < 128; i++, ontario_iterator_counter++)
    {
      char add_val_o[10];   /*  Initializing char variable to copy char pointer to char variable type   */
      char stg_val_o[10];   /*  Initializing char variable to store char to char recieved from char pointer */
      strcpy(add_val_o, data_set[i].values);    /*  Copying to char variable from char pointer variable */
      strcpy(stg_val_o, &add_val_o[1]); /*  Storing the char variable in another char variable to manipulate string literals    */
      double values_ontario = atof(stg_val_o);  /*  Converting the stored char variable to a float type varaible data type for mathematical computational maniupulation */
      if (sum_ontario == 0)
      {
        ontario_iterator_counter--; /*  Fail-Safe Mechanism for not counting the iterations in the iterating counter factor if the condition is met [CONDITION IS ONLY SATISFIED IF THE atof FUNCTION RETURN 0, IFF THE Var(char) = NULL]   */
      }
      //printf("%.2lf\n",values_ontario);   /*  Fail-Safe in Testing phase to verify succinctity of the values being read from atof function    */
      sum_ontario += values_ontario;    /*  Calculation of Summa function of all data points being read that are not NULL   */
    } double avg_ontario = (sum_ontario) / (ontario_iterator_counter); printf("Ontario Average: %.3lf\n", avg_ontario);

    /*  Alberta Average Calculator  */

    for (int i = 128; i < 170; i++, alberta_iterator_counter++)
    {
      char add_val_a[10];   /*  Initializing char variable to copy char pointer to char variable type   */
      char stg_val_a[10];   /*  Initializing char variable to store char to char recieved from char pointer */
      strcpy(add_val_a, data_set[i].values);    /*  Copying to char variable from char pointer variable */
      strcpy(stg_val_a, &add_val_a[1]); /*  Storing the char variable in another char variable to manipulate string literals    */
      double values_alberta = atof(stg_val_a);  /*  Converting the stored char variable to a float type varaible data type for mathematical computational maniupulation */
      if (values_alberta == 0)
      {
        alberta_iterator_counter--; /*  Fail-Safe Mechanism for not counting the iterations in the iterating counter factor if the condition is met [CONDITION IS ONLY SATISFIED IF THE atof FUNCTION RETURN 0, IFF THE Var(char) = NULL]   */
      }
      //printf("%.2lf\n",values_alberta);   /*  Fail-Safe in Testing phase to verify succinctity of the values being read from atof function    */
      sum_alberta += values_alberta;    /*  Calculation of Summa function of all data points being read that are not NULL   */
    } double avg_alberta = (sum_alberta) / (alberta_iterator_counter); printf("Alberta Average: %.3lf\n", avg_alberta);

    /*  British Columbia Average Calculator */

    for (int i = 170; i < 212; i++, british_columbia_iterator_counter++)
    {
      char add_val_b[10];   /*  Initializing char variable to copy char pointer to char variable type   */
      char stg_val_b[10];   /*  Initializing char variable to store char to char recieved from char pointer */
      strcpy(add_val_b, data_set[i].values);    /*  Copying to char variable from char pointer variable */
      strcpy(stg_val_b, &add_val_b[1]); /*  Storing the char variable in another char variable to manipulate string literals    */
      double values_british_columbia = atof(stg_val_b);  /*  Converting the stored char variable to a float type varaible data type for mathematical computational maniupulation */
      if (values_british_columbia == 0)
      {
        british_columbia_iterator_counter--; /*  Fail-Safe Mechanism for not counting the iterations in the iterating counter factor if the condition is met [CONDITION IS ONLY SATISFIED IF THE atof FUNCTION RETURN 0, IFF THE Var(char) = NULL]   */
      }
      //printf("%.2lf\n",values_british_columbia);   /*  Fail-Safe in Testing phase to verify succinctity of the values being read from atof function    */
      sum_british_columbia += values_british_columbia;    /*  Calculation of Summa function of all data points being read that are not NULL   */
    } double avg_british_columbia = (sum_british_columbia) / (british_columbia_iterator_counter); printf("British Columbia Average: %.3lf\n", avg_british_columbia);

	spacer();

    /*  Year-Wise Average Calculator*/

	/*		Year Wise Averages		*/avg_year();
	spacer();

	/*  Initializing Sum & Iterating Counter Variables for Year Averages Calculation	*/

    //  double sum_year - Variable to store the sum of the Value Data Points subsequently in every iteration
	//	double avg_year - Variable to store the average of the Value Data Points subsequently after all iterations
    //  iterator_counter_year - Variable to calculate the number of iterations performed in the for loop

	/*	2015 Variables	*/

    double sum_2015 = 0;
	double avg_2015 = 0;
	double sum_2015_f = 0;
	double avg_2015_f = 0;
	double sum_2015_q = 0;
	double avg_2015_q = 0;
	double sum_2015_o = 0;
	double avg_2015_o = 0;
	double sum_2015_a = 0;
	double avg_2015_a = 0;
	double sum_2015_b = 0;
	double avg_2015_b = 0;
	int iterator_counter_2015 = 0;
	int iterator_counter_2015_f = 0;
	int iterator_counter_2015_q = 0;
	int iterator_counter_2015_o = 0;
	int iterator_counter_2015_a = 0;
	int iterator_counter_2015_b = 0;

	/*	2016 Variables	*/

	double sum_2016 = 0;
	double avg_2016 = 0;
	double sum_2016_f = 0;
	double avg_2016_f = 0;
	double sum_2016_q = 0;
	double avg_2016_q = 0;
	double sum_2016_o = 0;
	double avg_2016_o = 0;
	double sum_2016_a = 0;
	double avg_2016_a = 0;
	double sum_2016_b = 0;
	double avg_2016_b = 0;
	int iterator_counter_2016 = 0;
	int iterator_counter_2016_f = 0;
	int iterator_counter_2016_q = 0;
	int iterator_counter_2016_o = 0;
	int iterator_counter_2016_a = 0;
	int iterator_counter_2016_b = 0;

	/*	2017 Variables	*/

	double sum_2017 = 0;
	double avg_2017 = 0;
	double sum_2017_f = 0;
	double avg_2017_f = 0;
	double sum_2017_q = 0;
	double avg_2017_q = 0;
	double sum_2017_o = 0;
	double avg_2017_o = 0;
	double sum_2017_a = 0;
	double avg_2017_a = 0;
	double sum_2017_b = 0;
	double avg_2017_b = 0;
	int iterator_counter_2017 = 0;
	int iterator_counter_2017_f = 0;
	int iterator_counter_2017_q = 0;
	int iterator_counter_2017_o = 0;
	int iterator_counter_2017_a = 0;
	int iterator_counter_2017_b = 0;

	/*	2018 Variables	*/

	double sum_2018 = 0;
	double avg_2018 = 0;
	double sum_2018_f = 0;
	double avg_2018_f = 0;
	double sum_2018_q = 0;
	double avg_2018_q = 0;
	double sum_2018_o = 0;
	double avg_2018_o = 0;
	double sum_2018_a = 0;
	double avg_2018_a = 0;
	double sum_2018_b = 0;
	double avg_2018_b = 0;
	int iterator_counter_2018 = 0;
	int iterator_counter_2018_f = 0;
	int iterator_counter_2018_q = 0;
	int iterator_counter_2018_o = 0;
	int iterator_counter_2018_a = 0;
	int iterator_counter_2018_b = 0;

	/*	2019 Variables	*/

	double sum_2019 = 0;
	double avg_2019 = 0;
	double sum_2019_f = 0;
	double avg_2019_f = 0;
	double sum_2019_q = 0;
	double avg_2019_q = 0;
	double sum_2019_o = 0;
	double avg_2019_o = 0;
	double sum_2019_a = 0;
	double avg_2019_a = 0;
	double sum_2019_b = 0;
	double avg_2019_b = 0;
	int iterator_counter_2019 = 0;
	int iterator_counter_2019_f = 0;
	int iterator_counter_2019_q = 0;
	int iterator_counter_2019_o = 0;
	int iterator_counter_2019_a = 0;
	int iterator_counter_2019_b = 0;

	/*	2020 Variables	*/

	double sum_2020 = 0;
	double avg_2020 = 0;
	double sum_2020_f = 0;
	double avg_2020_f = 0;
	double sum_2020_q = 0;
	double avg_2020_q = 0;
	double sum_2020_o = 0;
	double avg_2020_o = 0;
	double sum_2020_a = 0;
	double avg_2020_a = 0;
	double sum_2020_b = 0;
	double avg_2020_b = 0;
	int iterator_counter_2020 = 0;
	int iterator_counter_2020_f = 0;
	int iterator_counter_2020_q = 0;
	int iterator_counter_2020_o = 0;
	int iterator_counter_2020_a = 0;
	int iterator_counter_2020_b = 0;

	/*	2021 Variables	*/

	double sum_2021 = 0;
	double avg_2021 = 0;
	double sum_2021_f = 0;
	double avg_2021_f = 0;
	double sum_2021_q = 0;
	double avg_2021_q = 0;
	double sum_2021_o = 0;
	double avg_2021_o = 0;
	double sum_2021_a = 0;
	double avg_2021_a = 0;
	double sum_2021_b = 0;
	double avg_2021_b = 0;
	int iterator_counter_2021 = 0;
	int iterator_counter_2021_f = 0;
	int iterator_counter_2021_q = 0;
	int iterator_counter_2021_o = 0;
	int iterator_counter_2021_a = 0;
	int iterator_counter_2021_b = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
		for (int j = 2; j < 44; j++)	/*	Federal Year-Wise Average Calculator	*/
		{
			char add_val_y[10];
			char stg_val_y[10];
			strcpy(add_val_y, data_set[j].year);
			strcpy(stg_val_y, &add_val_y[1]);
			double year = atof(stg_val_y);
			
			if (year == 2015)
			{
				iterator_counter_2015_f++;
				char add_val_2015[10];
				char stg_val_2015[10];
				strcpy(add_val_2015, data_set[j].values);
				strcpy(stg_val_2015, &add_val_2015[1]);
				double values_2015 = atof(stg_val_2015);
				if (values_2015 == 0)
				{
					iterator_counter_2015_f--;
				}
				
				sum_2015_f += values_2015;
			} avg_2015_f = sum_2015_f / iterator_counter_2015_f;
			if (year == 2016)
			{
				iterator_counter_2016_f++;
				char add_val_2016[10];
				char stg_val_2016[10];
				strcpy(add_val_2016, data_set[j].values);
				strcpy(stg_val_2016, &add_val_2016[1]);
				double values_2016 = atof(stg_val_2016);
				if (values_2016 == 0)
				{
					iterator_counter_2016_f--;
				}
				
				sum_2016_f += values_2016;
			} avg_2016_f = sum_2016_f / iterator_counter_2016_f;
			if (year == 2017)
			{
				iterator_counter_2017_f++;
				char add_val_2017[10];
				char stg_val_2017[10];
				strcpy(add_val_2017, data_set[j].values);
				strcpy(stg_val_2017, &add_val_2017[1]);
				double values_2017 = atof(stg_val_2017);
				if (values_2017 == 0)
				{
					iterator_counter_2017_f--;
				}
				
				sum_2017_f += values_2017;
			} avg_2017_f = sum_2017_f / iterator_counter_2017_f;
			if (year == 2018)
			{
				iterator_counter_2018_f++;
				char add_val_2018[10];
				char stg_val_2018[10];
				strcpy(add_val_2018, data_set[j].values);
				strcpy(stg_val_2018, &add_val_2018[1]);
				double values_2018 = atof(stg_val_2018);
				if (values_2018 == 0)
				{
					iterator_counter_2018_f--;
				}
				
				sum_2018_f += values_2018;
			} avg_2018_f = sum_2018_f / iterator_counter_2018_f;
			if (year == 2019)
			{
				iterator_counter_2019_f++;
				char add_val_2019[10];
				char stg_val_2019[10];
				strcpy(add_val_2019, data_set[j].values);
				strcpy(stg_val_2019, &add_val_2019[1]);
				double values_2019 = atof(stg_val_2019);
				if (values_2019 == 0)
				{
					iterator_counter_2019_f--;
				}
				
				sum_2019_f += values_2019;
			} avg_2019_f = sum_2019_f / iterator_counter_2019_f;
			if (year == 2020)
			{
				iterator_counter_2020_f++;
				char add_val_2020[10];
				char stg_val_2020[10];
				strcpy(add_val_2020, data_set[j].values);
				strcpy(stg_val_2020, &add_val_2020[1]);
				double values_2020 = atof(stg_val_2020);
				if (values_2020 == 0)
				{
					iterator_counter_2020_f--;
				}
				
				sum_2020_f += values_2020;
			} avg_2020_f = sum_2020_f / iterator_counter_2020_f;
			if (year == 2021)
			{
				iterator_counter_2021_f++;
				char add_val_2021[10];
				char stg_val_2021[10];
				strcpy(add_val_2021, data_set[j].values);
				strcpy(stg_val_2021, &add_val_2021[1]);
				double values_2021 = atof(stg_val_2021);
				if (values_2021 == 0)
				{
					iterator_counter_2021_f--;
				}
				
				sum_2021_f += values_2021;
			} avg_2021_f = sum_2021_f / iterator_counter_2021_f;
		}
		for (int j = 44; j < 86; j++)	/*	Quebec Year-Wise Average Calculator	*/
		{
			char add_val_y[10];
			char stg_val_y[10];
			strcpy(add_val_y, data_set[j].year);
			strcpy(stg_val_y, &add_val_y[1]);
			double year = atof(stg_val_y);
			
			if (year == 2015)
			{
				iterator_counter_2015_q++;
				char add_val_2015[10];
				char stg_val_2015[10];
				strcpy(add_val_2015, data_set[j].values);
				strcpy(stg_val_2015, &add_val_2015[1]);
				double values_2015 = atof(stg_val_2015);
				if (values_2015 == 0)
				{
					iterator_counter_2015_q--;
				}
				
				sum_2015_q += values_2015;
			} avg_2015_q = sum_2015_q / iterator_counter_2015_q;
			if (year == 2016)
			{
				iterator_counter_2016_q++;
				char add_val_2016[10];
				char stg_val_2016[10];
				strcpy(add_val_2016, data_set[j].values);
				strcpy(stg_val_2016, &add_val_2016[1]);
				double values_2016 = atof(stg_val_2016);
				if (values_2016 == 0)
				{
					iterator_counter_2016_q--;
				}
				
				sum_2016_q += values_2016;
			} avg_2016_q = sum_2016_q / iterator_counter_2016_q;
			if (year == 2017)
			{
				iterator_counter_2017_q++;
				char add_val_2017[10];
				char stg_val_2017[10];
				strcpy(add_val_2017, data_set[j].values);
				strcpy(stg_val_2017, &add_val_2017[1]);
				double values_2017 = atof(stg_val_2017);
				if (values_2017 == 0)
				{
					iterator_counter_2017_q--;
				}
				
				sum_2017_q += values_2017;
			} avg_2017_q = sum_2017_q / iterator_counter_2017_q;
			if (year == 2018)
			{
				iterator_counter_2018_q++;
				char add_val_2018[10];
				char stg_val_2018[10];
				strcpy(add_val_2018, data_set[j].values);
				strcpy(stg_val_2018, &add_val_2018[1]);
				double values_2018 = atof(stg_val_2018);
				if (values_2018 == 0)
				{
					iterator_counter_2018_q--;
				}
				
				sum_2018_q += values_2018;
			} avg_2018_q = sum_2018_q / iterator_counter_2018_q;
			if (year == 2019)
			{
				iterator_counter_2019_q++;
				char add_val_2019[10];
				char stg_val_2019[10];
				strcpy(add_val_2019, data_set[j].values);
				strcpy(stg_val_2019, &add_val_2019[1]);
				double values_2019 = atof(stg_val_2019);
				if (values_2019 == 0)
				{
					iterator_counter_2019_q--;
				}
				
				sum_2019 += values_2019;
			} avg_2019_q = sum_2019_q / iterator_counter_2019_q;
			if (year == 2020)
			{
				iterator_counter_2020_q++;
				char add_val_2020[10];
				char stg_val_2020[10];
				strcpy(add_val_2020, data_set[j].values);
				strcpy(stg_val_2020, &add_val_2020[1]);
				double values_2020 = atof(stg_val_2020);
				if (values_2020 == 0)
				{
					iterator_counter_2020_q--;
				}
				
				sum_2020_q += values_2020;
			} avg_2020_q = sum_2020_q / iterator_counter_2020_q;
			if (year == 2021)
			{
				iterator_counter_2021_q++;
				char add_val_2021[10];
				char stg_val_2021[10];
				strcpy(add_val_2021, data_set[j].values);
				strcpy(stg_val_2021, &add_val_2021[1]);
				double values_2021 = atof(stg_val_2021);
				if (values_2021 == 0)
				{
					iterator_counter_2021_q--;
				}
				
				sum_2021_q += values_2021;
			} avg_2021_q = sum_2021_q / iterator_counter_2021_q;
		}
		for (int j = 86; j < 128; j++)	/*	Ontario Year-Wise Average Calculator	*/
		{
			char add_val_y[10];
			char stg_val_y[10];
			strcpy(add_val_y, data_set[j].year);
			strcpy(stg_val_y, &add_val_y[1]);
			double year = atof(stg_val_y);
			
			if (year == 2015)
			{
				iterator_counter_2015_o++;
				char add_val_2015[10];
				char stg_val_2015[10];
				strcpy(add_val_2015, data_set[j].values);
				strcpy(stg_val_2015, &add_val_2015[1]);
				double values_2015 = atof(stg_val_2015);
				if (values_2015 == 0)
				{
					iterator_counter_2015_o--;
				}
				
				sum_2015_o += values_2015;
			} avg_2015_o = sum_2015_o / iterator_counter_2015_o;
			if (year == 2016)
			{
				iterator_counter_2016_o++;
				char add_val_2016[10];
				char stg_val_2016[10];
				strcpy(add_val_2016, data_set[j].values);
				strcpy(stg_val_2016, &add_val_2016[1]);
				double values_2016 = atof(stg_val_2016);
				if (values_2016 == 0)
				{
					iterator_counter_2016_o--;
				}
				
				sum_2016_o += values_2016;
			} avg_2016_o = sum_2016_o / iterator_counter_2016_o;
			if (year == 2017)
			{
				iterator_counter_2017_o++;
				char add_val_2017[10];
				char stg_val_2017[10];
				strcpy(add_val_2017, data_set[j].values);
				strcpy(stg_val_2017, &add_val_2017[1]);
				double values_2017 = atof(stg_val_2017);
				if (values_2017 == 0)
				{
					iterator_counter_2017_o--;
				}
				
				sum_2017_o += values_2017;
			} avg_2017_o = sum_2017_o / iterator_counter_2017_o;
			if (year == 2018)
			{
				iterator_counter_2018_o++;
				char add_val_2018[10];
				char stg_val_2018[10];
				strcpy(add_val_2018, data_set[j].values);
				strcpy(stg_val_2018, &add_val_2018[1]);
				double values_2018 = atof(stg_val_2018);
				if (values_2018 == 0)
				{
					iterator_counter_2018_o--;
				}
				
				sum_2018_o += values_2018;
			} avg_2018_o = sum_2018_o / iterator_counter_2018_o;
			if (year == 2019)
			{
				iterator_counter_2019_o++;
				char add_val_2019[10];
				char stg_val_2019[10];
				strcpy(add_val_2019, data_set[j].values);
				strcpy(stg_val_2019, &add_val_2019[1]);
				double values_2019 = atof(stg_val_2019);
				if (values_2019 == 0)
				{
					iterator_counter_2019_o--;
				}
				
				sum_2019_o += values_2019;
			} avg_2019_o = sum_2019_o / iterator_counter_2019_o;
			if (year == 2020)
			{
				iterator_counter_2020_o++;
				char add_val_2020[10];
				char stg_val_2020[10];
				strcpy(add_val_2020, data_set[j].values);
				strcpy(stg_val_2020, &add_val_2020[1]);
				double values_2020 = atof(stg_val_2020);
				if (values_2020 == 0)
				{
					iterator_counter_2020_o--;
				}
				
				sum_2020_o += values_2020;
			} avg_2020_o = sum_2020_o / iterator_counter_2020_o;
			if (year == 2021)
			{
				iterator_counter_2021_o++;
				char add_val_2021[10];
				char stg_val_2021[10];
				strcpy(add_val_2021, data_set[j].values);
				strcpy(stg_val_2021, &add_val_2021[1]);
				double values_2021 = atof(stg_val_2021);
				if (values_2021 == 0)
				{
					iterator_counter_2021_o--;
				}
				
				sum_2021_o += values_2021;
			} avg_2021_o = sum_2021_o / iterator_counter_2021_o;
		}
		for (int j = 128; j < 170; j++)	/*	Alberta Year-Wise Average Calculator	*/
		{
			char add_val_y[10];
			char stg_val_y[10];
			strcpy(add_val_y, data_set[j].year);
			strcpy(stg_val_y, &add_val_y[1]);
			double year = atof(stg_val_y);
			
			if (year == 2015)
			{
				iterator_counter_2015_a++;
				char add_val_2015[10];
				char stg_val_2015[10];
				strcpy(add_val_2015, data_set[j].values);
				strcpy(stg_val_2015, &add_val_2015[1]);
				double values_2015 = atof(stg_val_2015);
				if (values_2015 == 0)
				{
					iterator_counter_2015_a--;
				}
				
				sum_2015_a += values_2015;
			} avg_2015_a = sum_2015_a / iterator_counter_2015_a;
			if (year == 2016)
			{
				iterator_counter_2016_a++;
				char add_val_2016[10];
				char stg_val_2016[10];
				strcpy(add_val_2016, data_set[j].values);
				strcpy(stg_val_2016, &add_val_2016[1]);
				double values_2016 = atof(stg_val_2016);
				if (values_2016 == 0)
				{
					iterator_counter_2016_a--;
				}
				
				sum_2016_a += values_2016;
			} avg_2016_a = sum_2016_a / iterator_counter_2016_a;
			if (year == 2017)
			{
				iterator_counter_2017_a++;
				char add_val_2017[10];
				char stg_val_2017[10];
				strcpy(add_val_2017, data_set[j].values);
				strcpy(stg_val_2017, &add_val_2017[1]);
				double values_2017 = atof(stg_val_2017);
				if (values_2017 == 0)
				{
					iterator_counter_2017_a--;
				}
				
				sum_2017_a += values_2017;
			} avg_2017_a = sum_2017_a / iterator_counter_2017_a;
			if (year == 2018)
			{
				iterator_counter_2018_a++;
				char add_val_2018[10];
				char stg_val_2018[10];
				strcpy(add_val_2018, data_set[j].values);
				strcpy(stg_val_2018, &add_val_2018[1]);
				double values_2018 = atof(stg_val_2018);
				if (values_2018 == 0)
				{
					iterator_counter_2018_a--;
				}
				
				sum_2018_a += values_2018;
			} avg_2018_a = sum_2018_a / iterator_counter_2018_a;
			if (year == 2019)
			{
				iterator_counter_2019_a++;
				char add_val_2019[10];
				char stg_val_2019[10];
				strcpy(add_val_2019, data_set[j].values);
				strcpy(stg_val_2019, &add_val_2019[1]);
				double values_2019 = atof(stg_val_2019);
				if (values_2019 == 0)
				{
					iterator_counter_2019_a--;
				}
				
				sum_2019_a += values_2019;
			} avg_2019_a = sum_2019_a / iterator_counter_2019_a;
			if (year == 2020)
			{
				iterator_counter_2020_a++;
				char add_val_2020[10];
				char stg_val_2020[10];
				strcpy(add_val_2020, data_set[j].values);
				strcpy(stg_val_2020, &add_val_2020[1]);
				double values_2020 = atof(stg_val_2020);
				if (values_2020 == 0)
				{
					iterator_counter_2020_a--;
				}
				
				sum_2020_a += values_2020;
			} avg_2020_a = sum_2020_a / iterator_counter_2020_a;
			if (year == 2021)
			{
				iterator_counter_2021_a++;
				char add_val_2021[10];
				char stg_val_2021[10];
				strcpy(add_val_2021, data_set[j].values);
				strcpy(stg_val_2021, &add_val_2021[1]);
				double values_2021 = atof(stg_val_2021);
				if (values_2021 == 0)
				{
					iterator_counter_2021_a--;
				}
				
				sum_2021_a += values_2021;
			} avg_2021_a = sum_2021_a / iterator_counter_2021_a;
		}
		for (int j = 170; j < 212; j++)	/*	British Columbia Year-Wise Average Calculator	*/
		{
			char add_val_y[10];
			char stg_val_y[10];
			strcpy(add_val_y, data_set[j].year);
			strcpy(stg_val_y, &add_val_y[1]);
			double year = atof(stg_val_y);
			
			if (year == 2015)
			{
				iterator_counter_2015_b++;
				char add_val_2015[10];
				char stg_val_2015[10];
				strcpy(add_val_2015, data_set[j].values);
				strcpy(stg_val_2015, &add_val_2015[1]);
				double values_2015 = atof(stg_val_2015);
				if (values_2015 == 0)
				{
					iterator_counter_2015_b--;
				}
				
				sum_2015_b += values_2015;
			} avg_2015_b = sum_2015_b / iterator_counter_2015_b;
			if (year == 2016)
			{
				iterator_counter_2016_b++;
				char add_val_2016[10];
				char stg_val_2016[10];
				strcpy(add_val_2016, data_set[j].values);
				strcpy(stg_val_2016, &add_val_2016[1]);
				double values_2016 = atof(stg_val_2016);
				if (values_2016 == 0)
				{
					iterator_counter_2016_b--;
				}
				
				sum_2016_b += values_2016;
			} avg_2016_b = sum_2016_b / iterator_counter_2016_b;
			if (year == 2017)
			{
				iterator_counter_2017_b++;
				char add_val_2017[10];
				char stg_val_2017[10];
				strcpy(add_val_2017, data_set[j].values);
				strcpy(stg_val_2017, &add_val_2017[1]);
				double values_2017 = atof(stg_val_2017);
				if (values_2017 == 0)
				{
					iterator_counter_2017_b--;
				}
				
				sum_2017_b += values_2017;
			} avg_2017_b = sum_2017_b / iterator_counter_2017_b;
			if (year == 2018)
			{
				iterator_counter_2018_b++;
				char add_val_2018[10];
				char stg_val_2018[10];
				strcpy(add_val_2018, data_set[j].values);
				strcpy(stg_val_2018, &add_val_2018[1]);
				double values_2018 = atof(stg_val_2018);
				if (values_2018 == 0)
				{
					iterator_counter_2018_b--;
				}
				
				sum_2018_b += values_2018;
			} avg_2018_b = sum_2018_b / iterator_counter_2018_b;
			if (year == 2019)
			{
				iterator_counter_2019_b++;
				char add_val_2019[10];
				char stg_val_2019[10];
				strcpy(add_val_2019, data_set[j].values);
				strcpy(stg_val_2019, &add_val_2019[1]);
				double values_2019 = atof(stg_val_2019);
				if (values_2019 == 0)
				{
					iterator_counter_2019_b--;
				}
				
				sum_2019_b += values_2019;
			} avg_2019_b = sum_2019_b / iterator_counter_2019_b;
			if (year == 2020)
			{
				iterator_counter_2020_b++;
				char add_val_2020[10];
				char stg_val_2020[10];
				strcpy(add_val_2020, data_set[j].values);
				strcpy(stg_val_2020, &add_val_2020[1]);
				double values_2020 = atof(stg_val_2020);
				if (values_2020 == 0)
				{
					iterator_counter_2020_b--;
				}
				
				sum_2020_b += values_2020;
			} avg_2020_b = sum_2020_b / iterator_counter_2020_b;
			if (year == 2021)
			{
				iterator_counter_2021_b++;
				char add_val_2021[10];
				char stg_val_2021[10];
				strcpy(add_val_2021, data_set[j].values);
				strcpy(stg_val_2021, &add_val_2021[1]);
				double values_2021 = atof(stg_val_2021);
				if (values_2021 == 0)
				{
					iterator_counter_2021_b--;
				}
				
				sum_2021_b += values_2021;
			} avg_2021_b = sum_2021_b / iterator_counter_2021_b;
		}
		
		
    } year_avg(avg_2015_f, avg_2016_f, avg_2017_f, avg_2018_f, avg_2019_f, avg_2020_f, avg_2021_f, avg_2015_q, avg_2016_q, avg_2017_q, avg_2018_q, avg_2019_q, avg_2020_q, avg_2021_q, avg_2015_o, avg_2016_o, avg_2017_o, avg_2018_o, avg_2019_o, avg_2020_o, avg_2021_o, avg_2015_a, avg_2016_a, avg_2017_a, avg_2018_a, avg_2019_a, avg_2020_a, avg_2021_a, avg_2015_b, avg_2016_b, avg_2017_b, avg_2018_b, avg_2019_b, avg_2020_b, avg_2021_b);

	spacer();

    /*  Age-Group-Wise Average Calculator*/

	/*		Age-Group Wise Averages		*/avg_age();
	spacer();

	/*  Initializing Sum & Iterating Counter Variables for Age-Group Averages Calculation	*/

    //  double sum_year - Variable to store the sum of the Value Data Points subsequently in every iteration
	//	double avg_year - Variable to store the average of the Value Data Points subsequently after all iterations
    //  iterator_counter_year - Variable to calculate the number of iterations performed in the for loop

	/*	35-49 Age Group Variables	*/

    double sum_35 = 0;
	double avg_35 = 0;
	double sum_35_f = 0;
	double avg_35_f = 0;
	double sum_35_q = 0;
	double avg_35_q = 0;
	double sum_35_o = 0;
	double avg_35_o = 0;
	double sum_35_a = 0;
	double avg_35_a = 0;
	double sum_35_b = 0;
	double avg_35_b = 0;
	int iterator_counter_35 = 0;
	int iterator_counter_35_f = 0;
	int iterator_counter_35_q = 0;
	int iterator_counter_35_o = 0;
	int iterator_counter_35_a = 0;
	int iterator_counter_35_b = 0;

	/*	50-65 Age Group Variables	*/

	double sum_50 = 0;
	double avg_50 = 0;
	double sum_50_f = 0;
	double avg_50_f = 0;
	double sum_50_q = 0;
	double avg_50_q = 0;
	double sum_50_o = 0;
	double avg_50_o = 0;
	double sum_50_a = 0;
	double avg_50_a = 0;
	double sum_50_b = 0;
	double avg_50_b = 0;
	int iterator_counter_50 = 0;
	int iterator_counter_50_f = 0;
	int iterator_counter_50_q = 0;
	int iterator_counter_50_o = 0;
	int iterator_counter_50_a = 0;
	int iterator_counter_50_b = 0;

	/*	65+ Age Group Variables	*/

	double sum_65 = 0;
	double avg_65 = 0;
	double sum_65_f = 0;
	double avg_65_f = 0;
	double sum_65_q = 0;
	double avg_65_q = 0;
	double sum_65_o = 0;
	double avg_65_o = 0;
	double sum_65_a = 0;
	double avg_65_a = 0;
	double sum_65_b = 0;
	double avg_65_b = 0;
	int iterator_counter_65 = 0;
	int iterator_counter_65_f = 0;
	int iterator_counter_65_q = 0;
	int iterator_counter_65_o = 0;
	int iterator_counter_65_a = 0;
	int iterator_counter_65_b = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
		for (int j = 2; j < 44; j++)	/*	Federal Age-Group-Wise Average Calculator	*/
		{
			char add_val_y[10];
			char stg_val_y[10];
			strcpy(add_val_y, data_set[j].age_group);
			strcpy(stg_val_y, &add_val_y[1]);
			double age_group = atof(stg_val_y);
			
			if (age_group == 35)
			{
				iterator_counter_35_f++;
				char add_val_2015[10];
				char stg_val_2015[10];
				strcpy(add_val_2015, data_set[j].values);
				strcpy(stg_val_2015, &add_val_2015[1]);
				double values_2015 = atof(stg_val_2015);
				if (values_2015 == 0)
				{
					iterator_counter_35_f--;
				}
				
				sum_35_f += values_2015;
			} avg_35_f = sum_35_f / iterator_counter_35_f;
			if (age_group == 50)
			{
				iterator_counter_50_f++;
				char add_val_2016[10];
				char stg_val_2016[10];
				strcpy(add_val_2016, data_set[j].values);
				strcpy(stg_val_2016, &add_val_2016[1]);
				double values_2016 = atof(stg_val_2016);
				if (values_2016 == 0)
				{
					iterator_counter_50_f--;
				}
				
				sum_50_f += values_2016;
			} avg_50_f = sum_50_f / iterator_counter_50_f;
			if (age_group == 65)
			{
				iterator_counter_65_f++;
				char add_val_2017[10];
				char stg_val_2017[10];
				strcpy(add_val_2017, data_set[j].values);
				strcpy(stg_val_2017, &add_val_2017[1]);
				double values_2017 = atof(stg_val_2017);
				if (values_2017 == 0)
				{
					iterator_counter_65_f--;
				}
				
				sum_65_f += values_2017;
			} avg_65_f = sum_65_f / iterator_counter_65_f;
		}
		for (int j = 44; j < 86; j++)	/*	Quebec Age-Group-Wise Average Calculator	*/
		{
			char add_val_y[10];
			char stg_val_y[10];
			strcpy(add_val_y, data_set[j].age_group);
			strcpy(stg_val_y, &add_val_y[1]);
			double age_group = atof(stg_val_y);
			
			if (age_group == 35)
			{
				iterator_counter_35_q++;
				char add_val_2015[10];
				char stg_val_2015[10];
				strcpy(add_val_2015, data_set[j].values);
				strcpy(stg_val_2015, &add_val_2015[1]);
				double values_2015 = atof(stg_val_2015);
				if (values_2015 == 0)
				{
					iterator_counter_35_q--;
				}
				
				sum_35_q += values_2015;
			} avg_35_q = sum_35_q / iterator_counter_35_q;
			if (age_group == 50)
			{
				iterator_counter_50_q++;
				char add_val_2016[10];
				char stg_val_2016[10];
				strcpy(add_val_2016, data_set[j].values);
				strcpy(stg_val_2016, &add_val_2016[1]);
				double values_2016 = atof(stg_val_2016);
				if (values_2016 == 0)
				{
					iterator_counter_50_q--;
				}
				
				sum_50_q += values_2016;
			} avg_50_q = sum_50_q / iterator_counter_50_q;
			if (age_group == 65)
			{
				iterator_counter_65_q++;
				char add_val_2017[10];
				char stg_val_2017[10];
				strcpy(add_val_2017, data_set[j].values);
				strcpy(stg_val_2017, &add_val_2017[1]);
				double values_2017 = atof(stg_val_2017);
				if (values_2017 == 0)
				{
					iterator_counter_65_q--;
				}
				
				sum_65_q += values_2017;
			} avg_65_q = sum_65_q / iterator_counter_65_q;
		}
		for (int j = 86; j < 128; j++)	/*	Ontario Age-Group-Wise Average Calculator	*/
		{
			char add_val_y[10];
			char stg_val_y[10];
			strcpy(add_val_y, data_set[j].age_group);
			strcpy(stg_val_y, &add_val_y[1]);
			double age_group = atof(stg_val_y);
			
			if (age_group == 35)
			{
				iterator_counter_35_o++;
				char add_val_2015[10];
				char stg_val_2015[10];
				strcpy(add_val_2015, data_set[j].values);
				strcpy(stg_val_2015, &add_val_2015[1]);
				double values_2015 = atof(stg_val_2015);
				if (values_2015 == 0)
				{
					iterator_counter_35_o--;
				}
				
				sum_35_o += values_2015;
			} avg_35_o = sum_35_o / iterator_counter_35_o;
			if (age_group == 50)
			{
				iterator_counter_50_o++;
				char add_val_2016[10];
				char stg_val_2016[10];
				strcpy(add_val_2016, data_set[j].values);
				strcpy(stg_val_2016, &add_val_2016[1]);
				double values_2016 = atof(stg_val_2016);
				if (values_2016 == 0)
				{
					iterator_counter_50_o--;
				}
				
				sum_50_o += values_2016;
			} avg_50_o = sum_50_o / iterator_counter_50_o;
			if (age_group == 65)
			{
				iterator_counter_65_o++;
				char add_val_2017[10];
				char stg_val_2017[10];
				strcpy(add_val_2017, data_set[j].values);
				strcpy(stg_val_2017, &add_val_2017[1]);
				double values_2017 = atof(stg_val_2017);
				if (values_2017 == 0)
				{
					iterator_counter_65_o--;
				}
				
				sum_65_o += values_2017;
			} avg_65_o = sum_65_o / iterator_counter_65_o;
		}
		for (int j = 128; j < 170; j++)	/*	Alberta Age-Group-Wise Average Calculator	*/
		{
			char add_val_y[10];
			char stg_val_y[10];
			strcpy(add_val_y, data_set[j].age_group);
			strcpy(stg_val_y, &add_val_y[1]);
			double age_group = atof(stg_val_y);
			
			if (age_group == 35)
			{
				iterator_counter_35_a++;
				char add_val_2015[10];
				char stg_val_2015[10];
				strcpy(add_val_2015, data_set[j].values);
				strcpy(stg_val_2015, &add_val_2015[1]);
				double values_2015 = atof(stg_val_2015);
				if (values_2015 == 0)
				{
					iterator_counter_35_a--;
				}
				
				sum_35_a += values_2015;
			} avg_35_a = sum_35_a / iterator_counter_35_a;
			if (age_group == 50)
			{
				iterator_counter_50_a++;
				char add_val_2016[10];
				char stg_val_2016[10];
				strcpy(add_val_2016, data_set[j].values);
				strcpy(stg_val_2016, &add_val_2016[1]);
				double values_2016 = atof(stg_val_2016);
				if (values_2016 == 0)
				{
					iterator_counter_50_a--;
				}
				
				sum_50_a += values_2016;
			} avg_50_a = sum_50_a / iterator_counter_50_a;
			if (age_group == 65)
			{
				iterator_counter_65_a++;
				char add_val_2017[10];
				char stg_val_2017[10];
				strcpy(add_val_2017, data_set[j].values);
				strcpy(stg_val_2017, &add_val_2017[1]);
				double values_2017 = atof(stg_val_2017);
				if (values_2017 == 0)
				{
					iterator_counter_65_a--;
				}
				
				sum_65_a += values_2017;
			} avg_65_a = sum_65_a / iterator_counter_65_a;
		}
		for (int j = 170; j < 212; j++)	/*	British Columbia Age-Group-Wise Average Calculator	*/
		{
			char add_val_y[10];
			char stg_val_y[10];
			strcpy(add_val_y, data_set[j].age_group);
			strcpy(stg_val_y, &add_val_y[1]);
			double age_group = atof(stg_val_y);
			
			if (age_group == 35)
			{
				iterator_counter_35_b++;
				char add_val_2015[10];
				char stg_val_2015[10];
				strcpy(add_val_2015, data_set[j].values);
				strcpy(stg_val_2015, &add_val_2015[1]);
				double values_2015 = atof(stg_val_2015);
				if (values_2015 == 0)
				{
					iterator_counter_35_b--;
				}
				
				sum_35_b += values_2015;
			} avg_35_b = sum_35_b / iterator_counter_35_b;
			if (age_group == 50)
			{
				iterator_counter_50_b++;
				char add_val_2016[10];
				char stg_val_2016[10];
				strcpy(add_val_2016, data_set[j].values);
				strcpy(stg_val_2016, &add_val_2016[1]);
				double values_2016 = atof(stg_val_2016);
				if (values_2016 == 0)
				{
					iterator_counter_50_b--;
				}
				
				sum_50_b += values_2016;
			} avg_50_b = sum_50_b / iterator_counter_50_b;
			if (age_group == 65)
			{
				iterator_counter_65_b++;
				char add_val_2017[10];
				char stg_val_2017[10];
				strcpy(add_val_2017, data_set[j].values);
				strcpy(stg_val_2017, &add_val_2017[1]);
				double values_2017 = atof(stg_val_2017);
				if (values_2017 == 0)
				{
					iterator_counter_65_b--;
				}
				
				sum_65_b += values_2017;
			} avg_65_b = sum_65_b / iterator_counter_65_b;
		}
    } age_avg(avg_35_f, avg_50_f, avg_65_f, avg_35_q, avg_50_q, avg_65_q, avg_35_o, avg_50_o, avg_65_o, avg_35_a, avg_50_a, avg_65_a, avg_35_b, avg_50_b, avg_65_b);

	spacer();

	/*          Question 2          */printf("|------------------------------------------------------------------------------------------Question 2------------------------------------------------------------------------------------------|\n");

	spacer();


}

/*  Defining all subsequent UDF's utilized in the program   */

void credits(void)
{
	spacer();
	printf("                      Toronto Metropolitan University\n");
	printf("                      *******************************\n");
	printf("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	sub_spacer();
	printf("---------------------------------------------------------------------------\n");
	printf("                 CPS 188 Term Project | 2023 Source Code\n");
	printf("---------------------------------------------------------------------------\n");
	sub_spacer();
	printf("                               ------------\n");
	printf("-------------------------------|Group - 40|-------------------------------\n");
	printf("                               ------------\n");
	sub_spacer();
	printf("Copyright (c) 2023 Sayeed Ahamad, Qurrat-Ul-Ain, Tre Spencer, Nourhan Antar\n");
	spacer();
	printf("/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
	spacer();
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

void spacer(void)	/*	UDF for creating NULL newline spaces for better tabular and visual output	*/
{
    for (int i = 0; i < SPACERS; i++)
    {
        printf("\n");
    }
    
}

void sub_spacer(void)	/*	UDF for creating NULL newline spaces for better tabular and visual output	*/
{
    for (int i = 0; i < SUB_SPACERS; i++)
    {
        printf("\n");
    }
    
}

void avg_province(void)	/*	UDF for Province-Wise Averages Header	*/
{
	printf("|--------------------Province-Wise Averages--------------------|\n");
}

void avg_year(void)	/*	UDF for Year-Wise Averages Header	*/
{
	printf("|--------------------Year-Wise Averages--------------------|\n");
}

void year_avg(double f_2015, double f_2016, double f_2017, double f_2018, double f_2019, double f_2020, double f_2021, double q_2015, double q_2016, double q_2017, double q_2018, double q_2019, double q_2020, double q_2021, double o_2015, double o_2016, double o_2017, double o_2018, double o_2019, double o_2020, double o_2021, double a_2015, double a_2016, double a_2017, double a_2018, double a_2019, double a_2020, double a_2021, double b_2015, double b_2016, double b_2017, double b_2018, double b_2019, double b_2020, double b_2021)	/*	UDF to print Year-Wise Averages in a tabular form	*/
{
	printf("|	Year	|		Canada		|		Quebec		|		Ontario		|		Alberta		|		British Columbia		|\n");
	printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
	printf("|	2015	|		%.3lf		|		%.3lf		|		%.3lf		|		%.3lf		|			%.3lf			|\n", f_2015, q_2015, o_2015, a_2015, b_2015);
	printf("|	2016	|		%.3lf		|		%.3lf		|		%.3lf		|		%.3lf		|			%.3lf			|\n", f_2016, q_2016, o_2016, a_2016, b_2016);
	printf("|	2017	|		%.3lf		|		%.3lf		|		%.3lf		|		%.3lf		|			%.3lf			|\n", f_2017, q_2017, o_2017, a_2017, b_2017);
	printf("|	2018	|		%.3lf		|		%.3lf		|		%.3lf		|		%.3lf		|			%.3lf			|\n", f_2018, q_2018, o_2018, a_2018, b_2018);
	printf("|	2019	|		%.3lf		|		%.3lf		|		%.3lf		|		%.3lf		|			%.3lf			|\n", f_2019, q_2019, o_2019, a_2019, b_2019);
	printf("|	2020	|		%.3lf		|		%.3lf		|		%.3lf		|		%.3lf		|			%.3lf			|\n", f_2020, q_2020, o_2020, a_2020, b_2020);
	printf("|	2021	|		%.3lf		|		%.3lf		|		%.3lf		|		%.3lf		|			%.3lf			|\n", f_2021, q_2021, o_2021, a_2021, b_2021);
}

void avg_age(void)	/*	UDF for Age-Group-Wise Averages Header	*/
{
	printf("|--------------------Age-Group-Wise Averages--------------------|\n");
}

void age_avg(double f_35, double f_50, double f_65, double q_35, double q_50, double q_65, double o_35, double o_50, double o_65, double a_35, double a_50, double a_65, double b_35, double b_50, double b_65)	/*	UDF to print Age-Group-Wise Averages in a tabular form	*/
{
	printf("| Age-Group	|		Canada		|		Quebec		|		Ontario		|		Alberta		|		British Columbia		|\n");
	printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
	printf("|	35-49	|		%.3lf		|		%.3lf		|		%.3lf		|		%.3lf		|			%.3lf			|\n", f_35, q_35, o_35, a_35, b_35);
	printf("|	50-64	|		%.3lf		|		%.3lf		|		%.3lf		|		%.3lf		|			%.3lf			|\n", f_50, q_50, o_50, a_50, b_50);
	printf("|	65+	|		%.3lf		|		%.3lf		|		%.3lf		|		%.3lf		|			%.3lf			|\n", f_65, q_65, o_65, a_65, b_65);
}

