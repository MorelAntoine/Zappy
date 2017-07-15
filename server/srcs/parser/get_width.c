/*
** get_width.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed Jun 14 14:21:32 2017 Dylan Deu
** Last update Wed Jun 14 14:21:32 2017 Dylan Deu
*/

#include		<stdio.h>
#include		"utils/nbr.h"
#include		"parser/parse.h"

bool			get_width(t_parse *ptr, int *pos, char **av, int ac)
{
  int			width;

  *pos = *pos + 1;
  if (*pos >= ac)
  {
    fprintf(stderr, "%s: option requires an argument -- 'x'\n\n", av[0]);
    return (false);
  }
  if (is_pos_num(av[*pos]) == false)
    return (false);
  width = atoi(av[*pos]);
  if (width < 10 || width > 30)
  {
    fprintf(stderr, "\n-x option only accepts integer "
      "values between 10 and 30\n\n");
  }
  ptr->width = width;
  return (true);
}
