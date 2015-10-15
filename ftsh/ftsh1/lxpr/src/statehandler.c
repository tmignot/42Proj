#include "chars.h"
#include "state.h"
#include "state_machine.h"

static t_chandler		*charsHandlers(int opt, unsigned char c, t_chandler func)
{
	static t_chandler	*ch = NULL;

	if (!ch && opt != 2)
	{
		ch = (t_chandler*)malloc(sizeof(t_chandler)*256);
		ft_bzero(ch, sizeof(t_chandler) * 256);
	}
	if (opt == 1) {
		if (ch)
			ch[c] = func;
	}
	else if (opt == 2 && ch) 
	{
		free(ch);
		ch = NULL;
	}
	return(ch);
}

RVAL			setCharsHandler(unsigned char c, t_chandler func)
{
	t_chandler		*handlers;

	handlers = charsHandlers(1, c, func);
	if (handlers)
		return(ROK);
	else
		return(RMALLOC_ERROR);
}

RVAL			freeCharsHandlers(void)
{
	t_chandler		*handlers;

	handlers = charsHandlers(2, 0, NULL);
	if (handlers)
		return(RFREE_ERROR);
	else
		return(ROK);
}

t_chandler	*getCharsHandlers(void)
{
	return(charsHandlers(0, 0, NULL));
}
