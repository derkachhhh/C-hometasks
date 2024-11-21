#include "8c_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Створення списку
c_list *create_list(size_t initial_capacity) {
    // Виділяємо пам’ять для структури `c_list`
    c_list *list = malloc(sizeof(c_list));

    // Виділяємо пам’ять для масиву елементів (items) і їхніх типів (types)
    list->items = malloc(initial_capacity * sizeof(void *));
    list->types = malloc(initial_capacity * sizeof(list_data_type));

    // Ініціалізуємо початкові значення
    list->size = 0;               // Початковий розмір списку — 0
    list->capacity = initial_capacity; // Початкова місткість списку

    // Прив’язуємо функції до структури
    list->append = append;       // Додавання елементів
    list->pop = pop;             // Видалення останнього елемента
    list->destroy = destroy;     // Звільнення пам’яті
    list->print = print_list;    // Виведення списку
    list->copy = copy_list;      // Копіювання списку
    list->clear = clear_list;    // Очищення списку

    return list; // Повертаємо створений список
}

// Додавання елемента
void append(c_list *list, void *item, list_data_type type) {
    // Якщо список заповнений, збільшуємо його місткість
    if (list->size == list->capacity) {
        list->capacity *= 2; // Подвоюємо розмір списку
        list->items = realloc(list->items, list->capacity * sizeof(void *)); // Перевиділяємо пам’ять для елементів
        list->types = realloc(list->types, list->capacity * sizeof(list_data_type)); // Перевиділяємо пам’ять для типів
    }

    // Додаємо новий елемент і його тип у список
    list->items[list->size] = item;
    list->types[list->size] = type;
    list->size++; // Збільшуємо розмір списку
}

// Видалення останнього елемента
void pop(c_list *list) {
    if (list->size > 0) { // Якщо список не порожній
        list->size--;     // Зменшуємо розмір списку
    }
}

// Звільнення пам’яті
void destroy(c_list *list) {
    free(list->items); // Звільняємо пам’ять для масиву елементів
    free(list->types); // Звільняємо пам’ять для масиву типів
    free(list);        // Звільняємо пам’ять для структури списку
}

// Виведення списку
void print_list(const c_list *list) {
    for (size_t i = 0; i < list->size; i++) { // Перебираємо всі елементи
        switch (list->types[i]) {             // Перевіряємо тип кожного елемента
            case int_type:
                printf("%d ", *(int *)list->items[i]); // Виводимо цілі числа
                break;
            case float_type:
                printf("%f ", *(float *)list->items[i]); // Виводимо числа з плаваючою точкою
                break;
            case string_type:
                printf("%s ", (char *)list->items[i]); // Виводимо рядки
                break;
        }
    }
    printf("\n"); // Завершуємо рядок
}

// Копіювання списку
c_list *copy_list(const c_list *list) {
    // Створюємо новий список із такою ж місткістю
    c_list *new_list = create_list(list->capacity);

    // Копіюємо всі елементи та їхні типи
    for (size_t i = 0; i < list->size; i++) {
        new_list->items[i] = list->items[i]; // Копіюємо елементи
        new_list->types[i] = list->types[i]; // Копіюємо типи
    }

    // Оновлюємо розмір нового списку
    new_list->size = list->size;
    return new_list; // Повертаємо новий список
}

// Очищення списку
void clear_list(c_list *list) {
    list->size = 0; // Встановлюємо розмір списку в 0 (дані залишаються, але вважаються "видаленими")
}
