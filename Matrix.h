#pragma once

#include "Generator.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iosfwd>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace miit::algebra
{
    template <typename T>
    class Matrix
    {
    private:
        std::size_t rowCount = 0;
        std::size_t columnCount = 0;
        std::vector<T> data;

        std::size_t offset(std::size_t row, std::size_t column) const
        {
            if (row >= rowCount || column >= columnCount)
            {
                throw std::out_of_range("Matrix index is out of range");
            }

            return row * columnCount + column;
        }

    public:
        Matrix() = default;

        Matrix(std::size_t rows, std::size_t columns)
            : rowCount(rows),
              columnCount(columns),
              data(rows * columns)
        {
        }

        Matrix(std::size_t rows, std::size_t columns, const T& value)
            : rowCount(rows),
              columnCount(columns),
              data(rows * columns, value)
        {
        }

        Matrix(const Matrix&) = default;
        Matrix(Matrix&&) noexcept = default;
        Matrix& operator=(const Matrix&) = default;
        Matrix& operator=(Matrix&&) noexcept = default;
        ~Matrix() = default;

        std::size_t rows() const noexcept { return rowCount; }
        std::size_t columns() const noexcept { return columnCount; }
        bool empty() const noexcept { return data.empty(); }

        T& at(std::size_t row, std::size_t column)
        {
            return data[offset(row, column)];
        }

        const T& at(std::size_t row, std::size_t column) const
        {
            return data[offset(row, column)];
        }

        // Оператор [] обращается к элементу по плоскому индексу:
        // индекс = row * columns + column.
        T& operator[](std::size_t index)
        {
            if (index >= data.size())
            {
                throw std::out_of_range("Matrix flat index is out of range");
            }

            return data[index];
        }

        const T& operator[](std::size_t index) const
        {
            if (index >= data.size())
            {
                throw std::out_of_range("Matrix flat index is out of range");
            }

            return data[index];
        }

        void fill(Generator& generator)
        {
            for (T& value : data)
            {
                value = static_cast<T>(generator.generate());
            }
        }

        void fill(const T& value)
        {
            std::fill(data.begin(), data.end(), value);
        }

        void removeColumn(std::size_t column)
        {
            if (column >= columnCount)
            {
                throw std::out_of_range("Column index is out of range");
            }

            if (columnCount == 0)
            {
                return;
            }

            std::vector<T> newData;
            newData.reserve(rowCount * (columnCount - 1));

            for (std::size_t row = 0; row < rowCount; ++row)
            {
                for (std::size_t currentColumn = 0; currentColumn < columnCount; ++currentColumn)
                {
                    if (currentColumn != column)
                    {
                        newData.push_back(at(row, currentColumn));
                    }
                }
            }

            --columnCount;
            data = std::move(newData);
        }

        std::string toString() const
        {
            std::ostringstream output;

            for (std::size_t row = 0; row < rowCount; ++row)
            {
                for (std::size_t column = 0; column < columnCount; ++column)
                {
                    if (column != 0)
                    {
                        output << ' ';
                    }

                    output << at(row, column);
                }

                if (row + 1 < rowCount)
                {
                    output << '\n';
                }
            }

            return output.str();
        }

        friend std::ostream& operator<<(std::ostream& output, const Matrix& matrix)
        {
            output << matrix.toString();
            return output;
        }

        friend std::istream& operator>>(std::istream& input, Matrix& matrix)
        {
            for (T& value : matrix.data)
            {
                input >> value;
            }

            return input;
        }
    };
}
