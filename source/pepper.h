#pragma once
#include "Header.h"

class Pepper : public BaseVegetable
{
private:
    std::string color;
    bool spicy;

public:
    ~Pepper() override = default;
    Pepper() = default;

    std::ostream &Print(std::ostream &out) const override
    {
        BaseVegetable::Print(out);
        out << "Length: " << color << " "
            << "Spicy: " << (spicy ? "true " : "false ")
            << std::endl;
        return out;
    }

    std::istream &Read(std::istream &in) override
    {
        BaseVegetable::Read(in);
        in >> color >> spicy;
        return in;
    }
};