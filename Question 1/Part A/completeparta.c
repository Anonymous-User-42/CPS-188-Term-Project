
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

