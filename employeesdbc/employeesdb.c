/*********************************
 * Author: Ahmed Mohammed Abdel Gaber
 * last update data: 09/30/2022
 * employees database program 
 **********************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NAME_MAX 20

struct{
	char *filename;
	FILE *pfile;
}global = {"mytext.bin", NULL};


typedef struct employee{
	char first_name[NAME_MAX];
	char last_name[NAME_MAX];
	int gross_income;
	char material_status[NAME_MAX];
}Employee;

bool get_person(Employee *pemployee);
void getname(char *name);
void show_person_data(void);
void record_search(void);


int main(void){
	
	Employee member;
	
	printf("\n%22c--------------------------------\n", ' ');
	printf("%25cWelcome to Database Program\n", ' ');
	printf("%22c--------------------------------\n\n", ' ');
	
	
	if (!(global.pfile = fopen(global.filename, "wb"))){
		perror("can not open file to write");
		exit(1);
	}
	
	while(get_person(&member))
		fwrite(&member, sizeof member, 1, global.pfile);
	fclose(global.pfile);
	show_person_data();
	
	// if(remove(global.filename)){
		// perror("can not delete the file");
		// exit(1);
	// }
	
	
	return 0;
}

bool get_person(Employee *temp){
	static char more = '\0';
	printf("%26cSELECT AN OPERATION\n\n", ' ');
	printf("%5c(A: Adding an employer, R: Retreiving data, S: Search for record)\n\n%35c", ' ', ' ');
	scanf(" %c", &more);
	
	if(tolower(more) == 'r') return false;
	
	if(tolower(more) == 's'){
		record_search();
		return false;
	}
	
	printf("\n%20cEnter the employee first name \n\n%32c", ' ', ' ');
	getname(temp->first_name);
	printf("\n%20cEnter the employee last name\n\n%32c", ' ', ' ');
	getname(temp->last_name);
	printf("%20cEnter the employee gross income\n\n%34c", ' ', ' ');
	scanf("%d", &temp->gross_income);
	printf("\n%20cEnter the employee material status\n\n%33c", ' ', ' ');
	scanf("%s", &temp->material_status);
	printf("\n\n\n");
	return true;
}      // GET EMPLOYEE


void getname(char *name){
	fflush(stdin);
	fgets(name, NAME_MAX, stdin);
	int len = strlen(name);
	if(name[len - 1] == '\n')
		name[len -1] = '\0';
}

void show_person_data(void){
	Employee member;
	int sum = 0, counter = 0;
	float avg;
	if (!(global.pfile = fopen(global.filename, "r"))){
		perror("can not open file for reading");
		exit(0);
	}
	
	printf("\n\n%30cRetrieving data\n\n", ' ');
	
	while(fread(&member,sizeof(member), 1, global.pfile)){
		printf("\n%25cEmployee: %s %s\n%25cgross income: %d\n%25cmaterial status: %s\n\n", ' ', member.first_name, member.last_name, ' ', member.gross_income, ' ', member.material_status);
		sum += member.gross_income;
		counter++;
		
	}
	avg = sum / counter;
	printf("%25cgross income average = %.2f\n\n", ' ', avg);
	
	fclose(global.pfile);
}  // SHOW DATA PERSON 

void record_search(void){
	Employee member;
	char name[NAME_MAX];
	int len_str;
	
	printf("%18cEnter the first name of the employee\n%20c", ' ', ' ');
	fflush(stdout);
	scanf("%s", &name);
	
	fclose(global.pfile);
	
	if (! (global.pfile = fopen(global.filename, "r"))){
		perror("can not open file reading");
		exit(1);
	}
	
	len_str = strlen(name);
	
	if (name[len_str -1] == '\n')
		name[len_str -1] = '\0';
	while(fread(&member, sizeof(member), 1, global.pfile)){
		if(strcmp(name, member.first_name) == 0)
			printf("\n%25cEmployee: %s %s\n%25cgross income: %d\n%25cmaterial status: %s\n\n", ' ', member.first_name, member.last_name, ' ', member.gross_income, ' ', member.material_status);
	}
	
		printf("\n%35c NOT FOUND\n\n", ' ');
}