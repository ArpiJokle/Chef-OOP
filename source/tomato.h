#pragma once
#include "Header.h"

class Tomato : public BaseVegetable
{
private:
    std::string color;

public:
    ~Tomato() override = default;
    Tomato() = default;

    std::ostream &Print(std::ostream &out) const override
    {
        BaseVegetable::Print(out);
        out << "Color: " << color << " " << std::endl;
        return out;
    }

    std::istream &Read(std::istream &in) override
    {
        BaseVegetable::Read(in);
        in >> color;
        return in;
    }
};