/*
** get_cmd.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Thu Jun 15 18:25:13 2017 Dylan Deu
** Last update Thu Jun 15 18:25:13 2017 Dylan Deu
*/

#include		<unistd.h>
#include		<string.h>
#include		"game/client.h"
#include		"utils/time.h"
#include		"utils/send.h"
#include		"core/core.h"
#include		"graphic_actions/actions_list.h"
#include		"player_actions/actions_list.h"

bool		treat_client_cmd(t_game *game, t_client *client,
					    char *cmd)
{
  char			*token;

  (void)g_actions_time;
  (void)g_actions;
  (void)g_actions_name;
  token = strtok(cmd, " ");
  if (token == NULL && client->disconnect == false)
    my_send(client->fd, "ko\n");
  else if (strcmp(g_graphic_actions_name[0], token) == 0 &&
	   game->graph_client < 0)
  {
    if (graph_init(game, client, cmd) == false)
      return (false);
  }
  else if (client->team == NULL)
  {
    if (add_team(game, client, token) == false)
      client->disconnect = true;
  }
  else
    init_cmd(game, client, token);
  return (true);
}

void		treat_graphical_cmd(t_game *game, char *cmd)
{
  int			index;
  char			*token;
  char			*next_cmd;

  index = 0;
  token = strtok(cmd, " ");
  if (!token)
    my_send(game->graph_client, "ko");
  else
  {
    while (g_graphic_actions_name[index])
    {
      if (strcmp(g_graphic_actions_name[index], token) == 0)
      {
	next_cmd = strtok(NULL, "\0");
	if (next_cmd == NULL)
	  (g_graphic_actions[index])(game, "");
	else
	  (g_graphic_actions[index])(game, next_cmd);
      }
      index++;
    }
    if (g_graphic_actions_name[index] == NULL)
      my_send(game->graph_client, "ko\n");
  }
}

bool			get_client_cmd(t_game *game, t_client *client)
{
  bool			value;
  ssize_t		size;
  char			buff[BUFF_SIZE];
  size_t		rd_size;

  memset(buff, 0, BUFF_SIZE);
  rd_size = get_free_size(client->buffer);
  size = read(client->fd, buff, rd_size);
  if (size <= 0)
    return (close_client(game, client));
  else
  {
    if (get_nb_cmd(client->buffer) < 10)
      buff_write(client->buffer, buff, size);
    if (is_lf(client->buffer) == true)
    {
      value = get_client_tab(game, client);
      if (value == true)
	return (true);
      else if (value == false)
	return (false);
    }
  }
  return (true);
}

bool			get_graphical_cmd(t_game *game)
{
  char			buff[BUFF_SIZE];
  size_t 		rd_size;
  ssize_t		size;

  memset(buff, 0, BUFF_SIZE);
  rd_size = get_free_size(game->buff);
  size = read(game->graph_client, buff, rd_size);
  if (size <= 0)
    close_graphic(game);
  else
  {
    if (get_nb_cmd(game->buff) < 10)
      buff_write(game->buff, buff, size);
    if (is_lf(game->buff) == true)
    {
      if (get_graphical_tab(game) == true)
	return (true);
    }
  }
  return (true);
}
