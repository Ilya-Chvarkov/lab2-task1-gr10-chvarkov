
/* main.c */
#include <stdbool.h>
#include <stdio.h>

// Функция проверяет, содержит ли число одинаковые цифры
bool hasUniqueDigits(int num) {
  // Массив для хранения встреченных цифр (0-9)
  bool digits[10] = {false};

  // Если число 0, то в нем только одна цифра - уникальная
  if (num == 0)
    return true;

  // Проверяем каждую цифру числа
  while (num > 0) {
    int digit = num % 10;

    // Если цифра уже встречалась, значит число содержит повторяющиеся цифры
    if (digits[digit])
      return false;

    // Отмечаем, что цифра встретилась
    digits[digit] = true;

    // Переходим к следующей цифре
    num /= 10;
  }

  // Если дошли до конца, значит все цифры уникальны
  return true;
}

// Функция подсчитывает количество чисел с уникальными цифрами в массиве
int countNumbersWithUniqueDigits(int arr[], int size) {
  int count = 0;

  for (int i = 0; i < size; i++) {
    if (hasUniqueDigits(arr[i])) {
      count++;
    }
  }

  return count;
}

int main(void) {
  int size;
  printf("Введите размер массива: ");
  scanf("%d", &size);

  int numbers[100]; // Предполагаем, что максимальный размер массива - 100

  printf("Введите %d натуральных чисел:\n", size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &numbers[i]);
  }

  int result = countNumbersWithUniqueDigits(numbers, size);

  printf("Количество чисел, десятичная запись которых не содержит одинаковых "
         "цифр: %d\n",
         result);

  // Вывод всех чисел с уникальными цифрами
  printf("Числа с уникальными цифрами:\n");
  for (int i = 0; i < size; i++) {
    if (hasUniqueDigits(numbers[i])) {
      printf("%d ", numbers[i]);
    }
  }
  printf("\n");

  return 0;
}
