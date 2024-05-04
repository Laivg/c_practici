#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

struct Studentik* iinit(char** data){
    struct Studentik* studentik = malloc(sizeof(struct Studentik));
    studentik->name = data[0];
    studentik->surname = data[1];
    studentik->gender = data[2];
    studentik->age = atoi(data[4]);
    studentik->group = data[3];
    studentik->Math = atoi(data[5]);
    studentik->Physics = atoi(data[6]);
    studentik->Chemistry = atoi(data[7]);

    return studentik;
}