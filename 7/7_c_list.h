#ifndef C_LIST_H
#define C_LIST_H

#include <stddef.h> // Для size_t

// Типи даних
typedef enum {
    int_type,
    float_type,
    string_type
} list_data_type;

// Структура для списку
typedef struct {
    void **items;           // Масив елементів
    list_data_type *types;  // Масив типів елементів
    size_t size;            // Поточний розмір списку
    size_t capacity;        // Поточна місткість списку
} c_list;

// Прототипи функцій
c_list *create_list(size_t initial_capacity); // Створення списку
void append(c_list *list, void *item, list_data_type type); // Додавання елемента
void *pop(c_list *list); // Видалення останнього елемента
void print_list(const c_list *list); // Виведення списку
void destroy_list(c_list *list); // Звільнення пам'яті
void sort_list(c_list *list); // Сортування списку

#endif // C_LIST_H
