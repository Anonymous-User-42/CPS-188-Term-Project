#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define BUFFER_SIZE 1024

int main() {
    FILE* file = fopen("statscan_diabetes.csv", "r");
    char buffer[BUFFER_SIZE];
    char* token;
    int geo_col = -1;
    int value_col = -1;
    int count_canada = 0;
    int count_quebec = 0;
    int count_ontario = 0;
    int count_alberta = 0;
    int count_british_columbia = 0;
    double sum_canada = 0;
    double sum_quebec = 0;
    double sum_ontario = 0;
    double sum_alberta = 0;
    double sum_british_columbia = 0;
    double max_avg = 0;
    double lowest_avg = 100;
    
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Find the GEO and VALUE column indices
    if (fgets(buffer, BUFFER_SIZE, file)) {
        token = strtok(buffer, ",");
        int col = 0;
        while (token != NULL) {
            if (strcmp(token, "GEO") == 0) {
                geo_col = col;
            } else if (strcmp(token, "VALUE") == 0) {
                value_col = col;
            }
            token = strtok(NULL, ",");
            col++;
        }
        if (geo_col == -1 || value_col == -1) {
            printf("Could not find GEO or VALUE column\n");
            return 1;
        }
    }

    // Loop through remaining lines and extract GEO and VALUE values
    while (fgets(buffer, BUFFER_SIZE, file)) {
        char* row_token;
        char* row_tokens[2];
        int col = 0;
        row_token = strtok(buffer, ",");
        while (row_token != NULL) {
            if (col == geo_col) {
                row_tokens[0] = row_token;
            } else if (col == value_col) {
                row_tokens[1] = row_token;
            }
            row_token = strtok(NULL, ",");
            col++;
        }
double value = atof(row_tokens[1]); // convert value to double

        if (strcmp(row_tokens[0], "Canada (excluding territories)") == 0) {
            sum_canada += value;
            count_canada++;
        } else if (strcmp(row_tokens[0], "Quebec") == 0) {
            sum_quebec += value;
            count_quebec++;
        } else if (strcmp(row_tokens[0], "Ontario") == 0) {
            sum_ontario += value;
            count_ontario++;
        } else if (strcmp(row_tokens[0], "Alberta") == 0) {
            sum_alberta += value;
            count_alberta++;
        } else if (strcmp(row_tokens[0], "British Columbia") == 0) {
            sum_british_columbia += value;
            count_british_columbia++;
        }
    }

// Calculate and print averages

if (count_quebec > 0) {
    double avg_quebec = sum_quebec / count_quebec;
    printf("Average for Quebec: %.2f\n", avg_quebec);
}
if (count_ontario > 0) {
    double avg_ontario = sum_ontario / count_ontario;
    printf("Average for Ontario: %.2f\n", avg_ontario);
}
if (count_alberta > 0) {
    double avg_alberta = sum_alberta / count_alberta;
    printf("Average for Alberta: %.2f\n", avg_alberta);
}
if (count_british_columbia > 0) {
    double avg_british_columbia = sum_british_columbia / count_british_columbia;
    printf("Average for British Columbia: %.2f\n", avg_british_columbia);
}

// Calculate and print highest and lowest averages

if ((sum_quebec / count_quebec) > max_avg) {
    max_avg = (sum_quebec / count_quebec);
}
if ((sum_alberta / count_alberta) > max_avg) {
    max_avg = (sum_alberta / count_alberta);
}
if ((sum_ontario / count_ontario) > max_avg) {
    max_avg = (sum_ontario / count_ontario);
}
if ((sum_british_columbia / count_british_columbia) > max_avg) {
    max_avg = (sum_british_columbia / count_british_columbia);
}

if (max_avg == (sum_quebec / count_quebec)) {
    printf("Quebec has the highest average value: %.2f\n", max_avg);
} 
else if (max_avg == (sum_ontario / count_ontario)) {
    printf("Ontario has the highest average value: %.2f\n", max_avg);
} 
else if (max_avg == (sum_alberta / count_alberta)) {
    printf("Alberta has the highest average value: %.2f\n", max_avg);
} 
else if (max_avg == (sum_british_columbia / count_british_columbia)) {
    printf("British Columbia has the highest average value: %.2f\n", max_avg);
}

if ((sum_quebec / count_quebec) < lowest_avg) {
    lowest_avg = (sum_quebec / count_quebec);
}
if ((sum_alberta / count_alberta) < lowest_avg) {
    lowest_avg = (sum_alberta / count_alberta);
}
if ((sum_ontario / count_ontario) < lowest_avg) {
    lowest_avg = (sum_ontario / count_ontario);
}
if ((sum_british_columbia / count_british_columbia) < lowest_avg) {
    lowest_avg = (sum_british_columbia / count_british_columbia);
}


if (lowest_avg == (sum_quebec / count_quebec)) {
    printf("Quebec has the lowest average value: %.2f\n", lowest_avg);
} else if (lowest_avg == sum_ontario / count_ontario) {
    printf("Ontario has the lowest average value: %.2f\n", lowest_avg);
} else if (lowest_avg == (sum_alberta / count_alberta)) {
    printf("Alberta has the lowest average value: %.2f\n", lowest_avg);
} else if (lowest_avg == (sum_british_columbia / count_british_columbia)) {
    printf("British Columbia has the lowest average value: %.2f\n", lowest_avg);
}
}

