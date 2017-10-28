#include "corewar.h"

static 			t_process *ft_malloc_process(t_player *player)
{
	t_process *p;
	int i;
	
	i = 0;
	p = malloc(sizeof(t_process));
	while (i < REG_NUMBER)
		p->regs[i++] = 0;
	i = 0;
	while (i < 4)
		p->args[i++] = 0;
	p->regs[0] = player->number * -1;
	p->cary = 0;
	p->f = NULL;
	p->exec_cycle = 0;
	p->number = player->number;
	p->mem_addres = player->mem_addr;
	p->alive = 0;
	p->command = 0;
	p->codage_octal = 0;
	p->next = NULL;
	return (p);
}

static void		ft_add2head_process(t_process **head, t_process *add)
{
	t_process *h;
	
	h = *head;
	add->next = h;
	*head = add;
}

t_process		*ft_create_proceses(t_player *player)
{
	t_player *p;
	t_process *head;
	t_process *h;
	
	h = NULL;
	head = ft_malloc_process(player);
	player = player->next;
	p = player;
	while (p != NULL)
	{
		h = ft_malloc_process(p);
		ft_add2head_process(&head, h);
		p = p->next;
//		g_dt.count_processes++;
	}
	return (head);
}

