/*
** create_msg.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Mar 31 10:32:05 2017 Gregoire Renard
** Last update Fri Mar 31 10:55:00 2017 Gregoire Renard
*/

#include "lib.h"

int			create_msg(t_info *info)
{
  if ((info->msg_id = msgget(info->key,
			     IPC_CREAT | SHM_R | SHM_W)) == -1)
    return (ERROR);
  return (SUCCESS);
}
