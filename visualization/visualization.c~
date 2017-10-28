//
// Created by Maksym Kaliberda on 16.10.17.
//


//
// Created by Maksym Kaliberda on 14.10.17.
//
# include "../corewar.h"

void    print_map()
{
	int i;
	int x;
	int y;
	int mem = 1024 * 4;
	y = 1;
	i = 0;
	gen_key();
	while(y < 66)
	{
		x = 2;
		while (i < MEM_SIZE)
		{
			set_color_on_map((int)g_dt.map[0][i], (int)g_dt.map[1][i], (int)g_dt.map[2][i], i);
			mvwprintw(g_vh.gen_win, y, x, "%.2X", (int)g_dt.map[0][i]);
			set_color_off_map((int)g_dt.map[0][i], (int)g_dt.map[1][i], (int)g_dt.map[2][i], i);
			++i;
			if (i % 62 == 0)
				break ;
			x += g_vh.step;
		}
		++y;
	}
	ft_print_info();
	usleep(g_vh.speed);
	wrefresh(g_vh.gen_win);
	wrefresh(g_vh.info);
	wrefresh(g_vh.term);
	ft_pause_first();
}


void fgt(char *str)
{
	int i = 0;
	int x = g_vh.av_pos_x / 2 - 24;
	while (i <= 48)
	{
		wattron(g_vh.avatar, COLOR_PAIR(P2) | A_BOLD);
		mvwprintw(g_vh.avatar, g_vh.av_pos, x + 1, "%c", '|');
		wattroff(g_vh.avatar, COLOR_PAIR(P2) | A_BOLD);
		wattron(g_vh.avatar, COLOR_PAIR(P2));
		mvwprintw(g_vh.avatar, g_vh.av_pos, x, "%c", str[i]);
		wattroff(g_vh.avatar, COLOR_PAIR(P2));
		i++;
		x++;
		usleep(10000);
		wrefresh(g_vh.avatar);
	}
	wattron(g_vh.avatar, COLOR_PAIR(P4));
	mvwprintw(g_vh.avatar, g_vh.av_pos, x, "%c", ' ');
	wattroff(g_vh.avatar, COLOR_PAIR(P4));
	wrefresh(g_vh.avatar);
	g_vh.av_pos++;
}

void fgp(char *str)
{
	int i = 0;
	int x = g_vh.av_pos_x / 2 - 24;
	while (i <= 48)
	{
		if (str[i] == 32)
			wattron(g_vh.avatar, COLOR_PAIR(AVATARB));
		else
			wattron(g_vh.avatar, COLOR_PAIR(AVATAR));
		mvwprintw(g_vh.avatar, g_vh.av_pos, x, "%c", str[i]);
		if (str[i] == 32)
			wattroff(g_vh.avatar, COLOR_PAIR(AVATARB));
		else
			wattroff(g_vh.avatar, COLOR_PAIR(AVATAR));
		i++;
		x++;
	}
	usleep(50000);
	wrefresh(g_vh.avatar);
	g_vh.av_pos++;
}

void init_avatar()
{
	g_vh.term_i = 1;
	getmaxyx(stdscr, g_vh.av_pos_y, g_vh.av_pos_x);
	g_vh.avatar = newwin(g_vh.av_pos_y, g_vh.av_pos_x, 0, 0);
	g_vh.av_pos = g_vh.av_pos_y / 2 - 7;
	fgp(" ####   ####  ####  ##### #   #   #    #    ####");
	fgp("#    # #    # #   # #     #   #   #    #    #   #");
	fgp("#      #    # #   # #      #  #  #    # #   #   #");
	fgp("#      #    # ####  #####  #  #  #    # #   ####");
	fgp("#      #    # #   # #      # # # #   #   #  #   #");
	fgp("#      #    # #   # #       #   #    #####  #   #");
	fgp("#    # #    # #   # #       #   #   #     # #   #");
	fgp(" ####   ####  #   # #####   #   #   #     # #   #");
	g_vh.av_pos++;
	fgt("                    INSTRUCTION                  ");
	fgt("key space..............................play/pause");
	fgt("key + .............................increase speed");
	fgt("key + .............................decrease speed");
	g_vh.av_pos+= 2;
	fgt("              ENTER ANY KEY TO START             ");
	getchar();
	endwin();
}

void	init_ncurses(void)
{
	g_vh.inf_p = 2;
	g_vh.pause = 1;
<<<<<<< HEAD
	g_vh.speed = 20000;
	g_vh.inf_o = 10;
	g_vh.cycle_p = 50;
=======
	g_vh.speed = 50000;
>>>>>>> f6f5317706d8765235a40ddb57d2b342939ecea9
	initscr();
	start_color();
	keypad(stdscr, true);
	noecho();
	ft_set_pair();
	curs_set(0);
	nodelay(stdscr, true);
	ft_adaptive();
//	init_avatar();
	keypad(stdscr, true);
	g_vh.gen_win = newwin(g_vh.y, g_vh.xg, 0, 0);
	g_vh.info = newwin(g_vh.y - g_vh.yin, g_vh.x - g_vh.xg, 0, g_vh.xg);
	g_vh.term = newwin(g_vh.yin, g_vh.x - g_vh.xg, g_vh.y - g_vh.yin , g_vh.xg);
	wattron(g_vh.gen_win, COLOR_PAIR(BORDER));
	wborder(g_vh.gen_win, '.', '.', '.', '.', '.', '.', '.', '.');
	wattroff(g_vh.gen_win, COLOR_PAIR(BORDER));
	wattron(g_vh.info, COLOR_PAIR(BORDER));
	wborder(g_vh.info, '.', '.', '.', '.', '.', '.', '.', '.');
	wattroff(g_vh.info, COLOR_PAIR(BORDER));
	wattron(g_vh.term, COLOR_PAIR(BORDER));
	wborder(g_vh.term, '.', '.', '.', '.', '.', '.', '.', '.');
	wattroff(g_vh.term, COLOR_PAIR(BORDER));
}




//fgp(" ####   ####  ####  ##### #   #   #    #    ####");
//fgp("#    # #    # #   # #     #   #   #    #    #   #");
//fgp("#      #    # #   # #      #  #  #     #   #   #");
//fgp("#      #    # ####  #####  #  #  #     #   ####");
//fgp("#      #    # #   # #      # # # #     #    #   #");
//fgp("#      #    # #   # #       #   #      #    #   #");
//fgp("#    # #    # #   # #       #   #      #   #   #");
//fgp(" ####   ####  #   # #####   #   #      # #   #");