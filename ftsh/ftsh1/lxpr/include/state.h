#ifndef STATE_H
# define STATE_H

# include "common.h"

# define N_STATE 25

typedef struct state_s t_state;

struct state_s
{
	unsigned int	type;
	size_t				pos;
};

enum	state_e
{
	STATE_GENERAL = 0,
	STATE_FILENAME,
	STATE_PARAMETER,
	STATE_IF,
	STATE_THEN,
	STATE_ELIF,
	STATE_ELSE,
	STATE_FI,
	STATE_FOR,
	STATE_IN,
	STATE_DO,
	STATE_DONE,
	STATE_LSCHEV,
	STATE_RSCHEV,
	STATE_LDCHEV,
	STATE_RDCHEV,
	STATE_SSTRING,
	STATE_DSTRING,
	STATE_SUBCMD,
	STATE_BSLASH,
	STATE_PARENT,
	STATE_SQBR,
	STATE_BRAC,
	STATE_SHBANG,
	STATE_AMPER,
	STATE_PIPE
};

t_lst		*getStateList(void);
t_state		*getLastState(void);
RVAL			addState(unsigned int type, size_t pos);
RVAL			freeStateList(void);


RVAL			isInState(unsigned int type);


#endif
