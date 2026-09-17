#include "RandomGenerator.h"

namespace miit::algebra
{
    RandomGenerator::RandomGenerator(int minValue, int maxValue)
        : distribution(minValue, maxValue),
          engine(std::random_device{}())
    {
    }

    int RandomGenerator::generate()
    {
        return distribution(engine);
    }
}
