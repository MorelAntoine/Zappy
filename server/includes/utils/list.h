/*
** list.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/utils
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:04:54 2017 Dylan Deu
** Last update Mon Jun 26 15:04:55 2017 Dylan Deu
*/

#ifndef		LIST_H_
# define	LIST_H_

# include	<stdlib.h>
# include	"utils/bool.h"

typedef struct	s_list_node
{
  void			*data;
  struct s_list_node	*next;
}		t_list_node;

typedef struct	s_list
{
  t_list_node	*first_node;
  t_list_node	*it;
}		t_list;

t_list	*list_create(void);
void	list_delete(t_list *, bool);
bool	list_push_back(t_list *, void *data);
bool	list_delete_node(t_list *, void *data, bool);
void	*list_get_first(t_list *);
void	*list_get_next(t_list *);
size_t	list_size(t_list *);

#endif
