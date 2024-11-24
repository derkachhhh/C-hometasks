#include "8c_list.h"
#include <stdio.h>

int main() {
    // Створюємо список із початковою місткістю 5
    c_list *list = create_list(5);

    // Додаємо елементи
    int a = 35, b = 15, c = 25;
    list->append(list, &a, int_type); // Додаємо 35
    list->append(list, &b, int_type); // Додаємо 15
    list->append(list, &c, int_type); // Додаємо 25

    // Виводимо список
    printf("Список:\n");
    list->print(list);

    // Звільняємо пам'ять
    list->destroy(list);

    return 0;
}
