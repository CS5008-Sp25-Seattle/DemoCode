#include <stdio.h>

typedef struct Student {
    int age;
    int id;
    char campus; //B=Boston, V=Vancouver, S=Seattle, P=Portland
} Student_t;

int main() {
    int i;

    // declare a student variable
    Student_t my_classroom[3];

    // initialize it
    my_classroom[0].age = 20;
    my_classroom[0].id = 334455;
    my_classroom[0].campus = 'S';

    my_classroom[1].age = 21;
    my_classroom[1].id = 223344;
    my_classroom[1].campus = 'B';

    my_classroom[2].age = 22;
    my_classroom[2].id = 112233;
    my_classroom[2].campus = 'V';

    for (i=0; i<3; ++i) {
    
        printf("Student number %d, %d years old, campus %c\n",
            my_classroom[i].id, 
	    my_classroom[i].age, 
	    my_classroom[i].campus);
    }

    return 0;
}

