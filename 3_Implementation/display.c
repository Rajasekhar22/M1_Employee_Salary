#include <stdio.h>
void display(){
  FILE *sal;
  char a;
  sal = fopen("salaryDetails.txt", "r");
  while ((a = fgetc(sal)) != EOF){ 
    printf ("%c", a);
  }
  fclose(sal);
}

void data(){
  FILE *fptr;
  char a;
  fptr = fopen("details.txt", "r");
  while ((a = fgetc(fptr)) != EOF){ 
    printf ("%c", a);
  }
  fclose(fptr);
}