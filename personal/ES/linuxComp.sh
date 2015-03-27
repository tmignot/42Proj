MODULE_NAME=threadlaunch
CC=gcc
IDIR_LOCAL=include

for f in  Makefile *.so *.bundle *.o
do
	rm $f 2>/dev/null
done

if [ "`uname`" == "Linux" ]
then
	LIB_EXT=so
	IDIR="-I/usr/local/include/ruby-2.1.0/x86_64-linux/ \
			  -I/usr/local/include/ruby-2.1.0/"
	CFLAGS=-shared
	SWIG_BIN=swig3.0
	RUBY_BIN=ruby
	SUDO=sudo
elif [ "`uname`" == "MacOSX" ]
then
	LIB_EXT=bundle
	IDIR=$HOME/.brew/Cellar/ruby/2.2.0/include/ruby-2.2.0/x86_64-darwin14 \
			 $HOME/.brew/Cellar/ruby/2.2.0/include/ruby-2.2.0 
	SWIG_BIN=swig
	RUBY_BIN=$HOME/.brew/Cellar/ruby/2.2.0/bin/ruby
	SUDO=
fi

$SWIG_BIN -ruby wrapper/swigWrapper.i &&
$CC -c -fpic src/*.c wrapper/swigWrapper_wrap.c $IDIR -I $IDIR_LOCAL &&
$CC $CFLAGS *.o -o "$MODULE_NAME.$LIB_EXT" &&
echo "require 'mkmf'
create_makefile '$MODULE_NAME'" > extconf.rb &&
$RUBY_BIN extconf.rb &&
make && $SUDO make install &&
rm extconf.rb *.o wrapper/*.c Makefile
