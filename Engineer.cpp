#include "Engineer.h"

#include <sstream>

Engineer::Engineer(
    const std::string& fullName,
    const std::string& department,
    const std::string& specialization)
    : Worker(fullName, "Инженер", department),
      specialization_(specialization)
{
}

const std::string& Engineer::getSpecialization() const noexcept
{
    return specialization_;
}

std::string Engineer::toString() const
{
    std::ostringstream stream;

    stream << "Инженер: " << fullName_
           << ", кафедра: " << department_
           << ", специализация: " << specialization_;

    return stream.str();
}
