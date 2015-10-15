#include "groupment.h"

static RVAL		addToStack(unsigned int t, size_t *s)
{
	if (t == TK_CLOS_PARENT)
		s[0]++;
	else if (t == TK_CLOS_SQBR)
		s[1]++;
	else if (t == TK_CLOS_BRAC)
		s[2]++;
	else
		return(ROUT_OF_RANGE);
	return(ROK);
}

static RVAL		checkStack(unsigned int t, size_t *s)
{
	if (s[0] == s[1] && s[1] == s[2] && s[2] == 0)
		return(RTRUE);
	if (t == TK_OPEN_PARENT && s[0])
		s[0]--;
	else if (t == TK_OPEN_SQBR && s[1])
		s[1]--;
	else if (t == TK_OPEN_BRAC && s[2])
		s[2]--;
	else
		return(RSYNTAX_ERROR);
	return(ROK);
}

static RVAL		getLastOpenedGroup(unsigned int *type)
{
	t_lst				*token;
	unsigned int	t;
	size_t				stack[3] = {0, 0, 0};
	RVAL					retval;

	token = getLastToken();
	while(token->prev)
	{
		t = ((t_token*)token->data)->type;
		if (t == TK_CLOS_PARENT || t == TK_CLOS_SQBR || t == TK_CLOS_BRAC)
			addToStack(t, stack);
		if (t == TK_OPEN_PARENT || t == TK_OPEN_SQBR || t == TK_OPEN_BRAC)
		{
			retval = checkStack(t, stack);
			if (retval == RSYNTAX_ERROR || retval == RTRUE)
			{
				*type = t;
				return(retval);
			}
		}
		token = token->prev;
	}
	return(RSYNTAX_ERROR);
}

RVAL		validCloseGroup(unsigned int type)
{
	unsigned int lastgrp;
	RVAL		retval;

	retval = getLastOpenedGroup(&lastgrp);
	if (retval == RTRUE && lastgrp == type)
		return(ROK);
	else
		return(retval);
}
