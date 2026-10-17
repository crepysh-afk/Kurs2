#include "Position.h"

Position::Position(const std::string& name)
    : name_(name)
{
}

const std::string& Position::getName() const noexcept
{
    return name_;
}

std::string Position::toString() const
{
    return name_;
}
