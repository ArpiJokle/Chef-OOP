#pragma once
#include "Header.h"

class Carrot : public BaseVegetable
{
private:
    int length;

public:
    ~Carrot() override = default;
    Carrot() = default;

    std::ostream &Print(std::ostream &out) const override
    {
        BaseVegetable::Print(out);
        out << "Length: " << length << "cm. " << std::endl;
        return out;
    }

    std::istream &Read(std::istream &in) override
    {
        BaseVegetable::Read(in);
        in >> length;
        return in;
    }
};