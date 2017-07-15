/*
** box.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/game
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:01:50 2017 Dylan Deu
** Last update Mon Jun 26 15:01:51 2017 Dylan Deu
*/

#ifndef		GAME_BOX_H_
# define	GAME_BOX_h_

# include	"game/stone_list.h"

typedef struct	s_box
{
  t_stone_list	*stones;
  unsigned int	food;
}		t_box;

t_box		*box_init(void);
void		box_delete(t_box *);

#endif
