#pragma once

namespace miit::algebra
{
/**
* @brief Абстрактный базовый класс генератора чисел.
*/
    class Generator
    {
    public:
/**
* @brief Виртуальный деструктор.
*/
        virtual ~Generator() = default;
/**
* @brief Генерирует одно целое число.
* @return Сгенерированное целое число.
*/
        virtual int generate() = 0;
    };
}
