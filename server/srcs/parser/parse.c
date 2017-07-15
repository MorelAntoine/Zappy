/*
** parse.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed Jun 14 13:53:51 2017 Dylan Deu
** Last update Wed Jun 14 13:53:51 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<string.h>
#include		"parser/parse.h"
#include		"parser/g_parse.h"

t_parse			*parse_init(void)
{
  t_parse		*new;

  new = malloc(sizeof(t_parse));
  if (new == NULL)
  {
    perror("init_parse()");
    return (NULL);
  }
  new->freq = 100;
  new->height = 20;
  new->width = 20;
  new->nbClients = 100;
  new->port = 4242;
  new->name = NULL;
  return (new);
}

bool			parse_args(int ac, char **av, t_parse *ptr)
{
  int			index;
  unsigned int		pos;

  index = 1;
  while (index < ac)
  {
    pos = 0;
    while (g_parser[pos])
    {
      if (strcmp(g_parser[pos], av[index]) == 0)
      {
	if ((g_parser_ptr[pos])(ptr, &index, av, ac) == false)
	  return (false);
	break;
      }
      pos++;
    }
    if (g_parser[pos] == NULL)
      return (false);
    index++;
  }
  return (true);
}

bool			check_args(t_parse *ptr)
{
  char			*team1;
  char			*team2;

  if (ptr->name == NULL)
  {
    team1 = strdup("Team1");
    team2 = strdup("Team2");
    ptr->name = list_create();
    list_push_back(ptr->name, team1);
    list_push_back(ptr->name, team2);
  }
  return (true);
}

void			parse_delete(t_parse *ptr)
{
  if (ptr->name != NULL)
    list_delete(ptr->name, true);
  if (ptr != NULL)
    free(ptr);
}
