/*
** create_semaphore.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Mar 30 17:40:43 2017 Gregoire Renard
** Last update Fri Mar 31 10:58:28 2017 Gregoire Renard
*/

#include "lib.h"

int			create_semaphore(t_info *info)
{
  if ((info->sem_id = semget(info->key, 1,
			     IPC_CREAT | SHM_R | SHM_W)) == -1)
    return (ERROR);
  if ((semctl(info->sem_id, 0, SETVAL, 9)) == -1)
    return (ERROR);
  return (SUCCESS);
}
