##
## Makefile for zappy in /mnt/d/Projects/C/PSU_2016_zappy/ai
## 
## Made by DESKTOP-DHNB9O5
## Login   <antoine.morel@epitech.eu>
## 
## Started on  Tue Jun 13 09:15:40 2017 DESKTOP-DHNB9O5
## Last update Sun Jul  2 23:43:31 2017 Dylan Deu
##

NAME			=	../zappy_ai

SRCS			=	srcs/main.cpp			\
				srcs/args/get.cpp		\
				srcs/args/lexer.cpp		\
				srcs/automata/manager.cpp	\
				srcs/automata/message.cpp	\
				srcs/automata/request.cpp	\
				srcs/automata/transitor.cpp	\
				srcs/client/Client.cpp		\
				srcs/trantorian/commands.cpp	\
				srcs/trantorian/manager.cpp	\
				srcs/trantorian/tools.cpp

OBJS			=	$(SRCS:.cpp=.o)

CC			=	g++

CXXFLAGS		=	-W -Wall -Wextra -std=c++11

CXXFLAGS		+=	-I ./incs/

RM			=	rm -rf

all			:	$(NAME)

$(NAME)			:	$(OBJS)
				$(CC) -o $(NAME) $(OBJS)

clean			:
				$(RM) $(OBJS)

fclean			:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY			:	all clean fclean re
