#include "corewar.h"

void	ft_init_global(void)
{
	g_dt.dump = 0;
	g_dt.aff = 0;
	g_dt.visual = 0;
	g_dt.count_players = 0;
	g_dt.nbr_live = 0;
	g_dt.max_checks = 0;
	g_dt.cycle = 0;
	g_dt.last_live = 0;
	g_dt.cycle_per_sec = 50;
	g_dt.cycle2die = CYCLE_TO_DIE;
	g_dt.map = NULL;
	g_dt.player_g = NULL;
	g_dt.process_g = NULL;
}