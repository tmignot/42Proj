#ifndef TOKEN_H
# define TOKEN_H

# include "common.h"

typedef struct	s_token t_token;

struct s_token
{
	size_t	 	type;
	size_t		src_index;
	size_t		src_len;
	t_token		*lhs;
	t_token		*rhs;
	t_token		*parent;
};

enum	e_token
{
	TK_COMMAND = 1,
	TK_PARAMETER,
	TK_SEMICOLON,
	TK_IF,
	TK_ELIF,
	TK_THEN,
	TK_FI,
	TK_FOR,
	TK_IN,
	TK_DO,
	TK_DONE,
	TK_WILDCARD,
	TK_OPEN_PARENT,
	TK_CLOS_PARENT,
	TK_OPEN_SQBR,
	TK_CLOS_SQBR,
	TK_OPEN_BRAC,
	TK_CLOS_BRAC,
	TK_BG,
	TK_PIPE,
	TK_AND,
	TK_OR,
	TK_SHBANG,
	TK_LSCHEV,
	TK_RSCHEV,
	TK_LDCHEV,
	TK_RDCHEV,
	TK_QUOTE,
	TK_DQUOTE,
	TK_BQUOTE,
	TK_VAR
};

/*	PROTOTYPE */
t_lst		*getTokenList(void);
/*	DESCRPTION
			get the token list

		PARAMETERS

		RETURN VALUES
			t_lst* :	the token list
			NULL :		no token has been pushed or list has been freed
*/

/*	PROTOTYPE */
t_lst		*getLastToken(void);
/*	DESCRIPTION
			get the last created token list element

		PARAMETERS

		RETURN VALUES
			t_lst* : the t_lst containing the last created token
			NULL :		no token has been created or the list has been freed
*/

/*	PROTOTYPE */
RVAL	freeTokenList(void);
/*	DESCRIPTION
			free the token Array

		RETURN VALUES
			ROK : everything is OK
			RFREE_ERROR : nullptr or free error
*/

/*	PROTOTYPE */
RVAL	addToken(unsigned int type, size_t src_i, size_t src_l);
/*	DESCRIPTION
			allocates a new token and pushes it back into the list
	
		PARAMETERS
			type: the type of the token from e_token enum
			src_i: the index of the first char of the token in the
						 parsed command line
			src_l: the length of the token in the parsed command line
	
		RETURN VALUES
			ROK : Everything is OK
			RMALLOC_ERROR : error appened with malloc;
*/

#endif
