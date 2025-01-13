// compile with lpthread option
// gcc -lpthread 01_thread1.c -o thread1
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 10

// thread to be executed - unspecified variable arguments
void* thread(void* vargp) {
    // add some time-consuming activity so that 
    // the threads don't necessarily all finish 
    // executing before the main does. If you 
    // comment out the pthread_join below, you
    // see that some of the threads don't print before
    // the program completes its execution
    int temp;
    for (int i=0; i<10000; ++i) {
        temp = temp + i;
    }
    printf("Hello from thread %ld\n", (long)pthread_self());
    return NULL;
}

int main() {
    // variale to keep Pthread ID of created thread
    pthread_t tid[NTHREADS];
    int i;

    printf("Hello from the main program %ld\n", (long)pthread_self());

    // create and run the threads
    for (i=0; i < NTHREADS; ++i) {
        pthread_create(&tid[i], NULL, thread, NULL);
    }

    // wait until all threads are done
    for (i=0; i < NTHREADS; ++i) {
        pthread_join(tid[i], NULL);
    }

    printf("Good bye from the main program: %ld\n", (long)pthread_self());

    return 0;
}


