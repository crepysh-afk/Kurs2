#pragma once

#include <string>

/**
 * @brief Специальность, по которой обучаются группы.
 */
class Specialty
{
private:
    std::string code_;
    std::string name_;

public:
    /**
     * @brief Создаёт специальность.
     * @param code Код специальности.
     * @param name Название специальности.
     */
    Specialty(
        const std::string& code,
        const std::string& name);

    /**
     * @return Код специальности.
     */
    const std::string& getCode() const noexcept;

    /**
     * @return Название специальности.
     */
    const std::string& getName() const noexcept;

    /**
     * @return Строковое представление специальности.
     */
    std::string toString() const;
};
