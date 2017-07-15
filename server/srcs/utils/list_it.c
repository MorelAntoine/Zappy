/*
** list_it.c for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:07:53 2017 Dylan Deu
** Last update Mon Jun 26 15:08:20 2017 Dylan Deu
*/

#include	"utils/list.h"

size_t	list_size(t_list *list)
{
  t_list_node	*node;
  size_t	size;

  if (!list)
    return (0);
  size = 0;
  node = list->first_node;
  while (node)
    {
      node = node->next;
      size++;
    }
  return (size);
}

void	*list_get_first(t_list *list)
{
  void	*tmp;

  if (!list)
    return (NULL);
  list->it = list->first_node;
  if (!list->it)
    return (NULL);
  tmp = list->it->data;
  return (tmp);
}

void	*list_get_next(t_list *list)
{
  void	*tmp;

  if (!list)
    return (NULL);
  if (!list->it)
    return (NULL);
  if (!list->it->next)
    tmp = NULL;
  else
    tmp = list->it->next->data;
  list->it = list->it->next;
  return (tmp);
}
