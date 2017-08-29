/*
** print_map.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Mar 28 12:14:19 2017 Gregoire Renard
** Last update Thu Mar 30 09:27:35 2017 Gregoire Renard
*/

#include "lib.h"

static void		print_wall_x()
{
  int			cpt;

  cpt = 0;
  while (cpt != X + 2)
    {
      printf("-");
      cpt++;
    }
  printf("\n");
}

void			print_map(char **map)
{
  int			cpt;

  cpt = 0;
  print_wall_x();
  while (map[cpt] != NULL)
    {
      printf("|%s|\n", map[cpt]);
      cpt++;
    }
  print_wall_x();
}

