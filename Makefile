NAME = corewar

LIB = -L./libft -lft

FLAGS = -Wall -Wextra -Werror -O3

SRC = ft_create_map.c ft_free_player.c ft_kill_processes.c ft_read_magic.c ft_read_instructions.c\
ft_create_processes.c ft_game_cycle.c ft_read_coment.c ft_read_program_name.c main.c\
ft_error.c ft_init_global.c ft_read_from_core.c ft_read_program_size.c validate_args.c ft_for_param_valid.c ft_sort_player.c\
op.c visualization/visualization.c visualization/set_color.c visualization/ft_print_info.c visualization/ft_putsrt_vis.c\
visualization/ft_key_plushki.c visualization/ft_panel.c commands/ft_fork.c  commands/ft_live.c  commands/ft_sti.c commands/ft_add.c \
commands/ft_ld.c commands/ft_lld.c commands/ft_sub.c commands/ft_lldi.c commands/ft_xor_and_or.c commands/ft_aff.c commands/ft_zjump.c commands/ft_ldi.c \
commands/ft_st.c commands/ft_lfork.c commands/ft_check_codage_octal.c \

		
# commands/ft_sti.c commands/ft_st.c commands/ft_add_sub.c \
# commands/ft_zjump.c commands/ft_fork_lfork.c commands/ft_live.c \ commands/ft_ld_lld.c  
BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	make -C libft/
	gcc $(LIB) -o $(NAME) $(BINS) -lncurses
%.o: %.c
	gcc -o $@ -c $<
clean:
	make -C libft/ clean
	rm -rf $(BINS)
fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)
re: fclean all