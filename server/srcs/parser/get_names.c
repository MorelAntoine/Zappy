/*
** get_names.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed Jun 14 14:22:45 2017 Dylan Deu
** Last update Wed Jun 14 14:22:45 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<string.h>
#include		"parser/parse.h"

static bool		search_name(t_list *names, char *name)
{
  char			*elem;

  elem = list_get_first(names);
  while (elem)
  {
    if (strcmp(elem, name) == 0)
    {
      fprintf(stderr, "\n-n option only accepts unique team names\n\n");
      return (false);
    }
    elem = list_get_next(names);
  }
  return (true);
}

bool			get_names(t_parse *ptr, int *pos, char **av, int ac)
{
  char			*name;

  *pos = *pos + 1;
  if (*pos >= ac)
  {
    fprintf(stderr, "%s: option requires an argument -- 'n'\n\n", av[0]);
    return (false);
  }
  while (*pos < ac && av[*pos][0] != '-')
  {
    if (ptr->name == NULL)
      ptr->name = list_create();
    name = strdup(av[*pos]);
    if (search_name(ptr->name, name) == false)
      return (false);
    if (list_push_back(ptr->name, name) == false)
      return (false);
    *pos = *pos + 1;
  }
  *pos = *pos - 1;
  return (true);
}
