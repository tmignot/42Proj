#include "chars.h"

RVAL isPipe(char c)
{
	return(c == '|');
}

RVAL isBSlash(char c)
{
	return(c == '\\');
}

RVAL isOpenParent(char c)
{
	return(c == '(');
}

RVAL isClosedParent(char c)
{
	return(c == ')');
}

RVAL isOpenSqBrac(char c)
{
	return(c == '[');
}
