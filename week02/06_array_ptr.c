#include <stdio.h>

typedef struct Student {
    int age;
    int id;
    char campus; //B=Bos, V=Van, S=Sea, P=Ptland
} Student_t;

int main() {
    int i;

    // declare a student array variable
    Student_t my_classroom[3];

    // now lets create a pointer to a student
    Student_t* a_student_p;

    // initialize the student struct
    my_classroom[0].age = 20;
    my_classroom[0].id = 334455;
    my_classroom[0].campus = 'S';

    my_classroom[1].age = 21;
    my_classroom[1].id = 223344;
    my_classroom[1].campus = 'B';

    my_classroom[2].age = 22;
    my_classroom[2].id = 112233;
    my_classroom[2].campus = 'V';

    a_student_p = &(my_classroom[1]);

    printf("Student number %d, %d years old, campus %c\n",
        a_student_p->id, 
	a_student_p->age, 
	a_student_p->campus);

    return 0;
}

