/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:14:42 by opariy            #+#    #+#             */
/*   Updated: 2017/10/20 14:14:44 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void 	ft_aff(t_process *process)
{
	ft_increment_index(process);
	if (g_dt.map[0][process->mem_addres] == 64)
	{
		ft_increment_index(process);
		process->args[1] = g_dt.map[0][ft_increment_index(process)];
		if (process->args[1] >= 0 && process->args[1] <= REG_NUMBER && g_dt.visual != 1)
		{
			ft_putchar((char)(process->regs[process->args[1]] % 256));
		}
	}
	ft_bzero(process->args, 16);
}
