//Лабораторная работа №9
//Тема: Указатели на функции
//В качестве материала для работы используется соответствующий вариант из лабораторной работы №6.
//Для выполнения работы нужно:
//1. Прописать объявление функции отдельно от её инициализации;
//2. Создать указатели на все используемые функции;
//3. Использовать в работе созданные указатели вместо исходных функций.
//
//Отдельно необходимо создать массив с функциями с одинаковой сигнатурой и на его основе разработать калькулятор для двух чисел (операции +-*/).

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void fillArray(int arr[SIZE][SIZE]);
int countEvenNumbers(int arr[SIZE][SIZE]);
void replaceMinMax(int* a);
void determineEvenOdd(int number);
void massofevenorodd(int arr[SIZE][SIZE],int* a);
void calculator();

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main() {


    void (*determineEvenOddPtr)(int number)= &determineEvenOdd;
    void (*massofevenorodd1)(int arr[SIZE][SIZE],int* a)= &massofevenorodd;
    void (*calculator1)()= &calculator;


    int arr[SIZE][SIZE] ;
    int a[SIZE];
    int expression;

    printf("\nSelect calculator operation:\n");
    printf("1. random array\n");
    printf("2.odd or even\n");
    printf("3. calculator\n");
    printf("Enter operation number: ");
    scanf("%d", &expression);

    switch (expression) {
        case 1: massofevenorodd1( arr, a);
        break;
        case 2: {
            int userNumber;
            printf("Enter your number: ");
            scanf("%d", &userNumber);
            determineEvenOddPtr(userNumber);
            break;
        }
        case 3: calculator1();
            break;
    }




    return 0;
}

void fillArray(int arr[SIZE][SIZE]) {
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = rand() % 10;
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
        printf("\n");
    }
}

int countEvenNumbers(int arr[SIZE][SIZE]) {
    int even_count = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j += 2) {
            if ((arr[i][j] % 2 == 0) && (arr[i][j] >= 0)) {
                even_count++;
            }
        }
    }

    return even_count;
}

void replaceMinMax(int* a) {
    int max = 0, min = 0, k;

    for (int i = 0; i < SIZE; i++) {
        if (a[i] < a[min]) min = i;
        if (a[i] > a[max]) max = i;
    }

    k = a[min];
    a[min] = a[max];
    a[max] = k;
}

void determineEvenOdd(int number) {
    if (number == 0) {
        printf("Invalid value\n");
    } else if (number % 2 == 0) {
        printf("The number is even\n");
    } else {
        printf("The number is odd\n");
    }
}

void massofevenorodd(int arr[SIZE][SIZE],int* a) {




    void (*fillArrayPtr)(int arr[SIZE][SIZE])= fillArray;
    int (*countEvenNumbersPtr)(int arr[SIZE][SIZE])=countEvenNumbers;
    void (*replaceMinMaxPtr)(int* a)= replaceMinMax;

    fillArrayPtr(arr);
    int even_count = countEvenNumbersPtr(arr);
    printf("Even numbers: %d\n\n", even_count);

    for (int i = 0; i < SIZE; i++) {
        a[i] = rand() % 10;
        printf("%d\t", a[i]);
    }
    printf("\n");

    replaceMinMaxPtr(a);

    for (int i = 0; i < SIZE; i++)
        printf("%d\t", a[i]);

    printf("\n");

}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0)
        return a / b;
    else {
        printf("Error: Division by zero\n");
        return 0;
    }
}

void calculator() {
    int (*operation[SIZE])(int, int);

    operation[0] = &add;
    operation[1] = &subtract;
    operation[2] = &multiply;
    operation[3] = &divide;

    int choice;
    printf("\nSelect calculator operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter operation number: ");
    scanf("%d", &choice);

    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if (choice >= 1 && choice <= SIZE) {
        int result = operation[choice - 1](num1, num2);
        printf("Result: %d\n", result);
    } else {
        printf("Invalid operation choice.\n");
    }
}