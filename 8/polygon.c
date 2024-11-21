#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для точки
typedef struct {
    int x, y; // Координати точки
} point_t;

// Структура для багатокутника
typedef struct {
    char *name;          // Назва багатокутника (динамічний рядок)
    int num_points;      // Кількість точок у багатокутнику
    point_t *points;     // Динамічний масив точок
} polygon_t;

// Функція для читання багатокутника з файлу
polygon_t *read_polygon(FILE *file) {
    char buffer[256]; // Буфер для зчитування рядка з назвою багатокутника

    // Зчитування назви багатокутника
    if (!fgets(buffer, sizeof(buffer), file)) return NULL; // Якщо не вдалося зчитати, повертаємо NULL

    buffer[strcspn(buffer, "\n")] = '\0'; // Видаляємо символ нового рядка

    polygon_t *polygon = malloc(sizeof(polygon_t)); // Виділяємо пам'ять для структури багатокутника
    polygon->name = strdup(buffer); // Копіюємо назву в пам'ять

    // Зчитування кількості точок
    if (fscanf(file, "%d\n", &polygon->num_points) != 1) { // Якщо не вдалося зчитати, звільняємо пам'ять
        free(polygon->name);
        free(polygon);
        return NULL;
    }

    // Виділення пам'яті для масиву точок
    polygon->points = malloc(polygon->num_points * sizeof(point_t));
    for (int i = 0; i < polygon->num_points; i++) {
        if (fscanf(file, "%d %d\n", &polygon->points[i].x, &polygon->points[i].y) != 2) { // Зчитування координат
            free(polygon->name);
            free(polygon->points);
            free(polygon);
            return NULL;
        }
    }

    return polygon; // Повертаємо зчитаний багатокутник
}

// Функція для виведення багатокутника
void print_polygon(const polygon_t *polygon) {
    printf("Багатокутник: %s\n", polygon->name); // Виведення назви багатокутника
    printf("Точки: ");
    for (int i = 0; i < polygon->num_points; i++) { // Перебір точок
        printf("(%d, %d)", polygon->points[i].x, polygon->points[i].y); // Виведення координат
        if (i != polygon->num_points - 1) printf(", "); // Додаємо кому між точками
    }
    printf("\n"); // Завершення виведення
}

// Функція для звільнення пам'яті багатокутника
void free_polygon(polygon_t *polygon) {
    free(polygon->name);    // Звільняємо пам'ять для назви
    free(polygon->points);  // Звільняємо пам'ять для масиву точок
    free(polygon);          // Звільняємо пам'ять для структури багатокутника
}

// Головна функція
int main() {
    FILE *file = fopen("polygons.txt", "r"); // Відкриваємо файл для читання
    if (!file) { // Перевірка, чи файл відкрився успішно
        perror("Помилка відкриття файлу"); // Виведення повідомлення про помилку
        return 1; // Завершення програми з кодом помилки
    }

    polygon_t **polygons = NULL; // Ініціалізація динамічного масиву багатокутників
    size_t num_polygons = 0;    // Лічильник кількості зчитаних багатокутників

    // Зчитування багатокутників з файлу
    polygon_t *polygon;
    while ((polygon = read_polygon(file)) != NULL) { // Читаємо багатокутники по черзі
        num_polygons++; // Збільшуємо кількість багатокутників
        polygons = realloc(polygons, num_polygons * sizeof(polygon_t *)); // Змінюємо розмір масиву
        polygons[num_polygons - 1] = polygon; // Зберігаємо вказівник на новий багатокутник
    }

    fclose(file); // Закриваємо файл після читання

    // Виведення всіх багатокутників
    for (size_t i = 0; i < num_polygons; i++) {
        print_polygon(polygons[i]); // Виводимо інформацію про кожен багатокутник
        free_polygon(polygons[i]); // Звільняємо пам'ять для кожного багатокутника
    }

    free(polygons); // Звільняємо пам'ять для масиву вказівників на багатокутники

    return 0; 
}