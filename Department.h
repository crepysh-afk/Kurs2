#pragma once

#include "Discipline.h"
#include "Group.h"
#include "Position.h"
#include "Specialty.h"
#include "Worker.h"

#include <memory>
#include <string>
#include <vector>

/**
 * @brief Кафедра.
 *
 * Содержит специальности, дисциплины, должности,
 * учебные группы и работников.
 * Студенты хранятся внутри учебных групп.
 */
class Department
{
private:
    std::string name_;

    std::vector<Specialty> specialties_;
    std::vector<Discipline> disciplines_;
    std::vector<Position> positions_;
    std::vector<Group> groups_;

    std::vector<std::unique_ptr<Worker>> workers_;

public:
    /**
     * @brief Создаёт кафедру.
     * @param name Название кафедры.
     */
    explicit Department(const std::string& name);

    /**
     * @brief Добавляет специальность.
     * @param specialty Добавляемая специальность.
     */
    void addSpecialty(const Specialty& specialty);

    /**
     * @brief Добавляет дисциплину.
     * @param discipline Добавляемая дисциплина.
     */
    void addDiscipline(const Discipline& discipline);

    /**
     * @brief Добавляет должность.
     * @param position Добавляемая должность.
     */
    void addPosition(const Position& position);

    /**
     * @brief Добавляет группу вместе с её студентами.
     * @param group Группа. В кафедре сохраняется её копия.
     */
    void addGroup(const Group& group);

    /**
     * @brief Добавляет работника и принимает владение им.
     * @param worker Умный указатель на работника.
     * @throws std::invalid_argument Если указатель пустой.
     */
    void addWorker(std::unique_ptr<Worker> worker);

    /**
     * @return Название кафедры.
     */
    const std::string& getName() const noexcept;

    /**
     * @return Специальности кафедры.
     */
    const std::vector<Specialty>& getSpecialties() const noexcept;

    /**
     * @return Дисциплины кафедры.
     */
    const std::vector<Discipline>& getDisciplines() const noexcept;

    /**
     * @return Должности кафедры.
     */
    const std::vector<Position>& getPositions() const noexcept;

    /**
     * @return Группы кафедры.
     */
    const std::vector<Group>& getGroups() const noexcept;

    /**
     * @return Коллекция работников базового типа Worker.
     */
    const std::vector<std::unique_ptr<Worker>>&
        getWorkers() const noexcept;

    /**
     * @return Сводная информация о кафедре.
     */
    std::string toString() const;
};
