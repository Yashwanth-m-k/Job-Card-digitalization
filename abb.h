
#ifndef ABB_H
#define ABB_H
#include <stdio.h>
typedef struct job_card
{
    char name[20];
    int id;
    char department[20];
    FILE *fpter;
    //
    char password[10];
   // FILE *emp_ptr;
    char emp_file_name[10];

}Job_Card;
 
void Supervisor(Job_Card *job_card);  
void user_detaile(Job_Card *job_card);
void user_Inspect(Job_Card *job_card);

#endif