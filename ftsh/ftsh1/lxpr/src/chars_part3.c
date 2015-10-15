#include "chars.h"

RVAL isClosedSqBrac(char c)
{
	return(c == ']');
}

RVAL isOpenBrac(char c)
{
	return(c == '{');
}

RVAL isClosedBrac(char c)
{
	return(c == '}');
}

RVAL isWildcard(char c)
{
	return(c == '*');
}

RVAL isQuote(char c)
{
	return(c == '\'');
}
