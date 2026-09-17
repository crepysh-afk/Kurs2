#pragma once

#include "Generator.h"
#include <functional>

namespace miit::algebra
{
/**
* @brief Генератор чисел на основе переданной функции.
*/
    class FunctionGenerator final : public Generator
    {
    private:
/**
* @brief Функция генерации числа.
*/
        std::function<int()> function;

    public:
/**
* @brief Создаёт генератор на основе функции.
* @param function Функция, возвращающая целое число.
*/
        explicit FunctionGenerator(std::function<int()> function);
/**
* @brief Выполняет функцию генерации.
* @return Значение, возвращённое функцией.
*/
        int generate() override;
    };
}
