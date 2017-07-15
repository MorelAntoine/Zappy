/*
** parse.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/parser
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:03:11 2017 Dylan Deu
** Last update Mon Jun 26 15:03:12 2017 Dylan Deu
*/

#ifndef PSU_2016_ZAPPY_INIT_H
#define PSU_2016_ZAPPY_INIT_H

#include		"utils/list.h"

typedef struct		s_parse
{
  int			port;
  int			width;
  int			height;
  int			nbClients;
  int			freq;
  t_list		*name;
}			t_parse;

bool			get_freq(t_parse *ptr, int *pos, char **av, int ac);
bool			get_names(t_parse *ptr, int *pos, char **av, int ac);
bool			get_nb_clients(t_parse *ptr, int *pos, char **av,
					   int ac);
bool			get_port(t_parse *ptr, int *pos, char **av, int ac);
bool			get_width(t_parse *ptr, int *pos, char **av, int ac);
bool			get_height(t_parse *ptr, int *pos, char **av, int ac);

t_parse			*parse_init();
void			parse_delete(t_parse *);
bool			parse_args(int, char **, t_parse *);
bool			check_args(t_parse *);

#endif /* !PSU_2016_ZAPPY_INIT_H_ */
