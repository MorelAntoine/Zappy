/*
** incantation.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/player_actions
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:03:43 2017 Dylan Deu
** Last update Mon Jun 26 15:03:44 2017 Dylan Deu
*/

#ifndef		PLAYERS_ACTIONS_INCANTATION_H_
# define	PLAYERS_ACTIONS_INCANTATION_H_

# include	"player_actions/actions.h"
# include	"game/stone_list.h"

static unsigned int	g_list_users[] =
  {
    1,
    2,
    2,
    4,
    4,
    6,
    6
  };

static t_stone_list	g_list_stones[] =
  {
    {1, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0},
    {2, 0, 1, 0, 2, 0},
    {1, 1, 2, 0, 1, 0},
    {1, 2, 1, 3, 0, 0},
    {1, 2, 3, 0, 1, 0},
    {2, 2, 2, 2, 2, 1},
  };

#endif
