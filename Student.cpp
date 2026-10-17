#include "Student.h"

Student::Student(
    const std::string& fullName,
    const std::string& recordBookNumber)
    : fullName_(fullName),
      recordBookNumber_(recordBookNumber)
{
}

const std::string& Student::getFullName() const noexcept
{
    return fullName_;
}

const std::string& Student::getRecordBookNumber() const noexcept
{
    return recordBookNumber_;
}

std::string Student::toString() const
{
    return fullName_
        + ", зачётная книжка: "
        + recordBookNumber_;
}
