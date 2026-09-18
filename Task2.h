#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Задание 2 варианта 13.
     *
     * Удаляет все столбцы, в которых первый элемент является чётным.
     */
    class Task2 final : public Exercise<int>
    {
    public:
        /**
         * @brief Создаёт объект задания 2 и заполняет матрицу.
         * @param rows Количество строк матрицы.
         * @param columns Количество столбцов матрицы.
         * @param generator Генератор значений матрицы.
         */
        Task2(const std::size_t rows, const std::size_t columns, Generator& generator);

        /**
         * @brief Выполняет задание 2.
         *
         * Удаляет столбцы, первые элементы которых являются чётными.
         */
        void solve() override;
    };
}
