#include <stdio.h>
#include <math.h>
#include "bisection.h"

// Функція для знаходження перетину за методом бісекції
float bisection(float a1, float b1, float a2, float b2, float *x, float *y) {
    float left = -M_PI, right = M_PI;  // Встановлення початкового інтервалу для методу бісекції
    float mid, f1, f2;

    // Перевірка, чи значення функцій на межах інтервалу мають різні знаки
    f1 = a1 * sin(left) - b1;
    f2 = a2 * cos(left) - b2;
    float f1_right = a1 * sin(right) - b1;
    float f2_right = a2 * cos(right) - b2;

    if (f1 * f1_right > 0 || f2 * f2_right > 0) {
        printf("Функції не мають перетину в заданому інтервалі.\n");
        return 0;
    }

    // Виконання бісекції
    while ((right - left) > 0.0001) { // Продовжуємо, поки інтервал не стане достатньо малим
        mid = (left + right) / 2;
        
        // Обчислюємо значення функцій у точці mid
        f1 = a1 * sin(mid) - b1;
        f2 = a2 * cos(mid) - b2;

        // Якщо значення функцій близькі до нуля, то ми знайшли перетин
        if (fabs(f1 - f2) < 0.0001) {
            *x = mid;
            *y = a1 * sin(*x);  // Обчислюємо y за допомогою першої функції
            return 1; // Перетин знайдено
        }

        // Оновлюємо інтервал для бісекції
        if ((f1 - f2) > 0) {
            left = mid;
        } else {
            right = mid;
        }
    }

    return 0;  // Перетину не знайдено в межах заданого діапазону
}
