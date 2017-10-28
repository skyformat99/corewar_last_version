#include "../corewar.h"

void	ft_st01(t_process *process)
{
	ft_take_args(process, 0, g_dt.map[0][process->mem_addres + 1]);
	if (process->args[1] >= 0 && process->args[1] <= REG_NUMBER)
	{
		process->args[2] = process->mem_addres - 5 + (process->args[2] % IDX_MOD);
		g_dt.map[0][ft_get_value(process->args[2])] = (unsigned char)(process->regs[process->args[1]] >> 24);
		g_dt.map[0][ft_get_value(process->args[2] + 1)] = (unsigned char)(process->regs[process->args[1]] >> 16);
		g_dt.map[0][ft_get_value(process->args[2] + 2)] = (unsigned char)(process->regs[process->args[1]] >> 8);
		g_dt.map[0][ft_get_value(process->args[2] + 3)] = (unsigned char)(process->regs[process->args[1]]);
		ft_write_col(process->number, process->args[2]);
		ft_write_bold(-50, process->args[2], 4);
	}
}

void	ft_st(t_process *process)
{
	if (g_dt.map[0][process->mem_addres + 1] == 122)
		ft_st01(process);
	else if (g_dt.map[0][process->mem_addres + 1] == 80)
	{
		ft_take_args(process, 0, g_dt.map[0][process->mem_addres + 1]);
		if (process->args[1] >= 0 && process->args[1] <= REG_NUMBER &&
				process->args[1] >= 0 && process->args[1] <= REG_NUMBER)
			process->regs[process->args[2]] = process->regs[process->args[1]];
	}
	else
		ft_increment_index(process);
	ft_bzero(process->args, 16);
}