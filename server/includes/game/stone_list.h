/*
** stone_list.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/game
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:02:20 2017 Dylan Deu
** Last update Mon Jun 26 15:02:21 2017 Dylan Deu
*/

#ifndef		GAME_STONE_LIST_H_
# define	GAME_STONE_LIST_H_

typedef struct	s_stone_list
{
  unsigned int	linemate;
  unsigned int	deraumere;
  unsigned int	sibur;
  unsigned int	mendiane;
  unsigned int	phiras;
  unsigned int	thystame;
}		t_stone_list;

t_stone_list	*stone_list_create(void);
void		stone_list_delete(t_stone_list *);

#endif
