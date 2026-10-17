#include "Group.h"

Group::Group(
    const std::string& name,
    const Specialty& specialty)
    : name_(name),
      specialty_(specialty)
{
}

void Group::addStudent(const Student& student)
{
    students_.push_back(student);
}

const std::string& Group::getName() const noexcept
{
    return name_;
}

const Specialty& Group::getSpecialty() const noexcept
{
    return specialty_;
}

const std::vector<Student>& Group::getStudents() const noexcept
{
    return students_;
}

std::string Group::toString() const
{
    return "Группа: " + name_
        + ", специальность: " + specialty_.toString()
        + ", студентов: " + std::to_string(students_.size());
}
