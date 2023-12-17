#pragma once
#include "Header.h"

class Cucumber : public BaseVegetable
{
private:
    int diameter;
    bool bitterEnds;

public:
    ~Cucumber() override = default;
    Cucumber() = default;

    std::ostream &Print(std::ostream &out) const override
    {
        BaseVegetable::Print(out);
        out << "Diameter: " << diameter << "cm. "
            << "Bitter ends: " << (bitterEnds ? "true " : "false ")
            << std::endl;
        return out;
    }

    std::istream &Read(std::istream &in) override
    {
        BaseVegetable::Read(in);
        in >> diameter >> bitterEnds;
        return in;
    }
};