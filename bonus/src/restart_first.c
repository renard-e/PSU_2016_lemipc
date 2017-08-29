/*
** restart_first.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Mar 31 16:48:25 2017 Gregoire Renard
** Last update Fri Mar 31 16:51:37 2017 Gregoire Renard
*/

#include "lib.h"

void			*restart_first(void *arg)
{
  t_info		*info2;

  info2 = arg;
  if ((set_all(info2)) == ERROR)
    return (NULL);
  pthread_exit(NULL);
}
