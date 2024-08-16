int	is_equal_position(int row, int col, int nbr, int **table);
int	is_zero_position(int row, int col, int nbr, int **table);

int	solve_ones(int *coord, int **table)
{
	int	i;
	int	row;
	int	col;
	int	nbr;

	i = 0;
	row = 0;
	col = 0;
	nbr = 4;
	while(i < 16)
	{
		if(coord[i] == 1)
		{

			if (i >= 0 && i <= 3)
			{
				row = 0;
				col = i;
				if (is_zero_position(row, col, nbr, table) || is_equal_position(row, col, nbr, table))
					table[row][col] = nbr;
				else
					return (0);
			}
			if (i >= 4 && i <= 7)
			{
				row = 3;
				col = i - 4;
				if (is_zero_position(row, col, nbr, table) || is_equal_position(row, col, nbr, table))
					table[row][col] = nbr;
				else
					return (0);
			}
			if (i >= 8 && i <= 11)
			{
				row = i - 8;
				col = 0;
				if (is_zero_position(row, col, nbr, table) || is_equal_position(row, col, nbr, table))
					table[row][col] = nbr;
				else
					return (0);
			}
			if (i >= 12 && i <= 15)
			{
				row = i - 12;
				col = 3;
				if (is_zero_position(row, col, nbr, table) || is_equal_position(row, col, nbr, table))
					table[row][col] = nbr;
				else
					return (0);
			}
		}
		i++;
	}
	return (1);
}
