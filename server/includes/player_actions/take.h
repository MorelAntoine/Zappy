/*
** take.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/player_actions
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:04:25 2017 Dylan Deu
** Last update Mon Jun 26 15:04:25 2017 Dylan Deu
*/

#ifndef		PLAYER_ACTIONS_TAKE_H_
# define	PLAYER_ACTIONS_TAKE_H_

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

bool		take_food(t_game *, t_client *);
bool		take_linemate(t_game *, t_client *);
bool		take_deraumere(t_game *, t_client *);
bool		take_sibur(t_game *, t_client *);
bool		take_mendiane(t_game *, t_client *);
bool		take_phiras(t_game *, t_client *);
bool		take_thystame(t_game *, t_client *);

static bool	(*g_list_actions[])(t_game  *game, t_client *client) =
{
  take_food,
  take_linemate,
  take_deraumere,
  take_sibur,
  take_mendiane,
  take_phiras,
  take_thystame
};

#endif
