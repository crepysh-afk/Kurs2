#pragma once

#include "Specialty.h"
#include "Student.h"

#include <string>
#include <vector>

/**
 * @brief Учебная группа.
 *
 * Хранит специальность и список студентов.
 */
class Group
{
private:
    std::string name_;
    Specialty specialty_;
    std::vector<Student> students_;

public:
    /**
     * @brief Создаёт учебную группу.
     * @param name Название группы.
     * @param specialty Специальность группы.
     */
    Group(
        const std::string& name,
        const Specialty& specialty);

    /**
     * @brief Добавляет студента в группу.
     * @param student Студент. В группе сохраняется его копия.
     */
    void addStudent(const Student& student);

    /**
     * @return Название группы.
     */
    const std::string& getName() const noexcept;

    /**
     * @return Специальность группы.
     */
    const Specialty& getSpecialty() const noexcept;

    /**
     * @return Список студентов группы.
     */
    const std::vector<Student>& getStudents() const noexcept;

    /**
     * @return Информация о группе.
     */
    std::string toString() const;
};
