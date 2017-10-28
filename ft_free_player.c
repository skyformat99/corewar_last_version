#include "corewar.h"

void ft_free_player(t_player **player)
{
    t_player *p;
    
    p = *player;
    ft_strdel((char**)&p->prog_name);
    ft_strdel((char**)&p->comment);
    ft_strdel((char**)&p->instructions);
    free(p);
    *player = NULL;
}