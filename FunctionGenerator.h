#pragma once

#include "Generator.h"
#include <functional>

namespace miit::algebra
{
    // Универсальный генератор. В main можно передать функцию,
    // которая читает значение с клавиатуры или возвращает число другим способом.
    class FunctionGenerator final : public Generator
    {
    private:
        std::function<int()> function;

    public:
        explicit FunctionGenerator(std::function<int()> function);
        int generate() override;
    };
}
