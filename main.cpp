#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Department.h"
#include "Engineer.h"
#include "Teacher.h"

/**
 * @brief Точка входа в демонстрационную программу.
 *
 * Создаёт кафедру, специальность, дисциплины, должности,
 * группы, студентов и работников.
 *
 * Работники хранятся как коллекция умных указателей
 * на базовый класс Worker. Вывод использует полиморфизм.
 *
 * @return 0 при успешном завершении.
 */
int main()
{
    Department department("Кафедра информатики");

    // Специальность.

    const Specialty specialty(
        "09.03.01",
        "Информатика и вычислительная техника"
    );

    department.addSpecialty(specialty);

    // Дисциплины и виды занятий по ним.

    const Discipline programming(
        "Программирование",
        {
            "Лекции",
            "Лабораторные",
            "Практические занятия"
        }
    );

    const Discipline algorithms(
        "Алгоритмы",
        {
            "Лекции",
            "Лабораторные"
        }
    );

    const Discipline databases(
        "Базы данных",
        {
            "Лекции",
            "Практические занятия"
        }
    );

    department.addDiscipline(programming);
    department.addDiscipline(algorithms);
    department.addDiscipline(databases);

    // Должности.

    department.addPosition(Position("Преподаватель"));
    department.addPosition(Position("Инженер"));

    // Первая группа и её студенты.

    Group firstGroup("ИВТ-201", specialty);

    firstGroup.addStudent(
        Student("Смирнов Алексей Андреевич", "24001")
    );

    firstGroup.addStudent(
        Student("Кузнецова Мария Олеговна", "24002")
    );

    // Вторая группа и её студент.

    Group secondGroup("ИВТ-202", specialty);

    secondGroup.addStudent(
        Student("Орлов Дмитрий Сергеевич", "24003")
    );

    // Добавляем уже заполненные группы на кафедру.

    department.addGroup(firstGroup);
    department.addGroup(secondGroup);

    // Работники — прежние классы Teacher и Engineer.

    department.addWorker(
        std::make_unique<Teacher>(
            "Иванов Иван Иванович",
            department.getName(),
            std::vector<std::string>{
                programming.getName(),
                algorithms.getName()
            },
            std::vector<std::string>{
                "Лекции",
                "Лабораторные"
            }
        )
    );

    department.addWorker(
        std::make_unique<Engineer>(
            "Петров Пётр Петрович",
            department.getName(),
            "Системное администрирование"
        )
    );

    department.addWorker(
        std::make_unique<Teacher>(
            "Сидорова Анна Сергеевна",
            department.getName(),
            std::vector<std::string>{
                databases.getName(),
                programming.getName()
            },
            databases.getLessonTypes()
        )
    );

    // Вывод информации.

    std::cout << department.toString() << "\n\n";

    std::cout << "Специальности:\n";

    for (const Specialty& item : department.getSpecialties())
    {
        std::cout << item.toString() << '\n';
    }

    std::cout << "\nДисциплины:\n";

    for (const Discipline& item : department.getDisciplines())
    {
        std::cout << item.toString() << '\n';
    }

    std::cout << "\nДолжности:\n";

    for (const Position& item : department.getPositions())
    {
        std::cout << item.toString() << '\n';
    }

    std::cout << "\nГруппы и студенты:\n";

    for (const Group& group : department.getGroups())
    {
        std::cout << group.toString() << '\n';

        for (const Student& student : group.getStudents())
        {
            std::cout << "  " << student.toString() << '\n';
        }
    }

    std::cout << "\nРаботники кафедры:\n";

    for (const std::unique_ptr<Worker>& worker
         : department.getWorkers())
    {
        std::cout << worker->toString() << "\n\n";
    }

    return 0;
}
