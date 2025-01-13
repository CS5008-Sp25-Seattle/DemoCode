#include <stdio.h> 
#include <stdbool.h>

#define MAXSIZE 100

int stack[MAXSIZE]; // array for stack
int top = -1;       // top valid stack location. 
                    // -1 means empty by convention

bool isEmpty() {
    // returns true if top = -1
    if (top < 0) {
        return true;
    } else {
        return false;
    }
}

bool isFull() {
    // returns true if no more room
    if (top >= MAXSIZE-1) {
        return true;
    } else {
        return false;
    }
}

void push(int v) {
    // put v onto the top of the stack unless it is already full
    if (!isFull()) {
	stack[++top] = v;
    } else {
        printf("*** attempt to push %d onto full stack ***\n", v);
    }
}

int pop() {
    // return the top entry in the stack unless stack is empty
    int returnval = 0;
    
    if (!isEmpty()) {
        returnval = stack[top--];
    } else {
	printf("*** attempt to pop empty stack ***\n");
    }
    return returnval;
}

int main() {
    printf("Pushing: 1, 2, 3, 4, 5\n\n");
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printf("Popping:\n");
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}


