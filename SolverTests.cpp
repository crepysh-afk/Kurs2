    #include "CppUnitTest.h"
#include "../Solver/ConstantGenerator.h"
#include "../Solver/FunctionGenerator.h"
#include "../Solver/RandomGenerator.h"
#include "../Solver/SequenceGenerator.h"
#include "../Solver/Matrix.h"
#include "../Solver/Task1.h"
#include "../Solver/Task2.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::algebra;

namespace SolverTests
{
    TEST_CLASS(GeneratorTests)
    {
    public:
        TEST_METHOD(ConstantGenerator_ReturnsValue)
        { ConstantGenerator generator(7); Assert::AreEqual(7, generator.generate()); }

        TEST_METHOD(FunctionGenerator_ReturnsFunctionResult)
        { FunctionGenerator generator([] { return 8; }); Assert::AreEqual(8, generator.generate()); }

        TEST_METHOD(SequenceGenerator_ReturnsValuesInOrder)
        { SequenceGenerator generator({ 2, 4 }); Assert::AreEqual(2, generator.generate()); Assert::AreEqual(4, generator.generate()); }

        TEST_METHOD(SequenceGenerator_ThrowsWhenEmpty)
        { SequenceGenerator generator({}); Assert::ExpectException<std::out_of_range>([&] { generator.generate(); }); }
    };

    TEST_CLASS(MatrixTests)
    {
    public:
        TEST_METHOD(Matrix_ConstructorsAndProperties)
        { Matrix matrix(2, 3, 5); Assert::AreEqual<std::size_t>(2, matrix.rows()); Assert::AreEqual<std::size_t>(3, matrix.columns()); Assert::IsFalse(matrix.empty()); Assert::AreEqual(5, matrix[0]); }

        TEST_METHOD(Matrix_FillValueAndGenerator)
        { Matrix matrix(2, 2); ConstantGenerator generator(3); matrix.fill(generator); Assert::AreEqual(3, matrix[3]); matrix.fill(9); Assert::AreEqual(9, matrix[0]); }

        TEST_METHOD(Matrix_RemoveColumn)
        { Matrix matrix(2, 3); for (int i = 0; i < 6; ++i) matrix[i] = i + 1; matrix.removeColumn(1); Assert::AreEqual<std::size_t>(2, matrix.columns()); Assert::AreEqual(1, matrix[0]); Assert::AreEqual(3, matrix[1]); }

        TEST_METHOD(Matrix_StringAndStreams)
        { Matrix matrix(1, 2); matrix[0] = 1; matrix[1] = 2; Assert::AreEqual(std::string("1 2"), matrix.toString()); std::stringstream input("3 4"); input >> matrix; Assert::AreEqual(4, matrix[1]); std::stringstream output; output << matrix; Assert::AreEqual(std::string("3 4"), output.str()); }

        TEST_METHOD(Matrix_InvalidIndexThrows)
        { Matrix matrix(1, 1); Assert::ExpectException<std::out_of_range>([&] { matrix[2]; }); Assert::ExpectException<std::out_of_range>([&] { matrix.removeColumn(2); }); }
    };

    TEST_CLASS(TaskTests)
    {
    public:
        TEST_METHOD(Task1_ReplacesEvenElements)
        { SequenceGenerator generator({ 2, -3, 4, -8, 5, 1 }); Task1 task(2, 3, generator); task.solve(); const auto& result = task.getMatrix(); Assert::AreEqual(-8, result[0]); Assert::AreEqual(-3, result[1]); Assert::AreEqual(-8, result[2]); Assert::AreEqual(-8, result[3]); }

        TEST_METHOD(Task2_RemovesColumns)
        { SequenceGenerator generator({ 2, 1, 4, 5, 7, 8, 9, 10 }); Task2 task(2, 4, generator); task.solve(); const auto& result = task.getMatrix(); Assert::AreEqual<std::size_t>(2, result.columns()); Assert::AreEqual(1, result[0]); Assert::AreEqual(5, result[1]); Assert::AreEqual(8, result[2]); Assert::AreEqual(10, result[3]); }
    };
}

    
