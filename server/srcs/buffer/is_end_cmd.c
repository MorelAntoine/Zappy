/*
** is_end_cmd.c for zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy/server
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Mon Jun 26 15:07:39 2017 Dylan Deu
** Last update Mon Jun 26 15:07:40 2017 Dylan Deu
*/

#include		"buffer/circular_buffer.h"

bool			is_crlf(t_buff *buff)
{
  int			pos;

  pos = buff->iwr - 1;
  if (pos < 0)
    pos = BUFF_SIZE - 1;
  if (buff->buf[pos] == '\n')
  {
    pos -= 1;
    if (pos < 0)
      pos = BUFF_SIZE - 1;
    if (buff->buf[pos] == '\r')
      return (true);
  }
  return (false);
}

bool			is_lf(t_buff *buff)
{
  int			pos;

  pos = buff->iwr - 1;
  if (pos < 0)
    pos = BUFF_SIZE - 1;
  if (buff->buf[pos] == '\n')
  {
    return (true);
  }
  return (false);
}
