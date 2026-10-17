#pragma once

#include <string>

/**
 * @brief Студент учебной группы.
 */
class Student
{
private:
    std::string fullName_;
    std::string recordBookNumber_;

public:
    /**
     * @brief Создаёт студента.
     * @param fullName ФИО студента.
     * @param recordBookNumber Номер зачётной книжки.
     */
    Student(
        const std::string& fullName,
        const std::string& recordBookNumber);

    /**
     * @return ФИО студента.
     */
    const std::string& getFullName() const noexcept;

    /**
     * @return Номер зачётной книжки.
     */
    const std::string& getRecordBookNumber() const noexcept;

    /**
     * @return Информация о студенте.
     */
    std::string toString() const;
};
