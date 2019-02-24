#include "checkmate.h"

int	main(int ac, char **av)
{
	t_result	tab[10];
	int		kx = -1;
	int		ky = -1;
	int		i = -1;
	int		ennemy = 0;
	int		square = 0;
	int		j;

	if (ac > 1)
	{
		av++;
		if ((square = check_square(ac - 1, av)))
		{
			print_map(av);
			while (++i < ac - 1)
			{
				j = -1;
				while (++j < ac - 1)
				{
					if (av[i][j] == 'K')
					{
						kx = j;
						ky = i;
					}
					if (is_ennemy(av[i][j]))
						ennemy++;
				}
			}
			if (kx != -1 && ky != -1)
			{
				if (!ennemy)
					write(1, "Fail", 4);
				else
				{
					i = -1;
					while (++i < 9)
					{
						tab[i].res = 1;
						tab[i].prio = 0;
					}
					tab[9].res = 0;
					if (kx > 0)
					{
						if (ky > 0)
						{
							tab[0].res = check_mate(kx - 1, ky - 1, ac - 1, av);
							tab[0].prio = priority(av[ky - 1][kx - 1]);
						}
						tab[1].res = check_mate(kx - 1, ky, ac - 1, av);
						tab[1].prio = priority(av[ky][kx - 1]);
						if (ky < ac - 2)
						{
							tab[2].res = check_mate(kx - 1, ky + 1, ac - 1, av);
							tab[2].prio = priority(av[ky + 1][kx - 1]);
						}
					}
					if (ky < ac - 2)
					{
						tab[5].res = check_mate(kx, ky + 1, ac - 1, av);
						tab[5].prio = priority(av[ky + 1][kx]);
						if (kx < ac - 2)
						{
							tab[8].res = check_mate(kx + 1, ky + 1, ac - 1, av);
							tab[8].prio = priority(av[ky + 1][kx + 1]);
						}
					}
					if (ky > 0)
					{
						tab[3].res = check_mate(kx, ky - 1, ac - 1, av);
						tab[3].prio = priority(av[ky - 1][kx]);
					}
					tab[4].res = check_mate(kx, ky, ac - 1, av);
					if (kx < ac - 2)
					{
						if (ky > 0)
						{
							tab[6].res = check_mate(kx + 1, ky - 1, ac - 1, av);
							tab[6].prio = priority(av[ky - 1][kx + 1]);
						}
						tab[7].res = check_mate(kx + 1, ky, ac - 1, av);
						tab[7].prio = priority(av[ky][kx + 1]);
					}
					result(tab);
				}
			}
			else
				write(1, "King Not Found!!", 16);
		}
	}
	if (square == 0)
		write(1, "Board isn't square!", 19);
	write(1, "\n", 1);
	return (0);
}
