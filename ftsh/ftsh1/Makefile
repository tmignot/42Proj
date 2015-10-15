
###  MAIN  ###
main_include_dir=include
main_src_dir=src
main_obj_dir=obj
main_outfile=ftsh1

### EXTERNAL LIBS  ###
ext_libs=libft lxpr

###  LIBFT  ###
libft_include_dir=libft
libft_static_dir=libft

###  LXPR  ###
lxpr_include_dir=lxpr/include
lxpr_static_dir=lxpr/lib

###  CC  ###
cc=gcc
cc_flags=-g -Wall -Wextra -Werror
cc_include=`for i in $(ext_libs); do echo "-I $(i)_include_dir"; done`
cc_lib=`for i in $(ext_libs); do echo "-I $(i)_static_dir"; done`

all: $(main_outfile)

$(main_outfile): $(main_obj)
	$(cc) $(cc_flags) $(cc_include) $(cc_lib) @^ -o $(cc_outfile)

re:

clean:

fclean:
