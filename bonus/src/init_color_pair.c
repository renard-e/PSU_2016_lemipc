/*
** init_color_paire.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Mar 30 16:02:35 2017 Gregoire Renard
** Last update Tue Apr  4 20:20:32 2017 Gregoire Renard
*/

#include "lib.h"

void			init_color_pair()
{
  short			COLOR_BROWN;
  short			COLOR_REAL_YELLOW;

  COLOR_BROWN = 12;
  COLOR_REAL_YELLOW = 16;
  start_color();
  init_color(COLOR_BROWN, 255, 124, 4);
  init_color(COLOR_REAL_YELLOW, 100, 255, 100);
  init_pair(0, 0, COLOR_WHITE);
  init_pair(1, 0, COLOR_GREEN);
  init_pair(2, 0, COLOR_YELLOW);
  init_pair(3, 0, COLOR_RED);
  init_pair(4, 0, COLOR_BLUE);
  init_pair(5, 0, COLOR_MAGENTA);
  init_pair(6, 0, COLOR_CYAN);
  init_pair(7, 0, COLOR_BROWN);
  init_pair(8, 0, COLOR_REAL_YELLOW);
}

void			print_color_player(t_pos pos,
					   char *str,
					   int tab)
{
  if (tab == 0)
    {
      attron(A_REVERSE);
      mvprintw(pos.y, pos.x, str);
      attroff(A_REVERSE);
    }
  else
    {
      attron(COLOR_PAIR(tab));
      mvprintw(pos.y, pos.x, str);
      attroff(COLOR_PAIR(tab));
    }
}
