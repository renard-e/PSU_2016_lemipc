/*
** start_ncurses_work.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
**
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
**
** Started on  Wed Mar 29 11:55:33 2017 Gregoire Renard
** Last update Sun Apr  2 23:35:51 2017 Gregoire Renard
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

int			start_ncurses_work(t_info *info,
					   t_global *global)
{
  int			ret;
  int			nb;
  SCREEN		*tmp;

  if ((init_or_end_ncurses(global, &tmp, &ret, 0)) == ERROR)
    return (ERROR);
  while ((nb = count_alive(global)) != 1
  	 || ret != SUCCESS)
    {
      if (nb >= 2)
	ret = SUCCESS;
      if (nb == 1 && ret == SUCCESS)
	return (SUCCESS);
      if ((print_map_ncurses(info->map_line)) == ERROR)
	return (ERROR);
      if ((getch()) == 27)
	{
	  if ((init_or_end_ncurses(global, &tmp, &ret, 2)) == ERROR)
	    return (ERROR);
	  return (SUCCESS);
	}
    }
  if ((init_or_end_ncurses(global, &tmp, &ret, 1)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
