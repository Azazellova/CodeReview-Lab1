//Хромой король.На квадратной доске расставлены монеты, достоинством от 1 до 100. 
//Хромой король, находящийся в правом нижнем углу, мечтает попасть в левый верхний.
//При этом он может передвигаться только в клетку слева или сверху и хочет, чтобы сумма всех
//монет, оказавшихся у него на пути, была бы максимальной.Определить эту сумму и путь, каким
//образом должен двигаться король, чтобы ее собрать.Ввод и вывод организовать при помощи
//текстовых файлов.Формат входных данных : в первой строке входного файла записано число 
//N - размер доски(1 < N < 80).Далее следует N строк, каждая из которых содержит N целых чисел,
//представляющих доску.В первую строку выходного файл нужно вывести единственное число :
//максимальную сумму, а во второй строке вывести путь в виде строки символов, обозначив сим
//волом L движение влево, а символом U - движение вверх.

#include <fstream>  
#include <iostream>  
#include <vector>  
#include <string>  

//FIX_ME: отсутствует подключение заголовочного файла с объявлениями функций
#include "Header.h"

//FIX_ME: отсутствует библиотека <limits> для проверки входных данных
#include <limits>

//FIX_ME: запрещено глобальное использование using namespace std;
//using namespace std;

//FIX_ME: запрещено глобальное объявление переменной
//int n;

int main()
{
	//FIX_ME: неинформативное наименование переменной
    int boardSize;

    setlocale(LC_ALL, "Russian");

	//FIX_ME: неправильные имена переменных для файлов
    std::ifstream inputFile("a.txt", std::ios::in);
    std::ofstream outputFile("b.txt", std::ios::out);

	//FIX_ME: отсутствует проверка открытия файлов
    if (!inputFile.is_open() || !outputFile.is_open())
    {
        std::cout << "Ошибка открытия файла." << std::endl;
        return 1;
    }

    //FIX_ME: добавлена проверка чтения размера доски
    if (!(inputFile >> boardSize))
    {
        std::cout << "Ошибка чтения размера доски." << std::endl;
        return 1;
    }

    //FIX_ME: добавлена проверка диапазона размера доски
    if (boardSize <= 1 || boardSize >= 80)
    {
        std::cout << "Некорректный размер доски." << std::endl;
        return 1;
    }

	//FIX_ME: неинформативные наименования переменных pole1, pole2, put

    std::vector<std::vector<int>> board(boardSize, std::vector<int>(boardSize));
    std::vector<std::vector<int>> dynamicTable(boardSize, std::vector<int>(boardSize));
    std::vector<std::vector<char>> pathTable(boardSize, std::vector<char>(boardSize));

	//FIX_ME: неинформативное наименование переменной
    //std::string put1;

    std::string resultPath;

	//FIX_ME: неправильные стили инкремента в циклах
    //    for (int i = 0; i < boardSize; i++)
    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < boardSize; ++j)
        {
            //FIX_ME: добавлена проверка чтения значения клетки
            if (!(inputFile >> board[i][j]))
            {
                std::cout << "Ошибка чтения данных доски." << std::endl;
                return 1;
            }

            //FIX_ME: добавлена проверка диапазона монет
            if (board[i][j] < 1 || board[i][j] > 100)
            {
                std::cout << "Некорректное значение монеты." << std::endl;
                return 1;
            }
        }
    }

    //FIX_ME: проверка лишних данных в файле
    int extraValue;
    if (inputFile >> extraValue)
    {
        std::cout << "Ошибка: в файле присутствуют лишние данные." << std::endl;
        return 1;
    }

    Solve(board, dynamicTable, pathTable, boardSize);
    outputFile << "Максимальная сумма монет, которую может собрать король: " << dynamicTable[0][0] << '\n';

    BuildPath(pathTable, resultPath, boardSize);
    outputFile << "Путь: " << resultPath;

    inputFile.close();
    outputFile.close();

    std::cout << "Программа завершена. Ответ записан в файл b.txt";

    return 0;
}