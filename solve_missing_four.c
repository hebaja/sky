int		find_four_all_col(int row, int **table);
int		find_four_all_row(int col, int **table);

int	there_are_three_fours(int **table)
{
	int		row;
	int		count;

	row = 0;
	count = 0;
	while (row < 4)
	{
		if (find_four_all_col(row, table) >= 0)
			count++;
		row++;
	}
	if (count == 3)
		return (1);
	return (0);
}

void	solve_missing_four(int **table)
{
	int row;
	int col;
	int miss_row;
	int miss_col;

	row = 0;
	col = 0;
	miss_row = -1;
	miss_col = -1;

	if (there_are_three_fours(table))
	{
		while (row < 4)
		{
			if (find_four_all_col(row, table) < 0)
			{
				miss_row = row;
				break;
			}
			row++;
		}
		while (col < 4)
		{
			if (find_four_all_row(col, table) < 0)
			{
				miss_col = col;
				break;
			}
			col++;
		}
		if (miss_row >= 0 && miss_col >= 0)
			table[miss_row][miss_col] = 4;
	}
}
