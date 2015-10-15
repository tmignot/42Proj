#ifndef STATE_MACHINE_H
# define STATE_MACHINE_H

# include "common.h"

typedef RVAL (*t_handler)(void);
typedef RVAL (*t_chandler)(size_t);


RVAL		runStateMachine(char *str);

RVAL		handleStateGeneral(void);
RVAL		handleStateFilename(void);
RVAL		handleStateParameter(void);
RVAL		handleStateIf(void);
RVAL		handleStateThen(void);
RVAL		handleStateElif(void);
RVAL		handleStateElse(void);
RVAL		handleStateFi(void);
RVAL		handleStateFor(void);
RVAL		handleStateIn(void);
RVAL		handleStateDo(void);
RVAL		handleStateDone(void);
RVAL		handleStateLSChev(void);
RVAL		handleStateRSChev(void);
RVAL		handleStateLDChev(void);
RVAL		handleStateRDChev(void);
RVAL		handleStateSString(void);
RVAL		handleStateDString(void);
RVAL		handleStateSubCmd(void);
RVAL		handleStateBSlash(void);
RVAL		handleStateParent(void);
RVAL		handleStateSqBr(void);
RVAL		handleStateBrac(void);
RVAL		handleStateShbang(void);
RVAL		handleStateAmper(void);
RVAL		handleStatePipe(void);

t_chandler		*getCharsHandlers(void);
RVAL				freeCharsHandlers(void);
RVAL				setCharsHandler(unsigned char c, t_chandler func);

RVAL		handleStateGeneral_general(size_t pos);
RVAL		handleStateGeneral_semicolon(size_t pos);
RVAL		handleStateGeneral_ampersand(size_t pos);
RVAL		handleStateGeneral_shebang(size_t pos);
RVAL		handleStateGeneral_lChevron(size_t pos);
RVAL		handleStateGeneral_rChevron(size_t pos);
RVAL		handleStateGeneral_pipe(size_t pos);
RVAL		handleStateGeneral_bSlash(size_t pos);
RVAL		handleStateGeneral_openParent(size_t pos);
RVAL		handleStateGeneral_closedParent(size_t pos);
RVAL		handleStateGeneral_openSqBrac(size_t pos);
RVAL		handleStateGeneral_closedSqBrac(size_t pos);
RVAL		handleStateGeneral_openBrac(size_t pos);
RVAL		handleStateGeneral_closedBrac(size_t pos);
RVAL		handleStateGeneral_wildcard(size_t pos);
RVAL		handleStateGeneral_quote(size_t pos);
RVAL		handleStateGeneral_dQuote(size_t pos);
RVAL		handleStateGeneral_bQuote(size_t pos);
RVAL		handleStateGeneral_space(size_t pos);
RVAL		handleStateGeneral_tab(size_t pos);
RVAL		handleStateGeneral_newl(size_t pos);
RVAL		handleStateGeneral_cReturn(size_t pos);
RVAL		handleStateGeneral_equal(size_t pos);
RVAL		handleStateGeneral_colon(size_t pos);
RVAL		handleStateGeneral_dollar(size_t pos);
RVAL		handleStateGeneral_endOfFile(size_t pos);
RVAL		handleStateGeneral_undefined(size_t pos);

#endif
