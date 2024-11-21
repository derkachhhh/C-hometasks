#include "c_list.h"
#include <stdio.h>

// Функція для додавання елемента до списку
int add_to_list(void* list[], list_data_type list_type[], int current_size, void* item, list_data_type type) {
    list[current_size] = item;         // Додаємо елемент до списку
    list_type[current_size] = type;    // Зберігаємо тип елемента
    return current_size + 1;           // Повертаємо новий розмір списку
}

// Функція для виведення елементів списку
void display_list(const void* list[], const list_data_type list_type[], int size) {
    printf("Розмір списку = %d\n\n", size);

    // Проходимо через список і виводимо елементи в залежності від їх типу
    for (int i = 0; i < size; ++i) {
        switch (list_type[i]) {
            case int_type:
                printf("%d ", *(int*)list[i]);
                break;
            case float_type:
                printf("%f ", *(float*)list[i]);
                break;
            case string_type:
                printf("%s ", (char*)list[i]);
                break;
            default:
                printf("Невідомий тип\n");
        }
    }
    printf("\n");
}
