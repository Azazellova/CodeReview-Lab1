#pragma once
#include <string>
#include <vector>

//FIX_ME: нет описания действия функции
//Решение задачи о хромом короле с помощью динамического программирования. 
//Функция заполняет таблицу динамического программирования и таблицу пути на основе входной доски и размера доски.
//FIX_ME: неправильное наименование параметров
//void Solve(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<char>>& put);
void Solve(std::vector<std::vector<int>>& board, std::vector<std::vector<int>>& dynamicTable, std::vector<std::vector<char>>& pathTable, int boardSize);

//FIX_ME: нет описания действия функции
//Функция восстанавливает путь от начальной позиции до конечной на основе таблицы пути, заполненной функцией Solve. 
//Результат сохраняется в строке resultPath.
//FIX_ME: неправильное наименований функции и параметров
//void p(vector<vector<char>>& put, string& put1);
void BuildPath(std::vector<std::vector<char>>& pathTable, std::string& resultPath, int boardSize);

