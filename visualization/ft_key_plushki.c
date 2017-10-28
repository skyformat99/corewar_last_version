/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_plushki.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 19:20:21 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/19 19:20:25 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../corewar.h"

void    ft_pause_first()
{
	int s;
	
	while (g_vh.pause == 1)
	{
		ft_print_pause();
		g_vh.inf_p = 2;
		usleep(1);
		s = wgetch(stdscr);
		if (s == 32)
		{
			ft_print_start();
			g_vh.inf_p = 2;
			g_vh.pause = 0;
		}
	}
}

void    ft_pause_iter()
{
	int s;

	while (g_vh.iter == 1)
	{
		ft_print_pause();
		g_vh.inf_p = 2;
		usleep(1);
		s = wgetch(stdscr);
		if (s == 115)
		{
			ft_print_start();
			g_vh.inf_p = 2;
			g_vh.iter = 0;
		}
		if (s == 32)
		{
			ft_print_start();
			g_vh.inf_p = 2;
			g_vh.iter_fl = 0;
			g_vh.iter = 0;
		}
	}
}

void    ft_pause(int c)
{
	int s;
	
	if (c == 32 && g_vh.pause == 0)
	{
		g_vh.pause = 1;
		ft_print_pause();
		g_vh.inf_p = 2;
		while (g_vh.pause == 1)
		{
			usleep(1);
			s = wgetch(stdscr);
			if (s == 32)
			{
				g_vh.pause = 0;
				ft_print_start();
				g_vh.inf_p = 2;
			}
		}
	}
}

void    ft_speed(int c)
{
	if (c == 43 || c == 45)
	{
		if(c == '-' && g_vh.speed < 640000)
		{
			g_vh.speed *= 2;
			ft_print_speed(g_vh.speed);
		}
		if(c == '+' && g_vh.speed > 400)
		{
			g_vh.speed /= 2;
			ft_print_speed(g_vh.speed);
		}
	}
}


void    gen_key()
{
	int c;

	c = wgetch(stdscr);
	ft_pause(c);
	ft_speed(c);
	if (c == 32 && g_vh.iter_fl == 1)
		g_vh.iter_fl = 0;
	else if (c == 32 && g_vh.iter_fl == 0)
		g_vh.iter_fl = 1;
}