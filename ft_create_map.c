#include "corewar.h"

static void			ft_copy_com(unsigned char **map, t_player *player, int i)
{
	int    j;

	j = 0;
	while (j < player->player_size)
	{
		map[0][i + j] = player->instructions[j];
		map[1][i + j] = player->number + 64;
		//map[2] init must be here
		j++;
	}
	// int l = 0;
	// printf("COPY\n");
	// while (l < player->player_size)
	// {
	// 	printf("%.2X ", map[0][l]);
	// 	l++;
	// }
	// printf("\n");
}

unsigned char		**ft_create_map(t_player *player, int n)
{
	int i;
	int mod;
	unsigned char **map;
	t_player *p;

	i = 0;
	p = player;
	map = malloc(sizeof(char*) * 4);
	mod = MEM_SIZE / g_dt.count_players;
	map[3] = NULL;
	mod = MEM_SIZE / g_dt.count_players;
	map[0] = (unsigned char*)ft_strnew(MEM_SIZE);
	map[1] = (unsigned char*)ft_strnew(MEM_SIZE);
	map[2] = (unsigned char*)ft_strnew(MEM_SIZE);
	ft_memset(map[2], 0, MEM_SIZE);
	ft_memset(map[1], 48, MEM_SIZE);
	while (p != NULL)
	{
		ft_copy_com(map, p, i * mod);
		p->mem_addr = i * mod;
		p = p->next;
		i++;
	}
	return (map);
}
