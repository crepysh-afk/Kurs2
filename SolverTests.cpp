#include "CppUnitTest.h"

#include "../Solver/SequenceGenerator.h"
#include "../Solver/Task1.h"
#include "../Solver/Task2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::algebra;

namespace SolverTests
{
    TEST_CLASS(MatrixTests)
    {
    public:
        TEST_METHOD(Task1_ReplacesEvenElements)
        {
            // Матрица:
            //  2  -3  4
            // -8   5  1
            // Максимальный по модулю элемент = -8.
            SequenceGenerator generator({ 2, -3, 4, -8, 5, 1 });
            Task1 task(2, 3, generator);

            task.solve();

            const auto& result = task.getMatrix();

            Assert::AreEqual(-8, result.at(0, 0));
            Assert::AreEqual(-3, result.at(0, 1));
            Assert::AreEqual(-8, result.at(0, 2));
            Assert::AreEqual(-8, result.at(1, 0));
            Assert::AreEqual(5, result.at(1, 1));
            Assert::AreEqual(1, result.at(1, 2));
        }

        TEST_METHOD(Task2_RemovesColumnsWithEvenFirstElement)
        {
            // Первые элементы столбцов: 2, 1, 4, 5.
            // Удаляются столбцы 0 и 2.
            SequenceGenerator generator({ 2, 1, 4, 5, 7, 8, 9, 10 });
            Task2 task(2, 4, generator);

            task.solve();

            const auto& result = task.getMatrix();

            Assert::AreEqual<std::size_t>(2, result.rows());
            Assert::AreEqual<std::size_t>(2, result.columns());
            Assert::AreEqual(1, result.at(0, 0));
            Assert::AreEqual(5, result.at(0, 1));
            Assert::AreEqual(8, result.at(1, 0));
            Assert::AreEqual(10, result.at(1, 1));
        }

        TEST_METHOD(Matrix_FlatIndexWorks)
        {
            SequenceGenerator generator({ 1, 2, 3, 4 });
            Task1 task(2, 2, generator);

            Assert::AreEqual(1, task.getMatrix()[0]);
            Assert::AreEqual(4, task.getMatrix()[3]);
        }
    };
}
