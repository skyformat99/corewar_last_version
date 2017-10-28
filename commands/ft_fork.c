/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 20:00:51 by opariy            #+#    #+#             */
/*   Updated: 2017/10/22 20:00:53 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

t_process	*ft_create_car(unsigned int pos, unsigned int num, t_process *p)
{
	t_process	*new_p;

	new_p = (t_process *)malloc(sizeof(t_process));
	new_p->mem_addres = pos;
	new_p->number = p->number;
	new_p->f = NULL;
	new_p->exec_cycle = -1;
	new_p->alive = p->alive;
	new_p->command = 0;
	new_p->codage_octal = 0;
	g_dt.count_processes++;
	ft_bzero(new_p->regs, 4 * REG_NUMBER);
	if (p)
	{
		ft_memcpy(new_p->regs, p->regs, 4 * REG_NUMBER);
		new_p->cary = p->cary;
		new_p->number = p->number;
	}
	else
	{
		new_p->regs[1] = num;
		new_p->number = (char)num;
		new_p->cary = 0;
	}
	return (new_p);
}

void		ft_fork(t_process *p)
{
	t_process *new_p;

	p->args[1] = (short)(g_dt.map[0][ft_increment_index(p)]
			<< 8) | g_dt.map[0][ft_increment_index(p)];
	ft_increment_index(p);
	p->args[1] = ft_get_value((p->mem_addres - 3) + (p->args[1] % IDX_MOD));
	new_p = ft_create_car(p->args[1], p->number, p);
	new_p->next = g_dt.process_g;
	g_dt.process_g = new_p;
	ft_bzero(p->args, 16);
}
