#include "corewar.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 0);
	exit(-1);
}