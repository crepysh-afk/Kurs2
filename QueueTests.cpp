#include "CppUnitTest.h"

#include "../QueueLibrary/Queue.h"

#include <stdexcept>
#include <string>
#include <utility>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueTests
{
    TEST_CLASS(QueueTests)
    {
    public:

        /**
         * @brief Проверяет конструктор по умолчанию.
         */
        TEST_METHOD(DefaultConstructor_CreatesEmptyQueue)
        {
            const Queue queue;

            Assert::IsTrue(queue.empty());
            Assert::AreEqual<std::size_t>(0, queue.size());
        }

        /**
         * @brief Проверяет конструктор со списком инициализации.
         */
        TEST_METHOD(InitializerList_CreatesQueue)
        {
            const Queue queue{ 1, 2, 3 };

            Assert::AreEqual<std::size_t>(3, queue.size());
            Assert::AreEqual(1, queue.peek());
            Assert::AreEqual(
                std::string("[1, 2, 3]"),
                queue.toString()
            );
        }

        /**
         * @brief Проверяет добавление элементов в очередь.
         */
        TEST_METHOD(Enqueue_AddsElementsToEnd)
        {
            Queue queue;

            queue.enqueue(10);
            queue.enqueue(20);
            queue.enqueue(30);

            Assert::AreEqual<std::size_t>(3, queue.size());
            Assert::AreEqual(
                std::string("[10, 20, 30]"),
                queue.toString()
            );
        }

        /**
         * @brief Проверяет FIFO-порядок извлечения элементов.
         */
        TEST_METHOD(Dequeue_RemovesElementsFromFront)
        {
            Queue queue{ 10, 20, 30 };

            Assert::AreEqual(10, queue.dequeue());
            Assert::AreEqual(20, queue.dequeue());
            Assert::AreEqual(30, queue.dequeue());

            Assert::IsTrue(queue.empty());
        }

        /**
         * @brief Проверяет оператор <<.
         */
        TEST_METHOD(LeftShift_AddsElements)
        {
            Queue queue;

            queue << 10 << 20 << 30;

            Assert::AreEqual(
                std::string("[10, 20, 30]"),
                queue.toString()
            );
        }

        /**
         * @brief Проверяет оператор >>.
         */
        TEST_METHOD(RightShift_RemovesElements)
        {
            Queue queue{ 10, 20, 30 };

            int value = 0;

            queue >> value;

            Assert::AreEqual(10, value);
            Assert::AreEqual(
                std::string("[20, 30]"),
                queue.toString()
            );
        }

        /**
         * @brief Проверяет просмотр головного элемента.
         */
        TEST_METHOD(Peek_ReturnsFrontElement)
        {
            const Queue queue{ 100, 200, 300 };

            Assert::AreEqual(100, queue.peek());
            Assert::AreEqual<std::size_t>(3, queue.size());
        }

        /**
         * @brief Проверяет копирующий конструктор.
         */
        TEST_METHOD(CopyConstructor_CopiesQueue)
        {
            const Queue source{ 1, 2, 3 };

            Queue copy(source);

            Assert::AreEqual(
                std::string("[1, 2, 3]"),
                copy.toString()
            );

            copy.enqueue(4);

            Assert::AreEqual(
                std::string("[1, 2, 3]"),
                source.toString()
            );

            Assert::AreEqual(
                std::string("[1, 2, 3, 4]"),
                copy.toString()
            );
        }

        /**
         * @brief Проверяет оператор копирующего присваивания.
         */
        TEST_METHOD(CopyAssignment_CopiesQueue)
        {
            const Queue source{ 10, 20 };

            Queue assigned;

            assigned = source;

            Assert::AreEqual(
                std::string("[10, 20]"),
                assigned.toString()
            );

            assigned.enqueue(30);

            Assert::AreEqual(
                std::string("[10, 20]"),
                source.toString()
            );
        }

        /**
         * @brief Проверяет конструктор перемещения.
         */
        TEST_METHOD(MoveConstructor_MovesQueue)
        {
            Queue source{ 1, 2, 3 };

            Queue moved(std::move(source));

            Assert::AreEqual(
                std::string("[1, 2, 3]"),
                moved.toString()
            );

            Assert::IsTrue(source.empty());
            Assert::AreEqual<std::size_t>(0, source.size());
        }

        /**
         * @brief Проверяет перемещающее присваивание.
         */
        TEST_METHOD(MoveAssignment_MovesQueue)
        {
            Queue source{ 1, 2, 3 };

            Queue assigned;

            assigned = std::move(source);

            Assert::AreEqual(
                std::string("[1, 2, 3]"),
                assigned.toString()
            );

            Assert::IsTrue(source.empty());
        }

        /**
         * @brief Проверяет поиск элемента.
         */
        TEST_METHOD(Contains_FindsElements)
        {
            const Queue queue{ 4, 8, 15, 16, 23, 42 };

            Assert::IsTrue(queue.contains(15));
            Assert::IsTrue(queue.contains(42));
            Assert::IsFalse(queue.contains(100));
        }

        /**
         * @brief Проверяет исключение при вызове peek для пустой очереди.
         */
        TEST_METHOD(Peek_ThrowsWhenQueueIsEmpty)
        {
            const Queue queue;

            Assert::ExpectException<std::out_of_range>(
                [&queue]()
                {
                    queue.peek();
                }
            );
        }

        /**
         * @brief Проверяет исключение при dequeue для пустой очереди.
         */
        TEST_METHOD(Dequeue_ThrowsWhenQueueIsEmpty)
        {
            Queue queue;

            Assert::ExpectException<std::out_of_range>(
                [&queue]()
                {
                    queue.dequeue();
                }
            );
        }

        /**
         * @brief Проверяет очистку очереди после удаления всех элементов.
         */
        TEST_METHOD(Queue_BecomesEmptyAfterAllDequeues)
        {
            Queue queue{ 1, 2, 3 };

            queue.dequeue();
            queue.dequeue();
            queue.dequeue();

            Assert::IsTrue(queue.empty());
            Assert::AreEqual<std::size_t>(0, queue.size());
        }
    };
}
