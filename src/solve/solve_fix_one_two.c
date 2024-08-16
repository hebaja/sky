void	swap(int row, int **table)
{
	int	tmp;

	tmp = table[row][1];
	table[row][1] = table[row][2];
	table[row][2] = tmp;
}

void	case_flip_row_down(int row, int col, int **table)
{
	if (table[row - 1][col] == 1 || table[row + 1][col] == 1 || table[row + 2][col] == 1)
		swap(row, table);
}

void	case_flip_row_up(int row, int col, int **table)
{
	if (table[row - 2][col] == 1 || table[row - 1][col] == 1 || table[row + 1][col] == 1)
		swap(row, table);
}

void solve_fix_one_two(int **table)
{
	if (table[1][1] == 1)
		case_flip_row_down(1, 1, table);
	if (table[1][2] == 1)
		case_flip_row_down(1, 2, table);
	if (table[2][1] == 1)
		case_flip_row_up(2, 1, table);
	if (table[2][2] == 1)
		case_flip_row_up(2, 2, table);
}
