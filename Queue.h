#pragma once

#include <cstddef>
#include <initializer_list>
#include <string>

/**
 * @brief Очередь целых чисел, работающая по принципу FIFO.
 *
 * Очередь поддерживает добавление элементов в конец,
 * удаление элементов из начала и просмотр головного элемента.
 */
class Queue
{
private:
    /**
     * @brief Элемент односвязной очереди.
     */
    struct Node
    {
        int data;
        Node* next;

        /**
         * @brief Создаёт узел.
         * @param value Значение элемента.
         * @param nextNode Указатель на следующий узел.
         */
        explicit Node(int value, Node* nextNode = nullptr);
    };

    Node* head_;
    Node* tail_;
    std::size_t size_;

    /**
     * @brief Удаляет все элементы очереди.
     */
    void clear() noexcept;

    /**
     * @brief Копирует элементы другой очереди.
     * @param other Очередь-источник.
     */
    void copyFrom(const Queue& other);

public:
    /**
     * @brief Создаёт пустую очередь.
     */
    Queue();

    /**
     * @brief Создаёт очередь из списка инициализации.
     * @param values Начальные значения элементов.
     */
    Queue(std::initializer_list<int> values);

    /**
     * @brief Конструктор копирования.
     * @param other Очередь-источник.
     */
    Queue(const Queue& other);

    /**
     * @brief Конструктор перемещения.
     * @param other Очередь-источник.
     */
    Queue(Queue&& other) noexcept;

    /**
     * @brief Деструктор.
     */
    ~Queue();

    /**
     * @brief Оператор копирующего присваивания.
     * @param other Очередь-источник.
     * @return Ссылка на текущую очередь.
     */
    Queue& operator=(const Queue& other);

    /**
     * @brief Оператор перемещающего присваивания.
     * @param other Очередь-источник.
     * @return Ссылка на текущую очередь.
     */
    Queue& operator=(Queue&& other) noexcept;

    /**
     * @brief Добавляет элемент в конец очереди.
     *
     * Используется как операция enqueue.
     *
     * @param value Добавляемое значение.
     * @return Ссылка на текущую очередь.
     */
    Queue& operator<<(int value);

    /**
     * @brief Извлекает элемент из начала очереди.
     *
     * Используется как операция dequeue.
     *
     * @param value Переменная для полученного значения.
     * @return Ссылка на текущую очередь.
     *
     * @throws std::out_of_range Если очередь пуста.
     */
    Queue& operator>>(int& value);

    /**
     * @brief Добавляет элемент в конец очереди.
     *
     * @param value Добавляемое значение.
     */
    void enqueue(int value);

    /**
     * @brief Извлекает элемент из начала очереди.
     *
     * @return Извлечённое значение.
     * @throws std::out_of_range Если очередь пуста.
     */
    int dequeue();

    /**
     * @brief Возвращает головной элемент без удаления.
     *
     * @return Значение головного элемента.
     * @throws std::out_of_range Если очередь пуста.
     */
    int peek() const;

    /**
     * @brief Проверяет, пуста ли очередь.
     *
     * @return true, если очередь пуста, иначе false.
     */
    bool empty() const noexcept;

    /**
     * @brief Возвращает количество элементов.
     *
     * @return Размер очереди.
     */
    std::size_t size() const noexcept;

    /**
     * @brief Проверяет наличие элемента в очереди.
     *
     * @param value Искомое значение.
     * @return true, если элемент найден, иначе false.
     */
    bool contains(int value) const noexcept;

    /**
     * @brief Преобразует содержимое очереди в строку.
     *
     * @return Строковое представление очереди.
     */
    std::string toString() const;
};
