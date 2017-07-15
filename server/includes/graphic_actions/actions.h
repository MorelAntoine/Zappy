/*
** actions.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/graphic_actions
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:02:42 2017 Dylan Deu
** Last update Mon Jun 26 15:02:42 2017 Dylan Deu
*/

#ifndef		GRAPHIC_ACTIONS_H_
# define	GRAPHIC_ACTIONS_H_

# include	"game/game.h"

typedef bool	(*graphic_action)(t_game *, char *);

bool	msz(t_game *, char *);
bool	bct(t_game *, char *);
bool	mct(t_game *, char *);
bool	tna(t_game *, char *);
bool	ppo(t_game *, char *);
bool	plv(t_game *, char *);
bool	pin(t_game *, char *);
bool	sgt(t_game *, char *);
bool	sst(t_game *, char *);
bool	graphic(t_game *, char *);
void		close_graphic(t_game *);

bool	bct_case(t_game *, int, int);

#endif
