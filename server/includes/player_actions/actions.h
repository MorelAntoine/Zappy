/*
** actions.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/player_actions
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:03:32 2017 Dylan Deu
** Last update Mon Jun 26 15:03:33 2017 Dylan Deu
*/

#ifndef		PLAYER_ACTIONS_H_
# define	PLAYER_ACTIONS_H_

# include	"game/game.h"
# include	"game/client.h"
# include	"game/egg.h"

typedef bool	(*player_action)(t_game *, t_client *, char *);

bool	forward(t_game *, t_client *, char *);
bool	right(t_game *, t_client *, char *);
bool	left(t_game *, t_client *, char *);
bool	look(t_game *, t_client *, char *);
bool	inventory(t_game *, t_client *, char *);
bool	broadcast_text(t_game *, t_client *, char *);
bool	connect_nbr(t_game *, t_client *, char *);
bool	game_fork(t_game *, t_client *, char *);
bool	eject(t_game *, t_client *, char *);
bool	take(t_game *, t_client *, char *);
bool	set(t_game *, t_client *, char *);
bool	incantation(t_game *, t_client *, char *);

bool	start_incantation(t_game *, t_client *);

bool	update_player_team(t_game *, t_client *);

bool	start_fork(t_game *, t_client *);
bool	death_egg(t_game *, t_egg *);
bool	birth_client_from_egg(t_game *game, t_egg *, t_client *);
bool	take_treat(t_game *, t_client *, char *, int);
bool	take_send(t_game *, t_client *);

void	send_eject(t_game *, t_client *, t_client *);

#endif
