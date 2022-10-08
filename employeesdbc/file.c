#include <stdio.h>
#include <stdlib.h>
int main(){

	FILE *pfile = NULL;
	char *filename = "text.txt";
	int grade1, grade2, grade3,
	fgd1, fgd2, fgd3, sum = 0;
	
	float avg;
	
	
	printf("Enter 3 grades: ");
	scanf("%d%d%d", &grade1, &grade2, &grade3);
	
	if (!(pfile = fopen(filename, "w"))){
		perror("can not open file for writing");
		exit(1);
	}
	
	fprintf(pfile, "%d\n %d \n%d \n", grade1, grade2, grade3);
	fclose(pfile);
	
	if (! (pfile = fopen(filename, "r"))){
		perror("can not open file for reading");
		exit(1);
	}
	
	fscanf(pfile, "%d%d%d", &fgd1, &fgd2, &fgd3);
	fclose(pfile);
	
	sum = fgd1 + fgd2 + fgd3;
	avg = sum / 3;
	
	printf("average = %.2f", avg);
	
	return 0;
}