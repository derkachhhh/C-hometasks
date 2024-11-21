#include "8c_list.h"
#include <gtest/gtest.h>

// Тест для створення списку
TEST(CListTest, CreateList) {
    c_list *list = create_list(5); // Створюємо список із початковою місткістю 5
    ASSERT_NE(list, nullptr); // Перевіряємо, що список створений (не є nullptr)
    EXPECT_EQ(list->size, 0); // Перевіряємо, що початковий розмір списку дорівнює 0
    EXPECT_EQ(list->capacity, 5); // Перевіряємо, що місткість списку дорівнює 5
    list->destroy(list); // Звільняємо пам'ять для списку
}

// Тест для додавання елементів
TEST(CListTest, AppendItems) {
    c_list *list = create_list(2); // Створюємо список із початковою місткістю 2
    int a = 10, b = 20; // Цілі числа для додавання
    float c = 3.14;     // Число з плаваючою точкою

    list->append(list, &a, int_type); // Додаємо перший елемент (ціле число)
    list->append(list, &b, int_type); // Додаємо другий елемент (ціле число)
    list->append(list, &c, float_type); // Додаємо третій елемент (float)

    EXPECT_EQ(list->size, 3); // Перевіряємо, що список містить 3 елементи
    EXPECT_EQ(*(int *)list->items[0], 10); // Перевіряємо, що перший елемент — 10
    EXPECT_EQ(*(int *)list->items[1], 20); // Перевіряємо, що другий елемент — 20
    EXPECT_EQ(*(float *)list->items[2], 3.14); // Перевіряємо, що третій елемент — 3.14

    list->destroy(list); // Звільняємо пам'ять для списку
}

// Тест для очищення списку
TEST(CListTest, ClearList) {
    c_list *list = create_list(2); // Створюємо список із початковою місткістю 2
    int a = 10, b = 20; // Цілі числа для додавання
    list->append(list, &a, int_type); // Додаємо перший елемент
    list->append(list, &b, int_type); // Додаємо другий елемент

    list->clear(list); // Очищаємо список

    EXPECT_EQ(list->size, 0); // Перевіряємо, що розмір списку став 0

    list->destroy(list); // Звільняємо пам'ять для списку
}

// Тест для копіювання списку
TEST(CListTest, CopyList) {
    c_list *list = create_list(2); // Створюємо список із початковою місткістю 2
    int a = 10, b = 20; // Цілі числа для додавання
    list->append(list, &a, int_type); // Додаємо перший елемент
    list->append(list, &b, int_type); // Додаємо другий елемент

    c_list *copied_list = list->copy(list); // Копіюємо список

    EXPECT_EQ(copied_list->size, 2); // Перевіряємо, що копія містить 2 елементи
    EXPECT_EQ(*(int *)copied_list->items[0], 10); // Перевіряємо, що перший елемент копії — 10
    EXPECT_EQ(*(int *)copied_list->items[1], 20); // Перевіряємо, що другий елемент копії — 20

    list->destroy(list); // Звільняємо пам'ять для оригінального списку
    copied_list->destroy(copied_list); // Звільняємо пам'ять для копії
}
