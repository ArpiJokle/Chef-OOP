#include "Header.h"

int FileNameInput(Vegetables &vegs)
{
    int option;
    while (true)
    {
        std::cout << "Which product list to use: \n";
        std::cout << "\t\'(1)\' - use default list\n";
        std::cout << "\t\'(2)\' - use custom list\n";
        std::cout << "enter option number : ";
        std::cin >> option;
        if ((option < 1) || (option > 2))
        {
            std::cout << "\nwrong option, try again\n\n";
        }
        else
        {
            break;
        }
    }
    std::ifstream fin;
    if (1 == option)
    {
        fin.open("list.txt");
    }
    else
    {
        std::cout << "Input file name : ";
        std::string name;
        std::cin >> name;
        fin.open(name);
    }
    if (!fin.is_open())
    {
        std::cout << "ERROR : WRONG FILE!\n";
        std::cout << "+++END+++\n";
        return 1;
    }
    vegs.Read(fin);
    return 0;
}

void InputOptionNumber(int &option)
{
    while (true)
    {
        std::cout << "List of options :\n";
        std::cout << "\t \'(1)\' - Create salad;\n";
        std::cout << "\t \'(2)\' - Find ingtidients in salad;\n";
        std::cout << "\t \'(3)\' - Sort salad ingridients list;\n";
        std::cout << "\t \'(4)\' - Show ingridients list;\n";
        std::cout << "\t \'(5)\' - Save ingridients list;\n";
        std::cout << "\t \'(6)\' - Exit;\n";
        std::cout << "Input option number : ";
        std::cin >> option;
        if ((option < 1) || (option > 6))
        {
            std::cout << "\nwrong option, try again\n\n";
        }
        else
        {
            return;
        }
    }
}

void SaladCreationOptions(Vegetables &vegs, Salad &salad)
{
    int option;
    while (true)
    {
        std::cout << "Which salad creation method: \n";
        std::cout << "\t\'(1)\' - create by weight\n";
        std::cout << "\t\'(2)\' - create by cost\n";
        std::cout << "\t\'(3)\' - create by caloticity\n";
        std::cout << "enter option number : ";
        std::cin >> option;
        if ((option < 1) || (option > 3))
        {
            std::cout << "\nwrong option, try again\n\n";
        }
        else
        {
            break;
        }
    }
    double Value;
    switch (option)
    {
    case 1:
        std::cout << "Input max weight : ";
        std::cin >> Value;
        salad.createByWeight(Value, vegs);
        break;
    case 2:
        std::cout << "Input max cost : ";
        std::cin >> Value;
        salad.createByCost(Value, vegs);
        break;
    case 3:
        std::cout << "Input max caloticity : ";
        std::cin >> Value;
        salad.createByCaloricity(Value, vegs);
        break;
    default:
        break;
    }
    std::cout << "Created!\n\n";
}

void SaladSortOptions(Salad &salad)
{
    int option;
    while (true)
    {
        std::cout << "Select a sorting option: \n";
        std::cout << "\t\'(1)\' - sort by name\n";
        std::cout << "\t\'(2)\' - sort by weight\n";
        std::cout << "\t\'(3)\' - sort by cost\n";
        std::cout << "\t\'(4)\' - sort by caloricity\n";
        std::cout << "enter option number : ";
        std::cin >> option;
        if ((option < 1) || (option > 4))
        {
            std::cout << "\nwrong option, try again\n\n";
        }
        else
        {
            break;
        }
    }
    switch (option)
    {
    case 1:
        salad.sortByName();
        break;
    case 2:
        salad.sortByWeight();
        break;
    case 3:
        salad.sortByCost();
        break;
    case 4:
        salad.sortByCaloricity();
        break;
    default:
        break;
    }
    std::cout << "Sorted!\n\n";
}

void SaladFindOptions(Salad &salad)
{
    int option;
    while (true)
    {
        std::cout << "Which ingridient find: \n";
        std::cout << "\t\'(1)\' - search for ingredients in a"
                  << " given calorie parameter\n ";
        std::cout << "\t\'(2)\' - search for the least calorie"
                  << " ingredient in a given calorie parameter\n ";
        std::cout << "enter option number : ";
        std::cin >> option;
        if ((option < 1) || (option > 2))
        {
            std::cout << "\nwrong option, try again\n\n";
        }
        else
        {
            break;
        }
    }
    double Min, Max;
    std::cout << "enter a lower calorie threshold : ";
    std::cin >> Min;
    std::cout << "enter a upper calorie threshold : ";
    std::cin >> Max;
    switch (option)
    {
    case 1:
        salad.findVegsCaloricity(Min, Max);
        break;
    case 2:
        salad.findMinVegsCaloricity(Min, Max);
        break;
    default:
        break;
    }
}

void SaladSave(Salad &salad)
{
    std::cout << "Input output file name : ";
    std::string Name;
    std::cin >> Name;
    std::ofstream fout(Name);
    salad.print(fout);
    std::cout << "Saved!\n\n";
}