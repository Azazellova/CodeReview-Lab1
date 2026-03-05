#include "Header.h"
#include <string>
#include <vector>

//FIX_ME: неправильное расположение фигурных скобок
//Исправлены все скобки
 std::vector<std::string> SplitRecursive(const std::string& input, char delimiter, size_t start)
 {
	//FIX_ME: название переменных должно быть lowerCamelCase, а также информативным
    /*std::vector<std::string> Result;
    size_t Pos = input.find(delimiter, start);*/

    std::vector<std::string> result;

    //FIX_ME: проверка стартовой позиции
    if (start >= input.size())
    {
        return result;
    }


    size_t position = input.find(delimiter, start);

    if (position != std::string::npos)
    {
        result.push_back(input.substr(start, position - start));
        std::vector<std::string> remaining = SplitRecursive(input, delimiter, position + 1);
        result.insert(result.end(), remaining.begin(), remaining.end());
    }
    else
    {
        if (start < input.size())
        {
            result.push_back(input.substr(start));
        }
    }

    return result;
 }

bool EvaluateAnd(const std::vector<std::string>& expressions, size_t index)
{
    if (index >= expressions.size())
    {
        return true;
    }

    if (!EvaluateExpression(expressions[index]))
    {
        return false;
    }

    return EvaluateAnd(expressions, index + 1);
}

bool EvaluateOr(const std::vector<std::string>& expressions, size_t index)
{
    if (index >= expressions.size())
    {
        return false;
    }

    if (EvaluateExpression(expressions[index]))
    {
        return true;
    }

    return EvaluateOr(expressions, index + 1);
}

bool EvaluateExpression(const std::string& expression)
{
    if (expression == "T")
    {
        return true;
    }
    else if (expression == "F")
    {
        return false;
    }
    else if (expression.substr(0, 3) == "And")
    {
        //FIX_ME: название переменных должно быть lowerCamelCase

        /*std::string Params = expression.substr(4, expression.size() - 5);
        std::vector<std::string> SubExpressions = SplitRecursive(Params, ',');*/
        std::string params = expression.substr(4, expression.size() - 5);
        std::vector<std::string> subExpressions = SplitRecursive(params, ',');
        return EvaluateAnd(subExpressions);
    }
    else if (expression.substr(0, 2) == "Or")
    {
        std::string params = expression.substr(3, expression.size() - 4);
        std::vector<std::string> subExpressions = SplitRecursive(params, ',');
        return EvaluateOr(subExpressions);
    }

    return false;
}