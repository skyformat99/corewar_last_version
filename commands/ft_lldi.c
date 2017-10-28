/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:57:26 by opariy            #+#    #+#             */
/*   Updated: 2017/10/22 19:57:27 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static inline void	ft_get_data(t_process *p, int index, char commmand)
{
	p->regs[p->args[3]] = (g_dt.map[0][ft_get_value(index)] << 24)
						  | (g_dt.map[0][ft_get_value(index + 1)] << 16) |
						  (g_dt.map[0][ft_get_value(index + 2)] << 8) |
						  g_dt.map[0][ft_get_value(index + 3)];
	if (commmand == 14)
	{
		if (p->regs[p->args[3]] == 0)
			p->cary = 1;
		else
			p->cary = 0;
	}
}

static inline void	ft_ldi_lldi_1(t_process *p, char op, char commmand)
{
	int index;

	if (op == 100 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER &&
		p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		index = p->mem_addres - 6;
		if (commmand == 10)
			index += (p->regs[p->args[1]] + p->args[2])	% IDX_MOD;
		else
			index += p->regs[p->args[1]] + p->args[2];
		ft_get_data(p, index, commmand);
	}
	else if (op == 84 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER &&
			 p->args[3] >= 0 && p->args[3] <= REG_NUMBER && p->args[2] >= 0 &&
			 p->args[2] <= REG_NUMBER)
	{
		index = p->mem_addres - 5;
		if (commmand == 10)
			index += (p->regs[p->args[1]] + p->regs[p->args[2]]) % IDX_MOD;
		else
			index += p->regs[p->args[1]] + p->regs[p->args[2]];
		ft_get_data(p, index, commmand);
	}
}

static inline void	ft_ldi_lldi_2(t_process *p, char op, char commmand)
{
	int index;

	if (op == -92 && p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		index = p->mem_addres - 7;
		index += (commmand == 10) ? ((p->args[1] + p->args[2]) % IDX_MOD) :
				 (p->args[1] + p->args[2]);
		ft_get_data(p, index, commmand);
	}
	else if (op == -108 && p->args[2] >= 0 && p->args[2] <= REG_NUMBER &&
			 p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		index = p->mem_addres - 6;
		if (commmand == 10)
			index += (p->args[1] + p->regs[p->args[2]]) %
					 IDX_MOD;
		else
			index += p->args[1] + p->regs[p->args[2]];
		ft_get_data(p, index, commmand);
	}
}

static inline void	ft_ldi_lldi_3(t_process *p, char op, char commmand)
{
	int index;

	if (op == -44 && p->args[2] >= 0 && p->args[2] <= REG_NUMBER &&
		p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		index = p->mem_addres - 6;
		p->args[1] = (commmand == 10) ? (p->args[1] % IDX_MOD) : (p->args[1]);
		p->args[1] += index;
		p->args[1] = ft_take_ind(p->args[1]);
		index += (commmand == 10) ? ((p->args[1] + p->regs[p->args[2]]) %
									 IDX_MOD) : (p->args[1] + p->regs[p->args[2]]);
		ft_get_data(p, index, commmand);
	}
	else if (op == -28 && p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		index = p->mem_addres - 7;
		p->args[1] = (commmand == 10) ? (p->args[1] % IDX_MOD) : (p->args[1]);
		p->args[1] += index;
		p->args[1] = ft_take_ind(p->args[1]);
		if (commmand == 10)
			index += (p->args[1] + p->args[2]) % IDX_MOD;
		else
			index += p->args[1] + p->args[2];
		ft_get_data(p, index, commmand);
	}
}

void		ft_lldi(t_process *p)
{
	char	commmand;
	char	position;

	commmand = g_dt.map[0][p->mem_addres];
	position = g_dt.map[0][ft_get_value(p->mem_addres + 1)];
	if (position == 100 || position == 84 || position == -92 ||
		position == -108 || position == -44 || position == -28)
		ft_take_args(p, 0, commmand);
	if (position == 100 || position == 84)
		ft_ldi_lldi_1(p, position, commmand);
	else if (position == -92 || position == -108)
		ft_ldi_lldi_2(p, position, commmand);
	else if (position == -44 || position == -28)
		ft_ldi_lldi_3(p, position, commmand);
	else
	{
		// ft_increment_index(p);
		ft_take_args(p, 0, g_dt.map[0][p->mem_addres]);

	}
	ft_bzero(p->args, 16);
}
