/*
** get_freq.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed Jun 14 14:23:52 2017 Dylan Deu
** Last update Wed Jun 14 14:23:52 2017 Dylan Deu
*/

#include		<stdio.h>
#include		"utils/nbr.h"
#include		"parser/parse.h"

bool			get_freq(t_parse *ptr, int *pos, char **av, int ac)
{
  int			freq;

  *pos = *pos + 1;
  if (*pos >= ac)
  {
    fprintf(stderr, "%s: option requires an argument -- 'f'\n\n", av[0]);
    return (false);
  }
  if (is_pos_num(av[*pos]) == false)
    return (false);
  freq = atoi(av[*pos]);
  if (freq == 0 || freq > 10000)
  {
    fprintf(stderr, "\n-f option only accepts integer "
      "values between 1 and 10000\n\n");
    return (false);
  }
  ptr->freq = freq;
  return (true);
}
