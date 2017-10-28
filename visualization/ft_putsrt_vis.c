/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_vis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:33:01 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/19 18:33:03 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../corewar.h"

void    upd_term()
{
	int i;
	
	i = 0;
	while (g_vh.term_i > 17*40)
		mvwprintw(g_vh.term, g_vh.term_i, 1, "%s",  " ");
	wrefresh(g_vh.term);
	g_vh.term_i = 0;
	usleep(5);
}

void   ft_putstr_vis(char *str)
{
	wattron(g_vh.term, COLOR_PAIR(P4));
	mvwprintw(g_vh.term, g_vh.term_i, 1, "%s",  str);
	wattroff(g_vh.term, COLOR_PAIR(P4));
	wattron(g_vh.term, COLOR_PAIR(BORDER));
	wborder(g_vh.term, '.', '.', '.', '.', '.', '.', '.', '.');
	wattroff(g_vh.term, COLOR_PAIR(BORDER));
	if (g_vh.term_i > 17)
		upd_term();
	g_vh.term_i++;
	wrefresh(g_vh.term);
}


void   ft_putstr_vis_int(int str)
{
	char *term;
	term = ft_strnew(1);
	wattron(g_vh.term, COLOR_PAIR(P4));
	mvwprintw(g_vh.term, g_vh.term_i, 1, "%d",  str);
	wattroff(g_vh.term, COLOR_PAIR(P4));
	wattron(g_vh.term, COLOR_PAIR(BORDER));
	wborder(g_vh.term, '.', '.', '.', '.', '.', '.', '.', '.');
	wattroff(g_vh.term, COLOR_PAIR(BORDER));
	wrefresh(g_vh.term);
	if (g_vh.term_i > 17)
		upd_term();
	g_vh.term_i++;
	g_vh.term_i++;
}