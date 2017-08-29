/*
** pop.c for lemipc in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/System_Unix/PSU_2016_lemipc/src
**
** Made by Rodrigue René
** Login   <rodrigue.rene@epitech.eu>
**
** Started on  Thu Mar 30 12:37:36 2017 Rodrigue René
** Last update Sun Apr  2 23:10:15 2017 Gregoire Renard
*/

#include <time.h>
#include "lib.h"

void	get_random_pos(int *x_rand, int *y_rand)
{
  srand(time(0));
  (*x_rand) = rand();
  (*y_rand) = rand();
  (*x_rand) = *x_rand % X;
  (*y_rand) = *y_rand % Y;
}

void	fonction_one(t_info *info, t_global *global, int *i)
{
  int	x;

  x = 0;
  while (x != 1 && (global->all_team[*i].team_number != -1 && *i < MAX))
    {
      if (global->all_team[*i].team_number == info->team_number)
	{
	  x = 1;
	  (*i)--;
	  global->all_team[*i].nb_player++;
	}
      ++(*i);
    }
  if (x == 0)
    dec_semaphore(info);
}
void	function_two(t_info *info, int *x_rand, int *y_rand)
{
  int	ok;

  ok = 0;
  while (ok != 1)
    {
      if (get_char_map(info, *x_rand, *y_rand) == ' ')
	ok = 1;
      else
	get_random_pos(x_rand, y_rand);
    }
}

void	pop(t_info *info, t_global *global, t_pos *my_pos)
{
  int	x_rand;
  int	y_rand;
  int	i;

  i = 0;
  get_random_pos(&x_rand, &y_rand);
  fonction_one(info, global, &i);
  global->all_team[i].team_number = info->team_number;
  ++global->all_team[i].nb_player;
  global->all_team[i].n_team = i;
  info->n_team = i;
  function_two(info, &x_rand, &y_rand);
  my_pos->x = x_rand;
  my_pos->y = y_rand;
  set_char_map(info, x_rand, y_rand, global->all_team[i].n_team + 48);
  move_pos(info, global, my_pos);
  --global->all_team[info->n_team].nb_player;
  if (global->all_team[info->n_team].nb_player == 1)
    {
      global->all_team[info->n_team].n_team = -1;
      inc_semaphore(info);
    }
}
