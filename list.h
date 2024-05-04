#ifndef LIST_H
#define LIST_H

#include "student.h"

typedef struct List {
    struct Studentik* head;
    struct Studentik* tl;
    int SIZE;
    void (*append)(struct List*, struct Studentik*);
    void (*print)(struct List*);
    void (*get)(struct List*);
} List;

struct List* init();
void l_append(struct List*, struct Studentik*);
void l_print(struct List*);
void l_get(struct List*);

#endif // LIST_H