/*
** start_work.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/bonus/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Mar 31 17:47:53 2017 Gregoire Renard
** Last update Fri Mar 31 21:25:31 2017 Gregoire Renard
*/

#include "lib.h"

static int		count_alive(t_global *global)
{
  int			cpt;
  int			nb;

  cpt = 0;
  nb = 0;
  while (cpt < MAX)
    {
      if (global->all_team[cpt].n_team != -1)
	nb++;
      cpt++;
    }
  return (nb);
}

static int		real_start_game(t_global *global, int ret)
{
  int			valid;
  int			cpt;

  if (ret == SUCCESS)
    return (SUCCESS);
  valid = 0;
  cpt = 0;
  while (cpt < MAX)
    {
      if (global->all_team[cpt].n_team != -1)
	{
	  if (global->all_team[cpt].nb_player >= 2)
	    valid++;
	}
      cpt++;
    }
  if (valid >= 2)
    return (SUCCESS);
  return (ERROR);
}

int			start_work(t_info *info,
				   t_global *global)
{
  int			ret;
  
  if ((init_or_end(global, &ret, 0)) == ERROR)
    return (ERROR);
  while ((count_alive(global)) != 1
  	 || (ret = real_start_game(global, ret)) != SUCCESS)
    {
      print_map(info->map_line);
      usleep(19000);
    }
  if ((init_or_end(global, &ret, 1)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
