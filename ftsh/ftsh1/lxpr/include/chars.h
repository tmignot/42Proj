#ifndef CHARS_H
# define CHARS_H

# include "common.h"

typedef RVAL	(*t_charTest)(char);

enum	chars_e
{
	GENERAL = 0,
	SEMICOLON,
	AMPERSAND,
	SHEBANG,
	LCHEVRON,
	RCHEVRON,
	PIPE,
	BSLASH,
	OPENPARENT,
	CLOSEDPARENT,
	OPENSQBRAC,
	CLOSEDSQBRAC,
	OPENBRAC,
	CLOSEDBRAC,
	WILDCARD,
	QUOTE,
	DQUOTE,
	BQUOTE,
	SPACE,
	TAB,
	NEWL,
	CRETURN,
	EQUAL,
	COLON,
	DOLLAR,
	ENDOFFILE,
	UNDEFINED
};

RVAL	isSemicolon(char c);
RVAL	isAmpersand(char c);
RVAL	isShebang(char c);
RVAL	isLChevron(char c);
RVAL	isRChevron(char c);
RVAL	isPipe(char c);
RVAL	isBSlash(char c);
RVAL	isOpenParent(char c);
RVAL	isClosedParent(char c);
RVAL	isOpenSqBrac(char c);
RVAL	isClosedSqBrac(char c);
RVAL	isOpenBrac(char c);
RVAL	isClosedBrac(char c);
RVAL	isWildcard(char c);
RVAL	isQuote(char c);
RVAL	isDQuote(char c);
RVAL	isBQuote(char c);
RVAL	isSpace(char c);
RVAL	isTab(char c);
RVAL	isNewLine(char c);
RVAL	isCarriageRet(char c);
RVAL	isEqual(char c);
RVAL	isColon(char c);
RVAL	isDollar(char c);
RVAL	isEOF(char c);

RVAL	isGeneral(char c);

int		translateChar(char c);

#endif
