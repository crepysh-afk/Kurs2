#pragma once

#include <string>

/**
 * @brief Должность на кафедре.
 */
class Position
{
private:
    std::string name_;

public:
    /**
     * @brief Создаёт должность.
     * @param name Название должности.
     */
    Position(const std::string& name);

    /**
     * @return Название должности.
     */
    const std::string& getName() const noexcept;

    /**
     * @return Строковое представление должности.
     */
    std::string toString() const;
};
