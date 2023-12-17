#pragma once
#include "Header.h"

class Vegetables
{
public:
    std::vector<std::shared_ptr<BaseVegetable>> data;
    ~Vegetables() = default;
    Vegetables() = default;

    void sortByWeight();
    void SortByCalorisity();
    void SortByCost();

    void Print(std::ostream &out)
    {
        std::copy(data.begin(), data.end(),
                  std::ostream_iterator<std::shared_ptr<BaseVegetable>>(out));
    }

    void Read(std::istream &in)
    {
        char vegetableType;
        while (in >> vegetableType)
        {
            std::shared_ptr<BaseVegetable> veg;
            switch (vegetableType)
            {
            case 't':
                veg = std::make_shared<Tomato>();
                break;
            case 'p':
                veg = std::make_shared<Pepper>();
                break;
            case 'a':
                veg = std::make_shared<Carrot>();
                break;
            case 'u':
                veg = std::make_shared<Cucumber>();
                break;
            }
            in >> veg;
            data.push_back(veg);
        }
    }
};

void Vegetables::SortByCalorisity()
{
    using VegetablePtr = std::shared_ptr<BaseVegetable>;
    std::sort(data.begin(), data.end(), [](VegetablePtr a, VegetablePtr b)
              { return a->GetCaloricity() < b->GetCaloricity(); });
}

void Vegetables::SortByCost()
{
    using VegetablePtr = std::shared_ptr<BaseVegetable>;
    std::sort(data.begin(), data.end(), [](VegetablePtr a, VegetablePtr b)
              { return a->GetCost() < b->GetCost(); });
}

void Vegetables::sortByWeight()
{
    using VegetablePtr = std::shared_ptr<BaseVegetable>;
    std::sort(data.begin(), data.end(), [](VegetablePtr a, VegetablePtr b)
              { return a->GetWeight() < b->GetWeight(); });
}