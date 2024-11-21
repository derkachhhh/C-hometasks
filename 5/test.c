#include <assert.h>
#include <stdio.h>
#include "bisection.h"

int bisect_test() {
    float x, y;

    // Тест 1: Перетин для f(x) = x * sin(x) і g(x) = x * cos(x)
    assert(bisection(1, 0, 1, 0, &x, &y) == 1); 
    assert(fabs(x - 0) < 0.0001); // Очікувана x-координата (перетин) наближена до 0
    assert(fabs(y - 0) < 0.0001); // Очікувана y-координата (перетин) наближена до 0

    // Тест 2: Немає перетину (Приклад, де sin(x) і cos(x) не можуть перетинатися з даними параметрами)
    assert(bisection(1, 0, 1, 10, &x, &y) == 0); 

    // Тест 3: Перевірка перетину в іншій точці
    assert(bisection(2, 0, 1, 0, &x, &y) == 1); 
    assert(fabs(x - 1.5708) < 0.0001);  // Очікуваний перетин біля pi/2
    assert(fabs(y - 0) < 0.0001); // Очікуваний y — наближений до 0

    printf("Усі тести пройдено успішно!\n");

    return 0;
}

int main() {
    bisect_test();
    return 0;
}
