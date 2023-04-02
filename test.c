#include <stdio.h>

int main() {
    // Define variables
    float ages[3] = {35.0, 60.0, 65.0}; // Age groups
    char* provinces[4] = {"Ontario", "Quebec", "British Columbia", "Alberta"}; // Province names
    float diabetes_rates[4][3] = {
        {6.5, 7.8, 12.4},
        {5.1, 7.2, 11.5},
        {5.9, 7.1, 10.8},
        {6.3, 7.4, 12.0}
    }; // Diabetes rates by province and age group
    float country_rates[3] = {0.0, 0.0, 0.0}; // Diabetes rates for the whole country
    int i, j; // Loop variables

    // Calculate province averages
    for (i = 0; i < 4; i++) {
        printf("Province: %s\n", provinces[i]);
        for (j = 0; j < 3; j++) {
            country_rates[j] += diabetes_rates[i][j];
            printf("Age group: %0.0f- %0.0f, Average diabetes rate: %0.2f%%\n", ages[j], ages[j+1], diabetes_rates[i][j]);
        }
        printf("\n");
    }

    // Calculate country averages
    printf("Country:\n");
    for (j = 0; j < 3; j++) {
        country_rates[j] /= 4.0;
        printf("Age group: %0.0f- %0.0f, Average diabetes rate: %0.2f%%\n", ages[j], ages[j+1], country_rates[j]);
    }

    return 0;
}
