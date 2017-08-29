/*
** print_map_ncurses.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Mar 29 15:39:17 2017 Gregoire Renard
** Last update Sun Apr  2 23:35:39 2017 Gregoire Renard
*/

#include "lib.h"

static void		print_wall_ncurses(t_pos pos)
{
  int			x;

  x = 0;
  if (pos.y == 0 && pos.x != X + 1)
    mvprintw(pos.y, pos.x - 1, "/");
  else
    mvprintw(pos.y, pos.x - 1, "\\");
  while (x <= X)
    {
      mvprintw(pos.y, pos.x, "-");
      x++;
      pos.x++;
    }
  if (pos.y == 0)
    mvprintw(pos.y, pos.x - 1, "\\");
  else
    mvprintw(pos.y, pos.x - 1, "/");
}

static char		*convert_char_str(char c)
{
  char			*str;

  if ((str = malloc(2)) == NULL)
    return (NULL);
  str[0] = c;
  str[1] = '\0';
  return (str);
}

static void		init_all(int *cpt, t_pos *pos, int indic)
{
  if (indic == 0)
    {
      *cpt = 0;
      pos->y = 0;
      pos->x = (COLS / 2) - (X / 2) ;
      print_wall_ncurses(*pos);
      pos->y = 1;
      mvprintw(pos->y, pos->x - 1, "|");
    }
  else
    {
      mvprintw(pos->y, pos->x, "|");
      pos->y++;
      pos->x = (COLS / 2) - (X / 2) ;
      print_wall_ncurses(*pos);
    }
}

static void		end_line_fct(t_pos *pos)
{
  init_color_pair();
  mvprintw(pos->y, pos->x, "|");
  pos->y++;
  pos->x = (COLS / 2) - (X / 2) ;
  mvprintw(pos->y, pos->x - 1, "|");
}

int			print_map_ncurses(char const *map)
{
  int			cpt;
  t_pos			pos;
  char			*str;

  clear();
  init_all(&cpt, &pos, 0);
  while (map[cpt] != '\0')
    {
      if (map[cpt] == '\n')
	end_line_fct(&pos);
      else if (map[cpt] == ' ')
	pos.x++;
      else
	{
	  if ((str = convert_char_str(map[cpt])) == NULL)
	    return (ERROR);
	  print_color_player(pos, str, map[cpt] - 48);
	  free(str);
	  pos.x++;
	}
      cpt++;
    }
  init_all(&cpt, &pos, 1);
  return (SUCCESS);
}
