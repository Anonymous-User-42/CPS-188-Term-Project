

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 500
#define LINE_SIZE 250

typedef struct {
  char year[10];
  char province[35];
  char age_group[15];
  char sex[10];
  char values[5];
} datatypes;

void main(void) {
  FILE *fp;
  char row[ARRAY_SIZE];
  char *token;

  fp = fopen("statscan_diabetes.csv", "r");

  datatypes data_points[ARRAY_SIZE];

  int line_count = 0;

  while (feof(fp) != true) {
    if (line_count == 0) {
      continue;
    } else {
      fgets(row, LINE_SIZE, fp);
    }

    token = strtok(row, ",");

    for (int count; token != NULL; token = strtok(NULL, ","), count++) {
      if (count == 0) {
        strcpy(data_points[count].year, token);
      };
      if (count == 1) {
        strcpy(data_points[count].province, token);
      };
      if (count == 3) {
        strcpy(data_points[count].age_group, token);
      };
      if (count == 4) {
        strcpy(data_points[count].sex, token);
      };
      if (count == 13) {
        strcpy(data_points[count].values, token);
      };
      token = strtok(NULL, ",");
    }
    line_count++;
  }

  for (int i; i <= ARRAY_SIZE; i++) {
    printf("%s", data_points[i].province);
  }
}
