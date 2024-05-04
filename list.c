#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>

void l_append(struct List* list, struct Studentik* stud) {
    if (list->SIZE == 0) {
        list->head = stud;
        list->tl = list->head;
    } else {
        list->tl->next = stud;
        list->tl = stud;
    }
    list->SIZE++;
}

void l_print(struct List* list) {
    struct Studentik* pr = list->head;
    for (int i = 0; i < list->SIZE; ++i) {
        printf("%s %s %s %s %d %d %d %d\n", pr->name, pr->surname, pr->gender, pr->group, pr->age, pr->Math, pr->Physics, pr->Chemistry);
        pr = pr->next;
    }
}

void l_get(struct List* list) {
    struct Studentik* gt = list->head;
    for (int i = 0; i < list->SIZE; ++i) {
        if (strcmp(gt->group, "ИСП-201") == 0 && gt->Math && gt->Physics && gt->Chemistry == 5)
            printf("%s %s %s %s %d %d %d %d\n", gt->name, gt->surname, gt->gender, gt->group, gt->age, gt->Math, gt->Physics, gt->Chemistry);
        else
            gt = gt->next;
    }
}

struct List* init() {
    struct List* list = malloc(sizeof(struct List));
    list->head = NULL;
    list->tl = NULL;
    list->SIZE = 0;
    list->append = l_append;
    list->print = l_print;
    list->get = l_get;

    return list;
}