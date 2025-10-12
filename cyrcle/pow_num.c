#include <stdio.h>
#include <math.h>
#include <inttypes.h>

// Функция для безопасного вычисления p^k
unsigned long long power(unsigned long long base, int exp) {
    if (exp < 0) return 0;
    if (exp == 0) return 1;
    unsigned long long res = 1;
    for (int i = 0; i < exp; i++) {
        // Использование безопасного умножения для проверки переполнения
        if (__builtin_mul_overflow(res, base, &res)) {
            return 0; // Возвращаем 0 при переполнении
        }
    }
    return res;
}

int main() {
    unsigned long long n;
    int k;
    
    // Считывание входных данных
    if (scanf("%llu %d", &n, &k) != 2 || k <= 0) {
        if (n == 1 && k > 0) { printf("1\n"); }
        else { printf("-1\n"); }
        return 0;
    }

    if (n == 1) {
        printf("1\n");
        return 0;
    }

    unsigned long long original_n = n;
    unsigned long long temp_n = n;
    unsigned long long sq_a = 1;
    unsigned long long i;
    
    // Флаг для отслеживания успешности разложения
    // Инициализируем 1 (успех), если в процессе найдем ошибку, установим в 0.
    int success_r = 1;

    // Факторизация n
    // Итерация до sqrt(temp_n)
    for (i = 2; i * i <= temp_n; i++) {
        if (temp_n % i == 0) {
            int count = 0;
            
            // Считаем все вхождения простого множителя i
            while (temp_n % i == 0) {
                temp_n /= i;
                count++;
            }
            
            // Количество множителей a_j, которые можно извлечь из i^count
            int num_of_factors = count / k;
            
            // Если оставшаяся степень не равна нулю (count % k != 0), 
            // то n не является k-ой степенью, но мы продолжаем печатать то, что нашли.
            if (count % k != 0) {
                success_r = 0;
            }
            
            // Логика отладочной печати по шагам
            // Каждый простой множитель 'i' корня 'a' печатается num_of_factors раз
            for (int step = 0; step < num_of_factors; step++) {
                // Обновляем общий корень 'a'
                sq_a *= i;
                
                // Вычисляем новое chastnoe: n / a^k
                unsigned long long a_k = power(sq_a, k);
                
                // Проверка на переполнение или некорректное деление (защита)
                if (a_k == 0 || original_n % a_k != 0) { 
                    success_r = 0;
                    break;
                }
                
                unsigned long long chastnoe = original_n / a_k;

                // Отладочная печать: i и текущее chastnoe
                printf("%llu %llu\n", i, chastnoe);
            }
            if (!success_r && count % k != 0) {
                // Если произошла ошибка разложения для текущего i, нет смысла продолжать
                // другие i, так как temp_n будет некорректным для дальнейшего деления
                // на i*i, но мы должны завершить цикл i.
            }
        }
    }

    // Обработка последнего простого множителя, если temp_n > 1
    if (temp_n > 1) {
        // В разложение входит множитель temp_n в степени 1.
        if (k > 1) {
            success_r = 0;
        } else {
            // k=1: множитель входит 1/1=1 раз
            sq_a *= temp_n;
            unsigned long long a_k = power(sq_a, k);
            unsigned long long chastnoe = original_n / a_k;
            printf("%llu %llu\n", temp_n, chastnoe);
        }
    }
    
    // Финальный вывод
    if (success_r) {
        // Финальная проверка: sq_a^k должно быть равно n
        unsigned long long final_power = power(sq_a, k);
        if (final_power == original_n) {
            printf("%llu\n", sq_a);
        } else {
            // Сюда попадем в случае переполнения или другой ошибки.
            printf("-1\n");
        }
    } else {
        printf("-1\n");
    }

    return 0;
}