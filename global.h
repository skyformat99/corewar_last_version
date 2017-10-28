#ifndef GLOBAL
#define GLOBAL
#include "corewar.h"

typedef struct                  s_process
{
	unsigned int                regs[REG_NUMBER];   //регистры
	int                         cary;       //кеэри
	int                         mem_addres; //адрес в памяти(индекс в массиве где стоит каретка)
	int                         number;     //номер процесса (номер игрока от которого создали процесс)
	void                        (*f)(struct s_process *p);//указатель на функцию (указатель на команду, которая исполняется)
	int                         exec_cycle; //цикл исполнения (сколько циклов осталось ждать до исполнения команды
	int                         alive;
	int							args[4];
	int							codage_octal;
	int							command;
	struct s_process            *next;
}                               t_process;

typedef struct 		    	    s_player
{
	unsigned char		        magic[4];     //меджик намбер(любой .сor начинается с него)
	unsigned char				*prog_name;   //имя программы
	unsigned char		        prog_size[4]; //размер программы в одном инте
	unsigned char				*comment;     //комментарий
	int                			number;       //номер игрока
	int                         player_size;  //размер инструкции
	unsigned char               *instructions;//интсрукции
	int                         mem_addr;	  //адрес начала инструкции в памяти игры
	struct s_player             *next;
	int 						n_live;
}						        t_player;

typedef struct                  s_data
{
	int 						dump;
	int 						aff;
	int 						visual;
	int 						count_players;
	int                         nbr_live;
	int                         max_checks;
	int                         cycle;
	t_player                    *last_live;
	int                         cycle2die;
	int                         cycle_per_sec;
	int 						count_processes;
	int 						change_cycle;
	unsigned char               **map;
	t_player                    *player_g;
	t_process                   *process_g;
}                               t_data;

t_data g_dt;
void							(*g_f[16])(struct s_process *p);
#endif
