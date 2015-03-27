for f in  *.o *.bundle *.so Makefile
do
	rm $f 2> /dev/null
done


swig -ruby swigWrapper.i &&
gcc -c -fpic swigWrapper_wrap.c main.c -I $HOME/.brew/Cellar/ruby/2.2.0/include/ruby-2.2.0/x86_64-darwin14 \
									   -I $HOME/.brew/Cellar/ruby/2.2.0/include/ruby-2.2.0 &&
gcc -bundle -flat_namespace -undefined suppress swigWrapper_wrap.o main.o -o threadlaunch.bundle &&
$HOME/.brew/Cellar/ruby/2.2.0/bin/ruby extconf.rb &&
make &&
make install
