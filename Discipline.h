#pragma once

#include <string>
#include <vector>

/**
 * @brief Дисциплина, преподаваемая на кафедре.
 */
class Discipline
{
private:
    std::string name_;
    std::vector<std::string> lessonTypes_;

public:
    /**
     * @brief Создаёт дисциплину.
     * @param name Название дисциплины.
     * @param lessonTypes Виды занятий по дисциплине.
     */
    Discipline(
        const std::string& name,
        const std::vector<std::string>& lessonTypes);

    /**
     * @return Название дисциплины.
     */
    const std::string& getName() const noexcept;

    /**
     * @return Виды занятий по дисциплине.
     */
    const std::vector<std::string>& getLessonTypes() const noexcept;

    /**
     * @return Информация о дисциплине.
     */
    std::string toString() const;
};
