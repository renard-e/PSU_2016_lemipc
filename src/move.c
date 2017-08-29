/*
** move.c for lemipc in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/System_Unix/PSU_2016_lemipc/src
**
** Made by Rodrigue René
** Login   <rodrigue.rene@epitech.eu>
**
** Started on  Thu Mar 30 18:52:40 2017 Rodrigue René
** Last update Sun Apr  2 20:31:44 2017 Rodrigue RENE
*/

#include <time.h>
#include "lib.h"

void		random_direction(t_pos *new_pos)
{
  int		try;

  try = rand() % 4;
  if (try == 0 && (new_pos->y != 0))
    --new_pos->y;
  else if (try == 1 && (new_pos->y != Y))
    ++new_pos->y;
  else if (try == 2 && (new_pos->x != X))
    ++new_pos->x;
  else if (try == 3 && (new_pos->x != 0))
    --new_pos->x;
}

int		is_eaten(t_info *info, t_pos *my_pos, char my_char)
{
  char		enemy[9];

  init_enemy(&enemy[0]);
  if (my_pos->x != 0)
    {
      if (my_pos->y != 0)
	enemy[0] = get_char_map(info, my_pos->x - 1, my_pos->y - 1);
      enemy[1] = get_char_map(info, my_pos->x - 1, my_pos->y);
      if (my_pos->y != (Y - 1))
	enemy[2] = get_char_map(info, my_pos->x - 1, my_pos->y + 1);
    }
  if (my_pos->x != (X - 1))
    {
      if (my_pos->y != 0)
	enemy[3]  = get_char_map(info, my_pos->x + 1, my_pos->y - 1);
      enemy[4] = get_char_map(info, my_pos->x + 1, my_pos->y);
      if (my_pos->y != (Y - 1))
	enemy[5] = get_char_map(info, my_pos->x + 1, my_pos->y + 1);
    }
  if (my_pos->y != 0)
    enemy[6] = get_char_map(info, my_pos->x, my_pos->y - 1);
  if (my_pos->y != (Y - 1))
    enemy[7] = get_char_map(info, my_pos->x, my_pos->y + 1);
  return (check_enemy(&enemy[0], my_char));
}

void	setter(t_info *info, t_pos *my_pos, t_pos *new_pos, char my_char)
{
  if (get_char_map(info, new_pos->x, new_pos->y) == ' ')
    {
      set_char_map(info, new_pos->x, new_pos->y, my_char);
      set_char_map(info, my_pos->x, my_pos->y, ' ');
      my_pos->x = new_pos->x;
      my_pos->y = new_pos->y;
    }
}

void		move_pos(t_info *info,
			 t_global *global,
			 t_pos *my_pos)
{
  t_pos		new_pos;
  char		my_char;
  int		dead;
  int		i;

  i = 0;
  dead = 0;
  new_pos.x = my_pos->x;
  new_pos.y = my_pos->y;
  my_char = get_char_map(info, my_pos->x, my_pos->y);
  while (dead < 2)
    {
      rec_sms(info, global);
      if ((i > 14) || (attack(info, global, my_pos, &new_pos) != 1))
	random_direction(&new_pos);
      setter(info, my_pos, &new_pos, my_char);
      dead = is_eaten(info, my_pos, my_char);
      if (dead != 0)
	send_sms(info, my_pos, info->n_team);
      if (i == 15)
	i = -1;
      ++i;
      usleep(100000);
    }
  set_char_map(info, my_pos->x, my_pos->y, ' ');
}
