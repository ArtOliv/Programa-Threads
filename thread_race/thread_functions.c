#include "thread.h"

pthread_t thread[THREADS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int ready_count = 0; 
int winner[3] = {0, 0, 0};
int count = 0;

void createThreads(){
    int *thread_id;
    for(int i = 0; i < THREADS; i++){
        thread_id = (int*) malloc (sizeof(int));
        *thread_id = i + 1;
        pthread_create(&thread[i], NULL, (void*)threadRace, thread_id);
    }
}

void threadJoin(){
    for(int i = 0; i < THREADS; i++){
        pthread_join(thread[i], NULL);
    }
}

void threadRace(void *arg){
    int thread_id = *((int*)arg);
    free(arg);

    pthread_mutex_lock(&mutex);
    ready_count++;
    if (ready_count == THREADS) {
        pthread_cond_broadcast(&cond);
    } else {
        pthread_cond_wait(&cond, &mutex);
    }
    pthread_mutex_unlock(&mutex);

    for(int i = 0; i < 10; i++){
        sleep(1);
    }

    pthread_mutex_lock(&mutex);
    if(count < 3){
        winner[count] = thread_id;
        count++;
        printf("A thread %d ficou em %dº lugar.\n", thread_id, count);
    }
    pthread_mutex_unlock(&mutex);
}