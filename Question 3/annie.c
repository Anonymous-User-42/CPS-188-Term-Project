printf("\n");
printf("3) Provinces with diabetes averages above the national average:\n");
if (avg_british_columbia > canadaAverage[0]) {
    printf("British Columbia\n");
}
if (avg_ontario > canadaAverage[0]) {
    printf("Ontario\n");
}
if (avg_alberta > canadaAverage[0]) {
    printf("Alberta\n");
}
if (avg_quebec > canadaAverage[0]) {
    printf("Quebec\n");
}
printf("\n");
printf("3) Provinces with diabetes averages below the national average:\n");
if (avg_british_columbia < canadaAverage[0]) {
    printf("British Columbia\n");
}
if (avg_ontario < canadaAverage[0]) {
    printf("Ontario\n");
}
if (avg_alberta < canadaAverage[0]) {
    printf("Alberta\n");
}
if (avg_quebec < canadaAverage[0]) {
    printf("Quebec\n");
}
