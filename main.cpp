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
    const std::string departmentName = "Кафедра информатики";

    const Specialty specialty(
        "09.03.01",
        "Информатика и вычислительная техника"
    );

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

    Teacher firstTeacher(
        "Иванов Иван Иванович",
        departmentName,
        {
            programming.getName(),
            algorithms.getName()
        },
        {
            "Лекции",
            "Лабораторные"
        }
    );

    Engineer engineer(
        "Петров Пётр Петрович",
        departmentName,
        "Системное администрирование"
    );

    Teacher secondTeacher(
        "Сидорова Анна Сергеевна",
        departmentName,
        {
            databases.getName(),
            programming.getName()
        },
        databases.getLessonTypes()
    );

    Department department(departmentName);

    department.addSpecialty(specialty);

    department.addDiscipline(programming);
    department.addDiscipline(algorithms);
    department.addDiscipline(databases);

    department.addPosition(Position("Преподаватель"));
    department.addPosition(Position("Инженер"));

    Group firstGroup("ИВТ-201", specialty);

    firstGroup.addStudent(
        Student("Смирнов Алексей Андреевич", "24001")
    );

    firstGroup.addStudent(
        Student("Кузнецова Мария Олеговна", "24002")
    );

    Group secondGroup("ИВТ-202", specialty);

    secondGroup.addStudent(
        Student("Орлов Дмитрий Сергеевич", "24003")
    );

    department.addGroup(firstGroup);
    department.addGroup(secondGroup);

    department.addWorker(&firstTeacher);
    department.addWorker(&engineer);
    department.addWorker(&secondTeacher);

    std::cout << department.toString()
              << "\n\nСпециальности:\n";

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

    for (const Worker* worker : department.getWorkers())
    {
        std::cout << worker->toString() << "\n\n";
    }

    const Worker* found =
        department.findWorker("Иванов Иван Иванович");

    if (found != nullptr)
    {
        std::cout << "Найден работник: "
                  << found->toString()
                  << '\n';
    }
    else
    {
        std::cout << "Работник не найден.\n";
    }

    if (department.findWorker("Неизвестный работник") == nullptr)
    {
        std::cout
            << "Неизвестный работник: на кафедре такого работника нет.\n";
    }

    return 0;
}
