#include "Header.h"
#include <algorithm>
#include <vector>

void Solve(std::vector<std::vector<int>>& board, std::vector<std::vector<int>>& dynamicTable, std::vector<std::vector<char>>& pathTable, int boardSize)
{
	//FIX_ME: конфликтующее наименование переменной
    // int max;
    int maxValue;
    dynamicTable[boardSize - 1][boardSize - 1] = board[boardSize - 1][boardSize - 1];

	//FIX_ME: неправильные стили декремента в циклах
    //for (int i = boardSize - 2; i >= 0; i--)
    for (int i = boardSize - 2; i >= 0; --i)
    {
        dynamicTable[i][boardSize - 1] = dynamicTable[i + 1][boardSize - 1] + board[i][boardSize - 1];
        pathTable[i][boardSize - 1] = 'U';
    }

    //for (int j = boardSize - 2; j >= 0; j--)
    for (int j = boardSize - 2; j >= 0; --j)
    {
        dynamicTable[boardSize - 1][j] = dynamicTable[boardSize - 1][j + 1] + board[boardSize - 1][j];
        pathTable[boardSize - 1][j] = 'L';
    }

    //for (int i = boardSize - 2; i >= 0; i--)
    for (int i = boardSize - 2; i >= 0; --i)
    {
        //for (int j = boardSize - 2; j >= 0; j--)
        for (int j = boardSize - 2; j >= 0; --j)
        {
            if (dynamicTable[i + 1][j] > dynamicTable[i][j + 1])
            {
                maxValue = dynamicTable[i + 1][j];
                pathTable[i][j] = 'U';
            }
            else
            {
                maxValue = dynamicTable[i][j + 1];
                pathTable[i][j] = 'L';
            }
            dynamicTable[i][j] = maxValue + board[i][j];
        }
    }
}
    
void BuildPath(std::vector<std::vector<char>>& pathTable, std::string& resultPath, int boardSize)
{
    int i = 0;
    int j = 0;
    while (i < boardSize - 1 || j < boardSize - 1)
    {
        if (pathTable[i][j] == 'U')
        {
            resultPath = resultPath + "U ";
            i++;
        }
        else if (pathTable[i][j] == 'L')
        {
            resultPath = resultPath + "L ";
            j++;
        }
    }
    reverse(resultPath.begin(), resultPath.end());
}