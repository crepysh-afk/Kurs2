#include "Specialty.h"

Specialty::Specialty(
    const std::string& code,
    const std::string& name)
    : code_(code),
      name_(name)
{
}

const std::string& Specialty::getCode() const noexcept
{
    return code_;
}

const std::string& Specialty::getName() const noexcept
{
    return name_;
}

std::string Specialty::toString() const
{
    return code_ + " - " + name_;
}
