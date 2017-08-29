/*
** set_map.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
**
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
**
** Started on  Tue Mar 28 12:10:25 2017 Gregoire Renard
** Last update Thu Mar 30 17:12:36 2017 Rodrigue René
*/

#include "lib.h"

static int		fill_map(t_info *info)
{
  int			pos;
  int			cpt;

  pos = 0;
  cpt = 1;
  if ((info->map_line = malloc(((X + 1) * Y) + 1)) == NULL)
    return (ERROR);
  while (pos < ((X + 1) * Y))
    {
      if (cpt == X + 1)
	{
	  info->map_line[pos] = '\n';
	  cpt = 0;
	}
      else
	info->map_line[pos] = ' ';
      pos++;
      cpt++;
    }
  info->map_line[pos - 1] = '\0';
  return (SUCCESS);
}

int			set_map(t_info *info)
{
  if ((fill_map(info)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
