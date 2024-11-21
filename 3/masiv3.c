#include <stdio.h>

// Функція для генерації шаблону
void generatePattern(int N) {
    // Зовнішній цикл для проходу по рядках
    for (int i = 0; i < N; i++) {
        // Внутрішній цикл для проходу по стовпцях
        for (int j = 0; j < N; j++) {
            if (N % 2 != 0) { 
                // Якщо N непарне, використовуємо шаблон з зірочками для діагоналей і середини
                if (i == j || i + j == N - 1 || i == N / 2 || j == N / 2) {
                    // Якщо індекси рядка і стовпця однакові (діагональ зліва направо)
                    // або сума індексів дорівнює N-1 (діагональ справа наліво),
                    // або індекс рядка/стовпця дорівнює середньому рядку/стовпцю, виводимо зірочку
                    printf("* ");
                } else {
                    // Якщо жодна з умов не виконана, виводимо пробіл
                    printf("  ");
                }
            } else {
                // Якщо N парне, використовуємо шаблон з знаками = і +
                if ((i + j) % 2 == 0) {
                    // Якщо сума індексів парна, виводимо знак =
                    printf("= ");
                } else {
                    // Якщо сума індексів непарна, виводимо знак +
                    printf("+ ");
                }
            }
        }
        
        printf("\n");
    }
}

int main() {
    int N;
    // Просимо користувача ввести значення N
    printf("Введіть значення N: ");
    scanf("%d", &N);  // Зчитуємо значення N з консолі
    generatePattern(N);  // Викликаємо функцію для генерації шаблону з заданим N
    return 0;  // Завершення програми
}
