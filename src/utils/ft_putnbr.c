void	ft_putchar(char c);

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar(45);
		ft_putchar(50);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar(45);
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar(n + 48);
		return;
	}
	ft_putnbr(n / 10);
	ft_putnbr(n % 10);
}
