#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Engineer.h"
#include "Teacher.h"
#include "Worker.h"

/**
 * @brief Точка входа в демонстрационную программу.
 *
 * Создаёт коллекцию объектов базового типа Worker,
 * заполняет её объектами производных типов Teacher и Engineer,
 * после чего выводит информацию обо всех работниках.
 */
int main()
{
    std::vector<std::unique_ptr<Worker>> workers;

    workers.push_back(
        std::make_unique<Teacher>(
            "Иванов Иван Иванович",
            "Кафедра информатики",
            std::vector<std::string>{
                "Программирование",
                "Алгоритмы"
            },
            std::vector<std::string>{
                "Лекции",
                "Лабораторные"
            }
        )
    );

    workers.push_back(
        std::make_unique<Engineer>(
            "Петров Пётр Петрович",
            "Кафедра информатики",
            "Системное администрирование"
        )
    );

    workers.push_back(
        std::make_unique<Teacher>(
            "Сидорова Анна Сергеевна",
            "Кафедра информатики",
            std::vector<std::string>{
                "Базы данных",
                "Программирование"
            },
            std::vector<std::string>{
                "Лекции",
                "Практические занятия"
            }
        )
    );

    std::cout << "Работники кафедры:\n\n";

    for (const std::unique_ptr<Worker>& worker : workers)
    {
        std::cout << worker->toString() << "\n\n";
    }

    return 0;
}
