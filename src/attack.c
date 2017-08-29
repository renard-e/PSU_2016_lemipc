/*
** attack.c for lemipc in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/System_Unix/PSU_2016_lemipc/src
**
** Made by Rodrigue René
** Login   <rodrigue.rene@epitech.eu>
**
** Started on  Sat Apr  1 04:00:05 2017 Rodrigue René
** Last update Sun Apr  2 22:45:35 2017 Gregoire Renard
*/

#include "lib.h"

void		go_to_direction(t_pos *direction, t_pos *my_pos)
{
  if (direction->x > my_pos->x)
    ++my_pos->x;
  else if (direction->x < my_pos->x)
    --my_pos->x;
  else if (direction->y > my_pos->y)
    ++my_pos->y;
  else if (direction->y < my_pos->y)
    --my_pos->y;
}

int		distance(t_pos *my_pos, t_pos *other_pos)
{
  t_pos		tmp_pos;

  if (other_pos->x < my_pos->x)
    tmp_pos.x = my_pos->x + ((other_pos->x - my_pos->x) * -1);
  else if (other_pos->x >= my_pos->x)
    tmp_pos.x = other_pos->x;
  if (other_pos->y < my_pos->y)
    tmp_pos.y = my_pos->y + ((other_pos->y - my_pos->y) * -1);
  else if (other_pos->y >= my_pos->y)
    tmp_pos.y = other_pos->y;
  return (tmp_pos.x + tmp_pos.y);
}

int		found_nearest(t_info *info,
			      t_global *global,
			      t_pos *my_pos)
{
  int		i;
  int		x;
  int		somme;
  int		newsomme;

  i = 0;
  x = -1;
  somme = 0;
  if (global->gate[info->n_team].msg[0].n_team != -1)
    {
      somme = distance(my_pos, &global->gate[info->n_team].msg[i].pos_target);
      x = 0;
    }
  while ((i < MAX_MSG) && (global->gate[info->n_team].msg[i].n_team != -1))
    {
      newsomme = distance(my_pos,
			  &global->gate[info->n_team].msg[i].pos_target);
      if (newsomme < somme)
	{
	  somme = newsomme;
	  x = i;
	}
      ++i;
    }
  return (x);
}

int		attack(t_info *info,
		       t_global *global,
		       t_pos *my_pos, t_pos *new_pos)
{
  static int	i = 0;
  int		x;

  x = found_nearest(info, global, my_pos);
  if (x != -1)
    {
      go_to_direction(&global->gate[info->n_team].msg[x].pos_target, new_pos);
      ++i;
      if (i > (X * 2))
	{
	  global->gate[info->n_team].msg[x].n_team = -1;
	  i = 0;
	}
      return (1);
    }
  return (0);
}
