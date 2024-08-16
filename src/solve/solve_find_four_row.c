int		find_four_row(int col, int **table)
{
	int		row;

	row = 1;
	while (row < 3)
	{
		if (table[row][col] == 4)
			return row;
		row++;
	}
	return 0;
}
