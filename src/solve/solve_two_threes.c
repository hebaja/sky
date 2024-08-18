#include <stdio.h>

void	solve_col(int col, int **table)
{
	int	ref_nbr;
	int row_check;
	int offset_a;
	int offset_b;

	if (col <= 3)
	{
		row_check = 0;
		offset_a = 0;
		offset_b = 0;
	}
	else
	{
		row_check = 3;
		offset_a = 1;
		offset_b = 3;
		col -= 4;
	}
	if (table[row_check][col] != 0)
	{
		ref_nbr = table[row_check][col];
		if (ref_nbr == 1)
		{
			table[2 - offset_a][col] = 3;
			table[3 - offset_b][col] = 2;
		}
		if (ref_nbr == 2)
		{
			table[2 - offset_a][col] = 3;
			table[3 - offset_b][col] = 1;
		}
		if (ref_nbr == 3)
		{
			table[2 - offset_a][col] = 2;
			table[3 - offset_b][col] = 1;
		}
	}

}

void	solve_row(int row, int **table)
{
	int	ref_nbr;
	int col_check;
	int offset_a;
	int offset_b;

	if (row <= 11)
	{
		col_check = 0;
		offset_a = 0;
		offset_b = 0;
		row -= 8;
	}
	else
	{
		col_check = 3;
		offset_a = 1;
		offset_b = 3;
		row -= 12;
	}
	if (table[row][col_check] != 0)
	{
		ref_nbr = table[row][col_check];
		if (ref_nbr == 1)
		{
			table[row][2 - offset_a] = 3;
			table[row][3 - offset_b] = 2;
		}
		if (ref_nbr == 2)
		{
			table[row][2 - offset_a] = 3;
			table[row][3 - offset_b] = 1;
		}
		if (ref_nbr == 3)
		{
			table[row][2 - offset_a] = 2;
			table[row][3 - offset_b] = 1;
		}
	}
}

void	solve_two_threes(int *coord, int **table)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = 0;
	col = 0;
	while (i < 16)
	{
		if (coord[i] == 2)
		{
			if ((i >= 0 && i <= 3) && coord[i + 4] == 3 || \
			(i >= 4 && i <= 7) && coord[i - 4] == 3)
			{
				col = i;
				solve_col(col, table);
			}
			if ((i >= 8 && i <= 11) && coord[i + 4] == 3 || \
			(i >= 12 && i <= 15) && coord[i - 4] == 3)
			{
				row = i;
				solve_row(row, table);
			}
		}
		i++;
	}
}
