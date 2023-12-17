#pragma once
#include "Header.h"

class BaseVegetable
{
private:
    std::string name;
    double weight;
    int caloricity;
    double cost;

public:
    BaseVegetable() = default;
    virtual ~BaseVegetable() = default;

    std::string GetName() const { return name; }
    double GetWeight() const { return weight; }
    int GetCaloricity() const { return caloricity; }
    double GetCost() const { return cost; }

    virtual std::ostream &Print(std::ostream &out) const
    {
        out << "Name: " << name << ", "
            << "Weight: " << weight << "g., "
            << "Caloricity: " << caloricity << "Kkl., "
            << "Cost: " << cost << "BYN/kg. ";
        return out;
    }

    virtual std::istream &Read(std::istream &in)
    {
        in >> name >> weight >> caloricity >> cost;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out,
        std::shared_ptr<BaseVegetable> vegetable)
    {
        vegetable->Print(out);
        return out;
    }

    friend std::istream &operator>>(std::istream &in,
        std::shared_ptr<BaseVegetable> vegetable)
    {
        vegetable->Read(in);
        return in;
    }
};