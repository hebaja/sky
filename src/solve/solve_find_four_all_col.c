int		find_four_all_col(int row, int **table)
{
	int		col;

	col = 0;
	while (col < 4)
	{
		if (table[row][col] == 4)
			return col;
		col++;
	}
	return -1;
}
