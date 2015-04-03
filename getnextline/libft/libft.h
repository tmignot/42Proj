/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 00:16:43 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 05:37:50 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define RED "\x1b[31m"
# define GRN "\x1b[32m"
# define YEL "\x1b[33m"
# define BLU "\x1b[34m"
# define MAG "\x1b[35m"
# define CYA "\x1b[36m"
# define WHT "\x1b[37m"
# define RES "\x1b[0m"

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_lst
{
	int				type;
	void			*data;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef	struct		s_tree
{
	void			*content;
	size_t			content_size;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

int					ft_atoi(const char *str);
int					ft_xatoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				ft_xbzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_xisalnum(int c);
int					ft_xisalpha(int c);
int					ft_xisascii(int c);
int					ft_xisdigit(int c);
int					ft_xisprint(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t m);
void				ft_memdel(void **ap);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_c(char *c, char *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_c(char *c, char *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_xputchar(char c);
void				ft_xputchar_fd(char c, int fd);
void				ft_xputendl(char const *s);
void				ft_xputendl_fd(char const *s, int fd);
void				ft_xputstr(char const *s);
void				ft_xputstr_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbrl(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_u(unsigned int n);
void				ft_putnbr_u_fd(unsigned int n, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strirchr(const char *s, int c);
int					ft_strichr(const char *s, int c);
void				ft_strclr(char *s);
void				ft_xstrclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *s1, const char *s2);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
int					ft_xstrequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_xstriter(char *s, void (*f)(char *));
void				ft_xstriteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_xstrjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_xstrmap(char const *s, char (*f)(char));
char				*ft_xstrmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_xstrnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				**ft_xstrsplit(char const *s, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_xstrsub(char const *s, unsigned int start, size_t len);
char				*ft_xstrtrim(char const *s);
int					ft_toupper(int c);
int					ft_tolower(int c);
t_list				*ft_lstnew(void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
int					ft_lstcount(t_list *lst);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				lst_push(t_lst **lst, int type, void *data);
void				lst_delone_data(t_lst **head, t_lst *lst);
void				lst_delone_elem(t_lst **head, t_lst *lst);
void				lst_swap_data(t_lst *lst1, t_lst *lst2);
void				ft_lstiter(t_list *alst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_tree				*ft_treenew(void const *content, size_t content_size);

#endif
