###  MAIN  ###
main_include_dir=include
main_src_dir=src
main_obj_dir=obj
main_outfile=ftsh1

### EXTERNAL LIBS  ###
ext_libs=libft

###  LIBFT  ###
libft_include_dir=../libft
libft_static_dir=../libft

###  SRC  ###
main_src=chars.c \
	chars_part1.c \
	chars_part2.c \
	chars_part3.c \
	chars_part4.c \
	chars_part5.c \
	groupment.c \
	statehandler.c \
	statehandler_general.c \
	statehandler_general_part1.c \
	state_list.c \
	state_machine.c \
	token_list.c

###  OBJ   ###
main_obj=$(addprefix $(main_obj_dir)/,$(subst .c,.o,$(main_src)))

###  CC  ###
cc=gcc
cc_flags=-g -Wall -Wextra -Werror
cc_include=$(addprefix -I ,$(main_include_dir) $(libft_include_dir))
cc_lib=$(addprefix -L ,$(libft_static_dir))
cc_link=$(subst lib,-l,$(ext_libs))

all: $(main_outfile) $(libft_static_dir)/libft.a

$(main_outfile): $(main_obj)
	make -C $(libft_static_dir)
	$(cc) $^ -o $@ $(cc_lib) $(cc_link) $(cc_flags)

$(main_obj_dir)/%.o:$(main_src_dir)/%.c
	$(cc) -c $< -o $@ $(cc_include) $(cc_flags)

obj: $(main_obj)

re: fclean all

clean:
	rm -f $(main_obj)

fclean: clean
	rm -f $(main_outfile)
