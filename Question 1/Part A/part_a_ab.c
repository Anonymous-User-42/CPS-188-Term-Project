#include <stdio.h>

int main ()
{
	double average; 
printf ("\t\t\t   Males with diabetes in Alberta (Percentages)\n\n");
printf ("\t\t2015\t 2016\t 2017\t 2018\t 2019\t 2020\t 2021\n");
printf ("35 - 49\t\t5.4\t 6\t 3.2\t 3.7\t 7.6\t 8.7\t 2.4\n");
printf ("50 - 64\t\t9.5\t 10.7\t 16.1\t 13\t 12.4\t 13.1\t 13.9\n");
printf ("65+\t\t15.8\t 15.8\t 22.4\t 23.6\t 22.8\t 21.2\t 20.6\n\n"); 

printf ("\t\t\t   Females with Diabetes in Alberta (Percentages)\n\n");
printf ("\t\t2015\t 2016\t 2017\t 2018\t 2019\t 2020\t 2021\n");
printf ("35 - 49\t\tN/A\t 2.2\t 3.5\t 3.6\t 3.8\t N/A\t 3.4\n");
printf ("50 - 64\t\t5.1\t 6.2\t 11.6\t 10.9\t 7.5\t 7\t 7\n");
printf ("65+\t\t10.8\t 17.7\t 15\t 11.3\t 13.9\t 14.4\t 11.6");

average = (5.4 + 9.5 + 15.8 + 6 + 10.7 + 15.8 + 3.2 + 16.1 + 22.4 
+ 3.7 + 13 + 23.6 + 7.6 + 12.4 + 22.8 + 8.7 + 13.1 + 21.2 + 2.4 + 13.9 
+ 20.6 + 5.1 + 10.8 + 2.2 + 6.2 + 17.7 + 3.5 + 11.6 + 15 + 3.6 + 10.9 
+ 11.3 +3.8 + 7.5 + 13.9 + 7 + 14.4) / 40;
printf ("\n\nThe average percentage of people in Alberta with Diabetes is: %.2lf%%\n", average);




return (0);

;
}



