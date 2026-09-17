#pragma once

#include "Exercise.h"

namespace miit::algebra
{
/**
 * @brief Класс решения второй задачи.
 */
    class Task2 final : public Exercise<int>
    {
    public:
/**
     * @brief Создаёт объект второй задачи.
     * @param rows Количество строк матрицы.
     * @param columns Количество столбцов матрицы.
     * @param generator Генератор значений.
     */
        Task2(std::size_t rows, std::size_t columns, Generator& generator);
/**
     * @brief Выполняет решение второй задачи.
     */
        void solve() override;
    };
}
