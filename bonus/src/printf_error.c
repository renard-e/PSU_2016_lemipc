/*
** printf_error.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Mar 20 10:41:38 2017 Gregoire Renard
** Last update Mon Mar 20 10:42:55 2017 Gregoire Renard
*/

#include "lib.h"

int			printf_error(char *error)
{
  printf("%s\n", error);
  return (ERROR);
}
