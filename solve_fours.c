int	is_equal_position(int row, int col, int nbr, int **table);
int	is_zero_position(int row, int col, int nbr, int **table);

int	solve_fours(int *coord, int **table)
{
	int	i;
	int	nbr;
	int	row;
	int	col;
	int	is_valid;

	i = 0;
	nbr = 1;
	row = 0;
	col = 0;
	is_valid = 1;
	while (i < 16)
	{
		if (coord[i] == 4)
		{
			if (i >= 0 && i <= 3)
			{
				row = 0;	
				col = i;
				nbr = 1;
				while (row < 4)
				{
					if (is_zero_position(row, col, nbr + row, table) || is_equal_position(row, col, nbr + row, table))
						table[row][col] = nbr + row;
					else
						return (0);
					row++;
				}	
			}
			if (i >= 4 && i <= 7)
			{
				row = 0;
				col = i - 4;	
				nbr = 4;
				while (row < 4)
				{
					if(is_zero_position(row, col, nbr - row, table) || is_equal_position(row, col, nbr - row, table))
						table[row][col] = nbr - row;
					else
						return (0);
					row++;
				}	
			}
			if (i >= 8 && i <= 11)
			{
				row = i - 8;
				col = 0;
				nbr = 1;
				while (col < 4)
				{
					if(is_zero_position(row, col, nbr + col, table) || is_equal_position(row, col, nbr + col, table))
						table[row][col] = nbr + col;
					else
						return (0);
					col++;
				}
			}
			if (i >= 12 && i <= 15)
			{
				row = i - 12;
				col = 0;
				nbr = 4;
				while (col < 4)
				{
					if(is_zero_position(row, col, nbr - col, table) || is_equal_position(row, col, nbr - col, table))
						table[row][col] = nbr - col;
					else
						return (0);
					col++;
				}
			}
		}
		i++;
	}
	return (1);
}
