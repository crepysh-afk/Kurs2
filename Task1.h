#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    // Вариант 13, задание 1:
    // заменить каждый чётный элемент максимальным по модулю элементом массива.
    class Task1 final : public Exercise<int>
    {
    public:
        Task1(std::size_t rows, std::size_t columns, Generator& generator);
        void solve() override;
    };
}
