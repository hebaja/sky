void	ft_putnbr(int n);
void	ft_putchar(char n);

int	coord_len(int *coord)
{
	int	count;

	count = 0;
	while (coord[count] != '\0')
		count++;
	return (count);
}

void	fetch_coord(char *str, int *coord)
{
	int	i;
	int	j;

	i = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			coord[j] = str[i] - 48;
			j++;
		}
		i++;
	}
}

int	is_correct_nbrs(int *coord)
{
	int	i;

	i = 0;
	while (i < coord_len(coord))
	{
		if (coord[i] < 1 || coord[i] > 4)
			return 0;
		i++;
	}
	return 1;
			
}

int	is_coord_valid(int *coord)
{
	if (coord_len(coord) == 16 && is_correct_nbrs(coord))
		return (1);
	else
		return (0);
}

void	print_coord(int *coord)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		ft_putnbr(coord[i]);
		i++;
	}
	ft_putchar('\n');
}
