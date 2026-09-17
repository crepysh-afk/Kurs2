#pragma once

#include "Generator.h"
#include "Matrix.h"

namespace miit::algebra
{
    template <typename T>
    class Exercise
    {
    protected:
        Matrix<T> matrix;
        Generator& generator;

    public:
        Exercise(std::size_t rows, std::size_t columns, Generator& generator)
            : matrix(rows, columns),
              generator(generator)
        {
            matrix.fill(generator);
        }

        virtual ~Exercise() = default;

        Exercise(const Exercise&) = delete;
        Exercise& operator=(const Exercise&) = delete;

        virtual void solve() = 0;

        const Matrix<T>& getMatrix() const noexcept
        {
            return matrix;
        }

        Matrix<T>& getMatrix() noexcept
        {
            return matrix;
        }
    };
}
