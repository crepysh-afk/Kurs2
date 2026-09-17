#pragma once

#include "Generator.h"
#include <random>

namespace miit::algebra
{
/**
* @brief Генератор случайных целых чисел.
*/
    class RandomGenerator final : public Generator
    {
    private:
/**
* @brief Распределение случайных чисел.
*/
        std::uniform_int_distribution<int> distribution;
/**
* @brief Генератор псевдослучайных чисел.
*/
        std::mt19937 engine;

    public:
/**
* @brief Создаёт генератор случайных чисел.
* @param minValue Минимальное значение диапазона.
* @param maxValue Максимальное значение диапазона.
*/
        RandomGenerator(int minValue, int maxValue);
/**
* @brief Генерирует случайное число.         
* @return Случайное целое число из заданного диапазона.
*/
        int generate() override;
    };
}
