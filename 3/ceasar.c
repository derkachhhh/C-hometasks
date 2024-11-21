#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Функція для шифрування символу
void encryptCharacter(char character, int key) {
    if (isalpha(character)) { // Перевірка чи є символ літерою
        char base = islower(character) ? 'a' : 'A'; // Визначення бази для малих або великих літер
        char encrypted = (character - base + key) % 26; // Шифрування символу
        if (encrypted < 0) {
            encrypted += 26; // Коригування від'ємних значень
        }
        encrypted += base; // Додавання бази до зашифрованого символу
        printf("Зашифрований символ: %c\n", encrypted); // Виведення зашифрованого символу
    } else {
        printf("Невірний ввід: має бути дійсним алфавітним символом\n"); // Повідомлення про невірний ввід
    }
}

int main() {
    int numChars;
    int key;

    printf("Введіть кількість символів для шифрування: ");
    if (scanf("%d", &numChars) != 1 || numChars <= 0) {
        printf("Невірний ввід. Вихід...\n");
        return 1;
    }

    srand(time(NULL)); // Ініціалізація генератора випадкових чисел
    key = rand() % 513 - 256; // Генерація випадкового ключа шифрування в діапазоні від -256 до 256
    printf("Згенерований ключ шифрування: %d\n", key);

    for (int i = 0; i < numChars; i++) {
        printf("Введіть символ %d: ", i + 1);
        char character;
        scanf(" %c", &character); // Зчитування символу
        encryptCharacter(character, key); // Шифрування символу
    }

    return 0;
}
