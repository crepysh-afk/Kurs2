#pragma once

#include "Generator.h"
#include "Matrix.h"

namespace miit::algebra
{
/**
 * @brief Шаблонный базовый класс задания.
 * @tparam T Тип элементов матрицы.
 * Метод solve() является чисто виртуальным
 * и реализуется в производных классах.
 */
    template <typename T>
    class Exercise
    {
    protected:
/**
     * @brief Матрица, над которой выполняется задание.
     */
        Matrix<T> matrix;
/**
     * @brief Генератор для заполнения матрицы.
     */
        Generator& generator;

    public:
/**
     * @brief Создаёт задание и заполняет матрицу.
     * @param rows Количество строк.
     * @param columns Количество столбцов.
     * @param generator Генератор значений.
     */
        Exercise(std::size_t rows, std::size_t columns, Generator& generator)
            : matrix(rows, columns),
              generator(generator)
        {
            matrix.fill(generator);
        }
/**
     * @brief Виртуальный деструктор.
     */
        virtual ~Exercise() = default;
/**
     * @brief Удалённый конструктор копирования.
     */
        Exercise(const Exercise&) = delete;
/**
     * @brief Удалённый оператор присваивания.
     */
        Exercise& operator=(const Exercise&) = delete;
/**
     * @brief Решает задачу.
*/
        virtual void solve() = 0;
/**
     * @brief Возвращает константную матрицу.
     *
     * @return Константная ссылка на матрицу.
     */
        const Matrix<T>& getMatrix() const noexcept
        {
            return matrix;
        }
/**
     * @brief Возвращает матрицу для изменения.
     * @return Ссылка на матрицу.
*/
        Matrix<T>& getMatrix() noexcept
        {
            return matrix;
        }
    };
}
