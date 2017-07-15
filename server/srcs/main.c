/*
** main.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed Jun 14 08:58:04 2017 Dylan Deu
** Last update Wed Jun 14 08:58:04 2017 Dylan Deu
*/

#include		<string.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		"parser/parse.h"
#include		"utils/error.h"
#include		"game/client.h"

static bool		prepare_game(t_game *game, t_parse *parser)
{
  char			*name;

  name = (char *)(list_get_first(parser->name));
  while (name != NULL)
  {
    if (game_add_team(game, name) == false)
      return (false);
    name = (char *)(list_get_next(parser->name));
  }
  game->max_players_team = parser->nbClients;
  game->f = parser->freq;
  return (true);
}

static int		print_usage(const char *bin)
{
  fprintf(stderr, "USAGE: %s -p port -x width -y height -n name1 name2 ... -c",
	  bin);
  fprintf(stderr, " nbClients -f freq\n");
  fprintf(stderr, "\tport\tis the port number\n");
  fprintf(stderr, "\twidth\tis the width of the world\n");
  fprintf(stderr, "\theight\tis the height of the world\n");
  fprintf(stderr, "\tnameX\tis the name of the team X\n");
  fprintf(stderr, "\tnbClients\tis the number of authorized ");
  fprintf(stderr, "clients per item\n");
  fprintf(stderr, "\tfreq\tis the time for the limit execution of actions\n\n");
  return (1);
}

int			main(int ac, char **av)
{
  t_game		*game;
  t_parse		*parser;

  if (ac > 1 && strcmp(av[1], "--help") == 0)
    return (print_usage(av[0]));
  parser = parse_init();
  if (parse_args(ac, av, parser) == false)
    return (print_usage(av[0]));
  if (check_args(parser) == false)
    return (print_usage(av[0]));
  game = game_init(parser->height, parser->width);
  if (prepare_game(game, parser) == false)
    return (my_error("Can't add teams"));
  if (init_connection(game, parser->port) == false)
    return (1);
  parse_delete(parser);
  core(game);
  game_delete(game);
  return (EXIT_SUCCESS);
}
