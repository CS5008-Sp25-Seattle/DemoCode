// compile with lpthread option
// gcc -lpthread 01_thread1.c -o thread1
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 10000
#define THREAD_LOOP 0

// shared variable
int counter = 0;

// thread to be executed - unspecified variable arguments
void* thread(void* vargp) {
    int temp;
    // Loop to consume time, so that threads don't
    // always complete before main
    for (int i=0; i<THREAD_LOOP; ++i) {
        temp = temp + i;
    }
    counter++;
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


