OS:=$(shell uname)
CC=gcc
CFLAGS=-fpic
MODULE=threadlaunch
SRC_DIR=src
OBJ_DIR=obj
WRAPPER_DIR=wrapper
WRAPPER=swigWrapper
IDIR_LOCAL=include
SRC= main.c					\

OBJ=$(SRC:.c=.o)

ifeq ($(OS), Linux)
LIB_EXT=so
IDIR=-I /usr/local/include/ruby-2.1.0/ -I /usr/local/include/ruby-2.1.0/x86_64-linux
LCFLAGS=-shared
RUBY_BIN=ruby
SUDO=sudo
endif
ifeq ($(OS), MacOSX)
LIB_EXT=bundle
IDIR=$HOME/.brew/Cellar/ruby/2.2.0/include/ruby-2.2.0/x86_64-darwin14 \
		 $HOME/.brew/Cellar/ruby/2.2.0/include/ruby-2.2.0 
LCFLAGS=
RUBY_BIN=$HOME/.brew/Cellar/ruby/2.2.0/bin/ruby
SUDO=
endif

all: wrapper $(MODULE)

wrapper:
	swig -ruby wrapper/swigWrapper.i
	$(CC) -o $(OBJ_DIR)/swigWrapper_wrap.o -c $(CFLAGS) wrapper/swigWrapper_wrap.c $(IDIR)

%.o: $(SRC_DIR)/%.c
	$(CC) -o $(OBJ_DIR)/$@ -c $< $(CFLAGS) -I $(IDIR_LOCAL)

$(MODULE): $(addprefix $(OBJ_DIR)/,$(OBJ)) $(OBJ_DIR)/swigWrapper_wrap.o
	$(CC) $(LCFLAGS) $^ -o $(MODULE).$(LIB_EXT)
	@mv Makefile Makefile_old
	@echo "require 'mkmf'; create_makefile('$(MODULE)')" > extconf.rb
	@$(RUBY_BIN) extconf.rb
	@make && $(SUDO) make install && rm extconf.rb
	@mv Makefile_old Makefile

.PHONY: all wrapper
