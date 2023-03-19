#include <stdio.h>

int main(void) {
    char c;
    FILE* in;
    in = fopen("statscan_diab1etes.txt", "r");
    if (in != NULL)    
     {
          while ((c = fgetc(in)) != EOF)  //reads characters from a file until the end of the file is reached, storing each character in the variable 'c'
          {
            putchar(c);
        }
        fclose(in);
    } else {
        printf("Error opening file.\n");
    }
    return 0;
}

//
// Open the file using fopen() function.
// Search for  Quebec province 
// Use a loop to read each line of the file.
// If = Quebec, extract the value in the second column and add it to a running total.
// After reading all lines, divide the running total by the number of rows that had Quebec as the first column.
// Print the average.



