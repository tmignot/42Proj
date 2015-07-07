#include <iostream>
#include <map>
#include <ruby.h>

void	PrintArg(void *i, void (*func)(void*)) {
	std::cout << "param is " << i << " from cpp" << std::endl;
	func(i);
}

void  Action(void (*func)(int), int i);
void	Action(void (*func)(int), int v);

void	Yield(void*);

VALUE Print(VALUE i, VALUE j, VALUE k) {
	void (*c_i)(int) = (void(*)(int)) NUM2ULONG(i);
	int	 c_j = NUM2INT(j);
	if (c_i)
		c_i(c_j);
	else 
		PrintArg(&Yield);
	return Qnil;
}

VALUE Print(VALUE i, VALUE j) {
}

void	PrintMap(std::map<ID,unsigned int> m) {
	std::map<ID,unsigned int>::iterator it;
	for (it = m.begin(); it != m.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
}
