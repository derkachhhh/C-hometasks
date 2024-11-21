#include <stdio.h>

// Функція для конвертації десяткового числа в бінарний формат
int decimal_to_binary(int decimal) {
    int binary = 0;
    int multiplier = 1;

    while (decimal > 0) {
        int remainder = decimal % 2;
        decimal /= 2;
        binary += remainder * multiplier;
        multiplier *= 10;
    }

    return binary;
}

// Основна функція для XOR-шифрування та дешифрування
void xor_cipher(int original_value, int key, int show_binary) {
    int encrypted = original_value ^ key;
    int decrypted = encrypted ^ key;

    if (show_binary) {
        printf("\nРезультати з бінарними значеннями:\n");
        printf("Оригінальне значення (Десяткове): %d\nБінарне: %d\n", original_value, decimal_to_binary(original_value));
        printf("Зашифроване значення (Десяткове): %d\nБінарне: %d\n", encrypted, decimal_to_binary(encrypted));
        printf("Дешифроване значення (Десяткове): %d\nБінарне: %d\n", decrypted, decimal_to_binary(decrypted));
    } else {
        printf("\nРезультати без бінарних значень:\n");
        printf("Оригінальне значення: %d\n", original_value);
        printf("Зашифроване значення: %d\n", encrypted);
        printf("Дешифроване значення: %d\n", decrypted);
    }
}

// Функція для введення значення
int input_value(const char* prompt) {
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    return value;
}

int main() {
    int value = input_value("Введіть значення: ");
    int key = input_value("Введіть ключ: ");
    int show_binary = input_value("Увімкнути відображення бітів? (1 - так, 0 - ні): ");
    
    xor_cipher(value, key, show_binary);

    return 0;
}
