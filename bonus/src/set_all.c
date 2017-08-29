/*
** shared_memory_fct.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
**
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
**
** Started on  Tue Mar 28 15:03:06 2017 Gregoire Renard
** Last update Sat Apr  1 16:40:32 2017 Rodrigue René
*/

#include "lib.h"

static int		clean_all(t_info *info)
{
  if ((shmctl(info->shm_id, IPC_RMID, NULL)) == -1)
    return (ERROR);
  if ((msgctl(info->msg_id, IPC_RMID, NULL)) == -1)
    return (ERROR);
  if ((semctl(info->sem_id, 0, IPC_RMID, 0)) == -1)
    return (ERROR);
  return (SUCCESS);
}

static int		create_part(t_info *info, t_global **global)
{
  if ((create_shared_memory(info, global)) == ERROR)
    return (printf_error("Error : Shared Memory Error"));
  if ((create_semaphore(info)) == ERROR)
    return (printf_error("Error : Semaphore Error"));
  if ((create_msg(info)) == ERROR)
    return (printf_error("Error : message queues Error"));
  return (SUCCESS);
}

static int		get_part(t_info *info,
				 t_global **global,
				 t_pos *my_pos)
{
  if ((get_shm(info, global)) == ERROR)
    return (printf_error("Error : get Shared Memory"));
  if ((get_sem(info)) == ERROR)
    return (printf_error("Error : get Semaphore"));
  if ((get_msg(info)) == ERROR)
    return (printf_error("Error : get message queues"));
  my_pos->x = 0;
  my_pos->y = 0;
  return (SUCCESS);
}

static int		first_process(t_info *info, t_global *global)
{
  pthread_t		thread;

  if ((pthread_create(&thread, NULL, restart_first, info)) != 0)
    return (printf_error("Error : thread error"));
  if ((start_ncurses_work(info, global)) == ERROR)
    return (printf_error("Error : Ncurses load fail"));
  if ((clean_all(info)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int			set_all(t_info *info)
{
  t_global		*global;
  t_pos			my_pos;

  if ((info->shm_id =
       shmget(info->key, (((X + 1) * Y) + 1)
	      + sizeof(t_global) + (sizeof(t_team) * (MAX + 4)),
	      SHM_R | SHM_W))
      == -1)
    {
      if ((create_part(info, &global)) == ERROR)
  	return (ERROR);
      if ((first_process(info, global)) == ERROR)
	return (ERROR);
    }
  else
    {
      if ((get_part(info, &global, &my_pos)) == ERROR)
      	return (ERROR);
      pop(info, global, &my_pos);
    }
  return (SUCCESS);
}
