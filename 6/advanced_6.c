#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Функція для заповнення масиву випадковими значеннями
void generate_array(int* arr) {
    srand(time(0));
    for (int i = 0; i < SIZE * SIZE; i++) {
        *(arr + i) = rand() % 11;
    }
}

// Функція для обробки нулів у масиві
void handle_zeros(int* arr) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (*(arr + i * SIZE + j) == 0) {
                // Заповнюємо весь рядок нулями
                for (int k = 0; k < SIZE; k++) {
                    *(arr + i * SIZE + k) = 0;
                }
                // Заповнюємо всю колонку нулями
                for (int k = 0; k < SIZE; k++) {
                    *(arr + k * SIZE + j) = 0;
                }
            }
        }
    }
}

// Функція для виведення масиву на екран
void display_array(int* arr) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", *(arr + i * SIZE + j));
        }
        printf("\n");
    }
}

int main() {
    int arr[SIZE][SIZE];
    generate_array((int*)arr);

    printf("Generated 2D array:\n");
    display_array((int*)arr);

    handle_zeros((int*)arr);

    printf("\nProcessed 2D array:\n");
    display_array((int*)arr);

    return 0;
}
