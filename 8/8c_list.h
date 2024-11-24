
#define C_LIST_H

#include <stddef.h> // Для size_t

#ifdef __cplusplus
extern "C" {
#endif

// Тип даних
typedef enum {
    int_type,
    float_type,
    string_type
} list_data_type;

// Структура c_list
typedef struct c_list {
    void **items;           // Динамічний масив елементів
    list_data_type *types;  // Масив типів даних
    size_t size;            // Поточний розмір списку
    size_t capacity;        // Поточна місткість списку

    // Функції для роботи зі списком
    void (*append)(struct c_list *list, void *item, list_data_type type);
    void (*pop)(struct c_list *list);
    void (*destroy)(struct c_list *list);
    void (*print)(const struct c_list *list);

    // Додаткові функції
    struct c_list *(*copy)(const struct c_list *list);
    void (*clear)(struct c_list *list);
} c_list;

// Оголошення функцій
c_list *create_list(size_t initial_capacity);
void append(c_list *list, void *item, list_data_type type);
void pop(c_list *list);
void destroy(c_list *list);
void print_list(const c_list *list);
c_list *copy_list(const c_list *list);
void clear_list(c_list *list);

#ifdef __cplusplus
}
#endif

