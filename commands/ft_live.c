/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:23:03 by ymushet           #+#    #+#             */
/*   Updated: 2017/10/25 12:26:47 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static int		ft_get_nbr(t_process *p)
{
	int j;
	unsigned char str[4];

	ft_bzero(str, 4);
	str[0] = g_dt.map[0][ft_increment_index(p)];
	str[1] = g_dt.map[0][ft_increment_index(p)];
	str[2] = g_dt.map[0][ft_increment_index(p)];
	str[3] = g_dt.map[0][ft_increment_index(p)];
	j = ft_create_int(str);
	return (j);
}

static t_player	*ft_is_live_arg_valid(t_process *process)
{
	t_player *player;
	int nbr;

	player = g_dt.player_g;
	nbr = ft_get_nbr(process);
	nbr = nbr * -1;
	while (player)
	{
		if (player->number == nbr)
			return(player);
		player = player->next;
	}
	return (NULL);
}

void			ft_live(t_process *process)
{
	t_player *player;

	if((player = ft_is_live_arg_valid(process)) != NULL)
	{
		g_dt.last_live = player;
		player->n_live++;
	}
	process->alive = 1;
	g_dt.nbr_live++;
	ft_increment_index(process);
}
