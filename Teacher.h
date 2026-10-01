#pragma once

#include "Worker.h"

#include <string>
#include <vector>

/**
 * @brief Преподаватель кафедры.
 *
 * Наследуется от базового класса Worker.
 * Хранит дисциплины и виды занятий.
 */
class Teacher : public Worker
{
private:
    std::vector<std::string> disciplines_;
    std::vector<std::string> lessonTypes_;

public:
    /**
     * @brief Создаёт преподавателя.
     *
     * @param fullName ФИО преподавателя.
     * @param department Кафедра.
     * @param disciplines Дисциплины преподавателя.
     * @param lessonTypes Виды занятий.
     */
    Teacher(
        const std::string& fullName,
        const std::string& department,
        const std::vector<std::string>& disciplines,
        const std::vector<std::string>& lessonTypes);

    /**
     * @brief Возвращает дисциплины преподавателя.
     *
     * @return Список дисциплин.
     */
    const std::vector<std::string>& getDisciplines() const noexcept;

    /**
     * @brief Возвращает виды занятий.
     *
     * @return Список видов занятий.
     */
    const std::vector<std::string>& getLessonTypes() const noexcept;

    /**
     * @brief Проверяет, ведёт ли преподаватель указанную дисциплину.
     *
     * @param discipline Название дисциплины.
     * @return true, если дисциплина есть в списке.
     */
    bool teachesDiscipline(const std::string& discipline) const;

    /**
     * @brief Возвращает строковое представление преподавателя.
     *
     * @return Информация о преподавателе.
     */
    std::string toString() const override;
};
