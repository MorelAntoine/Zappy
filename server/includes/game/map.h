/*
** map.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/game
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:02:13 2017 Dylan Deu
** Last update Mon Jun 26 15:02:14 2017 Dylan Deu
*/

#ifndef		GAME_MAP_H_
# define	GAME_MAP_H_

# include	"game/box.h"

typedef struct	s_map
{
  unsigned int	height;
  unsigned int	width;
  t_box		**content;
}		t_map;

t_map	*map_init(unsigned int, unsigned int);
void	map_delete(t_map *);

#endif
