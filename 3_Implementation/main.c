#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <string.h>
#include"declare.h"
#include"1.c"
#include"2.c"
#include"3.c"
void menu(void);
void password(void);
void namefun(void);
void searchfun(void);
void listfun(void);
void modifyfun(void);
void deletefun(void);
void exitfun(void);

int main(){
	system("color B");
	password();
	getch();
}

void listfun(){
		FILE *fptr;
	char name[100],address[100],gmail[100],gender[8];
	double phone;
	int f;
	fptr=fopen("ebraj.txt","r");
	system("cls");
	gotoxy(31,2);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB LIST SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
	printf("\n");
	while(fscanf(fptr,"%s %s %s %s %lf",name,address,gender,gmail,&phone)!=EOF){

			printf("------------------------------------------\n");
		printf("Name:%s\n",name);
		printf("Address:%s\n",address);
		printf("Gender:%s\n",gender);
		printf("Gmail:%s\n",gmail);
		printf("Phone:%.0lf\n",phone);
			f=1;
				printf("------------------------------------------");
				printf("\n\n");
		}
		Sleep(1000);
		printf("Enter y for menu section:");
		while(getch()=='y'){
			menu();
		}
			fclose(fptr);
			}



void modifyfun(){
	FILE *fptr,*fptr1;
	char name[100],address[100],gmail[100],gmail1[100],address1[100],name1[100],gender[8],gender1[8];
	int res,f=0;
	double phone,phone1;
	fptr=fopen("ebraj.txt","r");
	fptr1=fopen("temp.txt","a");
	system("cls");
	gotoxy(31,4);
	printf("Enter the name: ");
	gets(name1);
	system("cls");
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0)
		{
			f=1;
			gotoxy(31,4);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB MODIFY SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
			gotoxy(31,6);
			printf("Enter the new address:");
			scanf("%s",address1);
				gotoxy(31,7);
			printf("Enter the gender:");
			scanf("%s",gender1);
			gotoxy(31,8);
			printf("Enter the new gmail:");
			scanf("%s",gmail1);
			gotoxy(31,9);
			printf("Enter the new phone number:");
			scanf("%lf",&phone1);
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address1,gender1,gmail1,phone1);

		}else{
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
		}
	}
	if(f==0){
		printf("Record Not found.");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("ebraj.txt","w");
	fclose(fptr);
	fptr=fopen("ebraj.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);

	}

	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	printf("\n\nPress y for menu option.");
	fflush(stdin);
	if(getch()=='y'){
		menu();
	}
}
void deletefun(){
	FILE *fptr,*fptr1;
	char name[100],address[100],gmail[100],gmail1[100],address1[100],name1[100],gender[8];
	int res,f=0;
	double phone,phone1;
	fptr=fopen("ebraj.txt","r");
	fptr1=fopen("temp.txt","a");
	system("cls");
	gotoxy(31,4);
	printf("Enter the CONTACT name that you want to delete: ");
	gets(name1);
	system("cls");
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0)
		{
			f=1;
			printf("Record deleted successfully");

		}else{
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
		}
	}
	if(f==0){
		printf("Record Not found.");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("ebraj.txt","w");
	fclose(fptr);
	fptr=fopen("ebraj.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);

	}

	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	printf("\n\nPress y for menu option.");
	fflush(stdin);
	if(getch()=='y'){
		menu();
	};
}
void exitfun(){
	system("cls");
	gotoxy(31,4);
	printf("\xDB\xDB\xDB\xDB DESIGNED BY \xDB\xDB\xDB\xDB");
	gotoxy(31,6);
	printf("\xDB RAMASAMY A");
}
void password(void){
	char passwords[20]={"ramasamy"};
	gotoxy(22,2);
	int j;
	int z;
	char name[40]="PHONE BOOK";
	z=strlen(name);
	for(j=0;j<=16;j++){
		Sleep(50);
		printf("\xDB");
	}
	for(j=0;j<=z;j++){
		Sleep(60);
		printf(" %c",name[j]);
	}
	for(j=0;j<=16;j++){
		Sleep(50);
		printf("\xDB");
	}
	gotoxy(30,4);
	printf("Password:");
	char ch,pass[20];
	char w='*';
	int i=0;
	while(ch!=13){
		ch=getch();
		if(ch!=13 && ch!=8){
			printf("%c",w);
			pass[i]=ch;
			i++;
		}
			}
	pass[i]='\0';
	if(strcmp(pass,passwords)==0){
		gotoxy(30,6);
		printf("CORRECT PASSWORD.");
		Sleep(1000);
		menu();
	}
	else{
		gotoxy(30,6);
		printf("You entered the wrong password.");
		Sleep(700);
		system("cls");
		password();
}

}


void menu(){
	system("cls");
	gotoxy(30,1);
	printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PHONEBOOK DIRECTORY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");
	gotoxy(31,4);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 1.Add New");
	gotoxy(31,7);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 2.Search");
	gotoxy(31,10);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 3.List");
	gotoxy(31,13);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 4.Modify");
	gotoxy(31,16);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 5.Delete");
	gotoxy(31,19);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 6.Exit");
	switch(getch()){
		case '1':
			namefun();
			break;
		case '2':
			searchfun();
			break;
		case '3':
			listfun();
			break;
		case '4':
			modifyfun();
			break;
		case '5':
			deletefun();
			break;
		case '6':
			exitfun();
			break;
		default:
			system("cls");
			printf("Invalid Enter.");
			getch();
}
}
