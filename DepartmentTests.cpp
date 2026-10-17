#include "CppUnitTest.h"

#include "Department.h"
#include "Engineer.h"
#include "Teacher.h"

#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DepartmentTests
{
    TEST_CLASS(DepartmentModelTests)
    {
    public:
        TEST_METHOD(Specialty_StoresData)
        {
            const Specialty specialty(
                "09.03.01",
                "Информатика"
            );

            Assert::AreEqual(
                std::string("09.03.01"),
                specialty.getCode()
            );

            Assert::AreEqual(
                std::string("Информатика"),
                specialty.getName()
            );

            Assert::AreEqual(
                std::string("09.03.01 - Информатика"),
                specialty.toString()
            );
        }

        TEST_METHOD(Position_StoresData)
        {
            const Position position("Преподаватель");

            Assert::AreEqual(
                std::string("Преподаватель"),
                position.getName()
            );

            Assert::AreEqual(
                std::string("Преподаватель"),
                position.toString()
            );
        }

        TEST_METHOD(Student_StoresData)
        {
            const Student student("Иванов Иван", "24001");

            Assert::AreEqual(
                std::string("Иванов Иван"),
                student.getFullName()
            );

            Assert::AreEqual(
                std::string("24001"),
                student.getRecordBookNumber()
            );

            Assert::AreEqual(
                std::string(
                    "Иванов Иван, зачётная книжка: 24001"
                ),
                student.toString()
            );
        }

        TEST_METHOD(Discipline_StoresLessonTypes)
        {
            const Discipline discipline(
                "Физика",
                {
                    "Лекции",
                    "Лабораторные"
                }
            );

            const std::vector<std::string>& types =
                discipline.getLessonTypes();

            Assert::AreEqual(
                std::string("Физика"),
                discipline.getName()
            );

            Assert::AreEqual<std::size_t>(
                2,
                types.size()
            );

            Assert::AreEqual(
                std::string("Лекции"),
                types[0]
            );

            Assert::AreEqual(
                std::string("Лабораторные"),
                types[1]
            );

            Assert::AreEqual(
                std::string(
                    "Физика, виды занятий: Лекции, Лабораторные"
                ),
                discipline.toString()
            );
        }

        TEST_METHOD(Discipline_AllowsEmptyLessonTypes)
        {
            const Discipline discipline("Физика", {});

            Assert::IsTrue(
                discipline.getLessonTypes().empty()
            );

            Assert::AreEqual(
                std::string("Физика, виды занятий: "),
                discipline.toString()
            );
        }

        TEST_METHOD(Group_StoresSpecialtyAndStudents)
        {
            const Specialty specialty(
                "09.03.01",
                "Информатика"
            );

            Group group("ИВТ-201", specialty);

            Assert::AreEqual(
                std::string("ИВТ-201"),
                group.getName()
            );

            Assert::AreEqual(
                specialty.getCode(),
                group.getSpecialty().getCode()
            );

            Assert::AreEqual(
                specialty.getName(),
                group.getSpecialty().getName()
            );

            Assert::IsTrue(
                group.getStudents().empty()
            );

            group.addStudent(
                Student("Иванов Иван", "24001")
            );

            group.addStudent(
                Student("Петров Пётр", "24002")
            );

            Assert::AreEqual<std::size_t>(
                2,
                group.getStudents().size()
            );

            Assert::AreEqual(
                std::string("24001"),
                group.getStudents()[0].getRecordBookNumber()
            );

            Assert::AreEqual(
                std::string("24002"),
                group.getStudents()[1].getRecordBookNumber()
            );

            Assert::AreEqual(
                std::string(
                    "Группа: ИВТ-201, специальность: "
                    "09.03.01 - Информатика, студентов: 2"
                ),
                group.toString()
            );
        }

        TEST_METHOD(Department_StoresCollections)
        {
            Department department("Кафедра информатики");

            const Specialty specialty(
                "09.03.01",
                "Информатика"
            );

            Group group("ИВТ-201", specialty);

            group.addStudent(
                Student("Иванов Иван", "24001")
            );

            Assert::AreEqual(
                std::string("Кафедра информатики"),
                department.getName()
            );

            Assert::IsTrue(
                department.getSpecialties().empty()
            );

            Assert::IsTrue(
                department.getDisciplines().empty()
            );

            Assert::IsTrue(
                department.getPositions().empty()
            );

            Assert::IsTrue(
                department.getGroups().empty()
            );

            Assert::IsTrue(
                department.getWorkers().empty()
            );

            department.addSpecialty(specialty);

            department.addDiscipline(
                Discipline("Физика", {"Лекции"})
            );

            department.addPosition(
                Position("Преподаватель")
            );

            department.addGroup(group);

            Assert::AreEqual<std::size_t>(
                1,
                department.getSpecialties().size()
            );

            Assert::AreEqual<std::size_t>(
                1,
                department.getDisciplines().size()
            );

            Assert::AreEqual<std::size_t>(
                1,
                department.getPositions().size()
            );

            Assert::AreEqual<std::size_t>(
                1,
                department.getGroups().size()
            );

            Assert::AreEqual(
                specialty.getCode(),
                department.getSpecialties()[0].getCode()
            );

            Assert::AreEqual(
                std::string("Физика"),
                department.getDisciplines()[0].getName()
            );

            Assert::AreEqual(
                std::string("Преподаватель"),
                department.getPositions()[0].getName()
            );

            Assert::AreEqual(
                std::string("ИВТ-201"),
                department.getGroups()[0].getName()
            );

            Assert::AreEqual<std::size_t>(
                1,
                department.getGroups()[0].getStudents().size()
            );

            Assert::AreEqual(
                std::string("24001"),
                department.getGroups()[0]
                    .getStudents()[0]
                    .getRecordBookNumber()
            );

            Assert::AreEqual(
                std::string(
                    "Кафедра информатики, работников: 0, групп: 1"
                ),
                department.toString()
            );
        }

        TEST_METHOD(Department_OwnsDifferentWorkerTypes)
        {
            Department department("Кафедра информатики");

            std::unique_ptr<Worker> teacher =
                std::make_unique<Teacher>(
                    "Иванов Иван",
                    department.getName(),
                    std::vector<std::string>{
                        "Физика"
                    },
                    std::vector<std::string>{
                        "Лекции"
                    }
                );

            const std::string expectedTeacher =
                teacher->toString();

            department.addWorker(std::move(teacher));

            // Владение объектом перешло кафедре.
            Assert::IsTrue(teacher == nullptr);

            auto engineer = std::make_unique<Engineer>(
                "Петров Пётр",
                department.getName(),
                "Сети"
            );

            const std::string expectedEngineer =
                engineer->toString();

            department.addWorker(std::move(engineer));

            const auto& workers = department.getWorkers();

            Assert::AreEqual<std::size_t>(
                2,
                workers.size()
            );

            // Вызовы через Worker сохраняют поведение наследников.
            Assert::AreEqual(
                expectedTeacher,
                workers[0]->toString()
            );

            Assert::AreEqual(
                expectedEngineer,
                workers[1]->toString()
            );

            Assert::AreEqual(
                std::string(
                    "Кафедра информатики, работников: 2, групп: 0"
                ),
                department.toString()
            );
        }

        TEST_METHOD(Department_RejectsNullWorker)
        {
            Department department("Кафедра информатики");

            Assert::ExpectException<std::invalid_argument>(
                [&department]()
                {
                    department.addWorker(nullptr);
                }
            );

            Assert::IsTrue(
                department.getWorkers().empty()
            );
        }
    };
}
