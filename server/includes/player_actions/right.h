/*
** right.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/player_actions
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:04:19 2017 Dylan Deu
** Last update Mon Jun 26 15:04:20 2017 Dylan Deu
*/

#ifndef		PLAYER_ACTION_RIGHT_H_
# define	PLAYER_ACTION_RIGHT_H_

# include	"player_actions/actions.h"

static bool	turn_left(t_client *client);
static bool	turn_right(t_client *client);
static bool	turn_bottom(t_client *client);
static bool	turn_top(t_client *client);

static bool	(*g_turn[])(t_client *) =
{
  NULL,
  turn_right,
  turn_bottom,
  turn_left,
  turn_top
};

#endif
