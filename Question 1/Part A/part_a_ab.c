#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	char line [1000]; // Create an array to store lines read from file 
	char *column; // Pointer to store columns 
	int start_row = 128; // The first row Alberta begins at 
	int last_row = 169; // The last Alberta Row 
	int num_columns[] = {1, 2, 5, 14}; // Column numbers to print 	
	int current_row = 0; // current row being read
	int current_column = 0; //current column being read 
	int num_cols = sizeof(num_columns) / sizeof(num_columns[0]); //Find number of columns in the array
	
	FILE *fp; 
	
	fp = fopen ("statscan_diabetes.csv", "r"); //Open the file to be read
	
	if (fp == NULL) { //Check if file can be opened, if it cannot display Cannot Open File
		printf ("Cannot Open the File");
		exit(0);
	}

	while (fgets(line, 1000, fp) != NULL) { // read all lines and print required rows/columns
		current_row++;
		if (current_row >= start_row && current_row <= last_row) {
			current_column = 0;
			column = strtok(line, ",");
			while (column != NULL) {
				current_column++;
				for (int i = 0; i < num_cols; i++) { 
					if (current_column == num_columns[i]) {
						printf ("%s,", column);
					}
				}
				column = strtok(NULL, ",");
			}
			printf ("\n");
		}
	}

		
	fclose (fp);

	return(0);
}



