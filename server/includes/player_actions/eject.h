/*
** eject.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/player_actions
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:03:37 2017 Dylan Deu
** Last update Mon Jun 26 15:03:38 2017 Dylan Deu
*/

#ifndef		PLAYER_ACTIONS_EJECT_H_
# define	PLAYER_ACTIONS_EJECT_H_

# include	"player_actions/actions.h"

static bool	a_up(t_game *game, t_client *);
static bool	a_right(t_game *game, t_client *);
static bool	a_down(t_game *game, t_client *);
static bool	a_left(t_game *game, t_client *);

static bool	(*g_list_actions[])(t_game *game, t_client *client) =
{
  NULL,
  a_up,
  a_right,
  a_down,
  a_left
};

#endif
