#include "8c_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Створення списку
c_list *create_list(size_t initial_capacity) {
    // Виділяємо пам'ять для структури списку
    c_list *list = malloc(sizeof(c_list));
    if (!list) { // Перевіряємо, чи успішно виділена пам'ять
        perror("Не вдалося виділити пам'ять для структури"); // Виводимо повідомлення про помилку
        exit(EXIT_FAILURE); // Завершуємо програму
    }

    // Виділяємо пам'ять для динамічного масиву елементів
    list->items = malloc(initial_capacity * sizeof(void *));
    // Виділяємо пам'ять для типів елементів
    list->types = malloc(initial_capacity * sizeof(list_data_type));

    // Перевірка, чи успішно виділена пам'ять для обох масивів
    if (!list->items || !list->types) {
        perror("Не вдалося виділити пам'ять для елементів або типів");
        free(list); // Звільняємо пам'ять для структури, якщо виділення не вдалося
        exit(EXIT_FAILURE);
    }

    // Ініціалізація полів списку
    list->size = 0;                     // Початковий розмір списку — 0
    list->capacity = initial_capacity;  // Початкова місткість списку

     // Прив'язуємо функції до відповідних методів списку
    list->append = append;              // Додавання нового елемента до списку
    list->pop = pop;                    // Видалення останнього елемента зі списку
    list->destroy = destroy;            // Повне звільнення пам'яті, виділеної для списку
    list->print = print_list;           // Виведення вмісту списку
    list->copy = copy_list;             // Створення копії списку
    list->clear = clear_list;           // Очищення всіх елементів списку

    return list;                        // Повертаємо вказівник на створений список

}

// Додавання елемента
void append(c_list *list, void *item, list_data_type type) {
    // Перевіряємо, чи є місце для нового елемента
    if (list->size == list->capacity) {
        // Подвоюємо місткість списку
        list->capacity *= 2;
        // Розширюємо пам'ять для масиву елементів
        list->items = realloc(list->items, list->capacity * sizeof(void *));
        // Розширюємо пам'ять для масиву типів
        list->types = realloc(list->types, list->capacity * sizeof(list_data_type));
        // Перевіряємо, чи успішно виділена пам'ять
        if (!list->items || !list->types) {
            perror("Не вдалося розширити пам'ять"); // Виводимо повідомлення про помилку
            exit(EXIT_FAILURE); // Завершуємо програму
        }
    }

    // Ініціалізуємо новий елемент залежно від його типу
    void *new_item = NULL; // Вказівник на новий елемент
    switch (type) {
        case int_type:
            new_item = malloc(sizeof(int)); // Виділяємо пам'ять для цілого числа
            if (new_item) *(int *)new_item = *(int *)item; // Копіюємо значення
            break;
        case float_type:
            new_item = malloc(sizeof(float)); // Виділяємо пам'ять для числа з плаваючою точкою
            if (new_item) *(float *)new_item = *(float *)item; // Копіюємо значення
            break;
        case string_type:
            new_item = strdup((char *)item); // Копіюємо рядок
            break;
    }

    // Перевіряємо, чи вдалося створити новий елемент
    if (!new_item) {
        perror("Не вдалося скопіювати елемент"); // Виводимо повідомлення про помилку
        exit(EXIT_FAILURE); // Завершуємо програму
    }

    // Додаємо елемент у список
    list->items[list->size] = new_item; // Зберігаємо вказівник на новий елемент
    list->types[list->size] = type;    // Зберігаємо тип нового елемента
    list->size++; // Збільшуємо розмір списку
}

// Видалення останнього елемента
void pop(c_list *list) {
    // Перевіряємо, чи є елементи у списку
    if (list->size > 0) {
        list->size--; // Зменшуємо розмір списку
        free(list->items[list->size]); // Звільняємо пам'ять для останнього елемента
    }
}

// Звільнення пам'яті
void destroy(c_list *list) {
    clear_list(list); // Очищаємо всі елементи списку
    free(list->items); // Звільняємо пам'ять для масиву елементів
    free(list->types); // Звільняємо пам'ять для масиву типів
    free(list);        // Звільняємо пам'ять для структури списку
}

// Виведення списку
void print_list(const c_list *list) {
    for (size_t i = 0; i < list->size; i++) { // Перебираємо всі елементи списку
        switch (list->types[i]) { // Визначаємо тип кожного елемента
            case int_type:
                printf("%d ", *(int *)list->items[i]); // Виводимо ціле число
                break;
            case float_type:
                printf("%f ", *(float *)list->items[i]); // Виводимо число з плаваючою точкою
                break;
            case string_type:
                printf("%s ", (char *)list->items[i]); // Виводимо рядок
                break;
        }
    }
    printf("\n"); // Завершуємо рядок
}

// Копіювання списку
c_list *copy_list(const c_list *list) {
    // Створюємо новий список із такою ж місткістю
    c_list *new_list = create_list(list->capacity);
    for (size_t i = 0; i < list->size; i++) {
        // Копіюємо кожен елемент і додаємо у новий список
        new_list->append(new_list, list->items[i], list->types[i]);
    }
    return new_list; // Повертаємо вказівник на новий список
}

// Очищення списку
void clear_list(c_list *list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->items[i]); // Звільняємо пам'ять для кожного елемента
    }
    list->size = 0; // Скидаємо розмір списку до 0
}
