/*
** get_height.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed Jun 14 14:22:11 2017 Dylan Deu
** Last update Wed Jun 14 14:22:11 2017 Dylan Deu
*/

#include		<stdio.h>
#include		"utils/nbr.h"
#include		"parser/parse.h"

bool			get_height(t_parse *ptr, int *pos, char **av, int ac)
{
  int			height;

  *pos = *pos + 1;
  if (*pos >= ac)
  {
    fprintf(stderr, "%s: option requires an argument -- 'y'\n\n", av[0]);
    return (false);
  }
  if (is_pos_num(av[*pos]) == false)
    return (false);
  height = atoi(av[*pos]);
  if (height < 10 || height > 30)
  {
    fprintf(stderr, "\n-y option only accepts integer "
      "values between 10 and 30\n\n");
    return (false);
  }
  ptr->height = height;
  return (true);
}
