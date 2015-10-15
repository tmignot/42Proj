#include "chars.h"

RVAL isDQuote(char c)
{
	return(c == '"');
}

RVAL isBQuote(char c)
{
	return(c == '`');
}

RVAL isSpace(char c)
{
	return(c == ' ');
}

RVAL isTab(char c)
{
	return(c == '\t');
}

RVAL isNewLine(char c)
{
	return(c == '\n');
}
