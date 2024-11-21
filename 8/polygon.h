#ifndef POLYGON_H
#define POLYGON_H

#include <stdio.h>

// Структура для точки
typedef struct {
    int x; // Координата X
    int y; // Координата Y
} point_t;

// Структура для багатокутника
typedef struct {
    char *name;        // Назва багатокутника
    int num_points;    // Кількість точок
    point_t *points;   // Масив точок
} polygon_t;

// Функції для роботи з багатокутниками
polygon_t *read_polygon(FILE *file);           // Зчитування багатокутника з файлу
void print_polygon(const polygon_t *polygon); // Виведення багатокутника
void free_polygon(polygon_t *polygon);        // Звільнення пам'яті багатокутника

#endif 