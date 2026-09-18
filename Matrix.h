#pragma once

#include "Generator.h"
#include <cstddef>
#include <iosfwd>
#include <string>
#include <vector>

namespace miit::algebra
{
    /** @brief Класс двумерной целочисленной матрицы. */
    class Matrix
    {
    private:
        std::size_t rowCount;
        std::size_t columnCount;
        std::vector<int> data;

        /** @brief Вычисляет плоский индекс элемента с проверкой границ. */
        std::size_t offset(const std::size_t row, const std::size_t column) const;

    public:
        /** @brief Создаёт пустую матрицу. */
        Matrix();
        /** @brief Создаёт матрицу заданного размера. */
        Matrix(const std::size_t rows, const std::size_t columns);
        /** @brief Создаёт матрицу, заполненную заданным значением. */
        Matrix(const std::size_t rows, const std::size_t columns, const int value);
        /** @brief Конструктор копирования. */
        Matrix(const Matrix& other) = default;
        /** @brief Конструктор перемещения. */
        Matrix(Matrix&& other) noexcept = default;
        /** @brief Оператор копирующего присваивания. */
        Matrix& operator=(const Matrix& other) = default;
        /** @brief Оператор перемещающего присваивания. */
        Matrix& operator=(Matrix&& other) noexcept = default;
        /** @brief Деструктор. */
        ~Matrix() = default;

        /** @brief Возвращает количество строк. */
        std::size_t rows() const noexcept;
        /** @brief Возвращает количество столбцов. */
        std::size_t columns() const noexcept;
        /** @brief Проверяет, пуста ли матрица. */
        bool empty() const noexcept;
        /** @brief Возвращает элемент по плоскому индексу. */
        int& operator[](const std::size_t index);
        /** @brief Возвращает константный элемент по плоскому индексу. */
        const int& operator[](const std::size_t index) const;
        /** @brief Заполняет матрицу генератором. */
        void fill(Generator& generator);
        /** @brief Удаляет столбец. */
        void removeColumn(const std::size_t column);
        /** @brief Возвращает строковое представление матрицы. */
        std::string toString() const;

        friend std::ostream& operator<<(std::ostream& output, const Matrix& matrix);
        friend std::istream& operator>>(std::istream& input, Matrix& matrix);
    };
}
