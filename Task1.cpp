#include "Task1.h"
#include <cstdlib>
#include <stdexcept>

namespace miit::algebra
{
    Task1::Task1(const std::size_t rows, const std::size_t columns, Generator& generator)
        : Exercise<int>(rows, columns, generator)
    {
    }

    void Task1::solve()
    {
        if (matrix.empty())
        {
            return;
        }

        int maximumByAbsoluteValue = matrix[0];

        for (std::size_t index = 1; index < matrix.rows() * matrix.columns(); ++index)
        {
            if (std::abs(matrix[index]) > std::abs(maximumByAbsoluteValue))
            {
                maximumByAbsoluteValue = matrix[index];
            }
        }

        for (std::size_t index = 0; index < matrix.rows() * matrix.columns(); ++index)
        {
            if (matrix[index] % 2 == 0)
            {
                matrix[index] = maximumByAbsoluteValue;
            }
        }
    }
}

    
