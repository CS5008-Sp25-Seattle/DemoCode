// compile with lpthread option
// gcc -lpthread 01_thread1.c -o thread1
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 10000

// shared variable
int counter = 0;

// lock variable
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER; 

// thread to be executed - unspecified variable arguments
void* thread(void* vargp) {
    pthread_mutex_lock(&mutex1);
        counter = counter + 1;
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

int main() {
    // variale to keep Pthread ID of created thread
    pthread_t tid[NTHREADS];
    int i;

    printf("Counter starts at %d\n", counter);

    // create and run the threads
    for (i=0; i < NTHREADS; ++i) {
        pthread_create(&tid[i], NULL, thread, NULL);
    }

    // wait until all threads are done
    for (i=0; i < NTHREADS; ++i) {
        pthread_join(tid[i], NULL);
    }

    printf("Counter ends at %d\n", counter);

    return 0;
}


