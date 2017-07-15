/*
** buff_read.c for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:06:18 2017 Dylan Deu
** Last update Mon Jun 26 15:06:19 2017 Dylan Deu
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		"buffer/circular_buffer.h"

char			*buff_read(t_buff *buf)
{
  char			*str;
  size_t		index;
  size_t		size_str;

  index = 0;
  size_str = get_read_size(buf);
  if (size_str == 0)
    return (NULL);
  str = malloc(sizeof(char) * (size_str + 1));
  if (str == NULL)
  {
    fprintf(stderr, "Error: Malloc fail\n");
    return (NULL);
  }
  memset(str, 0, size_str);
  while (index < size_str)
  {
    str[index] = buf->buf[buf->ird];
    buf->ird = (buf->ird + 1) % BUFF_SIZE;
    index++;
  }
  str[index] = '\0';
  return (str);
}
