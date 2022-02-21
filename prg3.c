/*File System Calls*/
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include<stdlib.h>

int main(){
    int n, fd;
    char buff[50]; // declaring buffer

    system("clear");

    // message printing on the display
    printf("\nEnter text to write in the file:\n\n");
    // read from keyboard, specifying 0 as fd for std input device
    // Here, n stores the number of characters
    n = read(0, buff, 50);
    
    // creating a new file using open.
    fd = open("prg3.txt", O_CREAT | O_RDWR, 0777);
    printf("\nThe written text is : \n\n");
    // writting input data to file (fd)
    write(fd, buff, n);
    // Write to display (1 is standard fd for output device)
    write(1, buff, n);
    printf("\n");
    // closing the file
    int close(int fd);

    return 0;
}
