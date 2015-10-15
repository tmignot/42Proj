#include "chars.h"
#include "state.h"
#include "state_machine.h"
#include "token.h"
#include "groupment.h"

RVAL		handleStateGeneral_general(size_t pos)
{
	return(addState(STATE_FILENAME, pos));
}

RVAL		handleStateGeneral_semicolon(size_t pos)
{
	if (addToken(TK_SEMICOLON, pos, 1) != ROK
		|| addState(STATE_GENERAL, pos) != ROK)
		return(RMALLOC_ERROR);
	return(ROK);
}

RVAL		handleStateGeneral_ampersand(size_t pos)
{
	if (addState(STATE_AMPER, pos) != ROK)
		return(RMALLOC_ERROR);
	return(RSYNTAX_ERROR);
}

RVAL		handleStateGeneral_shebang(size_t pos)
{
	if (addToken(TK_SHBANG, pos, 1) != ROK
		|| addState(STATE_SHBANG, pos) != ROK)
		return(RMALLOC_ERROR);
	return(ROK);
}

RVAL		handleStateGeneral_lchevron(size_t pos)
{
	return(addState(STATE_LSCHEV, pos));
}

RVAL		handleStateGeneral_rchevron(size_t pos)
{
	return(addState(STATE_RSCHEV, pos));
}

RVAL		handleStateGeneral_pipe(size_t pos)
{
	(void)pos;
	return(RSYNTAX_ERROR);
}

RVAL		handleStateGeneral_bSlash(size_t pos)
{
	return(addState(STATE_BSLASH, pos));
}

RVAL		handleStateGeneral_openParent(size_t pos)
{
	return(addToken(TK_OPEN_PARENT, pos, 1));
}

RVAL		handleStateGeneral_closedParent(size_t pos)
{
	RVAL	valid;

	valid = validCloseGroup(0);
	if(valid == ROK)
		return(addToken(TK_CLOS_PARENT, pos, 1));
	else
		return(valid);
}

RVAL		handleStateGeneral_openSqBrac(size_t pos)
{
	return(addToken(TK_OPEN_SQBR, pos, 1));
}

RVAL		handleStateGeneral_closedSqBrac(size_t pos)
{
	RVAL	valid;

	valid = validCloseGroup(1);
	if(valid == ROK)
		return(addToken(TK_CLOS_SQBR, pos, 1));
	else
		return(valid);
}

RVAL		handleStateGeneral_openBrac(size_t pos)
{
	return(addToken(TK_OPEN_BRAC, pos, 1));
}

RVAL		handleStateGeneral_closedBrac(size_t pos)
{
	RVAL	valid;

	valid = validCloseGroup(2);
	if(valid == ROK)
		return(addToken(TK_CLOS_BRAC, pos, 1));
	else
		return(valid);
}

RVAL		handleStateGeneral_wildcard(size_t pos)
{
}

RVAL		handleStateGeneral_quote(size_t pos)
{
}

RVAL		handleStateGeneral_dQuote(size_t pos)
{
}

RVAL		handleStateGeneral_bQuote(size_t pos)
{
}

RVAL		handleStateGeneral_space(size_t pos)
{
	(void)pos;
	return(ROK);
}

RVAL		handleStateGeneral_tab(size_t pos)
{
	(void)pos;
	return(ROK);
}

RVAL		handleStateGeneral_newl(size_t pos)
{
	(void)pos;
	return(ROK);
}

RVAL		handleStateGeneral_cReturn(size_t pos)
{
	(void)pos;
	return(ROK);
}

RVAL		handleStateGeneral_equal(size_t pos)
{
	(void)pos;
	return(RSYNTAX_ERROR);
}

RVAL		handleStateGeneral_colon(size_t pos)
{
	(void)pos;
	return(RSYNTAX_ERROR);
}

RVAL		handleStateGeneral_dollar(size_t pos)
{
}

RVAL		handleStateGeneral_endOfFile(size_t pos)
{
	(void)pos;
	return(ROK);
}

RVAL		handleStateGeneral_undefined(size_t pos)
{
	(void)pos;
	return(RSYNTAX_ERROR);
}
