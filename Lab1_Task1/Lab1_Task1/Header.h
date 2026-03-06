#pragma once

#include <string>
#include <fstream>
#include <vector>

//FIX_ME: неправильное наименований функции и параметров
//void insert_sort(std::vector<int>& w, std::vector<int>& p) {
void InsertSort(std::vector<int>& weight, std::vector<int>& price);

//FIX_ME: неправильное наименований функции и параметров
//int backpack(int W, std::vector<int>& wt, std::vector<int>& val, int n) {
int CalculateBackpack(int backpackVolume, std::vector<int>& weight, std::vector<int>& values, int itemCount);
