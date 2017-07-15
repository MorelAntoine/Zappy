/*
** get_tab.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed Jun 28 13:42:38 2017 Dylan Deu
** Last update Wed Jun 28 13:42:38 2017 Dylan Deu
*/

#include		<string.h>
#include		"core/core.h"

bool			get_client_tab(t_game *game, t_client *client)
{
  int			index;
  char			*cmd;
  char			**tab;

  index = 0;
  cmd = buff_read(client->buffer);
  if (cmd == NULL)
    return (true);
  tab = get_tab(cmd);
  while (tab[index])
  {
    if (treat_client_cmd(game, client, tab[index]) == false)
      return (false);
    index++;
  }
  free_cmd(tab, cmd);
  return (true);
}

bool			get_graphical_tab(t_game *game)
{
  int			index;
  char			*cmd;
  char			**tab;

  index = 0;
  cmd = buff_read(game->buff);
  if (cmd == NULL)
    return (true);
  tab = get_tab(cmd);
  cmd[strlen(cmd) - 1] = '\0';
  while (tab[index])
  {
    treat_graphical_cmd(game, tab[index]);
    index++;
  }
  free_cmd(tab, cmd);
  return (true);
}
