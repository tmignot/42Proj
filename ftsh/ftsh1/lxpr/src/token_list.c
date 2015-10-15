#include "token.h"

static t_lst		*setTokenList(t_lst *list, int write)
{
	static t_lst	*tokenList = NULL;

	if (write)
		tokenList = list;
	return tokenList;
}

t_lst		*getTokenList(void)
{
	return setTokenList(0,0);
}

t_lst		*getLastToken(void)
{
	t_lst	*list;

	list = getTokenList();
	while (list && list->next)
	{
		list = list->next;
	}
	return(list);
}

RVAL			freeTokenList(void)
{
	t_lst	*tokenList;

	tokenList = getTokenList();
	if (tokenList) {
		lst_del(&tokenList);
		setTokenList(NULL,1);
	}
	else
		return(RFREE_ERROR);
	return(ROK);
}

RVAL			addToken(unsigned int type, size_t src_i, size_t src_l)
{
	t_token	*token;
	t_lst		*tokenList;

	token = (t_token*)malloc(sizeof(t_token));
	if (!token)
		return(RMALLOC_ERROR);
	token->type = type;
	token->src_index = src_i;
	token->src_len = src_l;
	token->rhs = NULL;
	token->lhs = NULL;
	token->parent = NULL;
	tokenList = getTokenList();
	lst_push(&tokenList, sizeof(t_token), (void*)token);
	setTokenList(tokenList, 1);
	return(ROK);
}
