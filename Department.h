#pragma once

#include "Discipline.h"
#include "Group.h"
#include "Position.h"
#include "Specialty.h"
#include "Teacher.h"
#include "Engineer.h"

#include <string>
#include <vector>

/**
 * @brief Кафедра.
 *
 * Содержит специальности, дисциплины, должности,
 * учебные группы, преподавателей и инженеров.
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
    std::vector<Teacher> teachers_;
    std::vector<Engineer> engineers_;

public:
    /**
     * @brief Создаёт кафедру с пустыми коллекциями.
     *
     * @param name Название кафедры.
     */
    explicit Department(const std::string& name);

    /**
     * @brief Добавляет специальность на кафедру.
     *
     * В коллекции сохраняется копия специальности.
     *
     * @param specialty Добавляемая специальность.
     */
    void addSpecialty(const Specialty& specialty);

    /**
     * @brief Добавляет дисциплину на кафедру.
     *
     * В коллекции сохраняется копия дисциплины.
     *
     * @param discipline Добавляемая дисциплина.
     */
    void addDiscipline(const Discipline& discipline);

    /**
     * @brief Добавляет должность на кафедру.
     *
     * В коллекции сохраняется копия должности.
     *
     * @param position Добавляемая должность.
     */
    void addPosition(const Position& position);

    /**
     * @brief Добавляет учебную группу вместе с её студентами.
     *
     * В коллекции сохраняется копия группы.
     *
     * @param group Добавляемая группа.
     */
    void addGroup(const Group& group);

    // Сохраняет копию работника; одинаковые ФИО не допускаются.
    void addWorker(const Teacher& worker);
    void addWorker(const Engineer& worker);

    /**
     * @brief Находит работника по полному совпадению ФИО.
     *
     * @param fullName ФИО искомого работника.
     *
     * @return Информация о работнике или пустая строка,
     * если работник не найден.
     */
    std::string findWorker(const std::string& fullName) const;

    /**
     * @brief Возвращает название кафедры.
     *
     * @return Константная ссылка на название кафедры.
     */
    const std::string& getName() const noexcept;

    /**
     * @brief Возвращает специальности кафедры.
     *
     * @return Константная ссылка на список специальностей.
     */
    const std::vector<Specialty>& getSpecialties() const noexcept;

    /**
     * @brief Возвращает дисциплины кафедры.
     *
     * @return Константная ссылка на список дисциплин.
     */
    const std::vector<Discipline>& getDisciplines() const noexcept;

    /**
     * @brief Возвращает должности кафедры.
     *
     * @return Константная ссылка на список должностей.
     */
    const std::vector<Position>& getPositions() const noexcept;

    /**
     * @brief Возвращает учебные группы кафедры.
     *
     * @return Константная ссылка на список групп.
     */
    const std::vector<Group>& getGroups() const noexcept;

    const std::vector<Teacher>& getTeachers() const noexcept;
    const std::vector<Engineer>& getEngineers() const noexcept;

    /**
     * @brief Формирует сводную информацию о кафедре.
     *
     * @return Строка с названием кафедры,
     * количеством работников и учебных групп.
     */
    std::string toString() const;
};
