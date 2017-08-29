/*
** get_sem.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Mar 30 18:44:39 2017 Gregoire Renard
** Last update Thu Mar 30 18:49:18 2017 Gregoire Renard
*/

#include "lib.h"

int			get_sem(t_info *info)
{
  if ((info->sem_id = semget(info->key, 1,
			     SHM_R | SHM_W)) == -1)
    return (ERROR);
  return (SUCCESS);
}
