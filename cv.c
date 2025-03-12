#include <stdio.h>
#include <string.h>
#include<ctype.h>

int main(){
	char NAME[16];
	char EMAIL[50];
	char CONTACT[15];
	int AGE[5];
	char GENDER[15];
	int QUALIFICATIONYEARS;
	char MATRICGRADE[5];
	int MATRICYEAR;
	char INTERGRADE[5];
	int INTERYEAR;
	char BACHELORSFIELD[15];
	char BACHELORSGRADE[5];
	int BACHELORSYEAR;
	int JOBEXP;
	char LASTJOB[15];	
	char filename[25];
    int j=0,i;
    char *p;
    int valid=0;
    int length=0;
    //NAME
    do{
    	printf("ENTER YOUR NAME :\n");
		scanf("%[^\n]",NAME);
		getchar();
		if(strlen(NAME)>16){
			printf("RENTER VALID NAME IT MUST BE UNDER 15 Characters \n");
		}
    }while(strlen(NAME)>16);
    //CONTACT
    do{
    	printf("ENTER YOUR CONTACT :\n");
    	scanf("%[^\n]",CONTACT);
    	getchar();
    	valid=1;
		for(i=0;CONTACT[i]!='\0';i++){
			if(CONTACT[i]<'0'||CONTACT[i]>'9'){
				printf("RETRY ONLY NUMERIC CHARACTERS ARE ALLOWED \n");
				valid=0;
				break;
			}
		}
	}while(valid==0);
	//EMAIL
    do{
    	printf("ENTER YOUR EMAIL : \n");
    	scanf("%[^\n]",EMAIL);
    	getchar();
    	if(strchr(EMAIL,'@')!=NULL){
    		break;
		}
		else{
			printf("RENTER WALID EMAIL : \n");
		}
	}while(1);
	//AGE
	printf("ENTER YOUR AGE : \n");
	scanf("%d",&AGE);
	getchar();
	if(AGE<16 && AGE>20){
		printf("YOU ARE NOT ELIGIBLE FOR THIS \n");
		exit(0);
	}
	//GENDER
	printf("ENTER YOUR GENDER: \n");
	scanf("%[^\n]",GENDER);
	getchar();
	//QUALIFICATIONYEARS
	printf("ENTER YOUR QUALIFICATION YEARS : \n");
	scanf("%d",&QUALIFICATIONYEARS);
	getchar();
	//MATRIC GRADE AND YEAR
    if(QUALIFICATIONYEARS>=10){
    printf("ENTER YOUR MATRIC GRADE : \n");
	scanf("%[^\n]",MATRICGRADE);
	printf("ENTER YOUR MATRIC YEAR : \n");
	scanf("%d",&MATRICYEAR);
	getchar();
	}
	//INTER GRADE AND YEAR
	if(QUALIFICATIONYEARS>=12){
    printf("ENTER YOUR INTERMEDIATE GRADE : \n");
	scanf("%[^\n]",INTERGRADE);
	printf("ENTER YOUR INTERMEDIATE YEAR : \n");
	scanf("%d",&INTERYEAR);
	getchar();
	}
	//BACHELORS FIELD GRADE AND YEAR
	if(QUALIFICATIONYEARS>=16){
    printf("ENTER YOUR BACHELORS FIELD: \n");
	scanf("%[^\n]",BACHELORSFIELD);
	getchar();
	printf("ENTER YOUR BACHELORS GRADE : \n");
	scanf("%[^\n]",BACHELORSGRADE);
	getchar();
	printf("ENTER YOUR BACHELORS YEAR : \n");
	scanf("%d",&BACHELORSYEAR);
	getchar();
	}
	//JOB EXPERIENCE
	printf("ENTER YOUR WORK EXPERIENCE : \n");
	scanf("%d",&JOBEXP);
	getchar();
	//JOB LAST
	printf("ENTER YOUR LAST JOB : \n");
	scanf("%[^\n]",LASTJOB);
	getchar();
//	FILE 
  	strupr(NAME);
	strcpy(filename, NAME);
	strcat(filename,".txt");
   FILE *file=fopen(filename,"w");
   if(file==NULL){
   	perror("ERROR CREATING FILE \n");
   	return 0;
	}

fprintf(file,"%s \n",NAME);
fprintf(file,"CONTACT : %s \n",CONTACT);
fprintf(file,"EMAIL : %s \n",EMAIL);
fprintf(file,"AGE : %d \n",AGE);
fprintf(file,"GENDER : %s \n",GENDER);
fprintf(file,"\n");
fprintf(file,"QUALIFICATION \n");
if(QUALIFICATIONYEARS>=10){
fprintf(file,"MATRIC:\n with %s GRADE in %d YEAR \n",MATRICGRADE,MATRICYEAR);
}
if(QUALIFICATIONYEARS>=12){
fprintf(file,"INTERMEDIATE:\n with %s GRADE in %d YEAR \n",INTERGRADE,INTERYEAR);
}
if(QUALIFICATIONYEARS>=16){
fprintf(file,"BACHELORS in %s:\n with %s GRADE in %d YEAR \n",BACHELORSFIELD,BACHELORSGRADE,BACHELORSYEAR);
}
fprintf(file,"\n");
fprintf(file,"JOB DETAILS \n");
fprintf(file,"WORK EXPERIENCE :\n %d YEARS OF EXPERIENCE \n",JOBEXP);
fprintf(file,"LAST JOB :\n  %s \n",LASTJOB);
 
fclose(file);
printf("YOUR FILE IS SUCCESFULLY SAVED TO %s.txt",NAME);

	return 0;
}
