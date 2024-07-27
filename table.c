void	ft_putnbr(int n);
void	ft_putchar(char c);

void	test_table(int rows, int cols, int **table)
{
	int	i;
	int	j;

	i = 0;
	while(i < rows)
	{
		j = 0;
		while(j < cols)
		{
			table[i][j] = j;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while(i < rows)
	{
		j = 0;
		while(j < cols)
		{
			ft_putnbr(table[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
