int		find_four_all_col(int row, int **table);
int		find_four_all_row(int col, int **table);

int		solve_put_last_four(int **table)
{
	int		row;
	int		col;
	int		miss_row;
	int		miss_col;

	row = 0;
	col = 0;
	miss_row = -1;
	miss_col = -1;
	while (row < 4)
	{
		if (find_four_all_col(row, table) == -1)
			miss_row = row;
		row++;
	}
	while (col < 4)
	{
		if (find_four_all_row(col, table) == -1)
			miss_col = col;
		col++;
	}
	if (miss_row == -1 || miss_col == -1)
		return (0);
	table[miss_row][miss_col] = 4;
	return (1);
}
