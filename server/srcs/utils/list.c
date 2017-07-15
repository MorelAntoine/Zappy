/*
** list.c for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:08:32 2017 Dylan Deu
** Last update Mon Jun 26 15:08:33 2017 Dylan Deu
*/

#include	<stdlib.h>
#include	"utils/list.h"

t_list	*list_create(void)
{
  t_list	*list;

  list = malloc(sizeof(t_list));
  if (!list)
    return (NULL);
  list->it = NULL;
  list->first_node = NULL;
  return (list);
}

void	list_delete(t_list *list, bool d)
{
  t_list_node	*node;
  t_list_node	*tmp;

  if (!list)
    return ;
  node = list->first_node;
  while (node)
    {
      tmp = node;
      node = node->next;
      if (d)
	free(tmp->data);
      free(tmp);
    }
  free(list);
}

bool	list_push_back(t_list *list, void *data)
{
  t_list_node	*node;
  t_list_node	*tmp;

  if (!list)
    return (false);
  node = malloc(sizeof(t_list_node));
  if (!node)
    return (false);
  node->next = NULL;
  node->data = data;
  tmp = list->first_node;
  if (!tmp)
    {
      list->first_node = node;
      return (true);
    }
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = node;
  return (true);
}

static bool	clean_node(t_list_node *node, bool d)
{
  if (d)
    free(node->data);
  free(node);
  return (true);
}

bool	list_delete_node(t_list *list, void *data, bool d)
{
  t_list_node	*node;
  t_list_node	*tmp;

  if (!list || !data)
    return (false);
  node = list->first_node;
  if (!node)
    return (false);
  while (node && node->data != data)
    node = node->next;
  if (!node)
    return (false);
  if (node == list->it)
    list->it = node->next;
  if (node == list->first_node)
    {
      list->first_node = node->next;
      return (clean_node(node, d));
    }
  node = list->first_node;
  while (node->next->data != data)
    node = node->next;
  tmp = node->next;
  node->next = tmp->next;
  return (clean_node(tmp, d));
}
