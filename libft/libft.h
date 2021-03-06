/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:29:08 by dluba             #+#    #+#             */
/*   Updated: 2021/10/17 14:29:11 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define BUFFER_SIZE 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_toupper(int c);

int				ft_tolower(int c);

int				ft_atoi(const char *str);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_strrchr(const char *str, int sym);

char			*ft_strnstr(const char *big, const char *little, size_t len);

int				ft_strncmp(const char *str1, const char *str2, size_t n);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

size_t			ft_strlen(const char *str);

size_t			ft_strlcpy(char *dest, const char *src, size_t n);

size_t			ft_strlcat(char *buf, const char *src, size_t n);

char			*ft_strjoin(char const *s1, char const *s2);

void			ft_striteri(char *s, void (*f)(unsigned int, char*));

char			*ft_strdup(const char *str);

char			*ft_strchr(const char *str, int sym);

char			**ft_split(char const *s, char c);

void			ft_putstr_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putchar_fd(char c, int fd);

void			*ft_memset(void *dest, int c, size_t n);

void			*ft_memmove(void *dest0, const void *src0, size_t n);

void			*ft_memcpy(void *dest_0, const void *src_0, size_t n);

int				ft_memcmp(const void *str1_0, const void *str2_0, size_t n);

void			*ft_memchr(const void *str_0, int c, size_t n);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstnew(void *content);

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
							void (*del)(void *));

t_list			*ft_lstlast(t_list *lst);

void			ft_lstiter(t_list *lst, void (*f)(void *));

void			ft_lstdelone(t_list *lst, void (*del)(void*));

void			ft_lstclear(t_list **lst, void (*del)(void*));

void			ft_lstadd_front(t_list **lst, t_list *new);

void			ft_lstadd_back(t_list **lst, t_list *new);

char			*ft_itoa(int n);

int				ft_isprint(int c);

int				ft_isdigit(int c);

int				ft_isascii(int c);

int				ft_isalpha(int c);

int				ft_isalnum(int c);

void			*ft_calloc(size_t elem, size_t size);

void			ft_bzero(void *s, size_t n);

int				ft_strlen_gnl(char *c);

char			*ft_strjoin_gnl(char *s1, char *s2, char c);

int				ft_strchr_gnl(const char *str, int sym);

char			*re_string(char *str, int flag);

char			*get_next_line(int fd);

char			*ft_strdup_gnl(char *str);

float			ft_atodb(char *str);

void			ft_putstr(char *str);

int				ft_strlen_printf(char *str);

void			ft_putchar(char c);

unsigned int	power_printf(int factor, int n);

int				int_len_printf(int a);

int				u_len_printf(unsigned int a, int b);

int				int_checker_printf(int n);

int				ft_putnbr(int a);

int				case_string_printf(char *str);

int				case_char_printf(int c);

int				case_integer_printf(int a);

int				case_unsigned_printf(unsigned int a);

int				case_x_printf(unsigned int a, int flag);

unsigned long	lu_power_printf(int factor, int n);

int				lu_len_printf(unsigned long a, int b);

int				case_p_printf(unsigned long a);

int				type_choose_printf(const char *str, int count, va_list *argptr);

int				array_runner_printf(const char *str, va_list *argptr);

int				ft_printf(const char *p, ...);

#endif
