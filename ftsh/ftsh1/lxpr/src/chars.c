#include "chars.h"

static void		fillTestFuncs(RVAL (***f)(char))
{
	(*f)[0] = isSemicolon;
	(*f)[1] = isAmpersand;
	(*f)[2] = isShebang;
	(*f)[3] = isLChevron;
	(*f)[4] = isRChevron;
	(*f)[5] = isPipe;
	(*f)[6] = isBSlash;
	(*f)[7] = isOpenParent;
	(*f)[8] = isClosedParent;
	(*f)[9] = isOpenSqBrac;
	(*f)[10] = isClosedSqBrac;
	(*f)[11] = isOpenBrac;
	(*f)[12] = isClosedBrac;
	(*f)[13] = isWildcard;
	(*f)[14] = isQuote;
	(*f)[15] = isDQuote;
	(*f)[16] = isBQuote;
	(*f)[17] = isSpace;
	(*f)[18] = isTab;
	(*f)[19] = isNewLine;
	(*f)[20] = isCarriageRet;
	(*f)[21] = isEqual;
	(*f)[22] = isColon;
	(*f)[23] = isDollar;
	(*f)[24] = isEOF;
}

static t_charTest			*getTestFuncs(void)
{
	static t_charTest	*f = NULL;
	
	if (f == NULL)
	{
		f = (t_charTest*)malloc(sizeof(void*) * 25);
		if (!f)
			return(NULL);
		fillTestFuncs(&f);
	}
	else {
		free(f);
		f = NULL;
	}
	return(f);
}

RVAL isGeneral(char c)
{
	t_charTest	*f;
	RVAL			retval;
	int				i;

	f = getTestFuncs();
	if (!f)
		return(RMALLOC_ERROR);
	i = 0;
	retval = RTRUE;
	while(i < 25)
	{
		if (f[i](c) == RTRUE)
		{
			retval = RFALSE;
			break;
		}
		i++;
	}
	getTestFuncs();
	f = NULL;
	return(retval);
}

int		translateChar(char c)
{
	int				i;
	t_charTest	*f;

	i = 0;
	f = getTestFuncs();
	if (!f)
		return(-1);
	while(i < 25)
	{
		if (f[i](c) == RTRUE)
		{
			getTestFuncs();
			return(i);
		}
		i++;
	}
	getTestFuncs();
	if (!ft_isprint(c))
		return(-1);
	else
		return(GENERAL);
}

