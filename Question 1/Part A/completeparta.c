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
    printf("Average for Quebec: %f\n", sum_quebec / count_quebec);
}
if (count_ontario > 0) {
    printf("Average for Ontario: %f\n", sum_ontario / count_ontario);
}
if (count_alberta > 0) {
    printf("Average for Alberta: %f\n", sum_alberta / count_alberta);
}
if (count_british_columbia > 0) {
    printf("Average for British Columbia: %f\n", sum_british_columbia / count_british_columbia);
}
}


/// Program 2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define NUM_PROVINCES 5

int main() {
    FILE* file = fopen("statscan_diabetes.csv", "r");
    char line_buffer[BUFFER_SIZE];
    char* token;
    int geo_col = -1;
    int value_col = -1;
    char* provinces[NUM_PROVINCES] = {"Canada (excluding territories)", "Quebec", "Ontario", "Alberta", "British Columbia"};
    int total_counts[NUM_PROVINCES] = {0};
    double total_sums[NUM_PROVINCES] = {0};

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Find the GEO and VALUE column indices
    if (fgets(line_buffer, BUFFER_SIZE, file)) {
        token = strtok(line_buffer, ",");
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
    while (fgets(line_buffer, BUFFER_SIZE, file)) {
        char* row_token;
        char* row_tokens[2];
        int col = 0;
        row_token = strtok(line_buffer, ",");
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

        // Update total counts and sums for each province
        for (int i = 0; i < NUM_PROVINCES; i++) {
            if (strcmp(row_tokens[0], provinces[i]) == 0) {
                if (value > 0) {
                    total_counts[i]++;
                    total_sums[i] += value;
                }
                break;
            }
        }
    }

    // Calculate and print averages for each province
    for (int i = 0; i < NUM_PROVINCES; i++) {
        if (total_counts[i] > 0) {
            printf("Average for %s: %f\n", provinces[i], total_sums[i] / total_counts[i]);
        }
    }

    fclose(file);
    return 0;
}

