/*
** core.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/core
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:01:27 2017 Dylan Deu
** Last update Mon Jun 26 15:01:30 2017 Dylan Deu
*/

#ifndef PSU_2016_ZAPPY_CORE_H
#define PSU_2016_ZAPPY_CORE_H

#include		"game/client.h"

int			get_max_fd(t_game *, fd_set *);
int			make_select(t_game *, fd_set *);
bool			prepare_cmd(t_game *, t_client *, int);
void			check_death(t_game *);
void			check_actions(t_game *);
void			check_eggs(t_game *);
void			init_cmd(t_game *, t_client *, char *);
bool			graph_init(t_game *, t_client *, char *);
bool			check_victory(t_game *);
bool			get_client_tab(t_game *, t_client *);
bool			get_graphical_tab(t_game *);
bool			treat_client_cmd(t_game *, t_client *, char *);
bool			add_team(t_game *, t_client *, char *);
void			treat_graphical_cmd(t_game *, char *);
void			exec_look(t_game *, t_client *, char *);
void			check_level(t_game *);
void			clean_game(t_game *);
int			core(t_game *);
void			free_cmd(char **, char *);
void			check_generate(t_game *);
char			*get_case(t_game *, t_client *, int, int);
char			**get_tab(char *);

#endif /* !PSU_2016_ZAPPY_CORE_H_ */
