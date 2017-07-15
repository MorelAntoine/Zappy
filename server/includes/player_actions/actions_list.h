/*
** actions_list.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/player_actions
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:04:00 2017 Dylan Deu
** Last update Mon Jun 26 15:04:01 2017 Dylan Deu
*/

#ifndef		PLAYERS_ACTIONS_ACTIONS_LIST_H_
# define	PLAYERS_ACTIONS_ACTIONS_LIST_H_

# include	"player_actions/actions.h"

static char		*g_actions_name[] =
  {
    "Forward",
    "Right",
    "Left",
    "Look",
    "Inventory",
    "Broadcast",
    "Connect_nbr",
    "Fork",
    "Eject",
    "Take",
    "Set",
    "Incantation",
    NULL
  };

static unsigned long long int	g_actions_time[] =
  {
    7,
    7,
    7,
    7,
    1,
    7,
    0,
    42,
    7,
    7,
    7,
    300
  };

static player_action	g_actions[] =
  {
    forward,
    right,
    left,
    look,
    inventory,
    broadcast_text,
    connect_nbr,
    game_fork,
    eject,
    take,
    set,
    incantation,
    NULL
  };

#endif
