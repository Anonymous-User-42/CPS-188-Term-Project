

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int year;
    double ontario[5], quebec[5], alberta[5], britishColumbia[5];
    double ontarioAvg, quebecAvg, albertaAvg, britishColumbiaAvg;
    double overallAvg;
    int i;

    fp = fopen("statscan_diab1etes.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open the input file");
        exit(0);
    }

    i = 0;
    while (!feof(fp) && i < 5) {
        char line[100];
        fgets(line, 100, fp);
        sscanf(line, "%d,%lf,%lf,%lf,%lf\n", &year, &ontario[i], &quebec[i], &alberta[i], &britishColumbia[i]);
        i++;
    }
    fclose(fp);

    ontarioAvg = quebecAvg = albertaAvg = britishColumbiaAvg = 0;
    int countOntario = 0, countQuebec = 0, countAlberta = 0, countBritishColumbia = 0;
    for (i = 0; i < 5; i++) {
        if (ontario[i] != -1) { // ignore missing data
            ontarioAvg += ontario[i];
            countOntario++;
        }
        if (quebec[i] != -1) {
            quebecAvg += quebec[i];
            countQuebec++;
        }
        if (alberta[i] != -1) {
            albertaAvg += alberta[i];
            countAlberta++;
        }
        if (britishColumbia[i] != -1) {
            britishColumbiaAvg += britishColumbia[i];
            countBritishColumbia++;
        }
    }
    ontarioAvg /= countOntario;
    quebecAvg /= countQuebec;
    albertaAvg /= countAlberta;
    britishColumbiaAvg /= countBritishColumbia;
    overallAvg = (ontarioAvg + quebecAvg + albertaAvg + britishColumbiaAvg) / 4;

    printf("Ontario Average = %.2lf\n", ontarioAvg);
    printf("Quebec Average = %.2lf\n", quebecAvg);
    printf("Alberta Average = %.2lf\n", albertaAvg);
    printf("British Columbia Average = %.2lf\n", britishColumbiaAvg);
    printf("Overall Average = %.2lf\n", overallAvg);

    return 0;
}


