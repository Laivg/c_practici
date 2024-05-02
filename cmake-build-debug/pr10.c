//Лабораторная работа №10
//Тема: Структуры
//Разработать структуру "Студент", в состав которой входят следующие свойства:
//Фамилия, Имя, Пол, Возраст, Группа, Оценка по математике, Оценка по физике,
//Оценка по химии. Структура обязана содержать в себе все функции,
//которые принимают объект этой структуры в качестве входного параметра (не прям все, а по аналогии с указателем this в ООП).
//Вывод в консоль должен содержать в себе исходные данные и результат. Использование статических и динамических массивов,
//состоящих из объектов структур, ЗАПРЕЩАЕТСЯ (можно списки/стеки и любые другие типы коллекций на свое усмотрение).
// 11.Вывести отличников определённой группы;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




struct Studentik{
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

struct List {
    struct Studentik* head;
    struct Studentik* tl;
    int SIZE;
    void (*append)(struct List*,struct Studentik*);
    void (*print)(struct List*);
    void(*get)(struct  List*);

};

void l_append(struct List*,struct Studentik*);
void l_print(struct List*);
void l_get(struct  List*);

void l_append(struct List* list,struct Studentik* stud){
    if(list->SIZE==0) {
        list->head = stud;
        list->tl = list->head;
    }
    else{
        list-> tl ->next = stud;
        list->tl = stud;
    }
    list-> SIZE++;
}

void l_print(struct List* list){
    struct Studentik* pr = list->head;
    for (int i = 0; i < list->SIZE; ++i) {
        printf("%s %s %s %s %d %d %d %d\n",pr->name,pr->surname,pr->gender,pr->group,pr->age,pr->Math,pr->Physics,pr->Chemistry);
        pr= pr->next;
    }
}

void l_get(struct  List* list){
    struct Studentik* gt = list->head;
    for (int i = 0; i < list->SIZE; ++i) {
        if (strcmp(gt->group,"ИСП-201")== 0 && gt->Math && gt->Physics && gt->Chemistry ==5 )
            printf("%s %s %s %s %d %d %d %d\n",gt->name,gt->surname,gt->gender,gt->group,gt->age,gt->Math,gt->Physics,gt->Chemistry);
        else gt= gt->next;
    }
}

struct List* init(){
    struct List* list = malloc(sizeof(struct List) );
    list->head = NULL;
    list->tl = NULL;
    list->SIZE = 0;
    list->append = l_append;
    list->print = l_print;
    list->get = l_get;

    return list;
}

struct Studentik* iinit(char** data){
    struct Studentik* studentik = malloc(sizeof (struct Studentik));
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

void main(){
    system("chcp 65001");
    char* students[][8] = {
            {"Иванов","Алексей","м","МАТ-301","14","3","4","5"},
            {"Петрова","Елена","ж","ФИЗ-101","12","5","4","3"},
            {"Сидоров","Дмитрий","м","ИСП-204","15","4","3","5"},
            {"Козлова","Анна","ж","ФИЛ-102","13","3","4","4"},
            {"Морозов","Игорь","м","МЕХ-203","12","4","3","5"},
            {"Смирнова","Ольга","ж","ИСП-201","13","5","5","5"},
            {"Лебедев","Сергей","м","ФИЗ-101","12","4","4","3"}
    };
    struct List* list = init();

    for (int i = 0; i <sizeof(students)/sizeof(students[0]);++i) {
        list->append(list, iinit(students[i]));
    }
   // list->print(list);
    list->get(list);
    
}