#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <string.h>
void searchfun(){
	FILE *fptr;
	int flag=0;
	int res;
	char name[100];
	char address[100];
	char gmail[100];
	double phone;
	char gender[8];
	char name1[100];
	system("cls");
	fflush(stdin);
	gotoxy(18,2);
	printf("\xDB\xDB\xDB Enter the name of the person you want to see the detail:: ");
	gets(name1);
	fptr=fopen("ebraj.txt","r");
	//fflush(stdin);
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0){
			gotoxy(39,4);
			printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Record Found \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
			gotoxy(28,5);
			printf("----------------------------------------");
		gotoxy(31,6.5);
		printf("\xB3\xB2\xB2\xB2 Name:\t%s",name);
		gotoxy(31,7);
		printf("\xB3\xB2\xB2\xB2 Address:\t%s",address);
			gotoxy(31,8);
		printf("\xB3\xB2\xB2\xB2 Gender:\t%s",gender);
		gotoxy(31,9);
		printf("\xB3\xB2\xB2\xB2 Gmail:\t%s",gmail);
		gotoxy(31,10);
		printf("\xB3\xB2\xB2\xB2 Phone Number:\t%.0lf",phone);
		gotoxy(31,11);
			printf("----------------------------------------");
		flag=1;
		Sleep(1000);
			gotoxy(18,12);
			printf("Enter y for menu option.");
	while(getch()=='y'){
		menu();
	}
	}
}
	if(flag==0){
		system("cls");
		gotoxy(39,4);
		printf("No record found.");;
		gotoxy(39,6);
		printf("Enter a to enter file again or double y key to open menu section:");
		if(getch()=='a'){
			system("cls");
			searchfun();
		}

	}


	fclose(fptr);
}
