#include "chars.h"
#include "state.h"
#include "state_machine.h"

static void	nextHandle(void)
{
	setCharsHandler(CLOSEDBRAC, handleStateFilename_closedBrac);
	setCharsHandler(WILDCARD, handleStateFilename_wildcard);
	setCharsHandler(QUOTE, handleStateFilename_quote);
	setCharsHandler(DQUOTE, handleStateFilename_dQuote);
	setCharsHandler(BQUOTE, handleStateFilename_bQuote);
	setCharsHandler(SPACE, handleStateFilename_space);
	setCharsHandler(TAB, handleStateFilename_tab);
	setCharsHandler(NEWL, handleStateFilename_newl);
	setCharsHandler(CRETURN, handleStateFilename_cReturn);
	setCharsHandler(EQUAL, handleStateFilename_equal);
	setCharsHandler(COLON, handleStateFilename_colon);
	setCharsHandler(DOLLAR, handleStateFilename_dollar);
	setCharsHandler(ENDOFFILE, handleStateFilename_endOfFile);
	setCharsHandler(UNDEFINED, handleStateFilename_undefined);
}

RVAL		handleStateFilename(void)
{
	setCharsHandler(GENERAL, handleStateFilename_general);
	setCharsHandler(SEMICOLON, handleStateFilename_semicolon);
	setCharsHandler(AMPERSAND, handleStateFilename_ampersand);
	setCharsHandler(SHEBANG, handleStateFilename_shebang);
	setCharsHandler(LCHEVRON, handleStateFilename_lChevron);
	setCharsHandler(RCHEVRON, handleStateFilename_rChevron);
	setCharsHandler(PIPE, handleStateFilename_pipe);
	setCharsHandler(BSLASH, handleStateFilename_bSlash);
	setCharsHandler(OPENPARENT, handleStateFilename_openParent);
	setCharsHandler(CLOSEDPARENT, handleStateFilename_closedParent);
	setCharsHandler(OPENSQBRAC, handleStateFilename_openSqBrac);
	setCharsHandler(CLOSEDSQBRAC, handleStateFilename_closedSqBrac);
	setCharsHandler(OPENBRAC, handleStateFilename_openBrac);
	nextHandle();
	return(ROK);
}

