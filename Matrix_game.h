#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include "C:\ֳּׂ׃\ׂומנטÿָדנ\NumCpp-master\include\NumCpp\Functions.hpp"
#include "C:\ֳּׂ׃\ׂומנטÿָדנ\NumCpp-master\include\NumCpp\NdArray.hpp"
#include "C:\ֳּׂ׃\\ׂומנטÿָדנ\NumCpp-master\include\NumCpp\Linalg.hpp"


void balance_Nesh(int N);
void balance_Pareto(int N);
void generate_matrix(int N);
void bypass_of_matrix(double elem_A, double elem_B, int N);
void print(int N);

extern nc::NdArray<double> matrix_for_player_A;
extern nc::NdArray<double> matrix_for_player_B;
extern std::vector<double> result_Nash;
extern std::vector<double> result_Pareto ;
