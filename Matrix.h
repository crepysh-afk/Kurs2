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
/**
* @brief Шаблонный класс для работы с матрицей.
* @tparam T Тип элементов матрицы.
*/
    template <typename T>
    class Matrix
    {
    private:
        std::size_t rowCount = 0;
        std::size_t columnCount = 0;
        std::vector<T> data;
/**
* @brief Возвращает индекс элемента в одномерном массиве.
* @param row Номер строки.
* @param column Номер столбца.
* @return Индекс элемента.
*/
        std::size_t offset(std::size_t row, std::size_t column) const
        {
            if (row >= rowCount || column >= columnCount)
            {
                throw std::out_of_range("Matrix index is out of range");
            }

            return row * columnCount + column;
        }

    public:
/**
* @brief Создаёт пустую матрицу.
*/
        Matrix() = default;
/**
* @brief Создаёт матрицу заданного размера.
* @param rows Количество строк.
* @param columns Количество столбцов.
*/
        Matrix(std::size_t rows, std::size_t columns)
            : rowCount(rows),
              columnCount(columns),
              data(rows * columns)
        {
        }
/**
* @brief Создаёт матрицу и заполняет её значением.
* @param rows Количество строк.
* @param columns Количество столбцов.
* @param value Начальное значение элементов.
*/
        Matrix(std::size_t rows, std::size_t columns, const T& value)
            : rowCount(rows),
              columnCount(columns),
              data(rows * columns, value)
        {
        }
/**
     * @brief Конструктор копирования.
     *
     * @param other Матрица, из которой выполняется копирование.
     */
        Matrix(const Matrix&) = default;
/**
     * @brief Конструктор перемещения.
     *
     * @param other Матрица, из которой перемещаются данные.
     */
        Matrix(Matrix&&) noexcept = default;
 /**
     * @brief Оператор присваивания копированием.
     *
     * @param other Исходная матрица.
     * @return Ссылка на текущую матрицу.
     */
        Matrix& operator=(const Matrix&) = default;
/**
     * @brief Оператор присваивания перемещением.
     *
     * @param other Матрица-источник.
     * @return Ссылка на текущую матрицу.
     */
        Matrix& operator=(Matrix&&) noexcept = default;
/**
     * @brief Деструктор матрицы.
     */
        ~Matrix() = default;
/**
     * @brief Возвращает количество строк.
     *
     * @return Количество строк матрицы.
     */
        std::size_t rows() const noexcept { return rowCount; }
 /**
     * @brief Возвращает количество столбцов.
     *
     * @return Количество столбцов матрицы.
     */
        std::size_t columns() const noexcept { return columnCount; }
/**
     * @brief Проверяет, является ли матрица пустой.
     *
     * @return true, если матрица пустая, иначе false.
     */
        bool empty() const noexcept { return data.empty(); }
/**
     * @brief Предоставляет доступ к элементу матрицы.
     *
     * @param row Номер строки.
     * @param column Номер столбца.
     * @return Ссылка на элемент матрицы.
     */
        T& at(std::size_t row, std::size_t column)
        {
            return data[offset(row, column)];
        }
/**
     * @brief Предоставляет константный доступ к элементу матрицы.
     * @param row Номер строки.
     * @param column Номер столбца.
     * @return Константная ссылка на элемент.
     */
        const T& at(std::size_t row, std::size_t column) const
        {
            return data[offset(row, column)];
        }

/**
     * @brief Возвращает элемент по плоскому индексу.
     *
     * @param index Индекс элемента в одномерном массиве.
     * @return Ссылка на элемент.
     */
        T& operator[](std::size_t index)
        {
            if (index >= data.size())
            {
                throw std::out_of_range("Matrix flat index is out of range");
            }

            return data[index];
        }
 /**
     * @brief Возвращает элемент по плоскому индексу для константной матрицы.
     *
     * @param index Индекс элемента.
     * @return Константная ссылка на элемент.
     */
        const T& operator[](std::size_t index) const
        {
            if (index >= data.size())
            {
                throw std::out_of_range("Matrix flat index is out of range");
            }

            return data[index];
        }
/**
     * @brief Заполняет матрицу с помощью генератора.
     *
     * @param generator Генератор значений.
     */
        void fill(Generator& generator)
        {
            for (T& value : data)
            {
                value = static_cast<T>(generator.generate());
            }
        }
 /**
     * @brief Заполняет матрицу одним значением.
     *
     * @param value Значение для заполнения.
     */
        void fill(const T& value)
        {
            std::fill(data.begin(), data.end(), value);
        }
/**
     * @brief Удаляет указанный столбец.
     *
     * @param column Номер удаляемого столбца.
     */
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
/**
     * @brief Преобразует матрицу в строку.
     * @return Строковое представление матрицы.
     */
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
