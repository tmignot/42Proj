swig3.0 -ruby swigWrapper.i &&
	gcc -c -fpic swigWrapper_wrap.c main.c -I /usr/local/include/ruby-2.1.0/x86_64-linux/ -I /usr/local/include/ruby-2.1.0/ &&
	gcc -shared swigWrapper_wrap.o main.o -o threadlaunch.so &&
	ruby extconf.rb &&
	make &&
	sudo make install
