int		find_four_all_col(int row, int **table);
int		solve_put_last_four(int **table);

int		solve_all_fours_found(int **table)
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
	{
		if(solve_put_last_four(table))
			return (1);
	}
	else if (count == 4)
		return (1);
	return (0);
}
