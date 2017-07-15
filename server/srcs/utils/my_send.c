/*
** mysend.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Sun Jul 02 19:27:29 2017 Dylan Deu
** Last update Sun Jul 02 19:27:29 2017 Dylan Deu
*/

#include	<stdarg.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	"utils/send.h"

int		my_send(int fd, char *str, ...)
{
  va_list	list;
  char		*buff;

  va_start(list, str);
  buff = NULL;
  vasprintf(&buff, str, list);
  send(fd, buff, strlen(buff), 0);
  free(buff);
  va_end(list);
  return (1);
}
