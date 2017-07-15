/*
** tab.c for PSU_2016_zappy in /home/dylan/Documents/TEK2/PSU_2016_zappy
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed Jun 28 13:25:47 2017 Dylan Deu
** Last update Wed Jun 28 13:25:47 2017 Dylan Deu
*/

#include		<string.h>
#include		<stdlib.h>

static unsigned int	get_tab_size(char *cmd)
{
  unsigned int		index;
  unsigned int		size;

  index = 0;
  size = 0;
  while (cmd[index])
  {
    if (cmd[index] == '\n')
      size++;
    index++;
  }
  return (size);
}

static void		copy_cmd(char **tab, char *cmd, unsigned int index,
				    unsigned int *index_str)
{
  unsigned int		index_tab_str;

  index_tab_str = 0;
  while (cmd[*index_str] != '\0' && cmd[*index_str] != '\n')
  {
    tab[index][index_tab_str] = cmd[*index_str];
    *index_str = *index_str + 1;
    index_tab_str++;
  }
  tab[index][index_tab_str] = '\0';
  *index_str = *index_str + 1;
}

void			free_cmd(char **tab, char *cmd)
{
  unsigned int		index;

  index = 0;
  if (cmd)
    free(cmd);
  if (tab == NULL)
    return ;
  while (tab[index])
  {
    free(tab[index]);
    index++;
  }
  free(tab);
}

char			**get_tab(char *cmd)
{
  char			**tab;
  unsigned int		index_str;
  unsigned int		index;
  unsigned int		size;

  index = 0;
  index_str = 0;
  size = get_tab_size(cmd);
  tab = malloc(sizeof(char *) * (size + 1));
  if (tab == NULL)
    return (NULL);
  while (index < size)
  {
    tab[index] = malloc(sizeof(char) * (strlen(cmd) + 1));
    if (tab[index] == NULL)
    {
      free(tab);
      return (NULL);
    }
    copy_cmd(tab, cmd, index, &index_str);
    index++;
  }
  tab[index] = NULL;
  return (tab);
}
