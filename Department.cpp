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

void Department::addWorker(Worker* worker)
{
    if (worker == nullptr)
    {
        throw std::invalid_argument(
            "Работник не существует: передан пустой указатель."
        );
    }

    if (findWorker(worker->getFullName()) != nullptr)
    {
        throw std::invalid_argument(
            "Работник с таким ФИО уже добавлен."
        );
    }

    workers_.push_back(worker);
}

const Worker* Department::findWorker(
    const std::string& fullName
) const
{
    for (const Worker* worker : workers_)
    {
        if (worker->getFullName() == fullName)
        {
            return worker;
        }
    }

    return nullptr;
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

const std::vector<Worker*>&
Department::getWorkers() const noexcept
{
    return workers_;
}

std::string Department::toString() const
{
    return name_
        + ", работников: " + std::to_string(workers_.size())
        + ", групп: " + std::to_string(groups_.size());
}
