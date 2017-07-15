/*
** set.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/player_actions
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:03:54 2017 Dylan Deu
** Last update Mon Jun 26 15:03:54 2017 Dylan Deu
*/

#ifndef		PLAYER_ACTIONS_SET_H_
# define	PLAYER_ACTIONS_SET_H_

# include	"player_actions/actions.h"

static char	*g_list_objects[] =
  {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"
  };

static bool	set_food(t_game *, t_client *);
static bool	set_linemate(t_game *, t_client *);
static bool	set_deraumere(t_game *, t_client *);
bool		set_sibur(t_game *, t_client *);
bool		set_mendiane(t_game *, t_client *);
bool		set_phiras(t_game *, t_client *);
bool		set_thystame(t_game *, t_client *);

static bool	(*g_list_actions[])(t_game  *game, t_client *client) =
{
  set_food,
  set_linemate,
  set_deraumere,
  set_sibur,
  set_mendiane,
  set_phiras,
  set_thystame
};

#endif
