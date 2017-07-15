/*
** client.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/game
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:01:55 2017 Dylan Deu
** Last update Mon Jun 26 15:01:56 2017 Dylan Deu
*/

#ifndef		GAME_CLIENT_H_
# define	GAME_CLIENT_H_

# include	"game/stone_list.h"
#include	"game/game.h"
#include	"game/team.h"
#include	"buffer/circular_buffer.h"
# include	"utils/bool.h"

typedef enum
  {
    ORIENTATION_NORTH = 1,
    ORIENTATION_EST = 2,
    ORIENTATION_SOUTH = 3,
    ORIENTATION_WEST = 4
  }	e_orientation;

typedef struct	s_client
{
  int		fd;
  t_team	*team;
  bool		disconnect;
  unsigned int	level;
  t_stone_list	*stones;
  unsigned long long int	time_death;
  unsigned int	pos_y;
  unsigned int	pos_x;
  e_orientation	pos_orientation;
  t_buff	*buffer;
  unsigned int	id;
}		t_client;

t_client	*client_init(int, t_game *);
void		client_delete(t_client *, bool);
bool		client_is_auth(t_client *);
bool		get_client_cmd(t_game *, t_client *);
bool		get_graphical_cmd(t_game *);
bool		close_client(t_game *, t_client *);

#endif
