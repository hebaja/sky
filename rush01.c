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

void	print_error()
{
	ft_putstr("Error");
	ft_putchar('\n');
}

void	solve_fours(int *coord, int **table)
{
	int	i;
	int	nbr;
	int	row;
	/*int	col;*/


	i = 0;
	nbr = 1;
	row = 0;
	/*col = 0;*/
	while (i < 16)
	{
		if (coord[i] == 4)
		{
			if (i >= 0 && i <= 3)
			{
				row = 0;	
				while (row < 4)
				{
					table[row][i] = nbr + row;
					row++;
				}	
			}
			if (i >= 4 && i <= 7)
			{
				row = 4;	
				while (row > 0)
				{
					table[row][i - 4] = nbr + row;
					row--;
				}	
			}
			/*
			if (i >= 8 && i <= 11)
			if (i >= 12 && i <= 15)
			*/
		}
		
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	*coord;
	int	**table;
	int	rows;
	int	cols;
	int	i;

	i = 0;
	rows = 4;
	cols = 4;

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
	/*print_tab(rows, cols, table);*/

	/*test_table(rows, cols, table);*/

	/* TODO add logic here */
	 
	solve_fours(coord, table);
	
	print_tab(rows, cols, table);
	 
   	/* End of logic */
	
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
