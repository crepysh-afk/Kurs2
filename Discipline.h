#pragma once 

#include <string> 
#include <vector>


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
    std::string toString() const;
};
