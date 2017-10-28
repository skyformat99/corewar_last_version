/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 13:25:38 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/19 13:25:40 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../corewar.h"

void    ft_print_mw(char *str, int x)
{
	mvwprintw(g_vh.info, g_vh.inf_p, x, "%s", str);
	g_vh.inf_p++;
	wrefresh(g_vh.info);
}

void    ft_print_pause(void)
{
	int x;
	
	x = g_vh.inf_x / 2 - 24;
	wattron(g_vh.info, COLOR_PAIR(COLOR_GREEN));
	ft_print_mw("_|_|_|      _|_|    _|    _|    _|_|_|  _|_|_|_|", x);
	ft_print_mw("_|    _|  _|    _|  _|    _|  _|        _|      ", x);
	ft_print_mw("_|_|_|    _|_|_|_|  _|    _|    _|_|    _|_|_|  ", x);
	ft_print_mw("_|        _|    _|  _|    _|        _|  _|      ", x);
	ft_print_mw("_|        _|    _|    _|_|    _|_|_|    _|_|_|_|", x);
	ft_print_mw("                                                ", x);
	ft_print_mw("                                                ", x);
	wattroff(g_vh.info, COLOR_PAIR(COLOR_GREEN));
}

void    ft_print_start(void)
{
	int x;
	
	x = g_vh.inf_x / 2 - 24;
	wattron(g_vh.info, COLOR_PAIR(COLOR_GREEN));
	ft_print_mw("         _|_|_|    _|    _|  _|      _|         ", x);
	ft_print_mw("         _|    _|  _|    _|  _|_|    _|         ", x);
	ft_print_mw("         _|_|_|    _|    _|  _|  _|  _|         ", x);
	ft_print_mw("         _|    _|  _|    _|  _|    _|_|         ", x);
	ft_print_mw("         _|    _|    _|_|    _|      _|         ", x);
	ft_print_mw("                                                ", x);
	ft_print_mw("                                                ", x);
	wattroff(g_vh.info, COLOR_PAIR(COLOR_GREEN));
}

void    ft_print_speed(int c)
{
	int x;
	
	x = g_vh.inf_x / 20;
	if (c > 20000)
	{
		c = c / 20000;
		wattron(g_vh.info, COLOR_PAIR(INFO_STAND));
		mvwprintw(g_vh.info, g_vh.inf_o, x, "%s", "cycles per second:");
		mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%s", "         ");
		mvwprintw(g_vh.info, g_vh.inf_o, x + 24, "%s", "x");
		mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%i", c == 1 ? c : -c);
		wattroff(g_vh.info, COLOR_PAIR(INFO_STAND));
	}
	else
	{
		c = 20000 / c;
		wattron(g_vh.info, COLOR_PAIR(INFO_STAND));
		mvwprintw(g_vh.info, g_vh.inf_o, x, "%s", "cycles per second:");
		mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%s", "         ");
		mvwprintw(g_vh.info, g_vh.inf_o, x + 24, "%s", "x");
		mvwprintw(g_vh.info, g_vh.inf_o, x + 25, "%i", c);
		wattroff(g_vh.info, COLOR_PAIR(INFO_STAND));
	}
	wrefresh(g_vh.info);
}

void   ft_print_info(void)
{
	int x;
	
	getmaxyx(g_vh.info, g_vh.inf_y, g_vh.inf_x);
	getmaxyx(g_vh.info, g_vh.info_y, g_vh.info_x);
	x = g_vh.info_x / 2;
	ft_print_speed(g_vh.speed);
	ft_print_c_processes();
	ft_print_player();
	ft_print_cycle_2die();
	g_vh.inf_o = 10;
}
