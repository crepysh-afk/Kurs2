#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    // Вариант 13, задание 2:
    // удалить все столбцы, в которых первый элемент чётный.
    class Task2 final : public Exercise<int>
    {
    public:
        Task2(std::size_t rows, std::size_t columns, Generator& generator);
        void solve() override;
    };
}
