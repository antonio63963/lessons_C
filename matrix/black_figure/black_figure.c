#include <stdio.h>
#include <stdlib.h>

// Максимальный размер, N <= 100. Используем 102 для рамки (N+2)
#define MAX_SIZE 102 

// Глобальная сетка для простоты, учитывая небольшие ограничения N
char grid[MAX_SIZE][MAX_SIZE];
int N;

/**
 * @brief Рекурсивная функция заливки (DFS) для "покраски" фигуры.
 * * @param i Строка текущей клетки.
 * @param j Столбец текущей клетки.
 */
void flood_fill(int i, int j) {
    if (i < 1 || i > N || j < 1 || j > N || grid[i][j] != '*') {
        return;
    }

    grid[i][j] = '3';

    flood_fill(i + 1, j); // Вниз
    flood_fill(i - 1, j); // Вверх
    flood_fill(i, j + 1); // Вправо
    flood_fill(i, j - 1); // Влево
}

int main() {
    if (scanf("%d", &N) != 1 || N <= 0 || N > 100) {
        // Базовая проверка ввода
        fprintf(stderr, "Invalid input for N.\n");
        return 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (scanf(" %c", &grid[i][j]) != 1) { 
                fprintf(stderr, "Error reading grid at (%d, %d).\n", i, j);
                return 1;
            }
        }
    }
    
    int figure_count = 0;

    // Обход поля N x N (с 1 до N)
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (grid[i][j] == '*') {
                // Это начало новой фигуры
                figure_count++;
                
                // Запускаем заливку, чтобы пометить/покрасить всю фигуру
                flood_fill(i, j);
            }
        }
    }

    // Вывод результата
    printf("%d\n", figure_count);

    return 0;
}