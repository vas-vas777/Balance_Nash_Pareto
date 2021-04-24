#include "Matrix_game.h"


void generate_matrix(int N)
{
	std::srand(time(NULL));
	double e = floor((static_cast <double> (rand()) / static_cast <double> (RAND_MAX))*10)/10; //случайное число для задачи Перекрёсток

	if (N == 2)
	{
		std::cout << "Задача смейный спор" << std::endl;
		matrix_for_player_A(0, 0) = 4; matrix_for_player_A(0, 1) = 0;
		matrix_for_player_A(1, 0) = 0; matrix_for_player_A(1, 1) = 1;
		matrix_for_player_B(0, 0) = 1; matrix_for_player_B(0, 1) = 0;
		matrix_for_player_B(1, 0) = 0; matrix_for_player_B(1, 1) = 4;
		balance_Nesh(2); balance_Pareto(2); print(2);
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		result_Nash.clear();result_Pareto.clear();
		std::cout << "Игра 'Перекрёсток'" << std::endl;
		matrix_for_player_A(0, 0) = 1; matrix_for_player_A(0, 1) = 1.0-e;
		matrix_for_player_A(1, 0) = 2; matrix_for_player_A(1, 1) = 0;
		matrix_for_player_B(0, 0) = 1; matrix_for_player_B(0, 1) = 2;
		matrix_for_player_B(1, 0) = 1.0-e; 	matrix_for_player_B(1, 1) = 0;
		balance_Nesh(2);balance_Pareto(2);print(2);
		result_Nash.clear();result_Pareto.clear();
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Задача дилемма заключенного" << std::endl;
		matrix_for_player_A(0, 0) = -5;	matrix_for_player_A(0, 1) = 0;
		matrix_for_player_A(1, 0) = -10; matrix_for_player_A(1, 1) = -1;
		matrix_for_player_B(0, 0) = -5;	matrix_for_player_B(0, 1) = -10;
		matrix_for_player_B(1, 0) = 0;	matrix_for_player_B(1, 1) = -1;
		balance_Nesh(2);balance_Pareto(2);print(2);
		result_Nash.clear();result_Pareto.clear();
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
	}

	if (N == 3)
	{
		std::cout << "Биматричная игра" << std::endl;
		matrix_for_player_A(0, 0) = 0;	matrix_for_player_A(0, 1) = 9;
		matrix_for_player_A(1, 0) = 4;	matrix_for_player_A(1, 1) = 6;
		matrix_for_player_B(0, 0) = 1;	matrix_for_player_B(0, 1) = 2;
		matrix_for_player_B(1, 0) = 6;	matrix_for_player_B(1, 1) = 3;
		result_Nash.clear(); result_Pareto.clear(); balance_Nesh(2); balance_Pareto(2); print(2);
		/*nc::NdArray<double> vec_u = { 1,1 };
		auto vv1 = 1.0 / (vec_u * nc::linalg::inv(matrix_for_player_A) * vec_u.transpose());
		auto vv2 = 1.0 / (vec_u * nc::linalg::inv(matrix_for_player_B) * vec_u.transpose());
		nc::NdArray<double> vec_x;
		nc::NdArray<double> vec_y;
		vec_x = vv2 * vec_u * nc::linalg::inv(matrix_for_player_B);
		vec_y = vv1 * nc::linalg::inv(matrix_for_player_B) * vec_u.transpose();
		std::cout << "Равновесные выигрыши: v1=" << floor((1.0 / vv1) * 100) / 100 << " v2=" << floor((1.0 / vv2) * 100) / 100 << std::endl;
		std::cout << "x=["<<vec_x << "] y=[" << vec_y.transpose() << "]" << std::endl;*/

		auto v1 = 7.0 / 36.0;
		auto v2 = 4.0 / 9.0;
		std::cout << "Равновесные выигрыши: v1=" << floor((1.0 / v1)*100)/100 << " v2=" << floor((1.0 / v2)*100)/100 << std::endl;
		std::cout << "x=[" << 3.0 / 4.0 << "," << 1.0 / 4.0 << "] y=[" << floor((3.0 / 7.0)*100)/100 << "," << floor((4.0 / 7.0)*100)/100 << "]" << std::endl;	
	}

	if (N == 10) //генерация матрицы 10 на 10
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

void bypass_of_matrix(double elem_A, double elem_B, int N) //Обход матрицы для равновесия Парето
{
	size_t flag = 0, flag2 = 0;//flag==0 - если найдена точка равновесия по Парето, flag2==1 - если точка не равновесна по Парето
	for (auto i = 0; i < N; ++i)
	{
		for (auto j = 0; j < N; ++j)
		{

			if (matrix_for_player_A(i, j) == elem_A && matrix_for_player_B(i, j) == elem_B)
			{
				flag++;
				continue;
			}

			if ((elem_A >= matrix_for_player_A(i, j)) && elem_B >= matrix_for_player_B(i, j))
			{

				flag++;
				continue;
			}
			else if ((elem_A < matrix_for_player_A(i, j)) && elem_B <= matrix_for_player_B(i, j))
			{
			flag = 0;
			flag2 = 1;
			break;
			}
			else if ((elem_A <= matrix_for_player_A(i, j)) && elem_B < matrix_for_player_B(i, j))
			{
			flag = 0;
			flag2 = 1;
			break;
			}
			else
			{
			flag++;
			continue;
			}

			if (elem_A < matrix_for_player_A(i, j) && (elem_B < matrix_for_player_B(i, j)))
			{
				flag = 0;
				flag2 = 1;
				break;
			}
		}
		if ((flag == 100) && N == 10) //для матриц 10 на 10
		{
			result_Pareto.push_back(elem_A);
			result_Pareto.push_back(elem_B);
			break;
		}

		if ((flag == 4) && N == 2) //для матриц 2 на 2
		{
			result_Pareto.push_back(elem_A);
			result_Pareto.push_back(elem_B);
			break;
		}

		if (flag2 == 1) //точка не равновесна по Парето
		{
			flag2 = 0;
			flag = 0;
			break;
		}
	}
}

void print(int N) //вывод 
{
	if (!result_Nash.empty())
	{
		std::cout << "Ситуации равновесия по Нэшу" << std::endl;
		for (auto i : result_Nash)
		{
			std::cout << i << " ";
		}
	}

	if (!result_Pareto.empty())
	{
		std::cout << std::endl;
		std::cout << "Ситуации равновесия по Парето" << std::endl;
		for (auto i : result_Pareto)
		{
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Пересечение множеств" << std::endl;
	for (auto itP = result_Pareto.begin(); itP != result_Pareto.end(); itP += 2)
	{
		if ((std::find(result_Nash.begin(), result_Nash.end(), *itP) != result_Nash.end()) && (std::find(result_Nash.begin(), result_Nash.end(), *(itP + 1)) != result_Nash.end()))
		{
			std::cout << *itP << " " << *(itP + 1) << " ";
		}
	}
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (auto i = 0; i < N; ++i)
	{
		for (auto j = 0; j < N; ++j)
		{
			if ((std::find(result_Nash.begin(), result_Nash.end(), matrix_for_player_A(i, j)) != result_Nash.end()) && ((std::find(result_Nash.begin(), result_Nash.end(), matrix_for_player_B(i, j))) != result_Nash.end()) && (std::find(result_Pareto.begin(), result_Pareto.end(), matrix_for_player_A(i, j)) != result_Pareto.end()) && (std::find(result_Pareto.begin(), result_Pareto.end(), matrix_for_player_B(i, j)) != result_Pareto.end()))
			{
				std::cout << "\x1b[33m" << matrix_for_player_A(i, j) << "\x1b[0m" << "," << "\x1b[33m" << matrix_for_player_B(i, j) << "\x1b[0m" << "\t";
				result_Pareto.erase(std::find(result_Pareto.begin(), result_Pareto.end(), matrix_for_player_A(i, j)));
				result_Pareto.erase(std::find(result_Pareto.begin(), result_Pareto.end(), matrix_for_player_B(i, j)));
			}
			else if ((std::find(result_Nash.begin(), result_Nash.end(), matrix_for_player_A(i, j)) != result_Nash.end()) && ((std::find(result_Nash.begin(), result_Nash.end(), matrix_for_player_B(i, j))) != result_Nash.end()))
			{
				std::cout << "\x1b[31m" << matrix_for_player_A(i, j) << "\x1b[0m" << "," << "\x1b[31m" << matrix_for_player_B(i, j) << "\x1b[0m" << "\t";
				result_Nash.erase(std::find(result_Nash.begin(), result_Nash.end(), matrix_for_player_A(i, j)));
				result_Nash.erase(std::find(result_Nash.begin(), result_Nash.end(), matrix_for_player_B(i, j)));
			}
			else if ((std::find(result_Pareto.begin(), result_Pareto.end(), matrix_for_player_A(i, j)) != result_Pareto.end()) && (std::find(result_Pareto.begin(), result_Pareto.end(), matrix_for_player_B(i, j)) != result_Pareto.end()))
			{
				std::cout << "\x1b[32m" << matrix_for_player_A(i, j) << "\x1b[0m" << "," << "\x1b[32m" << matrix_for_player_B(i, j) << "\x1b[0m" << "\t";
				result_Pareto.erase(std::find(result_Pareto.begin(), result_Pareto.end(), matrix_for_player_A(i, j)));
				result_Pareto.erase(std::find(result_Pareto.begin(), result_Pareto.end(), matrix_for_player_B(i, j)));
			}
			else
			{
				std::cout << matrix_for_player_A(i, j) << "," << matrix_for_player_B(i, j) << "\t";
			}
		}
		std::cout << std::endl;
	}
}