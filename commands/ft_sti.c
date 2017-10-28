/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:15:35 by opariy            #+#    #+#             */
/*   Updated: 2017/10/19 16:15:36 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		ft_get_value(int ind)
{
	int result;

	if (ind < 0)
	{
		while (ind < 0)
			ind += MEM_SIZE;
		result = ind;
	}
	else if (ind >= MEM_SIZE)
		result = ind % MEM_SIZE;
	else
		result = ind;
	return (result);
}

void	ft_write_bold(int num, int start, int end)
{
	int 	i;

	i = -1;
	while (++i < end)
		g_dt.map[2][ft_get_value(start + i)] = (unsigned char)(-num);
}

void 			ft_write_col(int num, int address)
{
	g_dt.map[1][ft_get_value(address)] = (unsigned char)(num + 64);
	g_dt.map[1][ft_get_value(address + 1)] = (unsigned char)(num + 64);
	g_dt.map[1][ft_get_value(address + 2)] = (unsigned char)(num + 64);
	g_dt.map[1][ft_get_value(address + 3)] = (unsigned char)(num + 64);
}

int 	ft_increment_index(t_process *process)
{
	process->mem_addres = (ft_get_value(process->mem_addres + 1)) % MEM_SIZE;
	return (process->mem_addres);
}

int		ft_take_args_2(t_process *process, int a)
{
	int res;

	if (a == 2)
		res = (short)(g_dt.map[0][ft_increment_index(process)] << 8) |
			  g_dt.map[0][ft_increment_index(process)];
	else
		res = ((g_dt.map[0][ft_increment_index(process)] << 24) |
			  (g_dt.map[0][ft_increment_index(process)] << 16) |
			  (g_dt.map[0][ft_increment_index(process)] << 8) |
			  (g_dt.map[0][ft_increment_index(process)]));
	return (res);
}

void	ft_take_args(t_process *process, int i, int command)
{
	process->mem_addres = ft_increment_index(process);
	process->args[0] = command;
	process->args[1] = g_dt.map[0][process->mem_addres] >> 6;
	process->args[2] = (g_dt.map[0][process->mem_addres]) << 2;
	process->args[2] = ((unsigned char)process->args[2]) >> 6;
	process->args[3] = g_dt.map[0][process->mem_addres] << 4;
	process->args[3] = ((unsigned char)process->args[3]) >> 6;
	i = 1;
//	printf("here\n");

//	 printf("args : %d, %d, %d, %d\n", process->args[0], process->args[1], process->args[2], process->args[3]);
	while (i < g_tab[command - 1].count_arg + 1)
	{
		if (process->args[i] == REG_CODE) {
//			printf("here reg\n");
			process->args[i] = g_dt.map[0][ft_increment_index(process)] - 1;
		}
		else if (process->args[i] == DIR_CODE)
		{
			if (command == 2 || command == 6 || command == 7 || command == 8 || command == 13){
//				printf("here dir\n");
				process->args[i] = ft_take_args_2(process, 4);
			}
			else
				{
//					printf("here dir2\n");
					process->args[i] = ft_take_args_2(process, 2);}
		}
		else if (process->args[i] == IND_CODE) {
//			printf("here ind\n");
			process->args[i] = ft_take_args_2(process, 2);
		}
		i++;
	}
//	printf("args : %d, %d, %d, %d\n", process->args[0], process->args[1], process->args[2], process->args[3]);

	ft_increment_index(process);
}

int		ft_get_ind(int value)
{
	int result;

	result = (g_dt.map[0][ft_get_value(value)] << 24) |
		  (g_dt.map[0][ft_get_value(value + 1)] << 16) |
		  (g_dt.map[0][ft_get_value(value + 2)] << 8) |
		  g_dt.map[0][ft_get_value(value + 3)];
	return (result);
}

void	ft_sti_load(t_process *p, char op_code, int i)
{
	g_dt.map[0][ft_get_value(i)] = p->regs[p->args[1]] >> 24;
	g_dt.map[0][ft_get_value(i + 1)] = p->regs[p->args[1]] >> 16;
	g_dt.map[0][ft_get_value(i + 2)] = p->regs[p->args[1]] >> 8;
	g_dt.map[0][ft_get_value(i + 3)] = p->regs[p->args[1]];
	ft_write_col(p->number, i);
	ft_write_bold(-50, i, 4);
}

static void		ft_sti_03(t_process *p, char op_code, int i)
{
	if (op_code == 120 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER)
	{
		p->args[2] = ft_get_ind(i + p->args[2] % IDX_MOD);
		i += (int)(p->args[2] + p->args[3]) % IDX_MOD;
		ft_sti_load(p, op_code, i);
	}
	else if (op_code == 116 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER &&
			 p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		p->args[2] = ft_get_ind(i + p->args[2] % IDX_MOD);
		i += (int)(p->args[2] + p->regs[p->args[3]]) % IDX_MOD;
		ft_sti_load(p, op_code, i);
	}
}

static void		ft_sti_02(t_process *p, char op_code, int i)
{
	if (op_code == 104 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER) //SUCCUSES
	{
		i += (int)(p->args[2] + p->args[3]) % IDX_MOD;
		ft_sti_load(p, op_code, i);
	}
	else if (op_code == 100 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER &&
			 p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		i += (int)(p->args[2] + p->regs[p->args[3]]) % IDX_MOD;
		ft_sti_load(p, op_code, i);
	}
}

void		ft_sti_01(t_process *p, char op_code, int i)
{
	if (op_code == 88 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER &&
		p->args[2] >= 0 && p->args[2] <= REG_NUMBER)
	{
		i += (int)(p->regs[p->args[2]] + p->args[3]) % IDX_MOD;
		ft_sti_load(p, op_code, i);
	}
	else if (op_code == 84 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER &&
			 p->args[2] >= 0 && p->args[2] <= REG_NUMBER && p->args[3] >= 0 &&
			 p->args[3] <= REG_NUMBER)
	{
		i += (int)(p->regs[p->args[2]] + p->regs[p->args[3]]) % IDX_MOD;
		ft_sti_load(p, op_code, i);
	}
}

void		ft_sti(t_process *process)
{
	char 	codage_octal;
	int 	i;

	i = process->mem_addres;
	codage_octal = g_dt.map[0][ft_get_value(process->mem_addres + 1)];
	// printf("codage_octal %d\n", codage_octal);
	if (codage_octal == 88 || codage_octal == 84 || codage_octal == 104 || codage_octal == 100 ||
		codage_octal == 120 || codage_octal == 116)
		ft_take_args(process, 1, g_dt.map[0][i]);
	// printf("args : %d, %d, %d, %d\n", process->args[0], process->args[1], process->args[2], process->args[3]);
	if (codage_octal == 88 || codage_octal == 84)
		ft_sti_01(process, codage_octal, i);
	else if (codage_octal == 104 || codage_octal == 100) ////
		ft_sti_02(process, codage_octal, i);
	else if (codage_octal == 120 || codage_octal == 116)
		ft_sti_03(process, codage_octal, i);
	else
	{
		printf("here\n");
		ft_take_args(process, 0, g_dt.map[0][process->mem_addres]);
		// process->mem_addres = ft_increment_index(process);
	}
	ft_bzero(process->args, 16);
}