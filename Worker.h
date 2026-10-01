#pragma once

#include <string>

/**
 * @brief Базовый класс работника кафедры.
 *
 * Содержит общую информацию, которая может быть
 * у преподавателей и инженеров.
 */
class Worker
{
protected:
    std::string fullName_;
    std::string position_;
    std::string department_;

public:
    /**
     * @brief Создаёт работника кафедры.
     *
     * @param fullName ФИО работника.
     * @param position Должность.
     * @param department Название кафедры.
     */
    Worker(
        const std::string& fullName,
        const std::string& position,
        const std::string& department);

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~Worker() = default;

    /**
     * @brief Возвращает ФИО работника.
     *
     * @return ФИО.
     */
    const std::string& getFullName() const noexcept;

    /**
     * @brief Возвращает должность.
     *
     * @return Должность.
     */
    const std::string& getPosition() const noexcept;

    /**
     * @brief Возвращает название кафедры.
     *
     * @return Название кафедры.
     */
    const std::string& getDepartment() const noexcept;

    /**
     * @brief Выводит информацию о работнике в строковом виде.
     *
     * @return Информация о работнике.
     */
    virtual std::string toString() const = 0;
};
