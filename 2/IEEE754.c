#include <stdio.h>
#include <float.h>
#include <math.h>

// Функція для отримання значення від користувача
float get_number() {
    float number = 0;
    printf("Введіть дійсне число: ");
    scanf("%f", &number);
    return number;
}

// Функція для визначення знаку числа
char determine_sign(float number) {
    return (signbit(number)) ? '-' : '+';
}

int main() {
    // Ввід числа користувачем
    float input_number = get_number();  // додано пропущену крапку з комою

    // Обробка знаку числа
    char sign = determine_sign(input_number);
    printf("Біт знаку: %c\n", sign);

    // Обчислення порядку (експоненти) з використанням функції ilogb
    int exponent = ilogb(input_number);
    printf("Значення порядку: %d\n", exponent);

    // Обчислення мантиси шляхом нормалізації числа
    float mantissa = input_number / scalbn(1.0, exponent) - 1;
    printf("Значення мантиси: %f\n", mantissa);

    // Виведення відновленого числа
    float reconstructed_number = (1.0 + mantissa) * pow(2, exponent);
    printf("Відновлене значення: (1.0 + %f) * 2**%d = %f\n", mantissa, exponent, reconstructed_number);

    return 0;
}

