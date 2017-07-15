/*
** queue_member.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/player_actions
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:03:49 2017 Dylan Deu
** Last update Mon Jun 26 15:03:50 2017 Dylan Deu
*/

#ifndef		QUEUE_MEMBER_H_
# define	QUEUE_MEMBER_H_

# include	"player_actions/actions.h"

typedef struct	s_queue_member
{
  int				action;
  t_client			*client;
  char				*cmd;
  unsigned long long int	time;
}		t_queue_member;

#endif
