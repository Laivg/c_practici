#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
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
    List* list = init();

    for (int i = 0; i < sizeof(students) / sizeof(students[0]); ++i) {
        list->append(list, iinit(students[i]));
    }

    // list->print(list);
    list->get(list);

    system("pause");
    return 0;
}
