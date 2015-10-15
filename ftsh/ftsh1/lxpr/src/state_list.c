#include "state.h"

static t_lst		*setStateList(t_lst *list, int write)
{
	static t_lst		*stateList = NULL;

	if (write)
		stateList = list;
	return(stateList);
}

t_lst		*getStateList(void)
{
	return(setStateList(NULL, 0));
}

t_state		*getLastState(void)
{
	t_lst	*stateList;

	stateList = getStateList();
	while (stateList && stateList->next)
	{
		stateList = stateList->next;
	}
	return((t_state*)stateList->data);
}

RVAL			addState(unsigned int type, size_t pos)
{
	t_lst	*stateList;
	t_state	*state;

	stateList = getStateList();
	state = (t_state*)malloc(sizeof(t_state));
	if (!state)
		return(RMALLOC_ERROR);
	state->type = type;
	state->pos = pos;
	lst_push(&stateList, sizeof(t_state), (void*)state);
	return(ROK);
}

RVAL			freeStateList(void)
{
	t_lst	*stateList;

	stateList = getStateList();
	if (!stateList)
		return(RFREE_ERROR);
	lst_del(&stateList);
	return(ROK);
}
