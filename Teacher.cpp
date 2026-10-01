#include "Teacher.h"

#include <sstream>

Teacher::Teacher(
    const std::string& fullName,
    const std::string& department,
    const std::vector<std::string>& disciplines,
    const std::vector<std::string>& lessonTypes)
    : Worker(fullName, "Преподаватель", department),
      disciplines_(disciplines),
      lessonTypes_(lessonTypes)
{
}

const std::vector<std::string>& Teacher::getDisciplines() const noexcept
{
    return disciplines_;
}

const std::vector<std::string>& Teacher::getLessonTypes() const noexcept
{
    return lessonTypes_;
}

bool Teacher::teachesDiscipline(const std::string& discipline) const
{
    for (const std::string& current : disciplines_)
    {
        if (current == discipline)
        {
            return true;
        }
    }

    return false;
}

std::string Teacher::toString() const
{
    std::ostringstream stream;

    stream << "Преподаватель: " << fullName_
           << ", кафедра: " << department_
           << ", дисциплины: ";

    for (std::size_t i = 0; i < disciplines_.size(); ++i)
    {
        stream << disciplines_[i];

        if (i + 1 < disciplines_.size())
        {
            stream << ", ";
        }
    }

    stream << ", виды занятий: ";

    for (std::size_t i = 0; i < lessonTypes_.size(); ++i)
    {
        stream << lessonTypes_[i];

        if (i + 1 < lessonTypes_.size())
        {
            stream << ", ";
        }
    }

    return stream.str();
}
