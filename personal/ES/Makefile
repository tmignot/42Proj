OS=				$(shell uname)
CC=				gcc
OBJ_CFLAGS=		-fPIC
MODULE_NAME=	threadlaunch
SRC_DIR=		src
OBJ_DIR=		obj
SRC=			$(wildcard $(SRC_DIR)/*/*.c)
OBJ=			$(subst $(SRC_DIR)/,$(OBJ_DIR)/,$(SRC:.c=.o))
WRAPPERS_DIR=	wrappers
WRAPPERS=		$(subst $(WRAPPERS_DIR),$(SRC_DIR),$(subst .i,_wrap.c,$(wildcard $(WRAPPERS_DIR)/*/*.i)))

IDIR_LOCAL=		include
IDIR_EXTERNAL=
IFILES=			$(wildcard $(IDIR_LOCAL)/*/*.h $(IDIR_LOCAL)/*/*.hpp)

LIB_CFLAGS=
LIB_EXTENSION=

ifeq ($(OS), Linux)
LIB_DIR=		lib/x86_64-linux
LIB_EXTENSION=so
IDIR_EXTERNAL=/usr/local/include/ruby-2.1.0/ \
	 /usr/local/include/ruby-2.1.0/x86_64-linux
LIB_CFLAGS=-shared -lc -lpthread
RUBY_BIN=ruby
SUDO=sudo
endif

ifeq ($(OS), Darwin)
LIB_DIR=	  lib/x86_64-darwin14
LIB_EXTENSION=bundle
IDIR_EXTERNAL=$(HOME)/.brew/Cellar/ruby/2.2.0/include/ruby-2.2.0/x86_64-darwin14 \
		   	  $(HOME)/.brew/Cellar/ruby/2.2.0/include/ruby-2.2.0 
LIB_CFLAGS=-bundle -flat_namespace -undefined suppress
RUBY_BIN=$(HOME)/.brew/Cellar/ruby/2.2.0/bin/ruby
SUDO=
endif

LIB_NAME=		$(MODULE_NAME).$(LIB_EXTENSION)

all: lib

wrap: $(WRAPPERS)

objects: wrap $(OBJ)

lib: objects $(LIB_DIR)/$(LIB_NAME)


$(SRC_DIR)/%_wrap.c: $(WRAPPERS_DIR)/%.i Makefile $(IFILES)
	swig -ruby -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(IFILES)
	$(CC) -o $@ -c $< $(OBJ_CFLAGS) $(addprefix -I,$(IDIR_LOCAL) $(IDIR_EXTERNAL))

$(LIB_DIR)/$(LIB_NAME): $(OBJ)
	$(CC) $(LIB_CFLAGS) $^ -o $@

clean:
	rm -f $(WRAPPERS) $(OBJ)

fclean: clean
	rm -f $(LIB_DIR)/$(LIB_NAME)

re: fclean all


.PHONY: all wrap objects lib module clean fclean re
