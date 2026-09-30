#include <iostream>
#include <utility>

#include "Queue.h"

/**
 * @brief Демонстрационная программа для класса Queue.
 *
 * Показывает создание очереди, добавление и удаление элементов,
 * копирование, перемещение и другие операции.
 */
int main()
{
    Queue queue{10, 20, 30};

    std::cout << "Initial queue: "
              << queue.toString()
              << '\n';

    std::cout << "Head element: "
              << queue.peek()
              << '\n';

    queue << 40 << 50;

    std::cout << "After enqueue: "
              << queue.toString()
              << '\n';

    int value = 0;

    queue >> value;

    std::cout << "Dequeued element: "
              << value
              << '\n';

    std::cout << "After dequeue: "
              << queue.toString()
              << '\n';

    Queue copy(queue);

    std::cout << "Copy: "
              << copy.toString()
              << '\n';

    Queue moved(std::move(copy));

    std::cout << "Moved queue: "
              << moved.toString()
              << '\n';

    std::cout << "Contains 30: "
              << (moved.contains(30) ? "yes" : "no")
              << '\n';

    std::cout << "Size: "
              << moved.size()
              << '\n';

    std::cout << "Empty: "
              << (moved.empty() ? "yes" : "no")
              << '\n';

    return 0;
}
