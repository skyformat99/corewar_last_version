/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:14:24 by ymushet           #+#    #+#             */
/*   Updated: 2017/10/25 12:41:26 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "./libft/libft.h"
# include "op.h"
# include "global.h"
# include "visualization/visualization.h"
# include "commands/commands.h"
# include <fcntl.h>
# define HEX 16

void			ft_init_global(void);
void			ft_error(char *str);
unsigned char	**ft_create_map(t_player *player, int n);
t_process		*ft_create_proceses(t_player *player);
void			ft_kill_processes(void);
void			ft_free_player(t_player **player);
t_player		*ft_read_from_core(int fd, unsigned int n);
int				ft_read_instructions(int fd, t_player *player);
int				ft_read_comment(int fd, t_player *player);
int				ft_read_magic(int fd, t_player *player);
int				ft_read_program_name(int fd, t_player *player);
int				ft_read_program_size(int fd, t_player *player);
void			ft_parse_args(int fd, char **argv, int i, t_player *head);
void			ft_game_cycle(void);
int				check_dump(char *str_next, char *str);
void			player_add(t_player **head, t_player *new);
int				ft_isadigit(char *str, char max_dump_or_ply);
int				ft_create_int(unsigned char *magic);
int				ft_increment_index(t_process *process);
void			ft_take_args(t_process *process, int i, int command);
int				ft_get_value(int ind);
void			ft_write_bold(int num, int start, int end);
void 			ft_write_col(int num, int address);
void			ft_sort_player(void);
t_process		*ft_create_car(unsigned int pos, unsigned int num, t_process *process);
#endif
