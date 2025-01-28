#include <stdio.h>
#include "abb.h"
#include <string.h>
char *data[12] = {
    "Check the paint shade of the cabinet as per GA.",
    "Check all screen printing are done.",
    "Check the Cabinet dimension as per GA drawing.",
    "Check the panel base frame dimension as per GA drawing.",
    "All Duct and Duct cover are suitable length, Any obstruction, no burr and bubbles.",
    "Check all electrical parts are matches as per SAP/E-part list BOM.",
    "Check all electrical components Identification label above component and Location labels Base plate are provided.",
    "Check all the TB markers present.",
    "Check the GPO3 part number as per the SAP BOM/ work Instruction.",
    "Check the PEBB Assembly mounting plates mounting holes M8 should be match properly.",
    "Check the power cables routing assembly should be in U,V,W direction.",
    "Check the GI sheet metal hole M6 counter sink should be there as per drawing."
};

void user_detaile(Job_Card *job_card)
{
     
    strcpy(job_card->emp_file_name, "Abb_Info.csv");

    // Get user details
    printf("Enter Your Name: ");
    scanf(" %[^\n]", job_card->name);
    printf("Enter Your ID: ");
    scanf("%d", &job_card->id);
    printf("Enter Your Department: ");
    scanf(" %[^\n]", job_card->department);

    // Open file in append mode to add new data at the end
    job_card->fpter= fopen(job_card->emp_file_name, "a+");
    if (job_card->fpter == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    // Write user details to the file
    fprintf(job_card->fpter, "name :%s,Id :%d,Depart :%s\n",job_card->name, job_card->id, job_card->department);
    fclose(job_card->fpter);

    printf("Data successfully added to file.\n");

}
void Supervisor(Job_Card *job_card){
     printf("Enter Password to Access Employee detile :");
    scanf(" %[^\n]",job_card->password);

    if(strcmp(job_card->password,"11234")==0){

        job_card->fpter= fopen(job_card->emp_file_name, "r");
    if (job_card->fpter == NULL) {
        printf("Error: Unable to open file.\n");
        
    }
        printf("Employee Detile :\n");
        char buffer[1000];

        while(fgets(buffer,sizeof(buffer),job_card->fpter))
        {
            printf("%s",buffer);
        }
    }
}
void user_Inspect(Job_Card *job_card)
{
    FILE *fptr;
    fptr= fopen("data.csv", "r+");
    if (fptr == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }
    char a='1',b='0';
    char arr[12];
    // Ensure data has enough entries for arr
    int n = sizeof(arr) / sizeof(arr[0]);

    // Input characters into arr
    
    for (int i = 0; i < n; i++) {
        printf("%s :",data[i]);
        scanf(" %c", &arr[i]); // Space before %c to ignore whitespace
    }

    // Write data to the file
    for (int i = 0; i < n; i++) {
        if(i==0){
            fprintf(fptr,"STAGE 1 cabinet Per Assembly check\n");
            }
        else if(i==4){fprintf(fptr,"STAGE 2 COU Frame Assembly\n");}
        else if(i==8){fprintf(fptr,"STAGE 3 PEBB Frame Assembly CHECK LIST\n");}
        fprintf(fptr, "%s -> %c\n", data[i], arr[i]);
    }

    fclose(fptr);
    printf("Data written to file successfully.\n");


}

