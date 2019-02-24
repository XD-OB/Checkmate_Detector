#include "checkmate.h"

static int	check_mate_p(int x, int y, int size, char **map)
{
	if (y == size - 1)
		return (0);
	if (x != size - 1)
	{
		if (map[y + 1][x + 1] == 'P')
			return (1);
	}
	if (x != 0)
	{
		if (map[y + 1][x - 1] == 'P')
			return (1);
	}
	return (0);
}

static int	check_mate_rq(int x, int y, int size, char **map)
{
	int		i;

	i = x;
	while (++i < size && map[y][i] != 'P' && map[y][i] != 'B' && map[y][i] != 'H')
		if (map[y][i] == 'R' || map[y][i] == 'Q')
			return (1);
	i = x;
	while (--i >= 0 && map[y][i] != 'P' && map[y][i] != 'B' && map[y][i] != 'H')
		if (map[y][i] == 'R' || map[y][i] == 'Q')
			return (1);
	i = y;
	while (++i < size && map[i][x] != 'P' && map[i][x] != 'B' && map[i][x] != 'H')
		if (map[i][x] == 'R' || map[i][x] == 'Q')
			return (1);
	i = y;
	while (--i >= 0 && map[i][x] != 'P' && map[i][x] != 'B' && map[i][x] != 'H')
		if (map[i][x] == 'R' || map[i][x] == 'Q')
			return (1);
	return (0);
}

static int	check_mate_bq(int x, int y, int size, char **map)
{
	int		i = y;
	int		j = x;

	while (++i < size && ++j < size &&
			map[i][j] != 'P' && map[i][j] != 'R' && map[i][j] != 'H')
		if (map[i][j] == 'B' || map[i][j] == 'Q')
			return (1);
	i = y;
	j = x;
	while (++i < size && --j >= 0 &&
			map[i][j] != 'P' && map[i][j] != 'R' && map[i][j] != 'H')
		if (map[i][j] == 'B' || map[i][j] == 'Q')
			return (1);
	i = y;
	j = x;
	while (--i >= 0 && ++j < size &&
			map[i][j] != 'P' && map[i][j] != 'R' && map[i][j] != 'H')
		if (map[i][j] == 'B' || map[i][j] == 'Q')
			return (1);
	i = y;
	j = x;
	while (--i >= 0 && --j >= 0 &&
			map[i][j] != 'P' && map[i][j] != 'R' && map[i][j] != 'H')
		if (map[i][j] == 'B' || map[i][j] == 'Q')
			return (1);
	return (0);
}

static int	check_mate_h(int x, int y, int size, char **map)
{
	if (x > 1)
	{
		if (y < size - 1)
			if (map[y + 1][x - 2] == 'H')
				return (1);
		if (y > 0)
			if (map[y - 1][x - 2] == 'H')
				return (1);
	}
	if (x < size - 2)
	{
		if (y > 0)
			if (map[y - 1][x + 2] == 'H')
				return (1);
		if (y < size - 1)
			if (map[y + 1][x + 2] == 'H')
				return (1);
	}
	if (x < size - 1)
	{
		if (y > 1)
			if (map[y - 2][x + 1] == 'H')
				return (1);
		if (y < size - 2)
			if (map[y + 2][x + 1] == 'H')
				return (1);
	}
	if (x > 0)
	{
		if (y > 1)
			if (map[y - 2][x - 1] == 'H')
				return (1);
		if (y < size - 2)
			if (map[y + 2][x - 1] == 'H')
				return (1);
	}
	return (0);
}

int		check_mate(int x, int y, int size, char **map)
{
	return (check_mate_p(x, y, size, map)
			|| check_mate_h(x, y, size, map)
			|| check_mate_rq(x, y, size, map)
			|| check_mate_bq(x, y, size, map));
}
