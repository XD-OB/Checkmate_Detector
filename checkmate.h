#ifndef CHECKMATE_H
# define CHECKMATE_H

# include <unistd.h>

typedef struct	s_result
{
	int	res;
	int	prio;
}		t_result;

int		check_mate(int x, int y, int size, char **map);
void		result(t_result *tab);
void		print_map(char **map);
int		priority(char c);
int		ft_strlen(char *str);
void		ft_putstr(char *str);
int		is_ennemy(char c);
int		check_square(int size, char **map);

#endif
