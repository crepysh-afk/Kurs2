#include "Queue.h"

#include <sstream>
#include <stdexcept>
#include <utility>

Queue::Node::Node(int value, Node* nextNode)
    : data(value),
      next(nextNode)
{
}

Queue::Queue()
    : head_(nullptr),
      tail_(nullptr),
      size_(0)
{
}

Queue::Queue(std::initializer_list<int> values)
    : Queue()
{
    for (const int value : values)
    {
        enqueue(value);
    }
}

Queue::Queue(const Queue& other)
    : Queue()
{
    copyFrom(other);
}

Queue::Queue(Queue&& other) noexcept
    : head_(other.head_),
      tail_(other.tail_),
      size_(other.size_)
{
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
}

Queue::~Queue()
{
    clear();
}

Queue& Queue::operator=(const Queue& other)
{
    if (this != &other)
    {
        Queue temporary(other);

        std::swap(head_, temporary.head_);
        std::swap(tail_, temporary.tail_);
        std::swap(size_, temporary.size_);
    }

    return *this;
}

Queue& Queue::operator=(Queue&& other) noexcept
{
    if (this != &other)
    {
        clear();

        head_ = other.head_;
        tail_ = other.tail_;
        size_ = other.size_;

        other.head_ = nullptr;
        other.tail_ = nullptr;
        other.size_ = 0;
    }

    return *this;
}

Queue& Queue::operator<<(int value)
{
    enqueue(value);
    return *this;
}

Queue& Queue::operator>>(int& value)
{
    value = dequeue();
    return *this;
}

void Queue::enqueue(int value)
{
    Node* newNode = new Node(value);

    if (tail_ == nullptr)
    {
        head_ = newNode;
        tail_ = newNode;
    }
    else
    {
        tail_->next = newNode;
        tail_ = newNode;
    }

    ++size_;
}

int Queue::dequeue()
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty");
    }

    Node* oldHead = head_;
    const int value = oldHead->data;

    head_ = head_->next;

    delete oldHead;
    --size_;

    if (head_ == nullptr)
    {
        tail_ = nullptr;
    }

    return value;
}

int Queue::peek() const
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty");
    }

    return head_->data;
}

bool Queue::empty() const noexcept
{
    return size_ == 0;
}

std::size_t Queue::size() const noexcept
{
    return size_;
}

bool Queue::contains(int value) const noexcept
{
    const Node* current = head_;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

std::string Queue::toString() const
{
    std::ostringstream stream;

    stream << '[';

    const Node* current = head_;

    while (current != nullptr)
    {
        stream << current->data;

        if (current->next != nullptr)
        {
            stream << ", ";
        }

        current = current->next;
    }

    stream << ']';

    return stream.str();
}

void Queue::clear() noexcept
{
    while (head_ != nullptr)
    {
        Node* next = head_->next;

        delete head_;

        head_ = next;
    }

    tail_ = nullptr;
    size_ = 0;
}

void Queue::copyFrom(const Queue& other)
{
    const Node* current = other.head_;

    while (current != nullptr)
    {
        enqueue(current->data);
        current = current->next;
    }
}
