/*
** semaphore_inc_dec.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Mar 30 17:15:12 2017 Gregoire Renard
** Last update Thu Mar 30 18:32:45 2017 Gregoire Renard
*/

#include "lib.h"

int			inc_semaphore(t_info *info)
{
  struct sembuf		sops;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = 1;
  if ((semop(info->sem_id, &sops, 1)) == -1)
    return (ERROR);
  return (SUCCESS);
}

int			dec_semaphore(t_info *info)
{
  struct sembuf		sops;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = -1;
  if ((semop(info->sem_id, &sops, 1)) == -1)
    return (ERROR);
  return (SUCCESS);
}
