int		find_four_col(int row, int **table);

int		solve_safe_middle_fours(int *coord, int **table)
{
	int		col;
	int		row;
	int		count;

	row = 1;
	count = 0;
	while (row < 3)
	{
		col = find_four_col(row, table);
		if (col != 0)
		{
			if (coord[row] != 1 && coord[row] != 4 && \
				coord[col] != 1 && coord[col] != 4 && \
				coord[row + 4] != 1 && coord[row + 4] != 4 && \
				coord[col + 4] != 1 && coord[col + 4] != 4)
				count++;
		}
		row++;
	}
	if (count == 0)
		return (0);
	return (1);
}
