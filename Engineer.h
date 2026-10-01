#pragma once

#include "Worker.h"

#include <string>

/**
 * @brief Инженер кафедры.
 *
 * Наследуется от базового класса Worker.
 */
class Engineer : public Worker
{
private:
    std::string specialization_;

public:
    /**
     * @brief Создаёт инженера.
     *
     * @param fullName ФИО инженера.
     * @param department Кафедра.
     * @param specialization Специализация инженера.
     */
    Engineer(
        const std::string& fullName,
        const std::string& department,
        const std::string& specialization);

    /**
     * @brief Возвращает специализацию инженера.
     *
     * @return Специализация.
     */
    const std::string& getSpecialization() const noexcept;

    /**
     * @brief Возвращает строковое представление инженера.
     *
     * @return Информация об инженере.
     */
    std::string toString() const override;
};
