/*
** all_process.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Mar 28 14:29:08 2017 Gregoire Renard
** Last update Thu Mar 30 18:39:50 2017 Gregoire Renard
*/

#include "lib.h"

int		all_process(t_info *info)
{
  if ((info->key = ftok(info->path, 0)) == -1)
    return (ERROR);
  if ((set_all(info)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
