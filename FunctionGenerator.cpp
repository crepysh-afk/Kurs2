#include "FunctionGenerator.h"
#include <stdexcept>

namespace miit::algebra
{
    FunctionGenerator::FunctionGenerator(cont std::function<int()> function)
        : function(std::move(function))
    {
        if (!this->function)
        {
            throw std::invalid_argument("Generator function is empty");
        }
    }

    int FunctionGenerator::generate()
    {
        return function();
    }
}
