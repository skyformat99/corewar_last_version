/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:43:14 by opariy            #+#    #+#             */
/*   Updated: 2017/10/18 18:43:15 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		find_players_num(t_player *p, int num)
{
	while (p)
	{
		if (p->number == num)
			return (0);
		p = p->next;
	}
	return (1);
}

void	parse_playr(int fd, t_player **h, int num, t_player *p)
{
	p = ft_read_from_core(fd, num);
	player_add(h, p);
	g_dt.count_players++;
}

int		get_fd(char *file_name)
{
	int		length;
	int		fd;

	fd = 0;
	length = ft_strlen(file_name);
	if (length <= 4 || ft_strcmp((file_name + length - 4), ".cor"))
		ft_error("only .cor files are accepted\n");
	fd = open(file_name, O_RDONLY);
	if (fd <= 2)
		ft_error("Invalid flag\n");
	return (fd);
}

int		basic_check(char *str)
{
	if (ft_strcmp(str, "-v") == 0)
	{
		g_dt.visual = 1;
		return (1);
	}
	else if (ft_strcmp(str, "-a") == 0)
	{
		g_dt.aff = 1;
		return (1);
	}
	return (0);
}

void	ft_parse_args(int fd, char **argv, int i, t_player *head)
{
	while (argv[i])
	{
		if (!basic_check(argv[i]))
		{
			if (argv[i + 1] && check_dump(argv[i + 1], argv[i]))
				i++;
			else if (ft_strcmp(argv[i], "-n") == 0)
			{
				if (argv[i + 1] && argv[i + 2] && ft_isadigit(argv[i + 1], 'p'))
				{
					fd = get_fd(argv[i + 2]);
					if (!find_players_num(head, ft_atoi(argv[i + 1])))
						ft_error("Invalid flag\n");
					parse_playr(fd, &head, ft_atoi(argv[i + 1]), g_dt.player_g);
					i += 2;
				}
				else
					ft_error("Invalid flag\n");
			}
			else
				parse_playr(get_fd(argv[i]), &head, 0, g_dt.player_g);
		}
		i++;
	}
	g_dt.player_g = head;
	//the lines below are just for prinitng the values
//	t_player *pl;
//	pl = g_dt.player_g;
//	while (pl)
//	{
//		printf("!!!\n");
//		printf("name %s\n", pl->prog_name);
//		printf("num %d\n", pl->number);
//		pl = pl->next;
//
//	}
//	printf("# of players %d\n", g_dt.count_players);
//	printf("dump : %d\n", g_dt.dump);
}

