//
// Created by Maksym Kaliberda on 16.10.17.
//

# include "../corewar.h"

void   ft_adaptive()
{
	getmaxyx(stdscr, g_vh.y, g_vh.x);
	if (g_vh.x > 400)
		g_vh.step = 5;
	if (g_vh.x < 400 && g_vh.x > 300)
		g_vh.step = 4;
	if (g_vh.x < 300 && g_vh.x > 250)
		g_vh.step = 3;
	if (g_vh.x < 250 && g_vh.x > 200)
		g_vh.step = 2;
	else if (g_vh.x < 200)
		g_vh.step = 2;
	g_vh.xg = g_vh.step * 66;
	g_vh.xin = g_vh.x - g_vh.xg;
	g_vh.yin = g_vh.y / 2 - g_vh.y / 4;
}

void    ft_set_pair()
{
	init_color(COLOR_RED, 256, 256, 256);
	init_pair(START, COLOR_RED, COLOR_BLACK);
	init_pair(P1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(P2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(P3, COLOR_CYAN, COLOR_BLACK);
	init_pair(P4, COLOR_GREEN, COLOR_BLACK);
	init_pair(BORDER, COLOR_RED, COLOR_RED);
	init_pair(P1CAR, COLOR_RED, COLOR_MAGENTA);
	init_pair(P2CAR, COLOR_RED, COLOR_YELLOW);
	init_pair(P3CAR, COLOR_RED, COLOR_CYAN);
	init_pair(P4CAR, COLOR_RED, COLOR_GREEN);
	init_pair(CAR_NP, COLOR_WHITE, COLOR_RED);
	init_pair(B1BOLT, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(B2BOLT, COLOR_YELLOW, COLOR_BLACK);
	init_pair(B3BOLT, COLOR_CYAN, COLOR_BLACK);
	init_pair(B4BOLT, COLOR_GREEN, COLOR_BLACK);
	init_pair(AVATAR, COLOR_GREEN, COLOR_GREEN);
	init_pair(AVATARB, COLOR_BLACK, COLOR_BLACK);
	init_pair(INFO_STAND, COLOR_WHITE, COLOR_BLACK);
}

int   check_car(int ind)
{
	t_process *p;
	
	p = g_dt.process_g;
	while (p)
	{
		if (ind == (int)p->mem_addres)
		{
			g_vh.count_processes++;
			return (1);
		}
		p = p->next;
	}
	return (0);
}

void set_color_on_map(int gen, int pl, int bold, int ind)
{
	if(check_car(ind) == 1)
	{
		if (pl != 48)
			wattron(g_vh.gen_win, COLOR_PAIR(pl - 64 + 10));
		else if (pl == 48)
			wattron(g_vh.gen_win, COLOR_PAIR(CAR_NP));
	}
	else if (pl != 48 && bold == 0)
		wattron(g_vh.gen_win, COLOR_PAIR(pl - 64));
	else if (pl != 48 && bold > 0)
		wattron(g_vh.gen_win, COLOR_PAIR(pl - 64) | A_BOLD);
	else if (pl == 48)
		wattron(g_vh.gen_win, COLOR_PAIR(START));
	
}

void set_color_off_map(int gen, int pl, int bold, int ind)
{
	if(check_car(ind) == 1)
	{
		if (pl != 48)
			wattroff(g_vh.gen_win, COLOR_PAIR(pl - 64 + 10));
		else if (pl == 48)
			wattroff(g_vh.gen_win, COLOR_PAIR(CAR_NP));
	}
	else if (pl != 48 && bold == 0)
		wattroff(g_vh.gen_win, COLOR_PAIR(pl - 64));
	else if (pl != 48 && bold > 0)
	{
		wattroff(g_vh.gen_win, COLOR_PAIR(pl - 64) | A_BOLD);
		g_dt.map[2][ind]--;
		ft_putstr_vis_int((int)g_dt.map[2][ind]);
	}
	else if (pl == 48)
		wattroff(g_vh.gen_win, COLOR_PAIR(START));
}
