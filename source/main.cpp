#include "Header.h"
#include "functions.h"

int main()
{
    std::cout << "+++START+++\n";
    Vegetables vegs;
    Salad salad;
    int res = FileNameInput(vegs);
    if (res == 1)
    {
        return 1;
    }
    bool run = true;
    while (run)
    {
        int option;
        InputOptionNumber(option);
        switch (option)
        {
        case 1:
            SaladCreationOptions(vegs, salad);
            break;
        case 2:
            SaladFindOptions(salad);
            break;
        case 3:
            SaladSortOptions(salad);
            break;
        case 4:
            salad.print(std::cout);
            break;
        case 5:
            SaladSave(salad);
            break;
        case 6:
            run = false;
            break;
        default:
            break;
        }
    }
    std::cout << "+++END+++\n";
    return 0;
}