#include "Discipline.h"

Discipline::Discipline(
    const std::string& name,
    const std::vector<std::string>& lessonTypes)
    : name_(name),
      lessonTypes_(lessonTypes)
{
}

const std::string& Discipline::getName() const noexcept
{
    return name_;
}

const std::vector<std::string>&
Discipline::getLessonTypes() const noexcept
{
    return lessonTypes_;
}

std::string Discipline::toString() const
{
    std::string result = name_ + ", виды занятий: ";

    for (std::size_t i = 0; i < lessonTypes_.size(); ++i)
    {
        result += lessonTypes_[i];

        if (i + 1 < lessonTypes_.size())
        {
            result += ", ";
        }
    }

    return result;
}
