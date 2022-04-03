//#include "unity.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "declarations.h"
#include "fun_call.h"
#include "add.c"
#include "display.c"

char name_Of_Company[30]="ABC-AUTOMOBILES";
char main_auth_User[30]="Rajasekhar";

char c;char name[31];char pass[31]; int z1=0;
int checku=1,checkp=1;

static int i=0, n;
struct detail
{
char name[31],pass[31];
}w;

int main(){
  //dummy();
  printf("\n\n\tEmployer Login: \n\t---------------\n\n");
  printf("\tEnter '1' for login \n\tEnter '2' for Registering a new user\n\tEnter '3' to see the details. \n\tEnter '4' to exit. \n");
  scanf("%d",&opt);
  switch (opt){
    case 1:
      login();
      call();
      break;
    case 2:
      login();
      reg();
      call();
      break;
    case 4:
      exit(0);
    case 3:
      view_Salary();
      break;
    default :
      printf("Wrong option entered!");
      exit(0);
  }

  return 0;
}
void call(){
  printf("\n\n\n\t-----Add details of the Employees -----\t\n\nEnter number of employees :\n");
  scanf("%d", &no_Of_Employees);
  add_Details( name_Of_Employee, no_Of_Days_Worked, no_Of_Employees, mob_No, basic_Salary_Emp, no_Of_hours_OT_Worked, allowance);
  printf("\nEnter 1 to display Employee salary\n\nEnter 2 to display Employee details\n\nEnter 3 to exit!\n");
  scanf("%d",&option);
  switch (option){
    case 1:
      display();
      break;
    case 2:
      data();
      break;
    case 3:
      exit(0);
    default :
      printf("Wrong number entered!");
      break;
  }
}

//basic_Salary_Calc calculates the basic salary of the person, with respect the number of days that respective person worked
double basic_Salary_Calc(int no_Of_Days_Worked,double basic_Salary_Emp){
  double a=basic_Salary_Emp/30;
  double b=(double)no_Of_Days_Worked*a;
  return b;
}
//OT_Calc function calculates the OVERTIME that respective person worked for a month
double OT_Calc(double no_Of_hours_OT_Worked, double basic_Salary_Emp){
  int no_Of_Hours_Per_Day =4;
  double no_Of_Days_Ot_Worked = no_Of_hours_OT_Worked/no_Of_Hours_Per_Day;
  double a=basic_Salary_Emp/30;
  double b=no_Of_Days_Ot_Worked*a;
  return b;
}
//pf_Calc function is implemented to calculate pf amount that should be deducted in the person salary
double pf_Calc(double basic_Salary_Emp){
  double pf=0.12*basic_Salary_Emp;
  return pf;
}
//This is to register a new user to add the details of the person
void reg(){
  FILE *fp;
  char checker[33];
  int y1=0;
  if(fp == NULL){
    fp=fopen("Reg.txt", "w");
    goto a;
  }
  else{
    fp=fopen("Reg.txt", "a");
    goto a;
  }
  a:
  printf("\n\t\t\t\t-----------------------------");
  printf("\n\n\t\t\t\t    REGISTERATION");
  printf("\n\t\t\t\t-----------------------------");
  for(i=0;i<100;i++){
    printf("\n\n\t\t\t\t  ENTER USERNAME: ");
    scanf("%32s",checker);
    while(!feof(fp)){
      if(strcmp(checker,w.name)==0){
        printf("\n\n\t\t\tYOU'RE ALREADY A USER");
        reg();
      }
      else{
        strcpy(w.name,checker);
        break;
      }
    }
    printf("\n\n\t\t\t\t  PASSWORD: ");
    scanf("%30s", pass);
    fprintf(fp,"\t%s %s\n", w.name, w.pass);
    fclose(fp);
    break;
  }
}
//This is to login the registered user.
void login(){
  FILE *fp;
  fp=fopen("Reg.txt", "r+");
  if(fp == NULL){
    printf("\t\t\tfile does not found !");
    exit(1);
  }
  else{
    printf("\n\n\t\t\t\t   LOG IN ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^");
    printf("\n\n\t\t\t\t  ENTER USERNAME: ");
    scanf("%30s",name);
    while( (c = fgetc(fp)) != EOF){
      fscanf(fp,"%30s %30s",w.name,w.pass);
      if(strcmp(w.name, name) == 0){
        checku=0;
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        scanf("%30s", pass);
        checkp=strcmp(w.pass, pass);
        break;
      }
    }
  }
  if(checku ==0 && checkp == 0){
    printf("\n\n\n\t\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
    printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY");
  }
  else if(checku==0&&checkp != 0){
    printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s \n\n\t\t\tTry logging in again!\n",name);
    printf("\n Enter 1 to login again\n Enter 2 to exit!\n");
    scanf("%d",&button);
    switch (button){
      case 1:
        login();
        break;
      case 2:
        exit(0);
      default:
        printf("\nEntered wrong option!, exitting!\n");
        exit(0);
    }
  }
  else if(checku!=0){
    printf("\n\n\n\t\t\tYou are not a Authorised User\n \t\t\tPress enter to register yourself\n");
    getchar();
    exit(0);
  }
}

void view_Salary(){
  FILE *det;
  char a;
  det=fopen("salaryDetails.txt","r");
  while ((a = fgetc(det)) != EOF){ 
    printf ("%c", a);
  }
  fclose(det);
}