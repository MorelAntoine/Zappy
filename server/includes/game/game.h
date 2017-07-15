/*
** game.h for zappt in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/game
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:02:08 2017 Dylan Deu
** Last update Mon Jun 26 15:02:09 2017 Dylan Deu
*/

#ifndef		GAME_GAME_H_
# define	GAME_GAME_H_

# include	"game/map.h"
# include	"utils/list.h"
# include	"buffer/circular_buffer.h"

typedef struct	s_game
{
  int		fd;
  char		*ip;
  t_map		*map;
  t_list	*teams;
  t_list	*clients;
  t_list	*eggs;
  unsigned int	max_players_team;
  unsigned long long int	regenerate;
  unsigned long long int	food;
  int		graph_client;
  unsigned int	f;
  t_list	*queue;
  t_buff	*buff;
}		t_game;

t_game		*game_init(unsigned int height, unsigned int width);
void		game_delete(t_game *);
bool		init_connection(t_game *game, int port);
bool		game_add_team(t_game *, char *);
bool		add_new_client(t_game *game, int fd);
int		get_max_fd(t_game *, fd_set *);
int		make_select(t_game *, fd_set *);
int		core(t_game *);
bool		generate_resources(t_game *);
bool		generate_resources_case(t_box *);

#endif
