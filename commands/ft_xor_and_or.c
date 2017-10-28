/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:18:56 by opariy            #+#    #+#             */
/*   Updated: 2017/10/20 17:18:57 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		ft_and_or_xor_5(t_process *p, char op, char c)
{
	if (c == -12 && p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		p->args[1] = ft_take_ind(p->mem_addres - 7 + p->args[1] % IDX_MOD);
		p->args[2] = ft_take_ind(p->mem_addres - 7 + p->args[2] % IDX_MOD);
		if (op == 6)
			(p->regs[p->args[3]] = p->args[1] & p->args[2]);
		if (op == 7)
			(p->regs[p->args[3]] = p->args[1] | p->args[2]);
		if (op == 8)
			(p->regs[p->args[3]] = p->args[1] ^ p->args[2]);
		p->cary = (p->regs[p->args[3]] == 0) ? 1 : 0;
	}
	else if (c == -28 && p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		p->args[1] = ft_take_ind(p->mem_addres - 9 + p->args[1] % IDX_MOD);
		if (op == 6)
			(p->regs[p->args[3]] = p->args[1] & p->args[2]);
		if (op == 7)
			(p->regs[p->args[3]] = p->args[1] | p->args[2]);
		if (op == 8)
			(p->regs[p->args[3]] = p->args[1] ^ p->args[2]);
		p->cary = (p->regs[p->args[3]] == 0) ? 1 : 0;
	}
}

void	ft_and_or_xor_1(t_process *p, char op)
{
	if (p->args[1] >= 0 && p->args[1] <= REG_NUMBER && p->args[2] >= 0 &&
		p->args[2] <= REG_NUMBER && p->args[3] && p->args[3] <= REG_NUMBER)
	{
		if (op == 6)
			p->regs[p->args[3]] = p->regs[p->args[1]] & p->regs[p->args[2]];
		if (op == 7)
			(p->regs[p->args[3]] = p->regs[p->args[1]] | p->regs[p->args[2]]);
		if (op == 8)
			(p->regs[p->args[3]] = p->regs[p->args[1]] ^ p->regs[p->args[2]]);
		if (p->regs[p->args[3]] == 0)
			p->cary = 1;
		else
			p->cary = 0;
	}
}

void	ft_and_or_xor_2(t_process *p, char op, char c)
{
	if (c == -108 && p->args[2] >= 0 && p->args[2] <= REG_NUMBER && p->args[3]
																  >= 0 && p->args[3] <= REG_NUMBER)
	{
		if (op == 6)
			(p->regs[p->args[3]] = p->args[1] & p->regs[p->args[2]]);
		if (op == 7)
			(p->regs[p->args[3]] = p->args[1] | p->regs[p->args[2]]);
		if (op == 8)
			(p->regs[p->args[3]] = p->args[1] ^ p->regs[p->args[2]]);
		p->cary = (p->regs[p->args[3]] == 0) ? 1 : 0;
	}
	else if (c == -44 && p->args[2] >= 0 && p->args[2] <=
											REG_NUMBER && p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		p->args[1] = ft_take_ind(p->mem_addres - 6 + p->args[1] % IDX_MOD);
		if (op == 6)
			(p->regs[p->args[3]] = p->args[1] & p->regs[p->args[2]]);
		if (op == 7)
			(p->regs[p->args[3]] = p->args[1] | p->regs[p->args[2]]);
		if (op == 8)
			(p->regs[p->args[3]] = p->args[1] ^ p->regs[p->args[2]]);
		p->cary = (p->regs[p->args[3]] == 0) ? 1 : 0;
	}
}

void	ft_and_or_xor_3(t_process *p, char op, char c)
{
	if (c == 116 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER && p->args[3] >= 0
		&& p->args[3] <= REG_NUMBER)
	{
		p->args[2] = ft_take_ind(p->mem_addres - 6 + p->args[2] % IDX_MOD);
		if (op == 6)
			(p->regs[p->args[3]] = p->regs[p->args[1]] & p->args[2]);
		if (op == 7)
			(p->regs[p->args[3]] = p->regs[p->args[1]] | p->args[2]);
		if (op == 8)
			(p->regs[p->args[3]] = p->regs[p->args[1]] ^ p->args[2]);
		p->cary = (p->regs[p->args[3]] == 0) ? 1 : 0;
	}
	else if (c == 100 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER && p->args[3]
																	  >= 0 && p->args[3] <= REG_NUMBER)
	{
		if (op == 6)
			(p->regs[p->args[3]] = p->regs[1] & p->args[2]);
		if (op == 7)
			(p->regs[p->args[3]] = p->regs[1] | p->args[2]);
		(op == 8) ? (p->regs[p->args[3]] = p->regs[1] ^ p->args[2]) : 0;
		p->cary = (p->regs[p->args[3]] == 0) ? 1 : 0;
	}
}

void	ft_and_or_xor_4(t_process *p, char op, char c)
{
	if (c == -76 && p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		p->args[2] = ft_take_ind(p->mem_addres - 9 + p->args[2] % IDX_MOD);
		if (op == 6)
			(p->regs[p->args[3]] = p->args[1] & p->args[2]);
		if (op == 7)
			(p->regs[p->args[3]] = p->args[1] | p->args[2]);
		if (op == 8)
			(p->regs[p->args[3]] = p->args[1] ^ p->args[2]);
		p->cary = (p->regs[p->args[3]] == 0) ? 1 : 0;
	}
	else if (c == -92 && p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		if (op == 6)
			(p->regs[p->args[3]] = p->args[1] & p->args[2]);
		if (op == 7)
			(p->regs[p->args[3]] = p->args[1] | p->args[2]);
		(op == 8) ? (p->regs[p->args[3]] = p->args[1] ^ p->args[2]) : 0;
		if (p->regs[p->args[3]] == 0)
			p->cary = 1;
		else
			p->cary = 0;
	}
}

void	ft_xor_and_or(t_process *process)
{
	char operation;
	char op_code;


	operation = g_dt.map[0][process->mem_addres];
	op_code = g_dt.map[0][ft_get_value(process->mem_addres + 1)];
	if (op_code == 84 || op_code == -108 || op_code == -44 || op_code == 116 ||
		op_code == 100 || op_code == -76 || op_code == -92 || op_code == -12 ||
		op_code == -28)
		ft_take_args(process, 0, g_dt.map[0][process->mem_addres]);
	if (op_code == 84)
		ft_and_or_xor_1(process, operation);
	else if (op_code == -108 || op_code == -44)
		ft_and_or_xor_2(process, operation, op_code);
	else if (op_code == 116 || op_code == 100)
		ft_and_or_xor_3(process, operation, op_code);
	else if (op_code == -76 || op_code == -92)
		ft_and_or_xor_4(process, operation, op_code);
	else if (op_code == -12 || op_code == -28)
		ft_and_or_xor_5(process, operation, op_code);
	else
		ft_increment_index(process);
	ft_bzero(process->args, 16);
}