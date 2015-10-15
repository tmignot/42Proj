#include "chars.h"
#include "state.h"
#include "state_machine.h"

static void	nextHandle(void)
{
	setCharsHandler(CLOSEDBRAC, handleStateGeneral_closedBrac);
	setCharsHandler(WILDCARD, handleStateGeneral_wildcard);
	setCharsHandler(QUOTE, handleStateGeneral_quote);
	setCharsHandler(DQUOTE, handleStateGeneral_dQuote);
	setCharsHandler(BQUOTE, handleStateGeneral_bQuote);
	setCharsHandler(SPACE, handleStateGeneral_space);
	setCharsHandler(TAB, handleStateGeneral_tab);
	setCharsHandler(NEWL, handleStateGeneral_newl);
	setCharsHandler(CRETURN, handleStateGeneral_cReturn);
	setCharsHandler(EQUAL, handleStateGeneral_equal);
	setCharsHandler(COLON, handleStateGeneral_colon);
	setCharsHandler(DOLLAR, handleStateGeneral_dollar);
	setCharsHandler(ENDOFFILE, handleStateGeneral_endOfFile);
	setCharsHandler(UNDEFINED, handleStateGeneral_undefined);
}

RVAL		handleStateGeneral(void)
{
	setCharsHandler(GENERAL, handleStateGeneral_general);
	setCharsHandler(SEMICOLON, handleStateGeneral_semicolon);
	setCharsHandler(AMPERSAND, handleStateGeneral_ampersand);
	setCharsHandler(SHEBANG, handleStateGeneral_shebang);
	setCharsHandler(LCHEVRON, handleStateGeneral_lChevron);
	setCharsHandler(RCHEVRON, handleStateGeneral_rChevron);
	setCharsHandler(PIPE, handleStateGeneral_pipe);
	setCharsHandler(BSLASH, handleStateGeneral_bSlash);
	setCharsHandler(OPENPARENT, handleStateGeneral_openParent);
	setCharsHandler(CLOSEDPARENT, handleStateGeneral_closedParent);
	setCharsHandler(OPENSQBRAC, handleStateGeneral_openSqBrac);
	setCharsHandler(CLOSEDSQBRAC, handleStateGeneral_closedSqBrac);
	setCharsHandler(OPENBRAC, handleStateGeneral_openBrac);
	nextHandle();
	return(ROK);
}
