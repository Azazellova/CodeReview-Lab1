#pragma once

#include <string>
#include <fstream>
#include <vector>

//FIX_ME: неправильное наименований функции и их параметров

//bool evaluate(const std::string& expr);
bool EvaluateExpression(const std::string& expression);

std::vector<std::string> SplitRecursive(const std::string& input, char delimiter, size_t start = 0);

bool EvaluateAnd(const std::vector<std::string>& expressions, size_t index = 0);

bool EvaluateOr(const std::vector<std::string>& expressions, size_t index = 0);