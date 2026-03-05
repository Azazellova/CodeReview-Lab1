//Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения, 
//не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
//Вывести значение логического выражения, заданного в виде строки S.Выражение определяется следующим 
//образом(«T» — True, «F» — False) :
//    <выражение> :: = T | F | And(<параметры>) | Or(<параметры>)
//    <параметры> :: = <выражение> | <выражение>, <параметры>

//FIX_ME: убраны ненужные библиотеки
//#include <fstream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <random>
//#include <sstream>

#include <iostream>
#include <string>

#include "Header.h"

//FIX_ME: запрещено глобальное использование using namespace std;
//using namespace std;

//FIX_ME: неинформативное наименование функции
//void Recur23() 
void runLogicalExpressionEvaluator()
{
    std::string expr;
    std::cin >> expr;
    //FIX_ME: отсутствует обработка некорректного ввода
    /*bool result = EvaluateExpression(expr);
    std::cout << (result ? "T" : "F") << std::endl;*/

    try
    {
        bool result = EvaluateExpression(expr);
        std::cout << (result ? "T" : "F") << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    runLogicalExpressionEvaluator();

    //FIX_ME: отсутствует возврат из функции main
    return 0;
}