int	is_equal_position(int row, int col, int nbr, int **table);
int	is_zero_position(int row, int col, int nbr, int **table);

int	solve_one_twos(int *coord, int **table)
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
		if (coord[i] == 1)
		{
			if ((i >= 0 && i <= 3) && coord[i + 4] == 2)
			{
				row = 0;
				col = i;
				if (is_zero_position(row, col, 4, table) || is_equal_position(row, col, 4, table) || \
					is_zero_position(row + 3, col, 3, table) || is_equal_position(row + 3, col, 3, table))
				{
					table[row][col] = 4;
					table[row + 3][col] = 3;
				}
				else
					return (0);
			}
			if ((i >= 4 && i <= 7) && coord[i - 4] == 2)
			{
				row = 3;
				col = i - 4;
				if(is_zero_position(row, col, 4, table) || is_equal_position(row, col, 4, table) || \
					is_zero_position(row - 3, col, 3, table) || is_equal_position(row - 3, col, 3, table))
				{
					table[row][col] = 4;
					table[row - 3][col] = 3;
				}
				else
					return (0);
			}
			if ((i >= 8 && i <= 11) && coord[i + 4] == 2)
			{
				row = i - 8;
				col = 0;
				if(is_zero_position(row, col, 4, table) || is_equal_position(row, col, 4, table) || \
					is_zero_position(row, col + 3, 3, table) || is_equal_position(row, col + 3, 3, table))
				{
					table[row][col] = 4;
					table[row][col + 3] = 3;
				}
				else
					return (0);
			}
			if ((i >= 12 && i <= 15) && coord[i - 4] == 2)
			{
				row = i - 12;
				col = 3;
				if(is_zero_position(row, col, 4, table) || is_equal_position(row, col, 4, table) || \
					is_zero_position(row, col - 3, 3, table) || is_equal_position(row, col - 3, 3, table))
				{
					table[row][col] = 4;
					table[row][col - 3] = 3;
				}
				else
					return (0);
			}
		}
		i++;
	}
	return (1);
}
