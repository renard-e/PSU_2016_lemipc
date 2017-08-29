/*
** create_sem_shm_msg.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Mar 30 17:30:27 2017 Gregoire Renard
** Last update Fri Mar 31 15:24:41 2017 Gregoire Renard
*/

#include "lib.h"

static void		init_msg(t_global **global)
{
  int			cpt;
  int			team;

  team = 0;
  while (team < MAX)
    {
      cpt = 0;
      while (cpt < MAX_MSG)
	{
	  (*global)->gate[team].msg[cpt].n_team = -1;
	  cpt++;
	}
      team++;
    }
}

static void		set_memory_shared(void *data,
					  t_global **global,
					  int team)
{
  int			nb;
  t_team		this_team;

  nb = 0;
  (*global) = (t_global *)(data + (((X + 1) * Y) + 2));
  (*global)->nb_team = 1;
  while (nb < MAX)
    {
      this_team.nb_player = 1;
      this_team.team_number = -1;
      this_team.n_team = -1;
      (*global)->all_team[nb] = this_team;
      nb++;
    }
  (*global)->all_team[0].nb_player = 1;
  (*global)->all_team[0].n_team = 0;
  (*global)->all_team[0].team_number = team;
  init_msg(global);
}

int			create_shared_memory(t_info *info, t_global **global)
{
  void			*data;

  if ((set_map(info)) == ERROR)
    return (ERROR);
  if ((info->shm_id = shmget(info->key, (((X + 1) * Y) + 1)
			     + sizeof(t_global) + (sizeof(t_team) * (MAX + 4)),
			     IPC_CREAT | SHM_R | SHM_W)) == -1)
    return (ERROR);
  if ((data = shmat(info->shm_id, NULL, SHM_R | SHM_W)) == (void *)-1)
    return (ERROR);
  memcpy(data, info->map_line, strlen(info->map_line));
  info->map_line = data;
  set_memory_shared(data, global, info->team_number);
  return (SUCCESS);
}
