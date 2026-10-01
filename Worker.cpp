#include "Worker.h"

Worker::Worker(
    const std::string& fullName,
    const std::string& position,
    const std::string& department)
    : fullName_(fullName),
      position_(position),
      department_(department)
{
}

const std::string& Worker::getFullName() const noexcept
{
    return fullName_;
}

const std::string& Worker::getPosition() const noexcept
{
    return position_;
}

const std::string& Worker::getDepartment() const noexcept
{
    return department_;
}
