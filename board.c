#include "checkmate.h"

void		print_map(char **map)
{
	while (*map)
	{
		ft_putstr("\t");
		ft_putstr(*map);
		ft_putstr("\n");
		map++;
	}
}

static void	priont(int n)
{
	if (n == 0)
		write(1, "     ", 5);
	if (n == 1)
		write(1, "!    ", 5);
	if (n == 2)
		write(1, "!!   ", 5);
	if (n == 3)
		write(1, "!!!  ", 5);
}

void		result(t_result *tab)
{
	int	i = -1;
	while (++i < 9)
		tab[9].res += tab[i].res;
	if (tab[9].res == 9)
		write(1, "Checkmate!\nGAME OVER", 20);
	else if (tab[4].res == 1)
	{
		write(1, "Check!\n\nPossible Moves:\n", 24);
		if (!tab[0].res)
		{
			priont(tab[0].prio);
			write(1, "<- ^\n", 5);
		}
		if (!tab[1].res)
		{
			priont(tab[1].prio);
			write(1, "<-\n", 3);
		}
		if (!tab[2].res)
		{
			priont(tab[2].prio);
			write(1, "<- v\n", 5);
		}
		if (!tab[3].res)
		{
			priont(tab[3].prio);
			write(1, "^\n", 2);
		}
		if (!tab[5].res)
		{
			priont(tab[5].prio);
			write(1, "v\n", 2);
		}
		if (!tab[6].res)
		{
			priont(tab[6].prio);
			write(1, "-> ^\n", 5);
		}
		if (!tab[7].res)
		{
			priont(tab[7].prio);
			write(1, "->\n", 3);
		}
		if (!tab[8].res)
		{
			priont(tab[8].prio);
			write(1, "-> v\n", 5);
		}
	}
	else
		write(1, "King is Safe", 12);
}
