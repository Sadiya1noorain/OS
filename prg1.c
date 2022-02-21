/*Read data from keyboard and write to file. (File Operations)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char fname[20], dataword[20];
    FILE *fptr;
    system("clear");
    printf("\nEnter filename : \t");
    scanf("%s", fname);
    printf("\nEntered filename is : %s", fname);
    fptr = fopen(fname, "w");
    if (fptr == NULL){
        perror("FILE_OPN_ERR:");
        exit(1);
    }
    while (1){
        printf("\nEnter dataword\n");
        scanf("%s", dataword);
        if (!strcmp(dataword, "end"))
            break;
        fprintf(fptr, "%s\n", dataword);
    }
    fclose(fptr);
    fptr = fopen(fname, "r");
    if (fptr == NULL){
        perror("FILE_OPN_ERR");
        exit(1);
    }
    while (fscanf(fptr, "%s", dataword) != EOF)
        printf("\n data recieved from file : %s \n", dataword);
    fclose(fptr);
    printf("\n\n");
}