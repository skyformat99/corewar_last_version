#include "corewar.h"

t_player	*ft_find_player(t_player *tmp, int i)
{
	while (tmp)
	{
		if (tmp->number == i)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void		ft_sortpath(t_player **lst)
{
	t_player	**arr;
	t_player	*tmp;
	int			i;

	arr = (t_player **)malloc(sizeof(t_player*) * (g_dt.count_players + 1));
	arr[g_dt.count_players] = NULL;
	i = -1;
	while (++i < g_dt.count_players)
	{
		arr[i] = ft_find_player(*lst, i + 1);
	}
	i = 0;
	*lst = arr[i];
	tmp = arr[i];
	while (i < g_dt.count_players)
	{
		tmp->next = arr[i++];
		tmp = tmp->next;
	}
	tmp->next = NULL;
	free(arr);
}

int			ft_cheack_number(t_player *tmp, int i)
{
	while (tmp)
	{
		if (tmp->number == i)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		ft_check_reiteration(void)
{
	t_player	*tmp;

	tmp = g_dt.player_g;
	while (tmp)
	{
		if (tmp->number > g_dt.count_players)
		{
			ft_putstr("Max -n == ");
			ft_putnbr(g_dt.count_players);
			ft_error("\n");
		}
		tmp = tmp->next;
	}
}

void		ft_sort_player(void)
{
	int			i;
	int			res;
	t_player	*tmp;

	i = 0;
	ft_check_reiteration();
	while (++i <= g_dt.count_players)
	{
		if (ft_cheack_number(g_dt.player_g, i))
		{
			tmp = g_dt.player_g;
			res = 1;
			while (res)
			{
				if (tmp->number == 0)
				{
					tmp->number = i;
					res = 0;
				}
				tmp = tmp->next;
			}
		}
	}
	ft_sortpath(&g_dt.player_g);
}
