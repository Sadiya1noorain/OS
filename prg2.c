/* Copy from one file to another (File Operations) */
#include <stdio.h>
#include <stdlib.h> // For exit()

int main(){
    FILE *fptr1, *fptr2;
    char fname[100], c;

    system("clear");

    printf("\nEnter the filename to open for reading : ");
    scanf("%s", fname);

    // Open one file for reading
    fptr1 = fopen(fname, "r");
    if (fptr1 == NULL){
        printf("Cannot open file %s \n", fname);
        exit(0);
    }

    printf("\nEnter the filename to open for writing : ");
    scanf("%s", fname);

    // Open another file for writing
    fptr2 = fopen(fname, "w");
    if (fptr2 == NULL){
        printf("Cannot open file %s \n", fname);
        exit(0);
    }

    // Read contents from file
    c = fgetc(fptr1);
    while (c != EOF){
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    printf("\nContents copied to %s \n", fname);

    fclose(fptr1);
    fclose(fptr2);

    printf("\n");
    return 0;
}