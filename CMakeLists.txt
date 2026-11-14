cmake_minimum_required(VERSION 3.15)
project(DepartmentDemo LANGUAGES CXX)

add_executable(DepartmentDemo
    main.cpp
    Department.cpp
    Discipline.cpp
    Engineer.cpp
    Group.cpp
    Position.cpp
    Specialty.cpp
    Student.cpp
    Teacher.cpp
    Worker.cpp
)

target_compile_features(DepartmentDemo PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(DepartmentDemo PRIVATE /utf-8)
endif()
