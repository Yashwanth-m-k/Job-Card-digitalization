#include<stdio.h>
#include "abb.h"
#include <string.h>
int main(){

    Job_Card job_card;
char str[11];
strcpy(job_card.emp_file_name, "Abb_Info.txt");
printf("User or Supervisor \n");
scanf("%s",str);

if(strcmp(str,"User")==0)
{
    printf("Enter Your Info below :\n");
    user_detaile(&job_card);
    user_Inspect(&job_card);
}
else if(strcmp(str,"Supervisor")==0)
{
   Supervisor(&job_card);
}

}