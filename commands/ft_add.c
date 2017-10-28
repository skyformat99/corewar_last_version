/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:52:58 by opariy            #+#    #+#             */
/*   Updated: 2017/10/22 19:52:59 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		ft_add(t_process *process)
{
	if (g_dt.map[0][ft_get_value(process->mem_addres + 1)] == 84)
	{
		ft_take_args(process, 0, g_dt.map[0][process->mem_addres]);
		if (process->args[1] >= 0 && process->args[1] <= REG_NUMBER &&
				process->args[2] >= 0 && process->args[2] <= REG_NUMBER &&
				process->args[3] >= 0 && process->args[3] <= REG_NUMBER)
		{
			process->regs[process->args[3]] = process->regs[process->args[1]] +
					process->regs[process->args[2]];
			if (process->regs[process->args[3]] == 0)
				process->cary = 1;
			else
				process->cary = 0;
		}
	}
	else
	{
		// ft_increment_index(process);
		ft_take_args(process, 0, g_dt.map[0][process->mem_addres]);
	}
	ft_bzero(process->args, 16);
}
