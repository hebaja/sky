#include <stdio.h>

void	solve_one_three_col(int col, int **table)
{
	int	row_check;
	int	offset;

	if (col <= 3)
	{
		row_check = 0;
		offset = 0;
	}
	else
	{
		row_check = 3;
		offset = 1;
		col -= 4;
	}
	if (table[row_check][col] == 4)
	{
		if (table[1 + offset][col] == 1)
		{
			table[2 - offset][col] = 3;
			table[3 - (offset * 3)][col] = 2;
		}
		if (table[2 - offset][col] == 1)
		{
			table[1 + offset][col] = 3;
			table[3 - (offset * 3)][col] = 2;
		}
		if (table[3 - (offset * 3)][col] == 1)
		{
			table[1][col] = 2 + offset;
			table[2][col] = 3 - offset;
		}
		if (table[1 + offset][col] == 3)
		{
			table[2 - offset][col] = 1;
			table[3 - (offset * 3)][col] = 2;
		}
		if (table[1 + offset][col] == 2)
		{
			table[2 - offset][col] = 3;
			table[3 - (offset * 3)][col] = 1;
		}
	}
}

void	solve_one_three_row(int row, int **table)
{
	int	col_check;
	int	offset;

	if (row <= 11)
	{
		col_check = 0;
		offset = 0;
		row -= 8;
	}
	else
	{
		col_check = 3;
		offset = 1;
		row -= 12;
	}
	if (table[row][col_check] == 4)
	{
		if (table[row][1 + offset] == 1)
		{
			table[row][2 - offset] = 3;
			table[row][3 - (offset * 3)] = 2;
		}
		if (table[row][2 - offset] == 1)
		{
			table[row][1 + offset] = 3;
			table[row][3 - (offset * 3)] = 2;
		}
		if (table[row][3 - (offset * 3)] == 1)
		{
			table[row][1] = 2 + offset;
			table[row][2] = 3 - offset;
		}
		if (table[row][1 + offset] == 3)
		{
			table[row][2 - offset] = 1;
			table[row][3 - (offset * 3)] = 2;
		}
		if (table[row][1 + offset] == 2)
		{
			table[row][2 - offset] = 3;
			table[row][3 - (offset * 3)] = 1;
		}
	}
}

void	solve_one_threes(int *coord, int **table)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = 0;
	col = 0;
	while (i < 16)
	{
		if (coord[i] == 1)
		{
			if ((i >= 0 && i <= 3) && coord[i + 4] == 3 || \
				(i >= 4 && i <= 7) && coord[i - 4] == 3)
			{
				col = i;
				solve_one_three_col(col, table);
			}
			if ((i >= 8 && i <= 11) && coord[i + 4] == 3 || \
			(i >= 12 && i <= 15) && coord[i - 4] == 3)
			{
				row = i;
				solve_one_three_row(row, table);
			}
		}
		i++;
	}
}
