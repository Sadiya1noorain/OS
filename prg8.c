/* Display message */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *dispmsg(char msg[]){
    printf("\n pid = %d \t Thread id = %u \n", getpid(), pthread_self());
    printf("\n Thread message : %s \n\n", msg);
    pthread_exit(0);
}
int main(){
    pthread_t pthr_id;
    int thread_status;
    char msg1[10];
    system("clear");
    printf("Enter the string : \t");
    scanf("%s", msg1);
    printf("\nMain thread : Before creating thread, pid = %d \t thread id = %u \n", getpid(), pthread_self());
    thread_status = pthread_create(&pthr_id, NULL, (void *)dispmsg, msg1);
    if (thread_status == -1){
        perror("THR-CRT-ERR");
        exit(1);
    }
    printf("\n Main thread waiting for thread to exit \n");
    pthread_join(pthr_id, NULL);
    printf("The thread exited, currently in main thread, pid = %d \t thread id = %u \n\n", getpid(), pthread_self());
    exit(0);
}
