# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 19:19:00 by tmignot           #+#    #+#              #
#    Updated: 2014/04/19 05:38:14 by tmignot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -O2 -g


OBJ = ft_atoi.o \
	ft_bzero.o \
	ft_isalnum.o \
	ft_isalpha.o \
	ft_isascii.o \
	ft_isdigit.o \
	ft_isprint.o \
	ft_memalloc.o \
	ft_memccpy.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_memcpy.o \
	ft_memdel.o \
	ft_memmove.o \
	ft_memset.o \
	ft_strcat.o \
	ft_strchr.o \
	ft_strichr.o \
	ft_strirchr.o \
	ft_strclr.o \
	ft_strcmp.o \
	ft_strcpy.o \
	ft_strdel.o \
	ft_strdup.o \
	ft_strequ.o \
	ft_striter.o \
	ft_striteri.o \
	ft_strjoin.o \
	ft_strlcat.o \
	ft_strlen.o \
	ft_strmap.o \
	ft_strmapi.o \
	ft_strncat.o \
	ft_strncmp.o \
	ft_strncpy.o \
	ft_strnequ.o \
	ft_strnew.o \
	ft_strnstr.o \
	ft_strrchr.o \
	ft_strsplit.o \
	ft_strstr.o \
	ft_strsub.o \
	ft_strtrim.o \
	ft_tolower.o \
	ft_toupper.o \
	ft_itoa.o \
	ft_putchar.o \
	ft_putchar_fd.o \
	ft_putstr.o \
	ft_putstr_c.o \
	ft_putendl.o \
	ft_putendl_c.o \
	ft_putnbr.o \
	ft_putnbrl.o \
	ft_putnbr_fd.o \
	ft_putnbr_u.o \
	ft_putnbr_u_fd.o \
	ft_putstr_fd.o \
	ft_putendl_fd.o \
	ft_lst_push.o \
	ft_lst_delone_data.o \
	ft_lst_delone_elem.o \
	ft_lst_swap_data.o \
	ft_lstnew.o \
	ft_lstcount.o \
	ft_lstdelone.o \
	ft_lstdel.o \
	ft_lstadd.o \
	ft_lstaddend.o \
	ft_lstiter.o \
	ft_lstmap.o \
	ft_treenew.o \
	ft_xatoi.o \
	ft_xbzero.o \
	ft_xisalnum.o \
	ft_xisalpha.o \
	ft_xisascii.o \
	ft_xisdigit.o \
	ft_xisprint.o \
	ft_xputchar.o \
	ft_xputchar_fd.o \
	ft_xputendl.o \
	ft_xputstr.o \
	ft_xputstr_fd.o \
	ft_xstrclr.o \
	ft_xstrequ.o \
	ft_xstriter.o \
	ft_xstriteri.o \
	ft_xstrjoin.o \
	ft_xstrmap.o \
	ft_xstrmapi.o \
	ft_xstrnequ.o \
	ft_xstrsplit.o \
	ft_xstrsub.o \
	ft_xstrtrim.o

all: $(NAME)

$(NAME):$(OBJ)
	@ar cr $@ $^
	ranlib $@

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<

clean:	
	rm -Rf $(OBJ)

fclean: clean
	rm -Rf libft.a

re: fclean\
	all
