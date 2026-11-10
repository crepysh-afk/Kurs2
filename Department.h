#pragma once

#include "Discipline.h"
#include "Group.h"
#include "Position.h"
#include "Specialty.h"
#include "Worker.h"

#include <string>
#include <vector>

/**
 * @brief Кафедра.
 *
 * Содержит специальности, дисциплины, должности,
 * учебные группы и указатели на работников.
 * Студенты хранятся внутри учебных групп.
 *
 * Кафедра не владеет работниками и не удаляет их.
 * Работники должны существовать всё время использования
 * сохранённых указателей.
 */
class Department
{
private:
    std::string name_;

    std::vector<Specialty> specialties_;
    std::vector<Discipline> disciplines_;
    std::vector<Position> positions_;
    std::vector<Group> groups_;
    std::vector<Worker*> workers_;

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

    /**
     * @brief Добавляет указатель на работника кафедры.
     *
     * Проверяет указатель на nullptr и отсутствие работника
     * с таким же ФИО. Владение объектом не передаётся.
     *
     * @param worker Указатель на существующего работника.
     *
     * @throws std::invalid_argument Если передан nullptr
     * или работник с таким ФИО уже добавлен.
     */
    void addWorker(Worker* worker);

    /**
     * @brief Находит работника по полному совпадению ФИО.
     *
     * @param fullName ФИО искомого работника.
     *
     * @return Указатель на найденного работника,
     * доступного только для чтения, или nullptr,
     * если работник не найден.
     */
    const Worker* findWorker(const std::string& fullName) const;

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

    /**
     * @brief Возвращает коллекцию указателей на работников.
     *
     * Полученная ссылка не позволяет менять состав коллекции.
     * Владение работниками не передаётся.
     *
     * @return Константная ссылка на список указателей Worker*.
     */
    const std::vector<Worker>& getWorkers() const noexcept;

    /**
     * @brief Формирует сводную информацию о кафедре.
     *
     * @return Строка с названием кафедры,
     * количеством работников и учебных групп.
     */
    std::string toString() const;
};
