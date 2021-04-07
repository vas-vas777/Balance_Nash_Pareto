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
			matrix_for_player_A(i, j) = -50 + rand() % 100;
			matrix_for_player_B(i, j) = -50 + rand() % 100;
		}
	}
	
}

void balance_Nesh()
{
	matrix_for_player_A.print();
	std::cout << std::endl;
	matrix_for_player_B.print();
	size_t flag = 0;
	
	for (auto i = 0; i < 10; ++i)
	{
		for (auto j = 0; j < 10; ++j)
		{

			if (j == 0 && i==0 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j + 1))) //i=0,j=0
			{
				if ((matrix_for_player_A(i, j) > matrix_for_player_A(i + 1, j)))
				{
					std::cout << "optimal Nash0,0=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << std::endl;
					flag = 1;
				//	break;

				}
			}

			if (j == 9 && i == 0 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j - 1))) //i=0,j=9
			{
				if ((matrix_for_player_A(i, j) > matrix_for_player_A(i + 1, j)))
				{
					std::cout << "optimal Nash0,9=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << std::endl;
					flag = 1;
				//	break;
				}
			}

			if (j == 0 && i == 9 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j + 1))) //i=9,j=0
			{
				if ((matrix_for_player_A(i, j) > matrix_for_player_A(i - 1, j)))
				{
					std::cout << "optimal Nash9,0=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << std::endl;
					flag = 1;
				//	break;
				}
			}

			if (j == 9 && i == 9 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j - 1))) //i=9,j=9
			{
				if ((matrix_for_player_A(i, j) > matrix_for_player_A(i - 1, j)))
				{
					std::cout << "optimal Nash9,9=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << std::endl;
					flag = 1;
				//	break;
				}
			}

			if (i > 0 && j == 0 && i<9 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j + 1))) //i>1 è i<9 è j=0
			{
				if (matrix_for_player_A(i, j) > matrix_for_player_A(i - 1, j) && matrix_for_player_A(i, j) > matrix_for_player_A(i + 1, j))
				{
					std::cout << "optimal Nash0=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << std::endl;
					flag = 1;
				//	break;
				}
			}

			if (i > 0 && j == 9 && i < 9 && (matrix_for_player_B(i, j) > matrix_for_player_B(i, j - 1))) //i>1 è i<9 è j=9
			{
				if (matrix_for_player_A(i, j) > matrix_for_player_A(i - 1, j) && matrix_for_player_A(i, j) > matrix_for_player_A(i + 1, j))
				{
					std::cout << "optimal Nash9=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << std::endl;
					flag = 1;
				//	break;
				}
			}

			if ((matrix_for_player_B(i, j) > matrix_for_player_B(i - 1, j)) && (matrix_for_player_B(i, j) > matrix_for_player_B(i + 1, j)) && i>0 && i<9 && j>0 && j<9)
			{
				if ((matrix_for_player_A(i, j) > matrix_for_player_A(i, j-1)) && (matrix_for_player_A(i, j) > matrix_for_player_A(i, j+1)))
				{
					std::cout << "optimal Nash=" << matrix_for_player_A(i, j) << " " << matrix_for_player_B(i, j) << std::endl;
					flag = 1;
				//	break;
				}
			}
		}
		if (flag==1)
		{
			break;
		}
	}
}
