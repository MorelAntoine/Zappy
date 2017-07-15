/*
** left.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/player_actions
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:04:13 2017 Dylan Deu
** Last update Mon Jun 26 15:04:14 2017 Dylan Deu
*/

#ifndef		PLAYER_ACTION_LEFT_H_
# define	PLAYER_ACTION_LEFT_H_

# include	"player_actions/actions.h"

static bool	turn_left(t_client *client);
static bool	turn_bottom(t_client *client);
static bool	turn_top(t_client *client);
static bool	turn_right(t_client *client);

static bool	(*g_turn[])(t_client *) =
{
  NULL,
  turn_left,
  turn_top,
  turn_right,
  turn_bottom
};

#endif
