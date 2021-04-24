#include <iostream>
#include <clocale>
#include "Matrix_game.h"

int main()
{
    system("chcp 1251");
    generate_matrix(2);
    generate_matrix(10);
  //  print(10);
    balance_Nesh(10);
    balance_Pareto(10);
    print(10);
    generate_matrix(3);
}
