#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include "declarations.h"
#include "fun_call.h"


int add_Details(char *name_of_Employee, int no_Of_Days_Worked,int no_Of_Employees, long long int mob_No, double basic_Salary_Emp, double no_Of_hours_OT_Worked, double allowance){
    FILE *fptr,*sal;
    fptr=fopen("details.txt","w+");
    sal=fopen("salaryDetails.txt","w+");
    fprintf(fptr, "\tNAME OF THE EMPLOYEE \t MOBILE NUMBER \t BASIC PAY \n");

    for(int j=0;j<no_Of_Employees;j++){
        printf("\n \n Add person details to the company records: (व्यक्ति विवरण जोड़ें)\nEnter name: ");
        scanf("%30s",name_of_Employee);
        printf("Enter Mob no. : ");
        scanf("%lld",&mob_No);
        printf("Enter Basic salary of the person: ");
        scanf("%lf",&basic_Salary_Emp);
        printf("Enter the Total allowance: ");
        scanf("%lf",&allowance);
        fprintf(fptr,"%d \t %s \t \t %lld \t %lf \t \n \n", j+1,name_of_Employee,mob_No,basic_Salary_Emp);
        printf("Enter No of days worked/month: ");
        scanf("%d",&no_Of_Days_Worked);
        printf("Enter OVERTIME worked/month(hrs): ");
        scanf("%lfd",&no_Of_hours_OT_Worked);
        x=basic_Salary_Calc((float)no_Of_Days_Worked, basic_Salary_Emp);
        y=OT_Calc(  no_Of_hours_OT_Worked,  basic_Salary_Emp);
        z=pf_Calc( basic_Salary_Emp);
        if(j==0){
            fprintf(sal,"SNO.\tEMPLOYEE NAME\tPRESENT\tOT\tBASIC PAY\tOT PAY\tPF DEDUCTED\tTOTAL SALARY\n");
        }
        fprintf(sal,"%d\t%s\t%d\t%0.llf\t%.2lf\t%.2lf\t%.1lf\t%0.2lf\n", j+1,name_of_Employee,no_Of_Days_Worked, no_Of_hours_OT_Worked,x, y, z,x+y+allowance-z);
    }
    fclose(fptr);
    fclose(sal);
}
