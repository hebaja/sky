#include <stdlib.h>
#include "utils/ft.h"
#include "solve/solve.h"

void	print_error()
{
	ft_putstr("Error");
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	int	*coord;
	int	**table;
	int	i;
	int	count;

	i = 0;
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

		table = malloc(4 * sizeof(int *));
		while (i < 4)
		{
			table[i] = malloc(4 * sizeof(int));
			i++;
		}
		//print_coord(coord);
	}
	else
	{
		print_error();
		return (0);
	}
	tab_zeroes(4, 4, table);
	solve_ones(coord, table);
	solve_fours(coord, table);
	solve_one_twos(coord, table);
	solve_fours_from_three(coord, table);
	solve_safe_middle_fours(coord, table);
	solve_all_fours_found(table);
	solve_two_two_row(coord, table);
	solve_two_two_col(coord, table);
	solve_two_threes(coord, table);
	solve_one_threes(coord, table);
	solve_missing_four(table);
	solve_complete_one_twos(coord, table);
	
	// print_tab(4, 4, table);
	// ft_putchar(10);
	
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
		print_tab(4, 4, table);
	else
		print_error();

	// ft_putchar(10);
	// print_tab(4, 4, table);
	
	free (coord);
	i = 0;
	while (i < 4)
	{
		free(table[i]);
		i++;
	}
	free (table);
	return (0);
}
