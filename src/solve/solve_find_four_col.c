int		find_four_col(int row, int **table)
{
	int		col;

	col = 1;
	while (col < 3)
	{
		if (table[row][col] == 4)
			return col;
		col++;
	}
	return 0;
}
