#include "Matrix_game.h"

nc::NdArray<double> matrix_for_player_B(10,10);
nc::NdArray<double> matrix_for_player_A(10,10);
std::vector<double> result_Nash;
std::vector<double> result_Pareto;

void generate_matrix(int N)
{
	auto e = 0.0;
	std::srand(time(NULL));
	if (N == 2)
	{
		std::cout << "Задача смейный спор" << std::endl;
		matrix_for_player_A(0, 0) = 4;
		matrix_for_player_A(0, 1) = 0;
		matrix_for_player_A(1, 0) = 0;
		matrix_for_player_A(1, 1) = 1;
		matrix_for_player_B(0, 0) = 1;
		matrix_for_player_B(0, 1) = 0;
		matrix_for_player_B(1, 0) = 0;
		matrix_for_player_B(1, 1) = 4;
		balance_Nesh(2);
		balance_Parreto(2);
		std::cout << "Введите e для игры 'Перекрёсток' e=";
		std::cin >> e;
		matrix_for_player_A(0, 0) = 1;
		matrix_for_player_A(0, 1) = 1-e;
		matrix_for_player_A(1, 0) = 2;
		matrix_for_player_A(1, 1) = 0;
		matrix_for_player_B(0, 0) = 1;
		matrix_for_player_B(0, 1) = 2;
		matrix_for_player_B(1, 0) = 1-e;
		matrix_for_player_B(1, 1) = 0;
		balance_Nesh(2);
		balance_Parreto(2);
		std::cout << "Задача дилема заключенного" << std::endl;
		matrix_for_player_A(0, 0) = -5;
		matrix_for_player_A(0, 1) = 0;
		matrix_for_player_A(1, 0) = -10;
		matrix_for_player_A(1, 1) = -1;
		matrix_for_player_B(0, 0) = -5;
		matrix_for_player_B(0, 1) = -10;
		matrix_for_player_B(1, 0) = 0;
		matrix_for_player_B(1, 1) = -1;
		balance_Nesh(2);
		balance_Parreto(2);
	}

	if (N == 10)
	{
		for (auto i = 0; i < 10; ++i)
		{
			for (auto j = 0; j < 10; j++)
			{
				matrix_for_player_A(i, j) = rand() % 100;
				matrix_for_player_B(i, j) = rand() % 100;
			}
		}
	}
}



void balance_Nesh(int N)
{
	std::cout << "-------" << std::endl;
	size_t flag = 0;
	size_t flag2 = 0;
	

	for (auto i = 0; i < N; ++i)
	{
		for (auto j = 0; j < N; ++j)
		{
			//std::cout << "i=" << i << " j=" << j << std::endl;

			if (j == 0 && i == 0 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j + 1))) //i=0,j=0
			{
					for (auto jj = 2; jj < N; ++jj)
					{
						if (matrix_for_player_B(i, j) > matrix_for_player_B(i, jj))
						{
							continue;
						}
						else
						{
							flag2 = 1;
							break;
						}
					}
					for (auto ii = 1; ii < N; ++ii)
					{
						if ((matrix_for_player_A(i, j) > matrix_for_player_A(ii, j)))
						{
							continue;
						}
						else
						{
							flag2 = 1;
							break;
						}
					}
					if (flag2 == 0)
					{
						result_Nash.emplace_back(matrix_for_player_A(i, j));
						result_Nash.emplace_back(matrix_for_player_B(i, j));
						//std::cout << "optimal Nash0,0=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << " i=" << i << " " << "j=" << j << std::endl;
					}
					//flag = 1;
			}
			flag2 = 0;
			if (j == N-1 && i == 0 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j - 1))) //i=0,j=N-1
			{
				
				for (auto jj = N-2; jj >= 0; --jj)
				{
					if (matrix_for_player_B(i, j) > matrix_for_player_B(i, jj))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}
				for (auto ii = 1; ii < N; ++ii)
				{
					if ((matrix_for_player_A(i, j) > matrix_for_player_A(ii, j)))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}
				if (flag2 == 0)
				{
					result_Nash.emplace_back(matrix_for_player_A(i, j));
					result_Nash.emplace_back(matrix_for_player_B(i, j));
					//std::cout << "optimal Nash0,9=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << " i=" << i << " " << "j=" << j << std::endl;
				}
				//flag = 1;
			}
			flag2 = 0;
			if (j == 0 && i == N-1 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j + 1))) //i=N-1,j=0
			{

				for (auto jj = 2; jj < N; ++jj)
				{
					if (matrix_for_player_B(i, j) > matrix_for_player_B(i, jj))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}
				for (auto ii = N-2; ii >= 0; --ii)
				{
					if ((matrix_for_player_A(i, j) > matrix_for_player_A(ii, j)))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}

				//if ((matrix_for_player_A(i, j) > matrix_for_player_A(i - 1, j)))
				//{
				if (flag2 == 0)
				{
					result_Nash.emplace_back(matrix_for_player_A(i, j));
					result_Nash.emplace_back(matrix_for_player_B(i, j));
					//std::cout << "optimal Nash9,0=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << " i=" << i << " " << "j=" << j << std::endl;
				}
				//flag = 1;
					//	break;
				//}
			}
			flag2 = 0;
			if (j == N-1 && i == N-1 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j - 1))) //i=9,j=9
			{
				
				for (auto jj = N-2; jj >= 0; --jj)
				{
					if (matrix_for_player_B(i, j) > matrix_for_player_B(i, jj))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}
				for (auto ii = N-2; ii >= 0; --ii)
				{
					if ((matrix_for_player_A(i, j) > matrix_for_player_A(ii, j)))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}
				
				//if ((matrix_for_player_A(i, j) > matrix_for_player_A(i - 1, j)))
				//{
				if (flag2 == 0)
				{
					result_Nash.emplace_back(matrix_for_player_A(i, j));
					result_Nash.emplace_back(matrix_for_player_B(i, j));
					//std::cout << "optimal Nash9,9=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << " i=" << i << " " << "j=" << j << std::endl;
				}
				//flag = 1;
					//	break;
				//}
			}
			flag2 = 0;
			if (i > 0 && j == 0 && i < N-1 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j + 1))) //i>1 и i<9 и j=0
			{
				
				for (auto ii = i+1; ii <= N-1; ++ii)
				{
					if (matrix_for_player_A(i, j) > matrix_for_player_A(ii, j))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}

				for (auto ii = i - 1; ii >= 0; --ii)
				{
					if (matrix_for_player_A(i, j) > matrix_for_player_A(ii, j))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}

				for (auto jj = 2; jj < N; ++jj)
				{
					if (matrix_for_player_B(i, j) > matrix_for_player_B(i, jj))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}
				//if (matrix_for_player_A(i, j) > matrix_for_player_A(i - 1, j) && matrix_for_player_A(i, j) > matrix_for_player_A(i + 1, j))
				//{
				if (flag2 == 0)
				{
					result_Nash.emplace_back(matrix_for_player_A(i, j));
					result_Nash.emplace_back(matrix_for_player_B(i, j));
					//std::cout << "optimal Nash0=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << " i=" << i << " " << "j=" << j << std::endl;
				}
					//flag = 1;
					//	break;
				//}
			}
			flag2 = 0;
			if (i > 0 && j == N-1 && i < N-1 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j - 1))) //i>1 и i<9 и j=9
			{

				for (auto ii = i + 1; ii <= N-1; ++ii)
				{
					if (matrix_for_player_A(i, j) > matrix_for_player_A(ii, j))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}

				for (auto ii = i - 1; ii >= 0; --ii)
				{
					if (matrix_for_player_A(i, j) > matrix_for_player_A(ii, j))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}

				for (auto jj = N-1; jj >= 0; --jj)
				{
					if (matrix_for_player_B(i, j) > matrix_for_player_B(i, jj))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}

				//if (matrix_for_player_A(i, j) > matrix_for_player_A(i - 1, j) && matrix_for_player_A(i, j) > matrix_for_player_A(i + 1, j))
				//{
				if (flag2 == 0)
				{
					result_Nash.emplace_back(matrix_for_player_A(i, j));
					result_Nash.emplace_back(matrix_for_player_B(i, j));
					//std::cout << "optimal Nash9=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << " i=" << i << " " << "j=" << j << std::endl;
				}
					//flag = 1;
					//	break;
				//}
			}
			flag2 = 0;
			if ((matrix_for_player_B(i, j) > matrix_for_player_B(i, j-1)) && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j+1)) && i > 0 && i < N-1 && j>0 && j < N-1) //i>0 i<9 j>0 j<9
			{
				for (auto ii = i + 1; ii < N; ++ii)
				{
					if (matrix_for_player_A(i, j) > matrix_for_player_A(ii, j))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}

				for (auto ii = i - 1; ii >= 0; --ii)
				{
					if (matrix_for_player_A(i, j) > matrix_for_player_A(ii, j))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}

				for (auto jj = j + 1; jj < N-1; ++jj)
				{
					if (matrix_for_player_B(i, j) > matrix_for_player_B(i, jj))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}

				for (auto jj = j - 1; jj >=0; --jj)
				{
					if (matrix_for_player_B(i, j) > matrix_for_player_B(i, jj))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}

				//if ((matrix_for_player_A(i, j) > matrix_for_player_A(i, j - 1)) && (matrix_for_player_A(i, j) > matrix_for_player_A(i, j + 1)))
				//{
				if (flag2 == 0)
				{
					//std::cout << "optimal Nash=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << " i=" << i << " " << "j=" << j << std::endl;
					result_Nash.emplace_back(matrix_for_player_A(i, j));
					result_Nash.emplace_back(matrix_for_player_B(i, j));
				}
				//flag = 1;
					//	break;
				//}
			}
		}
		/*if (flag == 1)
		{
			break;
		}*/
	}
	
}

void bypass_of_matrix_A(int elem_A, int elem_B, int N)
{
	size_t flag = 0, flag2 = 0;
	for (auto i = 0; i < N; ++i)
	{
		for (auto j = 0; j < N; ++j)
		{

			if (matrix_for_player_A(i, j) == elem_A && matrix_for_player_B(i, j) == elem_B)
			{
				flag++;
				continue;
			}
			else
			{
				if (elem_A >= matrix_for_player_A(i, j))
				{
					//if (elem_B >= matrix_for_player_B(i, j))
					{
						flag++;
						continue;
					}
				}
				if (elem_A < matrix_for_player_A(i, j))
				{
					if (elem_B < matrix_for_player_B(i, j))
					{
						flag2 = 1;
						flag = 0;
						break;
					}
					else
					{
						flag++;
						continue;
						
					}

				}
			}
		}
		if (( flag==100) && N==10)
		{
			//std::cout << "optimal_Pareto=" << flag << std::endl;
			std::cout << "optimal_Pareto -> elem_A=" << elem_A << " " << "elem_B=" << elem_B << std::endl;
			result_Pareto.emplace_back(elem_A);
			result_Pareto.emplace_back(elem_B);
			//print(elem_A, elem_B, N);
			break;
		}

		if ((flag == 4) && N == 2)
		{
			std::cout << "optimal_Pareto -> elem_A=" << elem_A << " " << "elem_B=" << elem_B << std::endl;
			result_Pareto.emplace_back(elem_A);
			result_Pareto.emplace_back(elem_B);
			//print(elem_A, elem_B, N);
			break;
		}

		if (flag2 == 1)
		{
			break;
		}
	}
	
}


void balance_Parreto(int N)
{
	auto element_matrix_A = 0;
	std::vector<double> matrix_for_A = matrix_for_player_A.toStlVector();
	std::vector<double> matrix_for_B = matrix_for_player_B.toStlVector();
	for (auto i = 0; i < N; ++i)
	{
		for (auto j = 0; j < N; ++j)
		{
			bypass_of_matrix_A(matrix_for_player_A(i, j), matrix_for_player_B(i, j), N);
		//	bypass_of_matrix_B(matrix_for_player_A(i, j), matrix_for_player_B(i, j), N);
		}
	}
			
	//std::cout << matrix_for_A.at(std::distance(matrix_for_A.begin(), std::max_element(matrix_for_A.begin(), matrix_for_A.end()))) << std::endl;
	//std::cout << matrix_for_B.at(std::distance(matrix_for_B.begin(), std::max_element(matrix_for_B.begin(), matrix_for_B.end()))) << std::endl;

}

void print(int N)
{

	for (auto i = 0; i < N; ++i)
	{
		for (auto j = 0; j < N; ++j)
		{
			if ((*std::find(result_Nash.begin(), result_Nash.end(), matrix_for_player_A(i, j))==matrix_for_player_A(i,j)) && (*std::find(result_Nash.begin(), result_Nash.end(), matrix_for_player_B(i, j))==matrix_for_player_B(i,j)))
			{
				std::cout << "\x1b[31m" << matrix_for_player_A(i, j) << "," << matrix_for_player_B(i, j) << "\x1b[0m" << "\t";
			}
			else if ((*std::find(result_Pareto.begin(), result_Pareto.end(), matrix_for_player_A(i, j)) == matrix_for_player_A(i, j)) && (*std::find(result_Pareto.begin(), result_Pareto.end(), matrix_for_player_B(i, j)) == matrix_for_player_B(i, j)))
			{
					std::cout << "\x1b[32m" << matrix_for_player_A(i, j) << "," << matrix_for_player_B(i, j) << "\x1b[0m" << "\t";
			}
			else 
			{
			std::cout << matrix_for_player_A(i, j) << "," << matrix_for_player_B(i, j) << "\t";
			}
		}
		std::cout << std::endl;
	}
}
