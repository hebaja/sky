int		find_four_all_row(int col, int **table)
{
	int		row;

	row = 0;
	while (row < 4)
	{
		if (table[row][col] == 4)
			return row;
		row++;
	}
	return -1;
}
