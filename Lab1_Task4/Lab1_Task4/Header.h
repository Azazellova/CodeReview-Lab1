#pragma once

#include <string>
#include <fstream>
#include <vector>

//FIX_ME: нет краткого описания действия функции
// Рекурсивное вычисление значения логических выражений
//FIX_ME: неправильное наименований функции и их параметров

//bool evaluate(const std::string& expr);
bool EvaluateExpression(const std::string& expression);

//FIX_ME: нет краткого описания действия функции
// Функция разделения строки на подвыражения
std::vector<std::string> SplitRecursive(const std::string& input, char delimiter, size_t start = 0);

//FIX_ME: нет краткого описания действия функции
// Рекурсивное вычисление логической операции And
bool EvaluateAnd(const std::vector<std::string>& expressions, size_t index = 0);

//FIX_ME: нет краткого описания действия функции
// Рекурсивное вычисление логической операции Or
bool EvaluateOr(const std::vector<std::string>& expressions, size_t index = 0);

