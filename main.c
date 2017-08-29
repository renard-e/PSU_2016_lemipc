/*
** main.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Mar 20 09:58:40 2017 Gregoire Renard
** Last update Wed Mar 29 10:17:59 2017 Gregoire Renard
*/

#include "lib.h"

int			main(int argc, char **argv)
{
  t_info		info;

  if ((fill_info(&info, argv, argc)) == ERROR)
    return (ERROR);
  if ((all_process(&info)) == ERROR)
    return (-1);
  free(info.path);
  return (0);
}
