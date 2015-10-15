#ifndef COMMON_H
# define COMMON_H

# include "libft.h"

# define RVAL int

enum	retval_e
{
	RFALSE = 0,
	RTRUE,
	ROK,
	RMALLOC_ERROR,
	RFREE_ERROR,
	ROUT_OF_RANGE,
	RSYNTAX_ERROR,
	RUNDEF_ERROR
};

#endif
