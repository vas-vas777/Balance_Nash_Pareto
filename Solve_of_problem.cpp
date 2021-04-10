#include "Matrix_game.h"

nc::NdArray<int> matrix_for_player_B(10,10);
nc::NdArray<int> matrix_for_player_A(10,10);

void generate_matrix()
{
	std::srand(time(NULL));
	for (auto i = 0; i < 10; ++i)
	{
		for (auto j = 0; j < 10; j++)
		{
			matrix_for_player_A(i, j) = rand() % 100;
			matrix_for_player_B(i, j) = rand() % 100;
		}
	}

}

void balance_Nesh()
{
	for (auto i = 0; i < 10; ++i)
	{
		for (auto j = 0; j <10; ++j)
		{
			std::cout << matrix_for_player_A(i, j)<<","<<matrix_for_player_B(i,j) << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "-------" << std::endl;
	//for (auto i = 0; i < 10; ++i)
	//{
	//	for (auto j = 0; j < 10; ++j)
	//	{
	//		std::cout << matrix_for_player_B(i, j) << "\t";
	//	}
	//	std::cout << std::endl;
	//}
	size_t flag = 0;

	for (auto i = 0; i < 10; ++i)
	{
		for (auto j = 0; j < 10; ++j)
		{

			if (j == 0 && i == 0 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j + 1))) //i=0,j=0
			{
				if ((matrix_for_player_A(i, j) > matrix_for_player_A(i + 1, j)))
				{
					std::cout << "optimal Nash0,0=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << " i=" << i << " " << "j=" << j << std::endl;
					flag = 1;
					//	break;

				}
			}

			if (j == 9 && i == 0 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j - 1))) //i=0,j=9
			{
				if ((matrix_for_player_A(i, j) > matrix_for_player_A(i + 1, j)))
				{
					std::cout << "optimal Nash0,9=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << " i=" << i << " " << "j=" << j << std::endl;
					flag = 1;
					//	break;
				}
			}

			if (j == 0 && i == 9 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j + 1))) //i=9,j=0
			{
				if ((matrix_for_player_A(i, j) > matrix_for_player_A(i - 1, j)))
				{
					std::cout << "optimal Nash9,0=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << " i=" << i << " " << "j=" << j << std::endl;
					flag = 1;
					//	break;
				}
			}

			if (j == 9 && i == 9 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j - 1))) //i=9,j=9
			{
				if ((matrix_for_player_A(i, j) > matrix_for_player_A(i - 1, j)))
				{
					std::cout << "optimal Nash9,9=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << " i=" << i << " " << "j=" << j << std::endl;
					flag = 1;
					//	break;
				}
			}

			if (i > 0 && j == 0 && i < 9 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j + 1))) //i>1 и i<9 и j=0
			{
				if (matrix_for_player_A(i, j) > matrix_for_player_A(i - 1, j) && matrix_for_player_A(i, j) > matrix_for_player_A(i + 1, j))
				{
					std::cout << "optimal Nash0=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << " i=" << i << " " << "j=" << j << std::endl;
					flag = 1;
					//	break;
				}
			}

			if (i > 0 && j == 9 && i < 9 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j - 1))) //i>1 и i<9 и j=9
			{
				if (matrix_for_player_A(i, j) > matrix_for_player_A(i - 1, j) && matrix_for_player_A(i, j) > matrix_for_player_A(i + 1, j))
				{
					std::cout << "optimal Nash9=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << " i=" << i << " " << "j=" << j << std::endl;
					flag = 1;
					//	break;
				}
			}

			if ((matrix_for_player_B(i, j) > matrix_for_player_B(i - 1, j)) && (matrix_for_player_B(i, j) > matrix_for_player_B(i + 1, j)) && i > 0 && i < 9 && j>0 && j < 9)
			{
				if ((matrix_for_player_A(i, j) > matrix_for_player_A(i, j - 1)) && (matrix_for_player_A(i, j) > matrix_for_player_A(i, j + 1)))
				{
					std::cout << "optimal Nash=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << " i=" << i << " " << "j=" << j << std::endl;
					flag = 1;
					//	break;
				}
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

void bypass_of_matrix_A(int elem_A, int elem_B)
{
	size_t flag = 0, flag2 = 0;
	for (auto i = 0; i < 10; ++i)
	{
		for (auto j = 0; j < 10; ++j)
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
					if (elem_B >= matrix_for_player_B(i, j))
					{
						flag++;
						continue;
					}
				}
				if (elem_A <= matrix_for_player_A(i, j))
				{
					if (elem_B <= matrix_for_player_B(i, j))
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
		if (flag == 99 || flag==100)
		{
			//std::cout << "optimal_Pareto=" << flag << std::endl;
			std::cout << "optimal_Pareto -> elem_A" << elem_A << " " << "elem_B" << elem_B << std::endl;
			break;
		}
		if (flag2 == 1)
		{
			break;
		}
	}
	
}

void bypass_of_matrix_B(int elem_A, int elem_B)
{
	size_t flag = 0, flag2 = 0;
	for (auto i = 0; i < 10; ++i)
	{
		for (auto j = 0; j < 10; ++j)
		{

			if (matrix_for_player_A(i, j) == elem_A && matrix_for_player_B(i, j) == elem_B)
			{
				flag++;
			//	std::cout << flag << " ";
				continue;
			}
			else
			{
				if (elem_B >= matrix_for_player_B(i, j))
				{
					if (elem_A >= matrix_for_player_A(i, j))
					{
						flag++;
					//	std::cout << flag << " ";
						continue;
					}
				}
				if (elem_B <= matrix_for_player_B(i, j))
				{
					if (elem_A <= matrix_for_player_A(i, j))
					{
						flag2 = 1;
						flag = 0;
						break;
					}
					else
					{
						flag++;
					//	std::cout << flag << " ";
						continue;

					}

				}
			}
			
		}
	//	std::cout << "----------" << std::endl;
		if (flag == 99 || flag==100)
		{
			//std::cout << "flag_B=" << flag << std::endl;
			std::cout << "optimal_Pareto -> elem_A" << elem_A << " " << "elem_B" << elem_B << std::endl;
			break;
		}

		if (flag2 == 1)
		{
			break;
		}
	}

}

void balance_Parreto()
{
	auto element_matrix_A = 0;
	std::vector<int> matrix_for_A = matrix_for_player_A.toStlVector();
	std::vector<int> matrix_for_B = matrix_for_player_B.toStlVector();
	for (auto i = 0; i < 10; ++i)
	{
		for (auto j = 0; j < 10; ++j)
		{
			bypass_of_matrix_A(matrix_for_player_A(i, j),matrix_for_player_B(i,j));
			bypass_of_matrix_B(matrix_for_player_A(i, j), matrix_for_player_B(i, j));
		}
	}
			
	std::cout << matrix_for_A.at(std::distance(matrix_for_A.begin(), std::max_element(matrix_for_A.begin(), matrix_for_A.end()))) << std::endl;
	std::cout << matrix_for_B.at(std::distance(matrix_for_B.begin(), std::max_element(matrix_for_B.begin(), matrix_for_B.end()))) << std::endl;

}
