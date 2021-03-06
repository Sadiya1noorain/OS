#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t mutex, rw_mutex;
int data = 0;
rCount = 0;
void *reader(void *arg){
    int f;
    f = (int)arg;
    sem_wait(&mutex);
    rCount++;
    if (rCount == 1)
        sem_wait(&rw_mutex);
    sem_post(&mutex);
    printf("data read by reader %d is %d\n", f, data);
    sleep(1);
    sem_wait(&mutex);
    rCount--;
    if (rCount == 0)
        sem_post(&rw_mutex);
    sem_post(&mutex);
}

void *writer(void *arg){
    int f;
    f = (int)arg;
    sem_wait(&rw_mutex);
    data++;
    printf("Data written by writer %d is %d \n", f + 1, data);
    sleep(1);
    sem_post(&rw_mutex);
}

int main(){
    int i;
    pthread_t rtid[5], wtid[5];
    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);
    for (int i = 0; i <= 2; i++){
        pthread_create(&wtid[i], NULL, writer, (void *)i);
        pthread_create(&rtid[i], NULL, reader, (void *)i);
    }
    for (int i = 0; i <= 2; i++){
        pthread_join(&wtid[i], NULL);
        pthread_join(&rtid[i], NULL);
    }
}