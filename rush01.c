#include <stdlib.h>

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	fetch_coord(char *str, int *coord);
void	print_coord(int *coord);
void	test_table(int rows, int cols, int **table);
int	is_coord_valid(int *coord);
void	tab_zeroes(int rows, int cols, int **table);
void	print_tab(int rows, int cols, int **table);
int	ft_strlen(char *str);
int	solve_fours(int *coord, int **table);
int	solve_ones(int *coord, int **table);
int	solve_one_twos(int *coord, int **table);
int	solve_fours_from_three(int *coord, int **table);
int		solve_safe_middle_fours(int *coord, int **table);
int		solve_middle_fours_row(int *coord, int **table);
int		solve_middle_fours_col(int *coord, int **table);
int		solve_two_two_col(int *coord, int **table);
int		solve_two_two_row(int *coord, int **table);
int		solve_all_fours_found(int **table);
void	solve_complete_one_twos(int *coord, int **table);
void	solve_two_threes(int *coord, int **table);
void	solve_one_threes(int *coord, int **table);
int	is_complete(int **table);
void solve_fix_one_two(int **table);
void	solve_missing_four(int **table);

void	print_error()
{
	ft_putstr("Error");
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	int	*coord;
	int	**table;
	int	rows;
	int	cols;
	int	i;
	int	count;

	i = 0;
	rows = 4;
	cols = 4;
	count = 0;
	if (argc == 2)
	{
		coord = malloc(sizeof(int) * 16);
		fetch_coord(argv[1], coord);
		if (!is_coord_valid(coord))
		{
			print_error();
			return (0);
		}

		table = malloc(rows * sizeof(int *));
		while (i < cols)
		{
			table[i] = malloc(cols * sizeof(int));
			i++;
		}
		print_coord(coord);
	}
	else
	{
		print_error();
		return (0);
	}
	tab_zeroes(rows, cols, table);
	solve_ones(coord, table);
	solve_fours(coord, table);
	solve_one_twos(coord, table);
	solve_fours_from_three(coord, table);
	solve_safe_middle_fours(coord, table);
	solve_all_fours_found(table);
	solve_two_two_row(coord, table);
	solve_two_two_col(coord, table);
	solve_complete_one_twos(coord, table);
	solve_two_threes(coord, table);
	solve_one_threes(coord, table);
	while (!is_complete(table) && count < 10)
	{
		solve_two_two_row(coord, table);
		solve_two_two_col(coord, table);
		solve_complete_one_twos(coord, table);
		solve_two_threes(coord, table);
		solve_one_threes(coord, table);
		solve_fix_one_two(table);
		solve_missing_four(table);
		count++;
	}			
	if (is_complete(table))
		print_tab(rows, cols, table);
	else
		print_error();
	free (coord);
	i = 0;
	while (i < rows)
	{
		free(table[i]);
		i++;
	}
	free (table);
	return (0);
}
