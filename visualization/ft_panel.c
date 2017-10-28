/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:51:08 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/20 15:51:09 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_print_c_processes(void)
{
	int x;

	x = g_vh.inf_x / 20;
	wattron(g_vh.info, COLOR_PAIR(INFO_STAND));
	mvwprintw(g_vh.info, g_vh.inf_o += 2, x, "%s", "Cycle:");
	mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%s", "           ");
	mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%d", g_dt.cycle);
	mvwprintw(g_vh.info, g_vh.inf_o += 2, x, "%s", "Processes:");
	mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%s", "           ");
	mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%d", g_dt.count_processes);
	wattroff(g_vh.info, COLOR_PAIR(INFO_STAND));
	wrefresh(g_vh.info);
	g_vh.inf_o++;
}

void    ft_print_player()
{
	
	t_player *p;
	int x;
	int i = 0;
	
	x = g_vh.inf_x / 20;
	p = g_dt.player_g;
	while (p)
	{
		wattron(g_vh.info, COLOR_PAIR(p->number));
		mvwprintw(g_vh.info, g_vh.inf_o += 2, x, "%s", p->prog_name);
		wattroff(g_vh.info, COLOR_PAIR(p->number));
		mvwprintw(g_vh.info, g_vh.inf_o, x + 20, "%s", "           ");
		mvwprintw(g_vh.info, g_vh.inf_o, x + 20, "%d", p->n_live);
		p = p->next;
	}
}

void	ft_print_cycle_2die(void)
{
	int x;

	x = g_vh.inf_x / 20;
	wattron(g_vh.info, COLOR_PAIR(INFO_STAND));
	mvwprintw(g_vh.info, g_vh.inf_o += 2, x, "%s", "CYCLE_TO_DIE:");
	mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%s", "           ");
	mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%d", g_dt.cycle2die);
	mvwprintw(g_vh.info, g_vh.inf_o += 2, x, "%s", "CYCLE_DELTA:");
	mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%s", "           ");
	mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%d", CYCLE_DELTA);
	mvwprintw(g_vh.info, g_vh.inf_o += 2, x, "%s", "NBR_LIVE:");
	mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%s", "           ");
	mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%d", g_dt.nbr_live);
	mvwprintw(g_vh.info, g_vh.inf_o += 2, x, "%s", "MAX_CHECKS:");
	mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%s", "           ");
	mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%d", g_dt.max_checks);
	wattroff(g_vh.info, COLOR_PAIR(INFO_STAND));
	wrefresh(g_vh.info);
}
