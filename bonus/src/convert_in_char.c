/*
** convert_in_char.c for convert_in_char in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sat Feb 13 19:40:36 2016 gregoire renard
** Last update Wed Mar 29 18:22:07 2017 Gregoire Renard
*/

#include "lib.h"

char            *set_var(int *div, int len , int nb)
{
  char          *nbr_char;

  *div = 1;
  while (nb / *div >= 10)
    {
      *div = *div * 10;
      len++;
    }
  len++;
  if ((nbr_char = malloc(len + 1)) == NULL)
    return (NULL);
  nbr_char[len] = '\0';
  return (nbr_char);
}

char            *convert_in_char(int nb)
{
  char          *nbr_char;
  int           div;
  int           len;

  len = 0;
  if ((nbr_char = set_var(&div, len, nb)) == NULL)
    return (NULL);
  if (nb >= 10)
    {
      while (div != 0)
        {
          nbr_char[len] = (nb / div % 10 + '0');
          div = div / 10;
          len++;
        }
    }
  if (nb < 10)
    nbr_char[len] = (nb + '0');
  return (nbr_char);
}
