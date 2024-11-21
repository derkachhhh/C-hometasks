#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

// Функція для заповнення масиву випадковими числами
void fillArray(int array[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            array[i][j] = rand() % 100;  // Генеруємо випадкові числа від 0 до 99
        }
    }
}

// Функція для виведення масиву на екран
void printArray(int array[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", array[i][j]);  // Виводимо кожен елемент масиву
        }
        printf("\n");  // Перехід на новий рядок після кожного рядка масиву
    }
}

// Функція для транспонування масиву на місці
void transposeInPlace(int array[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Міняємо місцями елементи масиву
            int temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }
}

int main() {
    int array[N][N];  // Оголошення двовимірного масиву

    // Ініціалізація генератора випадкових чисел
    srand(time(NULL));

    // Заповнення масиву випадковими числами
    fillArray(array);
    
    // Виведення оригінального масиву
    printf("Original Array:\n");
    printArray(array);
    
    // Транспонування масиву на місці
    transposeInPlace(array);
    
    // Виведення транспонованого масиву
    printf("\nTransposed Array:\n");
    printArray(array);

    return 0;
}
