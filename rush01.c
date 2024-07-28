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

void	print_error()
{
	ft_putstr("Error");
	ft_putchar('\n');
}
/*
 *
 * I should probably check if number exists in each cell
 * and retur error case true
 *
 */

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


int	solve_fours(int *coord, int **table)
{
	int	i;
	int	nbr;
	int	row;
	int	col;
	int	is_valid;

	i = 0;
	nbr = 1;
	row = 0;
	col = 0;
	is_valid = 1;
	while (i < 16)
	{
		if (coord[i] == 4)
		{
			if (i >= 0 && i <= 3)
			{
				row = 0;	
				col = i;
				nbr = 1;
				while (row < 4)
				{
					if (is_zero_position(row, col, nbr + row, table) || is_equal_position(row, col, nbr + row, table))
						table[row][col] = nbr + row;
					else
						return (0);
					row++;
				}	
			}
			if (i >= 4 && i <= 7)
			{
				row = 0;
				col = i - 4;	
				nbr = 4;
				while (row < 4)
				{
					if(is_zero_position(row, col, nbr - row, table) || is_equal_position(row, col, nbr - row, table))
						table[row][col] = nbr - row;
					else
						return (0);
					row++;
				}	
			}
			if (i >= 8 && i <= 11)
			{
				row = i - 8;
				col = 0;
				nbr = 1;
				while (col < 4)
				{
					if(is_zero_position(row, col, nbr + col, table) || is_equal_position(row, col, nbr + col, table))
						table[row][col] = nbr + col;
					else
						return (0);
					col++;
				}
			}
			if (i >= 12 && i <= 15)
			{
				row = i - 12;
				col = 0;
				nbr = 4;
				while (col < 4)
				{
					if(is_zero_position(row, col, nbr - col, table) || is_equal_position(row, col, nbr - col, table))
						table[row][col] = nbr - col;
					else
						return (0);
					col++;
				}
			}
		}
		i++;
	}
	return (1);
}

int	solve_ones(int *coord, int **table)
{
	int	i;
	int	row;
	int	col;
	int	nbr;

	i = 0;
	row = 0;
	col = 0;
	nbr = 4;
	while(i < 16)
	{
		if(coord[i] == 1)
		{

			if (i >= 0 && i <= 3)
			{
				row = 0;
				col = i;
				if (is_zero_position(row, col, nbr, table) || is_equal_position(row, col, nbr, table))
					table[row][col] = nbr;
				else
					return (0);
			}
			if (i >= 4 && i <= 7)
			{
				row = 3;
				col = i - 4;
				if (is_zero_position(row, col, nbr, table) || is_equal_position(row, col, nbr, table))
					table[row][col] = nbr;
				else
					return (0);
			}
			if (i >= 8 && i <= 11)
			{
				row = i - 8;
				col = 0;
				if (is_zero_position(row, col, nbr, table) || is_equal_position(row, col, nbr, table))
					table[row][col] = nbr;
				else
					return (0);
			}
			if (i >= 12 && i <= 15)
			{
				row = i - 12;
				col = 3;
				if (is_zero_position(row, col, nbr, table) || is_equal_position(row, col, nbr, table))
					table[row][col] = nbr;
				else
					return (0);
			}
		}
		i++;
	}
	return (1);

}

int	main(int argc, char **argv)
{
	int	*coord;
	int	**table;
	int	rows;
	int	cols;
	int	i;
	int	j;
	int	valid;

	i = 0;
	rows = 4;
	cols = 4;
	valid = 1;
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

	/*
	print_tab(rows, cols, table);
	*/


	/*test_table(rows, cols, table);*/

	/* TODO add logic here */
	/***********************/	

	
	valid = solve_ones(coord, table);
	valid = solve_fours(coord, table);

	if(valid)
		print_tab(rows, cols, table);
	else
		print_error();




	/***********************/ 
   	/* End of logic */

	/*
	free (coord);
	*/

	i = 0;
	while (i < rows)
	{
		free(table[i]);
		i++;
	}
	free (table);
	return (0);
}
