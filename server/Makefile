##
## Makefile for zappy in /mnt/d/Projects/C/PSU_2016_zappy/server
## 
## Made by DESKTOP-DHNB9O5
## Login   <antoine.morel@epitech.eu>
## 
## Started on  Tue Jun 13 09:17:52 2017 DESKTOP-DHNB9O5
## Last update Sun Jul  2 20:52:45 2017 Dylan Deu
##

NAME			=	../zappy_server

SRCS			=	srcs/main.c \
				srcs/game/game.c \
				srcs/game/map.c \
				srcs/game/box.c \
				srcs/game/client.c \
				srcs/game/stone_list.c \
				srcs/game/team.c \
				srcs/game/resources.c \
				srcs/graphic_actions/bct.c \
				srcs/graphic_actions/mct.c \
				srcs/graphic_actions/pin.c \
				srcs/graphic_actions/msz.c \
				srcs/graphic_actions/plv.c \
				srcs/graphic_actions/ppo.c \
				srcs/graphic_actions/sgt.c \
				srcs/graphic_actions/sst.c \
				srcs/graphic_actions/graphic.c \
				srcs/graphic_actions/tna.c \
				srcs/players_actions/forward.c \
				srcs/players_actions/left.c \
				srcs/players_actions/right.c \
				srcs/players_actions/look.c \
				srcs/players_actions/inventory.c \
				srcs/players_actions/take.c \
				srcs/players_actions/take_part_two.c \
				srcs/players_actions/set.c \
				srcs/players_actions/set_part_two.c \
				srcs/players_actions/incantation.c \
				srcs/players_actions/connect_nbr.c \
				srcs/players_actions/update_team.c \
				srcs/players_actions/eject.c \
				srcs/players_actions/take_treat.c \
				srcs/players_actions/send_eject.c \
				srcs/players_actions/death.c \
				srcs/players_actions/broadcast.c \
				srcs/players_actions/fork.c \
				srcs/players_actions/look_part_two.c \
				srcs/utils/list.c \
				srcs/utils/list_it.c \
				srcs/utils/shared_memory.c \
				srcs/utils/delete_shared_memory.c \
				srcs/utils/sem.c \
				srcs/utils/nbr.c \
				srcs/utils/error.c \
				srcs/utils/socket.c \
				srcs/utils/time.c \
				srcs/utils/tab.c \
				srcs/utils/my_send.c \
				srcs/parser/get_freq.c \
				srcs/parser/get_height.c \
				srcs/parser/get_width.c \
				srcs/parser/get_names.c \
				srcs/parser/get_nb_clients.c \
				srcs/parser/get_port.c \
				srcs/parser/parse.c \
				srcs/core/add_team.c \
				srcs/core/core.c \
				srcs/core/clean_game.c \
				srcs/core/close_client.c \
				srcs/core/graph_init.c \
				srcs/core/check_level.c \
				srcs/core/regenerate_ressources.c \
				srcs/core/check_victory.c \
				srcs/core/init_cmd.c \
				srcs/core/get_max_fd.c \
				srcs/core/get_tab.c \
				srcs/core/connection.c \
				srcs/core/accept_connection.c \
				srcs/core/add_new_client.c \
				srcs/core/select.c \
				srcs/core/get_cmd.c \
				srcs/core/prepare_cmd.c \
				srcs/core/exec_actions.c \
				srcs/buffer/buff_read.c \
				srcs/buffer/buff_write.c \
				srcs/buffer/get_free_size.c \
				srcs/buffer/init_buffer.c \
				srcs/buffer/is_end_cmd.c \
				srcs/buffer/get_nb_cmd.c

OBJS			=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS			=	-W -Wall -Wextra -D_GNU_SOURCE=1

CFLAGS			+=	-I ./includes/

RM			=	rm -rf

all			:	$(NAME)

$(NAME)			:	$(OBJS)
				$(CC) -o $(NAME) $(OBJS)

clean			:
				$(RM) $(OBJS)
				find . -name "*~" -print0 | xargs -0 $(RM)

fclean			:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY			:	all clean fclean re
