# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/25 13:58:09 by ababdelo          #+#    #+#              #
#    Updated: 2023/06/26 15:04:21 by ababdelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===========================colors============================#
BLACK  = \033[0;30m
RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
BLUE   = \033[0;34m
PURPLE = \033[0;35m
CYAN   = \033[0;36m
GREY   = \033[0;90m
WHITE  = \033[0m
#=============================================================#

#========================variables============================#
PRGM = philo

MAKE_MSG = --->> Mandatory part has been compiled successfully

CLN_MSG = --->> ' .o ' files has been removed successfully

FCLN_MSG = --->> executable file ' $(PRGM) ' has been removed successfully

CC = cc

RM = rm -f

TFLAGS = -lpthread

CFLAGS = -Wall -Wextra -Werror

SRCS = philo.c init.c utils.c timer.c checker.c

OBJS = $(SRCS:.c=.o)
#=============================================================#

#==========================rules==============================#
all :  $(PRGM)

$(PRGM) : $(OBJS)
	@echo "${GREEN}$(MAKE_MSG)${WHITE}"\
	&& $(CC) $(CFLAGS) $(TFLAGS) $(OBJS) -o $(PRGM)

clean :
	@echo "${YELLOW}$(CLN_MSG)${WHITE}"\
	&& $(RM) $(OBJS)

fclean : clean
	@echo "${RED}$(FCLN_MSG)${WHITE}"\
	&& $(RM) $(PRGM)

re : fclean all

.PHONY: all clean fclean re
#=============================================================#