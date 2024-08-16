int	is_complete(int **table)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (table[row][col] == 0)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}
