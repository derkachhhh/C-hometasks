#include <stdio.h>
#include <assert.h>
#include "7_c_list.h"

int main() {
    // Створюємо список
    void** dynamic_list = create();
    if (!dynamic_list) {
        printf("Не вдалося створити список.\n");
        return 1;
    }

    int list_size = 0;

    // Додаємо елементи до списку
    int integer_value = -6;
    dynamic_list = append(dynamic_list, &list_size, &integer_value, int_type); // Оновлюємо вказівник після append

    float float_value = 0.1;
    dynamic_list = append(dynamic_list, &list_size, &float_value, float_type); // Оновлюємо вказівник після append

    char* string_value = "string_type";
    dynamic_list = append(dynamic_list, &list_size, string_value, string_type); // Оновлюємо вказівник після append

    // Виводимо список
    printf("Оригінальний список:\n");
    print((const void**)dynamic_list, list_size);

    // Видаляємо останній елемент
    dynamic_list = pop(dynamic_list, &list_size); // Оновлюємо вказівник після pop
    printf("Список після pop:\n");
    print((const void**)dynamic_list, list_size);

    // Звільняємо пам'ять
    destroy(dynamic_list, list_size);

    return 0;
}
