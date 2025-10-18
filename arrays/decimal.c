#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Представляет правильную простую дробь в виде периодической десятичной дроби.
 *
 * @param numerator Числитель дроби (a).
 * @param denominator Знаменатель дроби (b).
 * @return Указатель на строку с десятичным представлением.
 */
char* fraction_to_decimal_string(int numerator, int denominator) {
    // Входные данные: a < b (правильная дробь) и a, b > 0 (натуральные числа)
    if (numerator <= 0 || denominator <= 0 || numerator >= denominator) {
        // Упрощенная проверка, хотя по условию дробь правильная и простая
        return strdup("Ошибка: некорректная дробь");
    }

    // Максимально возможное количество знаков после запятой,
    // прежде чем остаток гарантированно повторится, равно знаменателю.
    // Удвоенный размер с запасом на '0,', скобки и (0)
    int max_length = denominator * 2 + 10;
    
    // Результат будет храниться здесь.
    char* result = (char*)malloc(max_length * sizeof(char));
    if (result == NULL) return NULL; // Ошибка выделения памяти
    
    // Начало строки: "0,"
    strcpy(result, "0,");
    
    // remainder_map[r] хранит индекс в десятичной записи,
    // где впервые встретился остаток r. Индекс - это позиция цифры после запятой.
    // Максимальный остаток - denominator - 1.
    // Размер массива - denominator.
    int* remainder_map = (int*)malloc(denominator * sizeof(int));
    if (remainder_map == NULL) {
        free(result);
        return NULL; // Ошибка выделения памяти
    }
    // Инициализация нулями (0 - означает, что остаток не встречался)
    memset(remainder_map, 0, denominator * sizeof(int));

    // 'current_remainder' - текущий остаток. Начинаем с числителя.
    int current_remainder = numerator;
    // 'decimal_start_index' - индекс в 'result' с которого начинаются десятичные знаки (сразу после "0,").
    int decimal_start_index = 2;
    // 'current_pos' - текущая позиция в 'result' для записи следующей цифры.
    int current_pos = decimal_start_index;
    
    // Пока остаток не 0 и не повторялся
    while (current_remainder != 0 && remainder_map[current_remainder] == 0) {
        // 1. Запоминаем текущую позицию для данного остатка
        remainder_map[current_remainder] = current_pos - decimal_start_index; 
        
        // 2. Умножаем остаток на 10 и делим на знаменатель
        current_remainder *= 10;
        int digit = current_remainder / denominator;
        current_remainder %= denominator;
        
        // 3. Записываем новую цифру в результат
        result[current_pos++] = digit + '0';
        
        // Защита от переполнения (хотя по расчетам выше не должно произойти)
        if (current_pos >= max_length - 3) break; 
    }

    // Добавляем завершающий ноль для строки
    result[current_pos] = '\0'; 

    // Обработка случая, когда цикл закончился
    
    // Если остаток == 0, дробь конечная. Добавляем (0) для соответствия формату.
    if (current_remainder == 0) {
        strcat(result, "(0)");
    } 
    // Если остаток != 0, он повторился. Начинается период.
    else {
        // 'period_start_offset' - позиция в строке result, где начинается период.
        // Это смещение от начала десятичной части.
        int period_start_offset = remainder_map[current_remainder];
        int period_start_pos = decimal_start_index + period_start_offset;
        
        // 1. Перемещаем символы: с period_start_pos до конца, включая '\0', 
        // на две позиции вправо для ')' и '\0'. 
        // На одну позицию вправо для '('
        
        // current_pos - это позиция '\0' до всех вставок
        int len = current_pos - period_start_pos;
        memmove(&result[period_start_pos + 1], &result[period_start_pos], len + 1);
        
        // 2. Вставляем открывающую скобку
        result[period_start_pos] = '(';
        
        // 3. Добавляем закрывающую скобку в конец периода
        result[current_pos + 1] = ')';
        result[current_pos + 2] = '\0'; // Обновляем завершающий ноль
    }

    free(remainder_map);
    return result;
}

int main() {
    int a, b;

    // Чтение входных данных
    if (scanf("%d %d", &a, &b) != 2) {
        fprintf(stderr, "Ошибка чтения входных данных.\n");
        return 1;
    }

    // Вычисление и вывод результата
    char* result = fraction_to_decimal_string(a, b);
    if (result != NULL) {
        printf("%s\n", result);
        free(result); // Освобождение выделенной памяти
    } else {
        fprintf(stderr, "Ошибка при обработке дроби.\n");
        return 1;
    }

    return 0;
}