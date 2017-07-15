##
## Makefile for zappy in /mnt/d/Projects/C/PSU_2016_zappy
## 
## Made by DESKTOP-DHNB9O5
## Login   <antoine.morel@epitech.eu>
## 
## Started on  Tue Jun 13 09:13:15 2017 DESKTOP-DHNB9O5
## Last update Sun Jul  2 23:17:11 2017 Dylan Deu
##

all			:	zappy_ai zappy_server

zappy_ai		:
				make -C ai/

zappy_server		:
				make -C server/

clean			:
				make -C ai/ clean
				make -C server/ clean

fclean			:	clean
				make -C ai/ fclean
				make -C server/ fclean

re			:	fclean all

.PHONY			:	all clean fclean re
