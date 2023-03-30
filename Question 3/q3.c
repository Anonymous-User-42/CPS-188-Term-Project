double national_average = ((sum_quebec / count_quebec) + (sum_ontario / count_ontario) + (sum_alberta / count_alberta) + (sum_british_columbia / count_british_columbia)) / 4;

 
 printf("The National Average of Diabetes is: %lf\n", national_average); 
 
 if ((sum_quebec / count_quebec) < national_average) {
	 printf("The average in Quebec is lower than the national average\n"); //check if averages for provinces are lower or higher than the national average 
 }
 else {
	printf("The average in Quebec is higher than the national average\n");
}
	
 if ((sum_ontario / count_ontario) < national_average) {
	printf("The average in Ontario is lower than the national average\n");
}

 else  {
	printf("The average in Ontario is higher than the national average\n");
}

 if ((sum_alberta / count_alberta) < national_average) {
	printf("The average in Alberta is lower than the national average\n");
}
 if ((sum_alberta / count_alberta) > national_average) {
	printf("The average in Alberta is higher than the national average\n");
}
	
 if ((sum_british_columbia / count_british_columbia) < national_average) {
	printf("The average in British Columbia is higher than the national average\n");
}
 else  {
	printf("The average in British Columbia is higher than the national average\n");
}
}
