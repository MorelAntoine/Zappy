/*
** regenerate_ressources.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Sat Jul 01 17:44:58 2017 Dylan Deu
** Last update Sat Jul 01 17:44:58 2017 Dylan Deu
*/

#include			<stdio.h>
#include			"utils/time.h"
#include			"utils/send.h"
#include			"game/game.h"

static void			regenerate_ressources(t_game *game)
{
  int				x;
  int				y;
  t_box				*box;

  x = rand() % game->map->width;
  y = rand() % game->map->height;
  box = game->map->content[y * game->map->width + x];
  generate_resources_case(box);
  if (game->graph_client > 0)
    my_send(game->graph_client, "bct %d %d %u %u %u %u %u %u %u\n", x, y,
	    box->food, box->stones->linemate,
	    box->stones->deraumere, box->stones->sibur,
	    box->stones->mendiane, box->stones->phiras,
	    box->stones->thystame);
}

static void			generate_resources_food(t_box *box)
{
  box->food += rand() % 10;
}

static void			regenerate_food(t_game *game)
{
  unsigned int			loop;
  int				x;
  int				y;
  t_box				*box;

  loop = 0;
  while (loop < 2)
  {
    x = rand() % game->map->width;
    y = rand() % game->map->height;
    box = game->map->content[y * game->map->width + x];
    generate_resources_food(box);
    if (game->graph_client > 0)
      my_send(game->graph_client, "bct %d %d %u %u %u %u %u %u %u\n", x, y,
	      box->food, box->stones->linemate,
	      box->stones->deraumere, box->stones->sibur,
	      box->stones->mendiane, box->stones->phiras,
	      box->stones->thystame);
    loop++;
  }
}

void				check_generate(t_game *game)
{
  unsigned long long int	regenerate;

  regenerate = get_time();
  if (regenerate >= game->regenerate)
  {
    regenerate_ressources(game);
    game->regenerate = get_time() + (100 * 1E6 / game->f);
  }
  if (regenerate >= game->food)
  {
    regenerate_food(game);
    game->food = get_time() + (50 * 1E6 / game->f);
  }
}
