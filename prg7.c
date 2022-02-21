/*Program to demonstrate Zombie process.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
    int pid, a;
    system("clear");
    printf("\nZombie Process\n");
    printf("\nmain Process id = %d \n Parent process id = %d\n", getpid(), getppid());
    system("ps -l");
    pid = fork();
    if (pid == -1){
        perror("FRK_ERR:");
        exit(1);
    }
    if (pid == 0){
        printf("\nChild process id = %d\nparent process id = %d\n", getpid(), getppid());
        system("ps -l");
        a = 200;
        printf("\nchild : a = %d\n", a);
        exit(0);
    }
    else{
        int val;
        sleep(2);
        printf("\npid = %d\nppid = %d\n", getpid(), getppid());
        system("ps -l");
        a = 100;
        printf("\nparent : a = %d\n", a);
        val = wait(0);
        printf("\npp:id val = %d\n", val);
    }
    printf("\n");
}