#include "corewar.h"

int		ft_isadigit(char *str, char max_dump_or_ply)
{
	int				i;
	unsigned int	max;

	i = 0;
	if (max_dump_or_ply == 'd')
		max = 4294967294;
	else
		max = MAX_PLAYERS;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atoi(str) > 0 && ft_atoi(str) <= max)
		return (1);
	return (0);
}

int		check_dump(char *str_next, char *str)
{
	if (ft_strcmp(str, "-dump") == 0 && str_next && ft_isadigit(str_next, 'd'))
	{
		g_dt.dump = ft_atoi(str_next);
		return (1);
	}
	return (0);
}

void	player_add(t_player **head, t_player *new)
{
	new->next = *head;
	*head = new;
}
