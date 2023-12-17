#pragma once
#include "Header.h"

class Salad
{
private:
    std::vector<std::shared_ptr<BaseVegetable>> data;
    double weight = 0;
    double cost = 0;
    double caloticity = 0;

public:
    Salad() = default;
    ~Salad() = default;
    double getCost() const { return cost; }
    double getWeight() const { return weight; }
    double getCaloricity() const { return caloticity; }
    size_t getSize() const { return data.size(); }
    void sortByName();
    void sortByCost();
    void sortByWeight();
    void sortByCaloricity();
    void print(std::ostream &);
    void createByWeight(double, Vegetables &);
    void createByCost(double, Vegetables &);
    void createByCaloricity(double, Vegetables &);
    void findVegsCaloricity(double min, double max);
    void findMinVegsCaloricity(double min, double max);
};

void Salad::findVegsCaloricity(double min, double max)
{
    std::sort(data.begin(), data.end(),
              [](std::shared_ptr<BaseVegetable> a,
                 std::shared_ptr<BaseVegetable> b)
              { return a->GetCaloricity() < b->GetCaloricity(); });
    auto tempBegin = std::find_if(data.begin(), data.end(),
                                  [min](std::shared_ptr<BaseVegetable> a)
                                  { return a->GetCaloricity() >= min; });
    auto tempEnd = std::find_if(data.begin(), data.end(),
                                [max](std::shared_ptr<BaseVegetable> a)
                                { return a->GetCaloricity() > max; });
    if (tempBegin == data.end())
    {
        std::cout << "No vegetables!\n";
        return;
    }
    else
    {
        std::cout << "Suitable vegetables : \n";
        std::copy(tempBegin, tempEnd,
                  std::ostream_iterator<std::shared_ptr<BaseVegetable>>(std::cout, "\n"));
    }
}

void Salad::findMinVegsCaloricity(double min, double max)
{
    std::sort(data.begin(), data.end(),
              [](std::shared_ptr<BaseVegetable> a,
                 std::shared_ptr<BaseVegetable> b)
              { return a->GetCaloricity() < b->GetCaloricity(); });
    auto tempBegin = std::find_if(data.begin(), data.end(),
                                  [min](std::shared_ptr<BaseVegetable> a)
                                  { return a->GetCaloricity() >= min; });
    if (tempBegin == data.end())
    {
        std::cout << "No vegetables!\n";
        return;
    }
    else
    {
        std::cout << "Suitable vegetable : \n" << *(tempBegin);
    }
}

void Salad::createByWeight(double MaxWeight, Vegetables &veg)
{
    bool flag = true;
    Salad salad;
    veg.sortByWeight();
    while (MaxWeight > 0 && flag)
    {
        std::for_each(veg.data.begin(), veg.data.end(),
                      [&MaxWeight, &flag, &salad, &veg](std::shared_ptr<BaseVegetable> data)
                      {
            if (data->GetWeight() <= MaxWeight)
            {
                MaxWeight -= data->GetWeight();
                salad.cost += data->GetCost();
                salad.weight += data->GetWeight();
                salad.caloticity += data->GetCaloricity();
                salad.data.push_back(data);
            }
            else if (MaxWeight < veg.data.back()->GetWeight())
            {
                flag = false;
            } });
    }
    *this = salad;
}

void Salad::createByCost(double MaxCost, Vegetables &veg)
{
    bool flag = true;
    Salad salad;
    veg.SortByCost();
    while (MaxCost > 0 && flag)
    {
        std::for_each(veg.data.begin(), veg.data.end(),
                      [&MaxCost, &flag, &salad, &veg](std::shared_ptr<BaseVegetable> data)
                      {
            if (data->GetCost() <= MaxCost)
            {
                MaxCost -= data->GetCost();
                salad.cost += data->GetCost();
                salad.weight += data->GetWeight();
                salad.caloticity += data->GetCaloricity();
                salad.data.push_back(data);
            }
            else if (MaxCost < veg.data.back()->GetCost())
            {
                flag = false;
            } });
    }
    *this = salad;
}

void Salad::createByCaloricity(double MaxCaloricity, Vegetables &veg)
{
    bool flag = true;
    Salad salad;
    veg.SortByCalorisity();
    while (MaxCaloricity > 0 && flag)
    {
        std::for_each(veg.data.begin(), veg.data.end(),
                      [&MaxCaloricity, &flag, &salad, &veg](std::shared_ptr<BaseVegetable> data)
                      {
            if (data->GetCaloricity() <= MaxCaloricity)
            {
                MaxCaloricity -= data->GetCaloricity();
                salad.cost += data->GetCost();
                salad.weight += data->GetWeight();
                salad.caloticity += data->GetCaloricity();
                salad.data.push_back(data);
            }
            else if (MaxCaloricity < veg.data.back()->GetCaloricity())
            {
                flag = false;
            } });
    }
    *this = salad;
}

void Salad::sortByName()
{
    std::sort(data.begin(), data.end(),
              [](std::shared_ptr<BaseVegetable> a,
                 std::shared_ptr<BaseVegetable> b)
              { return a->GetName() < b->GetName(); });
}

void Salad::sortByCost()
{
    std::sort(data.begin(), data.end(),
              [](std::shared_ptr<BaseVegetable> a,
                 std::shared_ptr<BaseVegetable> b)
              { return a->GetCost() < b->GetCost(); });
}

void Salad::sortByWeight()
{
    std::sort(data.begin(), data.end(),
              [](std::shared_ptr<BaseVegetable> a,
                 std::shared_ptr<BaseVegetable> b)
              { return a->GetWeight() < b->GetWeight(); });
}

void Salad::sortByCaloricity()
{
    std::sort(data.begin(), data.end(),
              [](std::shared_ptr<BaseVegetable> a,
                 std::shared_ptr<BaseVegetable> b)
              { return a->GetCaloricity() < b->GetCaloricity(); });
}

void Salad::print(std::ostream &out)
{
    std::copy(data.begin(), data.end(),
              std::ostream_iterator<std::shared_ptr<BaseVegetable>>(out, "\n"));
}