OS=				$(shell uname)
CC=				g++
OBJ_CFLAGS=		-fPIC -std=c++11
SWIG_FLAGS= -ruby -c++ -w401
MODULE_NAME=	ng
SRC_DIR=		src
OBJ_DIR=		obj
SRC=			$(wildcard $(SRC_DIR)/*/*.cpp)
OBJ=			$(subst $(SRC_DIR)/,$(OBJ_DIR)/,$(SRC:.cpp=.o))
WRAPPERS_DIR=	wrappers
WRAPPERS= $(wildcard $(WRAPPERS_DIR)/*/*.i)
#WRAPPERS=		$(subst $(WRAPPERS_DIR),$(SRC_DIR),$(subst .i,_wrap.cpp,$(wildcard $(WRAPPERS_DIR)/*/*.i)))
WRAPPER_OBJ=$(OBJ_DIR)/module_wrap.o

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
LIB_CFLAGS=-shared -lc -lpthread -lstdc++
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

wrap: $(WRAPPERS_DIR)/module.i

objects: wrap $(OBJ)

lib: objects $(LIB_DIR)/$(LIB_NAME)

$(wildcard $(WRAPPERS_DIR)/*)/%.i:

$(WRAPPERS_DIR)/module.i: $(WRAPPERS) Makefile
	./bin/ngeerate wrapper module.i


$(SRC_DIR)/module_wrap.cpp: $(WRAPPERS_DIR)/module.i Makefile $(IFILES)
	swig  $(SWIG_FLAGS) $(addprefix -I,$(wildcard $(WRAPPERS_DIR)/*)) -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile $(IFILES)
	$(CC) -o $@ -c $< $(OBJ_CFLAGS) $(addprefix -I,$(IDIR_LOCAL) $(IDIR_EXTERNAL))

$(LIB_DIR)/$(LIB_NAME): $(OBJ) $(WRAPPER_OBJ)
	$(CC) $(LIB_CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ) $(WRAPPERS_OBJ) $(WRAPPERS_DIR)/module.i

fclean: clean
	rm -f $(LIB_DIR)/$(LIB_NAME)

re: fclean all


.PHONY: all wrap objects lib module clean fclean re
