/*
** get_nb_clients.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed Jun 14 14:23:12 2017 Dylan Deu
** Last update Wed Jun 14 14:23:12 2017 Dylan Deu
*/

#include		<stdio.h>
#include		"utils/nbr.h"
#include		"parser/parse.h"

bool			get_nb_clients(t_parse *ptr, int *pos, char **av,
					   int ac)
{
  int			nb;

  *pos = *pos + 1;
  if (*pos >= ac)
  {
    fprintf(stderr, "%s: option requires an argument -- 'n'\n\n", av[0]);
    return (false);
  }
  if (is_pos_num(av[*pos]) == false)
    return (false);
  nb = atoi(av[*pos]);
  if (nb == 0)
  {
    fprintf(stderr, "\n-c option only accepts integer "
      "values greater or equal to 1\n\n");
    return (false);
  }
  ptr->nbClients = nb;
  return (true);
}
