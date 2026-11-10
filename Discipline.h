#pragma once 

#include <string> 
#include 


class Discipline
{
private:
    std::string name_;
    std::vector<std::string> lessonTypes_; 

public:
    Discipline(
        const std::string& name,
        const std::vector<std::string>& lessonTypes
    );
    const std::string& getName() const noexcept;
    const std::vector<std::string>& getLessonTypes() const noexcept;

    // Получение информации в виде строки.
    std::string toString() const;
};
