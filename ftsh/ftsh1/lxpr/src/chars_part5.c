#include "chars.h"
#include <stdio.h>

RVAL isCarriageRet(char c)
{
	return(c == '\r');
}

RVAL isEqual(char c)
{
	return(c == '=');
}

RVAL isColon(char c)
{
	return(c == ':');
}

RVAL isDollar(char c)
{
	return(c == '$');
}

RVAL isEOF(char c)
{
	return(c == EOF);
}
