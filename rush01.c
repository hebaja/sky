#include <stdlib.h>

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	fetch_coord(char *str, int *coord);
void	print_coord(int *coord);
void	test_table(int rows, int cols, int **table);
int	is_coord_valid(int *coord);

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
	if(argc != 2)
	{
		ft_putstr("Error");
		ft_putchar('\n');
		return (0);
	}
	coord = malloc(sizeof(int) * 16);
	table = malloc(rows * sizeof(int *));
	while(i < cols)
	{
		table[i] = malloc(cols * sizeof(int));
		i++;
	}

	fetch_coord(argv[1], coord);

	ft_putnbr(is_coord_valid(coord));
	ft_putchar('\n');
	print_coord(coord);

	/*test_table(rows, cols, table);*/
	
	free(coord);
	i = 0;
	while(i < rows)
	{
		free(table[i]);
		i++;
	}
	free(table);

	return (0);
}
