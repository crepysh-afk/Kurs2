#pragma once

#include "Exercise.h"

namespace miit::algebra
{
/**
 * @brief Класс решения первой задачи.
 */
    class Task1 final : public Exercise<int>
    {
    public:
/**
     * @brief Создаёт объект первой задачи.
     * @param rows Количество строк матрицы.
     * @param columns Количество столбцов матрицы.
     * @param generator Генератор значений.
     */
        Task1(std::size_t rows, std::size_t columns, Generator& generator);
/**
     * @brief Выполняет решение первой задачи.
     */
        void solve() override;
    };
}
