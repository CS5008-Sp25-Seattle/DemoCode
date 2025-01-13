#include <stdio.h>

typedef struct Student {
    int age;
    int id;
    char campus; //B=Bos, V=Van, S=Sea, P=Ptland
} Student_t;

int main() {
    int i;

    // declare a student variable
    Student_t my_student;

    // now lets create a pointer to a student
    Student_t* a_student_p;

    // initialize the student struct
    my_student.age = 20;
    my_student.id = 334455;
    my_student.campus = 'S';

    a_student_p = &(my_student);

    printf("Student number %d, %d years old, campus %c\n",
        (*a_student_p).id, 
	(*a_student_p).age, 
	(*a_student_p).campus);

    return 0;
}

