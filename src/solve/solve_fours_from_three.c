int	is_equal_position(int row, int col, int nbr, int **table);
int	is_zero_position(int row, int col, int nbr, int **table);

int		check_possible_row(int row, int **table)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (table[row][i] == 4)
			return (0);
		i++;
	}
	return (1);
}

int		get_possible_col(int col, int **table)
{
	int		i;
	
	i = 0;
	while (i < 4)
	{
		if (table[i][col] == 4)
			return (0);
		i++;
	}
	return (1);
}

int	solve_fours_from_three(int *coord, int **table)
{
	int	i;
	int	row;
	int	col;
	int	is_valid;

	i = 0;
	row = 0;
	col = 0;
	is_valid = 1;
	while (i < 16)
	{
		if (coord[i] == 3)
		{
			if (i >= 0 && i <= 3)
			{
				row = 2;
				col = i;
				if (table[row][col] == 4 || table[row + 1][col] == 4)
					is_valid = 1;
				else if (check_possible_row(row, table))
					table[row][col] = 4;
				else if (check_possible_row(row + 1, table))
					table[row + 1][col] = 4;
				else
					return (0);
			}
			if (i >= 4 && i <= 7)
			{
				row = 0;
				col = i - 4;
				if (table[row][col] == 4 || table[row + 1][col] == 4)
					is_valid = 1;
				else if(check_possible_row(row, table))
					table[row][col] = 4;
				else if(check_possible_row(row + 1, table))
					table[row + 1][col] = 4;
				else
					return (0);
			}

			if (i >= 8 && i <= 11)
			{
				row = i - 8;
				col = 2;
				if (table[row][col] == 4 || table[row][col + 1] == 4)
					is_valid = 1;
				else if(get_possible_col(col, table))
					table[row][col] = 4;
				else if(get_possible_col(col + 1, table))
					table[row][col + 1] = 4;
				else
					return (0);
			}
			if (i >= 12 && i <= 15)
			{
				row = i - 12;
				col = 0;
				if (table[row][col] == 4 || table[row + 1][col] == 4)
					is_valid = 1;
				else if(get_possible_col(col, table))
					table[row][col] = 4;
				else if(get_possible_col(col + 1, table))
					table[row][col + 1] = 4;
				else
					return (0);
			}
		}
		i++;
	}
	return (is_valid);
}
