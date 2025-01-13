#include <stdio.h>

typedef struct Student {
    int age;
    int id;
    char campus; //B=Boston, V=Vancouver, S=Seattle, P=Portland
} Student_t;

int main() {
    int i;

    // declare a student variable
    Student_t my_student;

    // initialize it
    my_student.age = 20;
    my_student.id = 334455;
    my_student.campus = 'S';

    printf("Student number %d is %d years old and from campus %c\n",
		    my_student.id, my_student.age, my_student.campus);
    return 0;
}
