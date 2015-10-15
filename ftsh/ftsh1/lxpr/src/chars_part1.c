#include "chars.h"

RVAL isSemicolon(char c)
{
	return(c == ';');
}

RVAL isAmpersand(char c)
{
	return(c == '&');
}

RVAL isShebang(char c)
{
	return(c == '!');
}

RVAL isLChevron(char c)
{
	return(c == '<');
}

RVAL isRChevron(char c)
{
	return(c == '>');
}
