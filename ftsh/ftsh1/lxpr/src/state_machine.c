#include "chars.h"
#include "state.h"
#include "state_machine.h"

static
void							fillStateHandlers1(t_handler *sh)
{
	sh[STATE_GENERAL] = handleStateGeneral;
	sh[STATE_FILENAME] = handleStateFilename;
	sh[STATE_PARAMETER] = handleStateParameter;
	sh[STATE_IF] = handleStateIf;
	sh[STATE_THEN] = handleStateThen;
	sh[STATE_ELIF] = handleStateElif;
	sh[STATE_ELSE] = handleStateElse;
	sh[STATE_FI] = handleStateFi;
	sh[STATE_FOR] = handleStateFor;
	sh[STATE_IN] = handleStateIn;
	sh[STATE_DO] = handleStateDo;
	sh[STATE_DONE] = handleStateDone;
}

static
void							fillStateHandlers2(t_handler *sh)
{
	sh[STATE_LSCHEV] = handleStateLSChev;
	sh[STATE_RSCHEV] = handleStateRSChev;
	sh[STATE_LDCHEV] = handleStateLDChev;
	sh[STATE_RDCHEV] = handleStateRDChev;
	sh[STATE_SSTRING] = handleStateSString;
	sh[STATE_DSTRING] = handleStateDString;
	sh[STATE_SUBCMD] = handleStateSubCmd;
	sh[STATE_BSLASH] = handleStateBSlash;
	sh[STATE_PARENT] = handleStateParent;
	sh[STATE_SQBR] = handleStateSqBr;
	sh[STATE_BRAC] = handleStateBrac;
	sh[STATE_SHBANG] = handleStateShbang;
	sh[STATE_AMPER] = handleStateAmper;
	sh[STATE_PIPE] = handleStatePipe;
}

static
t_handler		*getStateHandlers(RVAL erase)
{
	static t_handler	*stateHandlers = NULL;
	int								state;

	state = 0;
	if (!stateHandlers) {
		stateHandlers = (t_handler*)malloc(sizeof(t_handler) * N_STATE);
		fillStateHandlers1(stateHandlers);
		fillStateHandlers2(stateHandlers);
	}
	else if (erase == RTRUE)
	{
		while (state < N_STATE) {
			free(stateHandlers[state]);
			stateHandlers[state++] = NULL;
		}
		free(stateHandlers);
		stateHandlers = NULL;
	}
	return(stateHandlers);
}


static
RVAL		handleState(unsigned int type, char	*str, size_t pos)
{
	char						c;
	RVAL						retval;
	t_handler *stateHandlers;
	t_chandler *charsHandlers;

	c = str[pos];
	stateHandlers = getStateHandlers(RFALSE);
	charsHandlers = getCharsHandlers();
	stateHandlers[type]();
	if (!charsHandlers)
		return(RMALLOC_ERROR);
	if (charsHandlers[translateChar(c)])
		retval = charsHandlers[translateChar(c)](pos);
	if (retval != ROK)
		return(retval);
	
	return(RTRUE);
}

RVAL		runStateMachine(char *str)
{
	int		i;
	RVAL	retval;

	i = 0;
	addState(STATE_GENERAL, 0);
	retval = RTRUE;
	while (retval == RTRUE)
	{
		retval = handleState(getLastState()->type, str, i);
		i++;
	}
	getStateHandlers(RTRUE);
	freeCharsHandlers();
	return(retval);
}
