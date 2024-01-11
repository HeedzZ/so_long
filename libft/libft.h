/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:53:13 by ymostows          #+#    #+#             */
/*   Updated: 2023/11/14 15:53:13 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

//		ft_printf		//
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_printu(unsigned int nb);
int				ft_printdec(int nb);
int				ft_int_to_hex(unsigned int nb);
int				ft_u_to_hex(uintptr_t n);
int				ft_ptr_len(uintptr_t num);
int				ft_print_ptr(unsigned long long ptr);
int				ft_int_to_hexmaj(unsigned int nb);
int				ft_printf(const char *format, ...);

# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

//		gnl			//
char			*get_next_line(int fd);
char			*ft_strjoin_gnl(char *backup, char *buffer);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

// Part 1 //
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strchr(char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
int				ft_atoi(const char *str);
char			*ft_strdup(char *src);
void			*ft_calloc(size_t nmemb, size_t size);

// Part 2 //
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(const char *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

// BONUS //

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}					t_list;

int				ft_lstsize(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst,
					void	*(*f)(void *), void (*del)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);

#endif