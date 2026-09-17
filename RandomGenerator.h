#pragma once

#include "Generator.h"
#include <random>

namespace miit::algebra
{
    class RandomGenerator final : public Generator
    {
    private:
        std::uniform_int_distribution<int> distribution;
        std::mt19937 engine;

    public:
        RandomGenerator(int minValue, int maxValue);
        int generate() override;
    };
}
