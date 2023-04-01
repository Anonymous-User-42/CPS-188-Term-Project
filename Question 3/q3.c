#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PARSE THE CSV FILE AND STORE INTO ARRAY of Structs

typedef struct diabetes
{
	char REF_DATE[100];
	char GEO[100];
	char Age_Group[100];
	char Sex[100];
	char VALUE[100];
}	dict;

int main()
{
	FILE *fp = fopen("statscan_diabetes.csv", "r"); //open in read mode 
	
	if(!fp	) 
	{
		printf("Cannot Open File");
		return 1;
	}
	
	char buff[1024]; 
	int row_count = 0;
	int field_count = 0;
	
	dict values[999];
	
	int i = 0;
	while (fgets(buff, 1024, fp))
	{
		field_count = 0;
		row_count++;
		if(row_count == 1)
		continue; 
		
		char *field = strtok(buff, ",");
		while(field)
	{ 
		if(field_count == 0)
			strcpy(values[i].REF_DATE, field);	
		if(field_count == 1)
			strcpy(values[i].GEO, field);
		if(field_count == 3)
			strcpy(values[i].Age_Group, field);
		if(field_count == 4)
			strcpy(values[i].Sex, field);
		if(field_count == 13)
			strcpy(values[i].VALUE, field);
			
		field = strtok(NULL, ",");
		field_count++;
	}
	i++;
}
fclose(fp);

printValues(values);
	

		
	return 0;
}

void printValues(dict values[])
{
	
	for(int i=0; i<42; i++)
	{
		printf("Province->%s VALUE->%s\n" ,values[i].GEO, values[i].VALUE);
	}
	
	double sum = 0;
	
	for(int i =0; i<42; i++)
	{
		sum += atof(values[i].VALUE);
	}
	printf("Sum: %lf\n", sum);
}
