#include "Task2.h"

namespace miit::algebra
{
    Task2::Task2(std::size_t rows, std::size_t columns, Generator& generator)
        : Exercise<int>(rows, columns, generator)
    {
    }

    void Task2::solve()
    {
        if (matrix.rows() == 0 || matrix.columns() == 0)
        {
            return;
        }

        // Идём справа налево, чтобы удаление столбца не изменяло
        // индексы ещё не проверенных столбцов.
        for (std::size_t column = matrix.columns(); column-- > 0;)
        {
            if (matrix.at(0, column) % 2 == 0)
            {
                matrix.removeColumn(column);
            }
        }
    }
}
