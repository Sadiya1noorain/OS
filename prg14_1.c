/*Write a program to demonstrate basic operations of message queues.*/

/*Writer Message*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
// structure for message queue
struct {
    long msg_type;
    char msg[100];
} message;
int main(){
    key_t my_key;
    int msg_id;
    my_key = ftok("progfile", 65);             // create unique key
    msg_id = msgget(my_key, 0666 | IPC_CREAT); // create message queue and return id
    message.msg_type = 1;
    printf("\nWrite Message : ");
    fgets(message.msg, 100, stdin);
    msgsnd(msg_id, &message, sizeof(message), 0); // send message
    printf("\nSent message is : %s \n", message.msg);
}