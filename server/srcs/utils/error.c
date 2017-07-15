/*
** error.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Thu Jun 15 11:06:08 2017 Dylan Deu
** Last update Thu Jun 15 11:06:08 2017 Dylan Deu
*/

#include		<stdio.h>

int			my_error(const char *error)
{
  fprintf(stderr, "Error: %s\n", error);
  return (1);
}
