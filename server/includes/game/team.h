/*
** team.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/game
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:02:27 2017 Dylan Deu
** Last update Mon Jun 26 15:02:27 2017 Dylan Deu
*/

#ifndef		GAME_TEAM_H_
# define	GAME_TEAM_H_

# include	"game/game.h"

typedef struct	s_team
{
  char		*name;
  int		nb_player_max_level;
  unsigned int	max_level;
  unsigned int	nb_players;
  unsigned int	max_clients;
}		t_team;

t_team	*team_init(char *, t_game *);
void	team_delete(t_team *);

#endif
