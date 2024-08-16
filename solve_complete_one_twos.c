void	complete_col(int row, int col, int nbr, int **table)
{
	int	i;
	int	is_valid;

	i = 0;
	is_valid = 1;
	while (i < 4)
	{
		if (table[row][i] == nbr)
			is_valid = 0;
		i++;
	}
	if (is_valid)
		table[row][col] = nbr;
}

void	complete_row(int row, int col, int nbr, int **table)
{
	int	i;
	int	is_valid;

	i = 0;
	is_valid = 1;
	while (i < 4)
	{
		if (table[i][col] == nbr)
			is_valid = 0;
		i++;
	}
	if (is_valid)
		table[row][col] = nbr;
}

int	there_is_one_or_two(int **table)
{
	int	row;
	int	col;
	int there_is;

	row = 1;
	there_is = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 4) {
			if (table[row][col] == 1 || table[row][col] == 2)
			{
				there_is = 1;
				break;
			}
			col++;
		}
		row++;
	}
	if (there_is == 0)
	{
		col = 1;
		while (col < 3)
		{
			row = 0;
			while (row < 4)
			{
				if (table[row][col] == 1 || table[row][col] == 2)
				{
					there_is = 1;
					break;
				}
				row++;
			}

			col++;
		}
	}
}

void	analize_col(int col, int **table)
{
	int	row;
	int	nbr_a;
	int	nbr_b;

	if (((col >= 0 && col <= 3) && (table[0][col] == 4 && table[3][col] == 3)) || \
		((col >= 4 && col <= 7) && (table[0][col - 4] == 3 && table[3][col - 4] == 4)))
	{
		if (there_is_one_or_two(table))
		{
			nbr_a = 1;
			nbr_b = 2;
			row = 1;
			if (col >= 4)
				col -= 4;
			if (table[row + 1][col] != nbr_a)
				complete_col(row, col, nbr_a, table);
			if (table[row + 1][col] != nbr_b)
				complete_col(row, col, nbr_b, table);
			row = 2;
			if (table[row - 1][col] != nbr_a)
				complete_col(row, col, nbr_a, table);
			if (table[row - 1][col] != nbr_b)
				complete_col(row, col, nbr_b, table);
		}
	}
}

void	analize_row(int row, int **table)
{
	int	col;
	int	nbr_a;
	int	nbr_b;

	if (((row >= 8 && row <= 11) && (table[row - 8][0] == 4 && table[row - 8][3] == 3)) || \
		((row >= 12 && row <= 15) && (table[row - 12][0] == 3 && table[row - 12][3] == 4)))
	{
		if (there_is_one_or_two(table))
		{
			nbr_a = 1;
			nbr_b = 2;
			col = 1;
			if (row <= 11)
				row -= 8;
			else
				row -= 12;
			if (table[row][col + 1] != nbr_a)
				complete_row(row, col, nbr_a, table);
			if (table[row][col + 1] != nbr_b)
				complete_row(row, col, nbr_b, table);
			col = 2;
			if (table[row][col - 1] != nbr_a)
				complete_row(row, col, nbr_a, table);
			if (table[row][col - 1] != nbr_b)
				complete_row(row, col, nbr_b, table);
		}
	}
}

void	solve_complete_one_twos(int *coord, int **table)
{
	int	i;
	int	row;
	int	col;
	int	is_valid;

	i = 0;
	row = 0;
	col = 0;
	is_valid = 1;
	while(i < 16)
	{
		if (coord[i] == 1)
		{
			if (((i >= 0 && i <= 3) && coord[i + 4] == 2) || \
				((i >= 4 && i <= 7) && coord[i - 4] == 2))
			{
				col = i;
				analize_col(col, table);
			}
			if (((i >= 8 && i <= 11) && coord[i + 4] == 2) || \
				((i >= 12 && i <= 15) && coord[i - 4] == 2))
			{
				row = i;
				analize_row(row, table);
			}
		}
		i++;
	}
}
