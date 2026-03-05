#include "Header.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <climits>

void InsertSort(std::vector<int>& weight, std::vector<int>& price)
{
    //FIX_ME: использование постфиксного инкремента в цикле for запрещено, 
    // необходимо использовать префиксный инкремент
    // for (int i = 1; i < weight.size(); i++) 
    for (int i = 1; i < weight.size(); ++i)
    {
        //FIX_ME: неинформативное название переменной temp
        //int temp = i;

        int currentIndex = i;
        while (currentIndex - 1 >= 0 && weight[currentIndex] < weight[currentIndex - 1])
        {
            std::swap(weight[currentIndex], weight[currentIndex - 1]);
            std::swap(price[currentIndex], price[currentIndex - 1]);
            currentIndex--;
        }

    }
}

int CalculateBackpack(int backpackVolume, std::vector<int>& weight, std::vector<int>& values, int itemCount)
{
    //FIX_ME: неинформативное название переменной dp
    //std::vector<std::vector<int>> dp(count + 1, std::vector<int>(backpackVolume + 1));

    std::vector<std::vector<int>> dynamicTable(itemCount + 1, std::vector<int>(backpackVolume + 1));
    // Заполнение таблицы

    //FIX_ME: неправильное использование инкремента, 
    // необходимо использовать префиксный инкремент
    // for (int i = 0; i <= count; i++) {
    // for (int w = 0; w <= backpackVolume; w++) 

    for (int i = 0; i <= itemCount; ++i) {
        for (int w = 0; w <= backpackVolume; ++w)
        {
            //FIX_ME: однострочные блоки if else запрещены
            //Исправлено: добавлены фигурные скобки для каждого блока

            if (i == 0 || w == 0)
            {
                dynamicTable[i][w] = 0; // нет предметов или вес рюкзака равен 0
            }
            else if (weight[i - 1] <= w)
            {
                // Выбор между включением и исключением текущего предмета
                dynamicTable[i][w] = std::max(values[i - 1] + dynamicTable[i - 1][w - weight[i - 1]], dynamicTable[i - 1][w]);
            }
            else
            {
                // Текущий предмет не вмещается в рюкзак
                dynamicTable[i][w] = dynamicTable[i - 1][w];
            }
        }
    }
    return dynamicTable[itemCount][backpackVolume];
}