#include "corewar.h"

static int ft_validate_magic(unsigned char *magic)
{
	unsigned int n;
	
	n = 0;
	n = (unsigned char)magic[0] << 24 | (unsigned char)magic[1] << 16 |
	    (unsigned char)magic[2] << 8 | (unsigned char)magic[3];
	if (n != COREWAR_EXEC_MAGIC)
		return (0);
	return (1);
}

int ft_read_magic(int fd, t_player *player)
{
	read(fd, player->magic, 4);
	if (!ft_validate_magic(player->magic))
	{
		ft_free_player(&player);
		close(fd);
		ft_error("Not valid magic number\n");
	}
	return (1);
}
