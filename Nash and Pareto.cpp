#include "Matrix_game.h"

 nc::NdArray<double> matrix_for_player_A(10, 10);
 nc::NdArray<double> matrix_for_player_B(10, 10);
 std::vector<double> result_Nash;
 std::vector<double> result_Pareto;

void balance_Nesh(int N) //равновесие по Нэшу
{
	size_t flag = 0;
	size_t flag2 = 0;

	for (auto i = 0; i < N; ++i)
	{
		for (auto j = 0; j < N; ++j)
		{
			if (j == 0 && i == 0 && (matrix_for_player_B(i, j) >= matrix_for_player_B(i, j + 1))) //i=0,j=0
			{
				for (auto jj = 2; jj < N; ++jj)
				{
					if (matrix_for_player_B(i, j) >= matrix_for_player_B(i, jj))
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
					if ((matrix_for_player_A(i, j) >= matrix_for_player_A(ii, j)))
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
					result_Nash.push_back(matrix_for_player_A(i, j));
					result_Nash.push_back(matrix_for_player_B(i, j));
				}
			}
			flag2 = 0;
			if (j == N - 1 && i == 0 && (matrix_for_player_B(i, j) >= matrix_for_player_B(i, j - 1))) //i=0,j=N-1
			{

				for (auto jj = N - 2; jj >= 0; --jj)
				{
					if (matrix_for_player_B(i, j) >= matrix_for_player_B(i, jj))
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
					if ((matrix_for_player_A(i, j) >= matrix_for_player_A(ii, j)))
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
					result_Nash.push_back(matrix_for_player_A(i, j));
					result_Nash.push_back(matrix_for_player_B(i, j));
				}
			}
			flag2 = 0;
			if (j == 0 && i == N - 1 && (matrix_for_player_B(i, j) >= matrix_for_player_B(i, j + 1))) //i=N-1,j=0
			{

				for (auto jj = 2; jj < N; ++jj)
				{
					if (matrix_for_player_B(i, j) >= matrix_for_player_B(i, jj))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}
				for (auto ii = N - 2; ii >= 0; --ii)
				{
					if ((matrix_for_player_A(i, j) >= matrix_for_player_A(ii, j)))
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
					result_Nash.push_back(matrix_for_player_A(i, j));
					result_Nash.push_back(matrix_for_player_B(i, j));
				}
			}
			flag2 = 0;
			if (j == N - 1 && i == N - 1 && (matrix_for_player_B(i, j) >= matrix_for_player_B(i, j - 1))) //i=N-1,j=N-1
			{

				for (auto jj = N - 2; jj >= 0; --jj)
				{
					if (matrix_for_player_B(i, j) >= matrix_for_player_B(i, jj))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}
				for (auto ii = N - 2; ii >= 0; --ii)
				{
					if ((matrix_for_player_A(i, j) >= matrix_for_player_A(ii, j)))
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
					result_Nash.push_back(matrix_for_player_A(i, j));
					result_Nash.push_back(matrix_for_player_B(i, j));
				}
			}
			flag2 = 0;
			if (i > 0 && j == 0 && i < N - 1 && (matrix_for_player_B(i, j) >= matrix_for_player_B(i, j + 1))) //i>1 и i<N-1 и j=0
			{

				for (auto ii = i + 1; ii <= N - 1; ++ii)
				{
					if (matrix_for_player_A(i, j) >= matrix_for_player_A(ii, j))
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
					if (matrix_for_player_A(i, j) >= matrix_for_player_A(ii, j))
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
					if (matrix_for_player_B(i, j) >= matrix_for_player_B(i, jj))
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
					result_Nash.push_back(matrix_for_player_A(i, j));
					result_Nash.push_back(matrix_for_player_B(i, j));
				}
			}
			flag2 = 0;
			if (i > 0 && j == N - 1 && i < N - 1 && (matrix_for_player_B(i, j) >= matrix_for_player_B(i, j - 1))) //i>1 и i<N-1 и j=N-1
			{

				for (auto ii = i + 1; ii <= N - 1; ++ii)
				{
					if (matrix_for_player_A(i, j) >= matrix_for_player_A(ii, j))
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
					if (matrix_for_player_A(i, j) >= matrix_for_player_A(ii, j))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}

				for (auto jj = N - 1; jj >= 0; --jj)
				{
					if (matrix_for_player_B(i, j) >= matrix_for_player_B(i, jj))
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
					result_Nash.push_back(matrix_for_player_A(i, j));
					result_Nash.push_back(matrix_for_player_B(i, j));
				}
			}
			flag2 = 0;
			if ((matrix_for_player_B(i, j) >= matrix_for_player_B(i, j - 1)) && (matrix_for_player_B(i, j) >= matrix_for_player_B(i, j + 1)) && i > 0 && i < N - 1 && j>0 && j < N - 1) //i>0 i<N-1 j>0 j<N-1
			{
				for (auto ii = i + 1; ii < N; ++ii)
				{
					if (matrix_for_player_A(i, j) >= matrix_for_player_A(ii, j))
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
					if (matrix_for_player_A(i, j) >= matrix_for_player_A(ii, j))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}

				for (auto jj = j + 1; jj < N; ++jj)
				{
					if (matrix_for_player_B(i, j) >= matrix_for_player_B(i, jj))
					{
						continue;
					}
					else
					{
						flag2 = 1;
						break;
					}
				}

				for (auto jj = j - 1; jj >= 0; --jj)
				{
					if (matrix_for_player_B(i, j) >= matrix_for_player_B(i, jj))
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
					result_Nash.push_back(matrix_for_player_A(i, j));
					result_Nash.push_back(matrix_for_player_B(i, j));
				}
			}
			flag2 = 0;
		}
	}
}

void balance_Pareto(int N) //равновесие по Парето
{
	auto element_matrix_A = 0;
	for (auto i = 0; i < N; ++i)
	{
		for (auto j = 0; j < N; ++j)
		{
			bypass_of_matrix(matrix_for_player_A(i, j), matrix_for_player_B(i, j), N);
		}
	}
}
