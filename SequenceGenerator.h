#pragma once

#include "Generator.h"
#include <vector>
#include <cstddef>

namespace miit::algebra
{
    // Генератор для модульных тестов: последовательно возвращает заданные числа.
    class SequenceGenerator final : public Generator
    {
    private:
        std::vector<int> values;
        std::size_t position = 0;

    public:
        explicit SequenceGenerator(std::vector<int> values);
        int generate() override;
    };
}
