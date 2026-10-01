#include "CppUnitTest.h"

#include "../DepartmentLibrary/Engineer.h"
#include "../DepartmentLibrary/Teacher.h"
#include "../DepartmentLibrary/Worker.h"

#include <memory>
#include <string>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DepartmentTests
{
    TEST_CLASS(WorkerTests)
    {
    public:

        TEST_METHOD(Teacher_CreatesCorrectObject)
        {
            const Teacher teacher(
                "Иванов Иван Иванович",
                "Кафедра информатики",
                {
                    "Программирование",
                    "Алгоритмы"
                },
                {
                    "Лекции",
                    "Лабораторные"
                }
            );

            Assert::AreEqual(
                std::string("Иванов Иван Иванович"),
                teacher.getFullName()
            );

            Assert::AreEqual(
                std::string("Преподаватель"),
                teacher.getPosition()
            );

            Assert::AreEqual(
                std::string("Кафедра информатики"),
                teacher.getDepartment()
            );
        }

        TEST_METHOD(Teacher_ContainsDiscipline)
        {
            const Teacher teacher(
                "Иванов Иван Иванович",
                "Кафедра информатики",
                {
                    "Программирование",
                    "Алгоритмы"
                },
                {
                    "Лекции",
                    "Лабораторные"
                }
            );

            Assert::IsTrue(
                teacher.teachesDiscipline("Программирование")
            );

            Assert::IsTrue(
                teacher.teachesDiscipline("Алгоритмы")
            );

            Assert::IsFalse(
                teacher.teachesDiscipline("Физика")
            );
        }

        TEST_METHOD(Teacher_ReturnsLessonTypes)
        {
            const Teacher teacher(
                "Иванов Иван Иванович",
                "Кафедра информатики",
                {
                    "Программирование"
                },
                {
                    "Лекции",
                    "Лабораторные"
                }
            );

            const std::vector<std::string>& lessonTypes =
                teacher.getLessonTypes();

            Assert::AreEqual<std::size_t>(
                2,
                lessonTypes.size()
            );

            Assert::AreEqual(
                std::string("Лекции"),
                lessonTypes[0]
            );

            Assert::AreEqual(
                std::string("Лабораторные"),
                lessonTypes[1]
            );
        }

        TEST_METHOD(Engineer_CreatesCorrectObject)
        {
            const Engineer engineer(
                "Петров Пётр Петрович",
                "Кафедра информатики",
                "Системное администрирование"
            );

            Assert::AreEqual(
                std::string("Петров Пётр Петрович"),
                engineer.getFullName()
            );

            Assert::AreEqual(
                std::string("Инженер"),
                engineer.getPosition()
            );

            Assert::AreEqual(
                std::string("Системное администрирование"),
                engineer.getSpecialization()
            );
        }

        TEST_METHOD(Polymorphism_WorksCorrectly)
        {
            std::unique_ptr<Worker> worker =
                std::make_unique<Teacher>(
                    "Иванов Иван Иванович",
                    "Кафедра информатики",
                    std::vector<std::string>{
                        "Программирование"
                    },
                    std::vector<std::string>{
                        "Лекции"
                    }
                );

            const std::string result = worker->toString();

            Assert::IsTrue(
                result.find("Преподаватель") != std::string::npos
            );

            Assert::IsTrue(
                result.find("Программирование") != std::string::npos
            );
        }

        TEST_METHOD(Engineer_ToStringContainsSpecialization)
        {
            const Engineer engineer(
                "Петров Пётр Петрович",
                "Кафедра информатики",
                "Системное администрирование"
            );

            const std::string result = engineer.toString();

            Assert::IsTrue(
                result.find("Инженер") != std::string::npos
            );

            Assert::IsTrue(
                result.find("Системное администрирование")
                != std::string::npos
            );
        }
    };
}
