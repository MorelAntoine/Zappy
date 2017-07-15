/*
** forward.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/player_actions
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:04:07 2017 Dylan Deu
** Last update Mon Jun 26 15:04:07 2017 Dylan Deu
*/

#ifndef		PLAYER_ACTION_FORWARD_H_
# define	PLAYER_ACTION_FORWARD_H_

# include	"player_actions/actions.h"

static bool	go_left(t_game *game, t_client *client);
static bool	go_right(t_game *game, t_client *client);
static bool	go_bottom(t_game *game, t_client *client);
static bool	go_top(t_game *game, t_client *client);

static bool	(*g_go[])(t_game *, t_client *) =
{
  NULL,
  go_top,
  go_right,
  go_bottom,
  go_left
};

#endif
