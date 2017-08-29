/*
** get_shm.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Mar 30 18:35:56 2017 Gregoire Renard
** Last update Fri Mar 31 16:53:35 2017 Gregoire Renard
*/

#include "lib.h"

int			get_shm(t_info *info,
				t_global **global)
{
  void			*data;

  if ((data = shmat(info->shm_id, NULL, SHM_R | SHM_W)) == (void *)-1)
    return (ERROR);
  info->map_line = (char *)data;
  (*global) = (t_global *)(data + ((((X + 1) * Y) + 2)));
  return (SUCCESS);
}
