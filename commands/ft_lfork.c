/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 20:00:57 by opariy            #+#    #+#             */
/*   Updated: 2017/10/22 20:00:59 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_lfork(t_process *p)
{
	t_process *new_p;

	p->args[1] = (short)(g_dt.map[0][ft_increment_index(p)]
			<< 8) | g_dt.map[0][ft_increment_index(p)];
	ft_increment_index(p);
	p->args[1] = ft_get_value(p->mem_addres - 3 + p->args[1]);
	new_p = ft_create_car(p->args[1], p->regs[1], p);
	new_p->next = g_dt.process_g;
	g_dt.process_g = new_p;
	ft_bzero(p->args, 16);
}
