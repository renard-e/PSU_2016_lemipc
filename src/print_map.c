/*
** print_map.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Mar 28 12:14:19 2017 Gregoire Renard
** Last update Fri Mar 31 18:23:19 2017 Gregoire Renard
*/

#include "lib.h"

static void		my_putchar(char c)
{
  write(1, &c, 1);
}

static void		print_wall_x(int indic)
{
  int			cpt;

  cpt = 0;
  if (indic == 1)
    my_putchar('/');
  else
    my_putchar('\\');
  while (cpt != X)
    {
      my_putchar('-');
      cpt++;
    }
  if (indic == 1)
    {
      my_putchar('\\');
      printf("\n");
    }
  else
    my_putchar('/');
}

void			print_map(char *map)
{
  int			cpt;

  cpt = 0;
  print_wall_x(1);
  my_putchar('|');
  while (map[cpt] != '\0')
    {
      my_putchar(map[cpt]);
      if (map[cpt] != '\n' &&
	  map[cpt] != '\0' && map[cpt + 1] == '\n')
	my_putchar('|');
      if (map[cpt] == '\n')
	my_putchar('|');
      cpt++;
    }
  my_putchar('|');
  my_putchar('\n');
  print_wall_x(2);
  my_putchar('\n');
}

