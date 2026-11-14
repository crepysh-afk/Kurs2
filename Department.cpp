#include "Department.h"

#include <stdexcept>

Department::Department(const std::string& name)
    : name_(name)
{
}

void Department::addSpecialty(const Specialty& specialty)
{
    specialties_.push_back(specialty);
}

void Department::addDiscipline(const Discipline& discipline)
{
    disciplines_.push_back(discipline);
}

void Department::addPosition(const Position& position)
{
    positions_.push_back(position);
}

void Department::addGroup(const Group& group)
{
    groups_.push_back(group);
}

void Department::addWorker(const Teacher& worker)
{
    if (!findWorker(worker.getFullName()).empty())
    {
        throw std::invalid_argument(
            "Работник с таким ФИО уже добавлен."
        );
    }
    teachers_.push_back(worker);
}

void Department::addWorker(const Engineer& worker)
{
    if (!findWorker(worker.getFullName()).empty())
    {
        throw std::invalid_argument(
            "Работник с таким ФИО уже добавлен."
        );
    }

    engineers_.push_back(worker);
}

std::string Department::findWorker(
    const std::string& fullName
) const
{
    for (const Teacher& worker : teachers_)
    {
        if (worker.getFullName() == fullName)
        {
            return worker.toString();
        }
    }

    for (const Engineer& worker : engineers_)
    {
        if (worker.getFullName() == fullName)
        {
            return worker.toString();
        }
    }
    return "";
}

const std::string& Department::getName() const noexcept
{
    return name_;
}

const std::vector<Specialty>&
Department::getSpecialties() const noexcept
{
    return specialties_;
}

const std::vector<Discipline>&
Department::getDisciplines() const noexcept
{
    return disciplines_;
}

const std::vector<Position>&
Department::getPositions() const noexcept
{
    return positions_;
}

const std::vector<Group>&
Department::getGroups() const noexcept
{
    return groups_;
}

const std::vector<Teacher>&
Department::getTeachers() const noexcept
{
    return teachers_;
}

const std::vector<Engineer>&
Department::getEngineers() const noexcept
{
    return engineers_;
}

std::string Department::toString() const
{
    return name_
        + ", работников: " + std::to_string(teachers_.size() + engineers_.size())
        + ", групп: " + std::to_string(groups_.size());
}
