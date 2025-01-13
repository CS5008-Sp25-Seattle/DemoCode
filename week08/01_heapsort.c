#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// max number of inputs
#define MAX_INPUT 100

// max random number
#define RAND_RANGE 100

// swap the contents of integers *i and *j
// we must pass the ints by ref (pointer) so the function
// can change them.
void swap(int* i, int* j) {
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
    return;
}

// =============== MAX HEAP DEFINITIONS ==============

// max size of heap
#define LIMIT 200

// heap will be a pair of a data array and the index
// of the next open slot. We will use index 0 as the 
// root of the heap
typedef struct heap {
    int data[LIMIT];  // array to hold the heap data
    int next;         // index of next open slot in heap
} heap_t;

// Note we will declare the max heap on our system stack
// not with malloc. But we have to pass a pointer to the
// heap to most functions

// is the heap *h empty?
bool is_empty(heap_t* h) {
    if (h->next <= 0) {
        return true;
    } else {
        return false;
    }
}

// is the heap *h full?
bool is_full(heap_t* h) {
    if (h->next >= LIMIT) {
        return true;
    } else {
	return false;
    }
}

// is the heap node of *h indexed by ix NULL?
// null nodes are beyond the end of the heap
bool is_null(heap_t* h, int ix) {
    if (ix >= h->next) {
	return true;
    } else {
        return false;
    }
}

// finding parent, left, and right are independent
// of the heap *h. They are entirely determined
// by the index relationships.

// find the index of the parent of node at ix
int parent(int ix) {
    // root has no parent, so return 0
    if ((0 < ix) && (ix < LIMIT)) {
        return ((ix + 1) /2 ) - 1;
    } else {
	return 0;
    }
}

// find the index of the left child of node at index ix
int left_child(int ix) {
    if ((0 <= ix) && (ix < LIMIT)) {
        return ((2 * ix) + 1);
    } else {
        return 0;
    }
}

// find the index of the right child of node at index ix
int right_child(int ix) {
    if ((0 <= ix) && (ix < LIMIT)) {
        return ((2 * ix) + 2);;
    } else {
        return 0;
    }
}

// node at ix of heap *h may be out of place because it
// was just added. Bubble it up through its chain of
// parents
void rebalance_up(heap_t* h, int ix) {
    if (ix == 0) {
        // ix is the root node; we're done
    } else if ((0 < ix) && (ix < LIMIT) && (ix < h->next)) {
        // ix is a valid non-root node
	// see if value at ix is bigger than value of parent
	// if so, swap them and recurse
	if (h->data[parent(ix)] < h->data[ix]) {
            swap(&(h->data[parent(ix)]), &(h->data[ix]));
            rebalance_up(h, parent(ix));
	}
    } else {
        // invalid node
	printf("***ERROR*** Attempting to rebalance node %d\n", ix);
    }
    return;
}

// node at ix of heap *h may be out of place because it 
// was just added. Bubble down through its chain of 
// children
void rebalance_down(heap_t* h, int ix) {
    int left;
    int right;

    if ((0 <= ix) && (ix < LIMIT) && (ix < h->next)) {
        // ix is a valid node
	// see if value at ix is smaller than the value of 
	// children of ix. If so, swap them and recurse down.
	// Note that if the left child is null, then so is 
	// the right child
	if (is_null(h, left_child(ix))) {
	    // both left and right children are NULL
	    // this is a leaf node, so we're done. 
	} else if (is_null(h, right_child(ix))) {
	    // left child is not null, but right child is null
	    // So we know the left child is a leaf. We either 
	    // swap with the left child or not. 
	    left = left_child(ix);
	    if (h->data[left] > h->data[ix]) {
	        swap(&(h->data[left]), &(h->data[ix]));
	    }
	} else {
            // both children exist. Find the largest one.
	    left = left_child(ix);
	    right = right_child(ix);
	    if (h->data[left] > h->data[right]) {
                // left child is biggest. Should we swap?
		if (h->data[left] > h->data[ix]) {
		    swap(&(h->data[left]), &(h->data[ix]));
		    rebalance_down(h, left);
                }
	    } else {
                // right child is biggest. Should we swap?
	        if (h->data[right] > h->data[ix]) {
		    swap(&(h->data[right]), &(h->data[ix]));
		    rebalance_down(h, right);
                }
	    }
	}
    } else {
	printf("***ERROR*** Attempting to rebalance node %d\n", ix);
    }
}

// initialize the heap *h to empty
void heap_init(heap_t* h) {
    h->next = 0;
    return;
}

// push an integer d onto the heap *h
void push(heap_t* h, int d) {
    if (is_full(h)) {
        // overflow of heap
	printf("***ERROR*** cannot push data &d because heap is full\n", d);
    } else {
        // put d in the heap and increment the size of the heap
	h->data[(h->next)++] = d;

	// rebalance the new node by comparing to its parent
	rebalance_up(h, (h->next)-1);
    }
}

// pop off the biggest value at heap *h
int pop(heap_t* h) {
    int result;

    if (is_empty(h)) {
        // underflow of heap
	printf("***ERROR*** Cannot pop because heap is empty\n");
	result = RAND_RANGE+1; // an obviously illegal return value
    } else {
	// get top of heap
	result = h->data[0];

	if (h->next <= 1) {
	    // we just removed the last element of the heap
	    h->next = 0;
	} else {
	    // move the last element of the heap to the top and rebalance
	    h->data[0] = h->data[h->next-1];
	    (h->next)--;
	    rebalance_down(h, 0);
	}
    }
    return result;
}

// ===================== MAIN PROGRAM ====================
int main() {
    int source[MAX_INPUT]; 	// array to hold input data values
    int dest[MAX_INPUT]; 	// array to hold sorted data values

    int i;			// loop variable
    int j; 			// loop variable

    heap_t heap;		// our heap
    heap_init(&heap);		// initialize to empty

    // seed random number generator
    srand((unsigned)time(NULL));

    // initialize source array with random number
    // from 0..RAND_RANGE
    for (i=0; i<MAX_INPUT; ++i) {
        source[i] = rand() % RAND_RANGE;
    }

    // printout source array in rows of 20 elements
    printf("Source array:\n");
    for (i=0; i < ((MAX_INPUT/20)+1); ++i) {
        for (j=0; j < 20; ++j) {
            if (i*20+j < MAX_INPUT) {
	        printf("%.2d ", source[i*20+j]);
	    }
	}
	printf("\n");
    }
    printf("\n");
    
    // push elements of source array into heap
    for (i=0; i<MAX_INPUT; ++i) {
        push(&heap, source[i]);
    }

    // pop elements out of heap into dest array
    for (i=0; i<MAX_INPUT; ++i) {
        dest[i] = pop(&heap);
    }

    // print out destination array in rows of 20
    printf("Destination array:\n");
    for (i=0; i < ((MAX_INPUT/20)+1); ++i) {
        for (j=0; j < 20; ++j) {
            if (i*20+j < MAX_INPUT) {
	        printf("%.2d ", dest[i*20+j]);
	    }
	}
	printf("\n");
    }
    printf("\n");
    
    return 0;
}




