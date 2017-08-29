/*
** init_or_end_ncurses.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Mar 30 14:31:49 2017 Gregoire Renard
** Last update Fri Mar 31 18:10:28 2017 Gregoire Renard
*/

#include "lib.h"

static int		ident_and_print_winner(t_global *global)
{
  int			cpt;

  cpt = 0;
  while (cpt < MAX)
    {
      if (global->all_team[cpt].n_team != -1)
	printf("The winner of the game is : %i\n",
	       global->all_team[cpt].team_number);
      cpt++;
    }
  return (SUCCESS);
}

int			init_or_end(t_global *global,
				    int *ret,
				    int indic)
{
  if (indic == 0)
    *ret = ERROR;
  else
    {
      if (indic != 2)
	if ((ident_and_print_winner(global)) == ERROR)
	  return (ERROR);
    }
  return (SUCCESS);
}
