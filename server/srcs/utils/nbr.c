/*
** nbr.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:55:44 2017 Dylan Deu
** Last update Mon Jun 26 14:55:44 2017 Dylan Deu
*/

#include	"utils/nbr.h"

bool	is_pos_num(char *str)
{
  unsigned int	index;

  if (!str)
    return (false);
  index = 0;
  while (str[index])
    {
      if (str[index] < '0' || str[index] > '9')
	return (false);
      index++;
    }
  return (true);
}
