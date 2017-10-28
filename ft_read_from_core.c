#include "corewar.h"

static t_player *ft_malloc_player(unsigned int n)
{
	t_player *player;
	size_t len;
	
	player = malloc(sizeof(t_player));
	ft_bzero(player->magic, 4);
	ft_bzero(player->prog_size, 4);
	len = PROG_NAME_LENGTH + 1;
	while ((len % 4) != 0)
		len++;
	player->prog_name = (unsigned char*)ft_strnew(len);
	len = COMMENT_LENGTH + 1;
	while ((len % 4) != 0)
		len++;
	player->comment = (unsigned char*)ft_strnew(len);
	player->number = n;
	player->n_live = 0;
	player->instructions = NULL;
	player->next = NULL;
	return (player);
}

static int ft_core_file_validation(int fd, t_player **player)
{
	if (ft_read_magic(fd, *player))
		if (ft_read_program_name(fd, *player))
			if (ft_read_program_size(fd, *player))
				if (ft_read_comment(fd, *player))
					if (ft_read_instructions(fd, *player))
						return (1);
	return (0);
}

t_player *ft_read_from_core(int fd, unsigned int n)
{
	t_player	*player;
	
	player = ft_malloc_player(n);
	if (!ft_core_file_validation(fd, &player))
	{
		ft_free_player(&player);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (player);
}