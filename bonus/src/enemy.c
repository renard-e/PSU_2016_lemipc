/*
** enemy.c for lemipc in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/System_Unix/PSU_2016_lemipc/src
**
** Made by Rodrigue René
** Login   <rodrigue.rene@epitech.eu>
**
** Started on  Sat Apr  1 13:52:44 2017 Rodrigue René
** Last update Sat Apr  1 14:22:52 2017 Rodrigue René
*/

#include "lib.h"

void	init_enemy(char *enemy)
{
  int	i;

  i = 0;
  while (i < 9)
    enemy[i++] = 0;
}

int	check_enemy(char *enemy, char my_char)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (i < 8)
    {
      if (enemy[i] != ' ' && enemy[i] != my_char && enemy[i] != 0)
	{
	  x = 1;
	  if (index(&enemy[i + 1], enemy[i]) != NULL)
	    return (2);
	}
      ++i;
    }
  return (x);
}
