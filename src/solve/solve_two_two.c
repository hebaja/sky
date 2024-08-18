#include <stdio.h>

int		find_four_row(int col, int **table);
int		find_four_col(int row, int **table);

void	populate_row(int row, int offset, int **table)
{
	int		check_col;

	if (offset == 2)
	{
		check_col = 0;
		if (table[row][check_col] == 1)
		{
			table[row][offset] = 2;
			table[row][offset + 1] = 3;
		}
		if (table[row][check_col] == 2)
		{
			table[row][offset] = 1;
			table[row][offset + 1] = 3;
		}
		if (table[row][check_col] == 3)
		{
			table[row][offset] = 1;
			table[row][offset + 1] = 2;
		}
	}
	else
	{
		check_col = 3;
		if (table[row][check_col] == 1)
		{
			table[row][offset] = 3;
			table[row][offset + 1] = 2;
		}
		if (table[row][check_col] == 2)
		{
			table[row][offset] = 3;
			table[row][offset + 1] = 1;
		}
		if (table[row][check_col] == 3)
		{

			table[row][offset] = 2;
			table[row][offset + 1] = 1;
		}
	}
}

void	populate_col(int col, int offset, int **table)
{
	int		check_row;


	if (offset == 2)
	{
		check_row = 0;
		if (table[check_row][col] == 1)
		{
			table[offset][col] = 2;
			table[offset + 1][col] = 3;
		}
		if (table[check_row][col] == 2)
		{
			table[offset][col] = 1;
			table[offset + 1][col] = 3;
		}
		if (table[check_row][col] == 3)
		{
			table[offset][col] = 1;
			table[offset + 1][col] = 2;
		}
	}
	else
	{
		check_row = 3;
		if (table[check_row][col] == 1)
		{
			table[offset][col] = 3;
			table[offset + 1][col] = 2;
		}
		if (table[check_row][col] == 2)
		{
			table[offset][col] = 3;
			table[offset + 1][col] = 1;
		}
		if (table[check_row][col] == 3)
		{
			table[offset][col] = 2;
			table[offset + 1][col] = 1;
		}
	}
}

int		get_offset(int nb)
{
	if (nb == 1)
		return (2);
	return (0);
}

int		solve_two_two_row(int *coord, int **table)
{
	int		four_col;
	int		row;
	int		col;
	int		i;
	int		offset;

	row = 0;
	i = 0;
	while (i < 16)
	{
		if (i >= 8 && i <= 11 && coord[i] == 2 && coord[i + 4] == 2)
		{
			row = i - 8;
			four_col = find_four_col(row, table);
			if (four_col == 0)
				return (0);
			offset = get_offset(four_col);
			populate_row(row, offset, table);
		}
		i++;
	}
	return (1);
}

int		solve_two_two_col(int *coord, int **table)
{
	int		four_row;
	int		row;
	int		col;
	int		i;
	int		offset;

	col = 0;
	i = 0;
	while (i < 16)
	{
		if (i >= 0 && i <= 3 && coord[i] == 2 && coord[i + 4] == 2)
		{
			col = i;
			four_row = find_four_row(col, table);
			if (four_row == 0)
				return (0);
			offset = get_offset(four_row);
			populate_col(col, offset, table);
		}
		i++;
	}
	return (1);
}
