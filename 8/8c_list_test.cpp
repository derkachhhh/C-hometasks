#include "8c_list.h"
#include <gtest/gtest.h>

// Тест для перевірки створення списку
TEST(CListTest, CreateList) {
    c_list *list = create_list(5); // Створюємо список із початковою місткістю 5
    ASSERT_NE(list, nullptr); // Перевіряємо, що список був успішно створений
    EXPECT_EQ(list->size, 0); // Початковий розмір списку має бути 0
    EXPECT_EQ(list->capacity, 5); // Початкова місткість списку має бути 5
    list->destroy(list); // Звільняємо пам'ять після тесту
}

// Тест для перевірки додавання елементів у список
TEST(CListTest, AppendItems) {
    c_list *list = create_list(2); // Створюємо список із початковою місткістю 2
    int a = 10, b = 20; // Цілі числа для додавання
    float c = 3.14;     // Число з плаваючою точкою
    list->append(list, &a, int_type); // Додаємо ціле число 15
    list->append(list, &b, int_type); // Додаємо ціле число 25
    list->append(list, &c, float_type); // Додаємо число 3.14
    EXPECT_EQ(list->size, 3); // Перевіряємо, що список містить 3 елементи
    EXPECT_EQ(*(int *)list->items[0], 10); // Перший елемент має бути 15
    EXPECT_EQ(*(int *)list->items[1], 20); // Другий елемент має бути 25
    EXPECT_NEAR(*(float *)list->items[2], 3.14f, 0.001); // Третій елемент має бути 3.14
    list->destroy(list); // Звільняємо пам'ять після тесту
}

// Тест для перевірки очищення списку
TEST(CListTest, ClearList) {
    c_list *list = create_list(2); // Створюємо список із початковою місткістю 2
    int a = 10, b = 20; // Цілі числа для додавання
    list->append(list, &a, int_type); // Додаємо ціле число 15
    list->append(list, &b, int_type); // Додаємо ціле число 25
    list->clear(list); // Очищаємо список
    EXPECT_EQ(list->size, 0); // Після очищення розмір списку має бути 0
    list->destroy(list); // Звільняємо пам'ять після тесту
}

// Тест для перевірки копіювання списку
TEST(CListTest, CopyList) {
    c_list *list = create_list(2); // Створюємо список із початковою місткістю 2
    int a = 10, b = 20; // Цілі числа для додавання
    list->append(list, &a, int_type); // Додаємо ціле число 15
    list->append(list, &b, int_type); // Додаємо ціле число 25
    c_list *copy = list->copy(list); // Копіюємо список
    EXPECT_EQ(copy->size, 2); // Перевіряємо, що копія має 2 елементи
    EXPECT_EQ(*(int *)copy->items[0], 10); // Перший елемент копії має бути 15
    EXPECT_EQ(*(int *)copy->items[1], 20); // Другий елемент копії має бути 25
    list->destroy(list); // Звільняємо пам'ять для оригінального списку
    copy->destroy(copy); // Звільняємо пам'ять для копії
}

// Головна функція для запуску тестів
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Ініціалізуємо Google Test
    return RUN_ALL_TESTS(); // Запускаємо всі тести
}
