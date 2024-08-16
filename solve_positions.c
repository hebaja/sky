int	is_equal_position(int row, int col, int nbr, int **table)
{
	if (table[row][col] == nbr)
		return (1);
	return (0);
}

int	is_zero_position(int row, int col, int nbr, int **table)
{
	if (table[row][col] == 0)
		return (1);
	return (0);
}
