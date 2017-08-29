/*
** map_function.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Mar 29 10:26:51 2017 Gregoire Renard
** Last update Thu Mar 30 09:27:16 2017 Gregoire Renard
*/

#include "lib.h"

void			mov_char_map(t_info *info, t_pos const pos_start,
				     t_pos const pos_end)
{
  char			tmp_start;
  char			tmp_end;

  tmp_start = get_char_map(info, pos_start.x, pos_start.y);
  tmp_end = get_char_map(info, pos_end.x, pos_end.y);
  set_char_map(info, pos_start.x, pos_start.y, tmp_end);
  set_char_map(info, pos_end.x, pos_end.y, tmp_start);
}

void			set_char_map(t_info *info, int const x,
				     int const y, char const value)
{
  int			cpt;
  int			back;

  cpt = 0;
  back = 0;
  while (back != y && info->map_line[cpt] != '\0')
    {
      if (info->map_line[cpt] == '\n' &&
	  info->map_line[cpt + 1] != '\0')
	back++;
      cpt++;
    }
  if (info->map_line[cpt] != '\0')
    info->map_line[cpt + x] = value;
}

char			get_char_map(t_info *info, int const x, int const y)
{
  int			cpt;
  int			back;

  cpt = 0;
  back = 0;
  while (back != y && info->map_line[cpt] != '\0')
    {
      if (info->map_line[cpt] == '\n' &&
	  info->map_line[cpt + 1] != '\0')
	back++;
      cpt++;
    }
  if (info->map_line[cpt] == '\0')
    return (info->map_line[cpt]);
  return (info->map_line[cpt + x]);
}
