/*
** client.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon Jun 26 14:51:46 2017 Dylan Deu
** Last update Mon Jun 26 14:51:46 2017 Dylan Deu
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<time.h>
#include	"utils/send.h"
#include	"utils/time.h"
#include	"game/client.h"

static void	set_id(t_game *game, t_client *client)
{
  t_client	*tmp;
  unsigned int	n;

  n = 0;
  tmp = list_get_first(game->clients);
  while (tmp)
    {
      n = tmp->id + 1;
      tmp = list_get_next(game->clients);
    }
  client->id = n;
}

static void	init_position_death(t_game *game, t_client *client)
{
  (void)game;
  client->pos_y = 0;
  client->pos_x = 0;
  client->pos_orientation = ORIENTATION_SOUTH;
  client->time_death = get_time() + (1260000000 / game->f);
}

t_client	*client_init(int fd, t_game *game)
{
  t_client	*client;

  if (fd == -1)
    return (NULL);
  client = malloc(sizeof(t_client));
  if (!client)
    return (NULL);
  client->fd = fd;
  client->team = NULL;
  client->level = 1;
  client->disconnect = false;
  client->stones = stone_list_create();
  client->buffer = init_buff();
  if (!client->stones)
    {
      free(client);
      return (NULL);
    }
  set_id(game, client);
  init_position_death(game, client);
  list_push_back(game->clients, client);
  my_send(fd, "WELCOME\n");
  return (client);
}

void		client_delete(t_client *client, bool state)
{
  if (!client)
    return ;
  if (client->stones)
    stone_list_delete(client->stones);
  if (client->buffer)
  {
    free(client->buffer);
    client->buffer = NULL;
  }
  if (state == true)
  {
    close(client->fd);
    client->fd = -1;
  }
  free(client);
}

bool		client_is_auth(t_client *client)
{
  if (!client)
    return (false);
  if (!client->team)
    return (false);
  return (true);
}
