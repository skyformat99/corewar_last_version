/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:59:32 by opariy            #+#    #+#             */
/*   Updated: 2017/10/20 15:59:34 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_zjmp(t_process *process)
{
	if (process->cary == 1)
	{
		process->args[1] = (short)(g_dt.map[0][ft_increment_index(process)]
				<< 8) | g_dt.map[0][ft_increment_index(process)];
		ft_increment_index(process);
		process->mem_addres = ft_get_value(process->mem_addres - 3 + process->args[1] % IDX_MOD);
		ft_bzero(process->args, 16);
	}
	else
	{
		ft_increment_index(process);
		process->mem_addres = ft_get_value(process->mem_addres + 2);
	}

}

