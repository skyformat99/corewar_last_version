//
// Created by Maksym Kaliberda on 14.10.17.
//

#ifndef __VISUALIZATION_H
#define __VISUALIZATION_H

# include <unistd.h>
# include <pthread.h>
# include <ncurses.h>
# include <curses.h>

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "ncurses.h"
# include "curses.h"
# include <pthread.h>
# define FIELD_Y
# include "../corewar.h"

# define P1 1
# define P2 2
# define P3 3
# define P4 4
# define START 5
# define BORDER 6
# define P1CAR 11
# define P2CAR 12
# define P3CAR 13
# define P4CAR 14
# define AVATAR 15
# define AVATARB 16

# define B1BOLT 17
# define B2BOLT 18
# define B3BOLT 19
# define B4BOLT 20
# define CAR_NP 21
# define INFO_STAND 22




typedef struct  s_visual
{
	WINDOW  *gen_win;
	WINDOW  *info;
	WINDOW  *term;
	WINDOW  *avatar;
	int     av_pos;
	int     av_pos_y;
	int     av_pos_x;
	
	int     inf_p;
	int     inf_y;
	int     inf_x;
	
	int     inf_o;
	int     info_y;
	int     info_x;
	
	int     width_w;
	int     step;
	int     x;
	int     y;
	int     xg;
	int     xin;
	int     yin;
	int     term_i;
	int     pause;
	int     speed;
	int     cycle_p;
	char    *color_pair;
	int     count_processes;
	int		iter;
	int		iter_fl;
}               t_vis;

t_vis        g_vh;


void	init_ncurses(void);
void    print_map();

void    ft_set_pair();

void   set_color_on_map(int gen, int pl, int bold, int ind);
void   set_color_off_map(int gen, int pl, int bold, int ind);
void   ft_putstr_vis_int(int str);
void   ft_print_info(void);
void   ft_adaptive();
void    gen_key(void);
void   ft_putstr_vis(char *str);
void    ft_pause_first();
void   ft_print_info(void);
void    ft_print_pause(void);
void    ft_print_start(void);
void    ft_print_speed(int c);
void    ft_print_speed_s(int c);
void    ft_print_c_processes();
void    ft_print_cycle_2die();
void    ft_pause_iter();
void    ft_print_player();
void    final();
#endif
