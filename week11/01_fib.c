#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// max number of inputs
#define MAX_FIB 200

// max number of inputs that can be computed with 
// naive fib and memoized fib
#define NAIVE_BIG_FIB 55
#define MEMO_BIG_FIB 90

// invalid value for memo table
#define INVALID -1

// ===================== MEMO DEFINIIONS =================

// define a type for array to hold computed data values
typedef unsigned long long memo_t[MAX_FIB];  

// add vals for 0,1, set other memo entries invalid
void init_memo(memo_t m) {
    m[0] = 0;
    m[1] = 1;
    for (int i=2; i<MAX_FIB; ++i) {
        m[i] = INVALID;
    }
    
    return;
}

// ==================== TIME DEFINITIONS =================
// timer functions found in time.h
// time_t is time type
time_t start_time;
time_t stop_time;

// get current time in seconds from some magic date with
// t = time(NULL);
// or 
// time(&t);
// where t is of type time_t
//
// get difference in secs between times t1-t2 with
// d = difftime(t1, t2) where d is of type double

// ==================== NAIVE FIB ========================

unsigned long long n_fib(int n) {
    if (n < 1) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return n_fib(n-2) + n_fib(n-1);
    }
}


// ==================== MEMOIZED FIB =====================

unsigned long long m_fib(int n, memo_t m) {
    unsigned long long temp;

    if (n < 0) {
        // error condition
	return INVALID;
    } else if (m[n] != INVALID) {
        // already solved this sub problem
	return (m[n]);
    } else {
        // unsolved sub problem
	temp = m_fib(n-2, m) + m_fib(n-1, m);
	m[n] = temp;
	return temp;
    }
}

// ==================== MAIN PROGRAM =====================
int main() {

    // result of call to fib function;
    unsigned long long result;

    // loop variable
    int i;

    // memo array to hold computed data values
    memo_t memo;
    init_memo(memo);

    printf("Start naive Fibonacci from 0 to %d by 5s\n", NAIVE_BIG_FIB-5);
    for (i=0; i <NAIVE_BIG_FIB; i+=5) {
        // get start time
	time(&start_time);
	// call n_fib
	result = n_fib(i);
	// get stop time
	time(&stop_time);

	printf("Naive fib of %d = %llu\n", i, result);
	printf("Time taken (seconds) = %lf\n", difftime(stop_time, start_time));
    }

    printf("\n\n");
    printf("Start memoized Fibonacci from 0 to %d by 5s\n", MEMO_BIG_FIB-5);
    for (i=0; i<MEMO_BIG_FIB; i+=5) {
        time(&start_time);
	// call m_fib;
	result = m_fib(i, memo);
	// get stop time
	time(&stop_time);

	printf("Memoized fib of %d = %llu\n", i, result);
	printf("Time taken seconds) = %lf\n", difftime(stop_time, start_time));
    } 
}


