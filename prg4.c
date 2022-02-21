/*Copy - System Calls*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdlib.h>

int main(){
    char buf;
    int fd_one, fd_two;
    system("clear");
    fd_one = open("prg3.txt", O_RDONLY);

    if (fd_one == -1){
        printf("Error opening first_file\n");
        close(fd_one);
    }

    fd_two = open("prg4.txt",
                  O_WRONLY | O_CREAT,
                  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    while (read(fd_one, &buf, 1)){
        write(fd_two, &buf, 1);
    }

    printf("\nContent successfully copied from one file to another \n\n");

    close(fd_one);
    close(fd_two);
}