#pragma once

#include "Generator.h"
#include <vector>
#include <cstddef>

namespace miit::algebra
{
/**
* @brief Генератор значений из последовательности.
*/
    class SequenceGenerator final : public Generator
    {
    private:
/**
* @brief Последовательность генерируемых значений.
*/
        std::vector<int> values;
/**
* @brief Индекс текущего элемента последовательности.
*/
        std::size_t position = 0;

    public:
/**
* @brief Создаёт генератор последовательности.
* @param values Вектор значений для генерации.
*/
        explicit SequenceGenerator(std::vector<int> values);
/**
* @brief Возвращает следующее значение последовательности.
* @return Следующее целое число.
* @throws std::out_of_range Если последовательность закончилась.
*/
        int generate() override;
    };
}
