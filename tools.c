#include "checkmate.h"

int		priority(char c)
{
	if (c == 'P')
		return (1);
	if (c == 'H' || c == 'R' || c == 'B')
		return (2);
	if (c == 'Q')
		return (3);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	is_ennemy(char c)
{
	if (c == 'Q' || c == 'B' ||
			c == 'P' || c == 'R' || c == 'H')
		return (1);
	return (0);
}

int	check_square(int size, char **map)
{
	int	i = -1;

	while (++i < size)
		if (ft_strlen(map[i]) != size)
			return (0);
	return (1);
}
