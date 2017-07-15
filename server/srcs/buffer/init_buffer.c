/*
** init_buffer.c for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:06:55 2017 Dylan Deu
** Last update Mon Jun 26 15:06:56 2017 Dylan Deu
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		"buffer/circular_buffer.h"

t_buff			*init_buff()
{
  t_buff		*buf;

  buf = malloc(sizeof(t_buff));
  if (buf == NULL)
  {
    fprintf(stderr, "Error: Malloc fail\n");
    exit(EXIT_FAILURE);
  }
  memset(buf->buf, 0, BUFF_SIZE);
  buf->ird = 0;
  buf->iwr = 0;
  return (buf);
}

void			clean_buff(t_buff *buff)
{
  memset(buff->buf, 0, BUFF_SIZE);
}
