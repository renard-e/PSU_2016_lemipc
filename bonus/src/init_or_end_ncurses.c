/*
** init_or_end_ncurses.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Mar 30 14:31:49 2017 Gregoire Renard
** Last update Fri Mar 31 10:57:41 2017 Gregoire Renard
*/

#include "lib.h"

static int		print_winner(int team_number)
{
  char			*team_number_str;
  int			i;

  i = 0;
  if ((team_number_str = convert_in_char(team_number)) == NULL)
    return (ERROR);
  while (i != 1)
    {
      clear();
      mvprintw(LINES / 2, (COLS / 2)
	       - (strlen("The Winner is the team :") / 2)
	       , "The Winner is the team :");
      mvprintw((LINES / 2) + 1, COLS / 2, team_number_str);
      mvprintw(LINES - 1, 0, "Press Enter for quit the game :)");
      if (getch() == '\n')
	i = 1;
    }
  free(team_number_str);
  return (SUCCESS);
}

static int		ident_and_print_winner(t_global *global)
{
  int			cpt;

  cpt = 0;
  while (cpt < MAX)
    {
      if (global->all_team[cpt].n_team != -1)
	if ((print_winner(global->all_team[cpt].team_number)) == ERROR)
	  return (ERROR);
      cpt++;
    }
  return (SUCCESS);
}

int			init_or_end_ncurses(t_global *global,
					    SCREEN **tmp,
					    int *ret,
					    int indic)
{
  if (indic == 0)
    {
      *ret = ERROR;
      if (((*tmp) = newterm(NULL, stderr, stdin)) == NULL)
	return (ERROR);
      curs_set(0);
      noecho();
      timeout(1);
    }
  else
    {
      if (indic != 2)
	if ((ident_and_print_winner(global)) == ERROR)
	  return (ERROR);
      if ((endwin()) == ERR)
	return (ERROR);
      free((*tmp));
    }
  return (SUCCESS);
}
