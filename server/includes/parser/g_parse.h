/*
** g_parse.h for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server/includes/parser
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:03:05 2017 Dylan Deu
** Last update Mon Jun 26 15:03:06 2017 Dylan Deu
*/

#ifndef PSU_2016_ZAPPY_G_PARSE_H
#define PSU_2016_ZAPPY_G_PARSE_H

#include		"parser/parse.h"

char			*g_parser[7] =
  {
    "-p",
    "-x",
    "-y",
    "-n",
    "-c",
    "-f",
    NULL
  };

bool			(*g_parser_ptr[7])(t_parse *, int *, char **, int) =
  {
    &get_port,
    &get_width,
    &get_height,
    &get_names,
    &get_nb_clients,
    &get_freq,
    NULL
  };

#endif /* !PSU_2016_ZAPPY_G_PARSE_H_ */
