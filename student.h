#ifndef STUDENT_H
#define STUDENT_H

struct Studentik {
    char* surname;
    char* name;
    char* gender;
    int age;
    char* group;
    int Math;
    int Physics;
    int Chemistry;
    struct Studentik* next;
};

struct Studentik* iinit(char** data);

#endif // STUDENT_H