//Лабораторная работа №11.
//Тема: Бинарные деревья.
//Выполнить лабораторную работу №10 при помощи бинарных деревьев.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Studentik {
    char* surname;
    char* name;
    char* gender;
    int age;
    char* group;
    int Math;
    int Physics;
    int Chemistry;
    struct Studentik* left;
    struct Studentik* right;
};

void tree_insert(struct Studentik**, struct Studentik*);
void find_students(struct Studentik*, char*, int, int, int);
void print_tree(struct Studentik*);
void find_excellent_students(struct Studentik*, char*);

void tree_insert(struct Studentik** root, struct Studentik* stud) {
    if (*root == NULL) {
        *root = stud;
    } else {
        if (strcmp(stud->surname, (*root)->surname) < 0) {
            tree_insert(&(*root)->left, stud);
        } else {
            tree_insert(&(*root)->right, stud);
        }
    }
}

void find_students(struct Studentik* root, char* group, int Math, int Physics, int Chemistry) {
    if (root != NULL) {
        find_students(root->left, group, Math, Physics, Chemistry);
        if (strcmp(root->group, group) == 0 && root->Math == Math && root->Physics == Physics && root->Chemistry == Chemistry) {
            printf("%s %s %s %s %d %d %d %d\n", root->name, root->surname, root->gender, root->group, root->age, root->Math, root->Physics, root->Chemistry);
        }
        find_students(root->right, group, Math, Physics, Chemistry);
    }
}

void print_tree(struct Studentik* root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%s %s %s %s %d %d %d %d\n", root->name, root->surname, root->gender, root->group, root->age, root->Math, root->Physics, root->Chemistry);
        print_tree(root->right);
    }
}

void find_excellent_students(struct Studentik* root, char* group) {
    if (root != NULL) {
        find_excellent_students(root->left, group);
        if (strcmp(root->group, group) == 0 && root->Math == 5 && root->Physics == 5 && root->Chemistry == 5) {
            printf("%s %s %s %s %d %d %d %d\n", root->name, root->surname, root->gender, root->group, root->age, root->Math, root->Physics, root->Chemistry);
        }
        find_excellent_students(root->right, group);
    }
}

int main() {
    struct Studentik* root = NULL;

    char* students[][8] = {
            {"Иванов", "Алексей", "м", "МАТ-301", "14", "3", "4", "5"},
            {"Петрова", "Елена", "ж", "ФИЗ-101", "12", "5", "4", "3"},
            {"Сидоров", "Дмитрий", "м", "ИСП-204", "15", "4", "3", "5"},
            {"Козлова", "Анна", "ж", "ФИЛ-102", "13", "3", "4", "4"},
            {"Морозов", "Игорь", "м", "МЕХ-203", "12", "4", "3", "5"},
            {"Смирнова", "Ольга", "ж", "ИСП-201", "13", "5", "5", "5"},
            {"Лебедев", "Сергей", "м", "ФИЗ-101", "12", "4", "4", "3"}
    };

    for (int i = 0; i < sizeof(students) / sizeof(students[0]); ++i) {
        struct Studentik* stud = malloc(sizeof(struct Studentik));
        stud->name = students[i][1];
        stud->surname = students[i][0];
        stud->gender = students[i][2];
        stud->age = atoi(students[i][4]);
        stud->group = students[i][3];
        stud->Math = atoi(students[i][5]);
        stud->Physics = atoi(students[i][6]);
        stud->Chemistry = atoi(students[i][7]);
        stud->left = NULL;
        stud->right = NULL;
        tree_insert(&root, stud);
    }

    printf("All students:\n");
    print_tree(root);

    printf("\nExcellent students in group ИСП-201:\n");
    find_excellent_students(root, "ИСП-201");

    return 0;
}
