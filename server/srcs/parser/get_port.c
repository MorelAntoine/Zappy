/*
** get_port.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed Jun 14 14:15:19 2017 Dylan Deu
** Last update Wed Jun 14 14:15:19 2017 Dylan Deu
*/

#include		<stdio.h>
#include		"utils/nbr.h"
#include		"parser/parse.h"

bool			get_port(t_parse *ptr, int *pos, char **av, int ac)
{
  *pos = *pos + 1;
  if (*pos >= ac)
  {
    fprintf(stderr, "%s: option requires an argument -- 'p'\n\n", av[0]);
    return (false);
  }
  if (is_pos_num(av[*pos]) == false)
    return (false);
  ptr->port = atoi(av[*pos]);
  return (true);
}
