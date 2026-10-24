#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Задание 1 варианта 13.
     *
     * Заменяет каждый чётный элемент матрицы максимальным по модулю
     * элементом массива.
     */
    class Task1 final : public Exercise<int>
    {
    public:
        /**
         * @brief Создаёт объект задания 1 и заполняет матрицу.
         * @param rows Количество строк матрицы.
         * @param columns Количество столбцов матрицы.
         * @param generator Генератор значений матрицы.
         */
        Task1(const std::size_t rows, const std::size_t columns, Generator& generator);

        /**
         * @brief Выполняет задание 1.
         *
         * Находит максимальный по модулю элемент матрицы и заменяет им
         * все чётные элементы.
         */
        void solve() override;
    };
}
