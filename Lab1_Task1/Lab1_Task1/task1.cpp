//Археолог нашел N артефактов.Известны веса(сi) и ценности(di) артефактов.Нужно
//выбрать такое подмножество найденных вещей, чтобы суммарный их вес не превысил Z кг, а их
//общая ценность оказалась максимальной.Известно, что решение единственно.Укажите поряд
//ковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом файле, в
//первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - ценность
//находок.Вывести так же суммарный вес и общую ценность результата.

//FIX_ME: функции должны быть описаны в заголовочном файле
#include "Header.h"

#include <iostream>
#include <vector>
//FIX_ME: нет явного подключения include <algorithm> для std::max и std::swap
#include <algorithm>
//FIX_ME: нет явного подключения include <locale> для setlocale
#include <locale>

//FIX_ME: подключение для отчистки потока вывода
#include <limits>

//FIX_ME: запрещено глобальное использование using namespace std;
//using namespace std;

//FIX_ME: неправильно расставлены фигурные скобки
//Исправлено: скобки перемещены на новые строчки

int main()
{
    setlocale(LC_ALL, "ru");

    //FIX_ME: неинформативные названия переменных n и W
    // int n, W;
    int itemCount, maxWeight;

    //FIX_ME: неполная проверка корректности ввода числа
     /*do
    {
        std::cout << "Введите объем рюкзака >=0: ";
        std::cin >> maxWeight;
    } while (maxWeight <= 0);*/
    while (true)
    {
        std::cout << "Введите объем рюкзака >= 0: ";
        std::cin >> maxWeight;

        if (std::cin.fail() || maxWeight <= 0)
        {
            std::cout << "Ошибка ввода. Введите целое число." << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    //FIX_ME: неполная проверка корректности ввода числа
   /* do
    {
        std::cout << "Введите кол-во артефактов >=0: ";
        std::cin >> itemCount;
    } while (itemCount <= 0);*/
    while (true)
    {
        std::cout << "Введите кол-во артефактов >= 0: ";
        std::cin >> itemCount;

        if (std::cin.fail() || itemCount <= 0)
        {
            std::cout << "Ошибка ввода. Введите целое число." << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }


    std::cout << "Поочередно вводите параметры артефактов";

    std::vector<int> profit(itemCount);
    std::vector<int> weight(itemCount);

    //FIX_ME: использование постфиксного инкремента в цикле for запрещено
    // for (int i = 0; i < itemCount; i++) 

    //FIX_ME: неполная проверка корректности ввода чисел
    /*for (int i = 0; i < itemCount; ++i)
    {
        std::cout << std::endl << "Вес " << i + 1 << ": ";
        std::cin >> weight[i];
        std::cout << std::endl << "стоимость " << i + 1 << ": ";
        std::cin >> profit[i];
    }*/
    for (int i = 0; i < itemCount; ++i)
    {
        while (true)
        {
            std::cout << std::endl << "Вес " << i + 1 << ": ";
            std::cin >> weight[i];

            if (std::cin.fail() || weight[i] < 0)
            {
                std::cout << "Ошибка ввода. Введите целое число." << std::endl;

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                break;
            }
        }

        while (true)
        {
            std::cout << std::endl << "Стоимость " << i + 1 << ": ";
            std::cin >> profit[i];

            if (std::cin.fail() || profit[i] < 0)
            {
                std::cout << "Ошибка ввода. Введите целое число." << std::endl;

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                break;
            }
        }
    }
    InsertSort(weight, profit);
    std::cout << "Максимальная возможная стоимость вещей, уместимых в рюкзак: " << CalculateBackpack(maxWeight, weight, profit, itemCount) << std::endl;

    return 0;
}
