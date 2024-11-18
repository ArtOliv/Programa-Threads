#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREADS 100

void createThreads();

void threadJoin();

void threadRace(void * arg);
