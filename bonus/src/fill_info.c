/*
** remp_info.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Mar 20 10:04:43 2017 Gregoire Renard
** Last update Fri Mar 31 14:11:16 2017 Gregoire Renard
*/

#include "lib.h"

static int		check_number(char *line)
{
  int			cpt;

  cpt = 0;
  while (line[cpt] != '\0')
    {
      if (line[cpt] >= '0' && line[cpt] <= '9' && cpt <= 9)
	cpt++;
      else
	return (ERROR);
    }
  cpt = atoi(line);
  return (cpt);
}

static int		set_path(t_info *info, char *line)
{
  if ((access(line, R_OK)) == ERROR)
    return (ERROR);
  if ((info->path = strdup(line)) == NULL)
    return (ERROR);
  return (SUCCESS);
}

static int		set_team_number(t_info *info, char *line)
{
  int			number;

  if ((number = check_number(line)) == ERROR)
    return (ERROR);
  if (number < 0)
    return (ERROR);
  info->team_number = number;
  return (SUCCESS);
}

static int		set_info(int cpt, t_info *info, char *line)
{
  if (cpt == 1)
    {
      if ((set_path(info, line)) == ERROR)
	return (printf_error("Error : bad [PATH]"));
    }
  else if (cpt == 2)
    {
      if ((set_team_number(info, line)) == ERROR)
	return (printf_error("Error : bad [TEAM_NUMBER]"));
    }
  else
    return (ERROR);
  return (SUCCESS);
}

int			fill_info(t_info *info, char **argv, int argc)
{
  int			cpt;

  if (argc != 3)
    return (printf_error("Error : bad usage ./lemipc [PATH] [TEAM_NUMBER]"));
  cpt = 1;
  while (argv[cpt] != NULL)
    {
      if ((set_info(cpt, info, argv[cpt])) == ERROR)
	return (ERROR);
      cpt++;
    }
  return (SUCCESS);
}
