#include "bisection.h"
#include <stdio.h>

int main() {
    float a1, b1, a2, b2, x, y;

    printf("Введіть коефіцієнти для першого рівняння (a1 b1 для f(x) = a1 * sin(x) + b1): ");
    scanf("%f %f", &a1, &b1);
    
    printf("Введіть коефіцієнти для другого рівняння (a2 b2 для g(x) = a2 * cos(x) + b2): ");
    scanf("%f %f", &a2, &b2);
    
    // Знаходимо перетин за допомогою методу бісекції
    if (bisection(a1, b1, a2, b2, &x, &y) == 1) {
        printf("Перетин знайдений в точці x = %.3f, y = %.3f\n", x, y);
    } else {
        printf("Перетин не знайдений у заданому діапазоні.\n");
    }

    return 0;
}
