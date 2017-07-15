/*
** egg.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/game
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:02:02 2017 Dylan Deu
** Last update Mon Jun 26 15:02:02 2017 Dylan Deu
*/

#ifndef		GAME_EGG_H_
# define	GAME_EGG_H_

# include	"game/team.h"

typedef struct	s_egg
{
  unsigned long long int	time_death;
  unsigned int			y;
  unsigned int			x;
  t_team			*team;
  unsigned int			id;
}		t_egg;

#endif
