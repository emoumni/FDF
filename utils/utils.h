/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:51:08 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/22 14:45:08 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# ifndef FD_MAX
#  define FD_MAX 1000
# endif

char			**ft_split(const char *s, char c);
char			*ft_malloc_size(char **line, char *buf);
int				ft_add_to_line(char **line, char *buf);
int				get_next_line(int fd, char **line);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putstr(char *str);
int				ft_atoi(const char *nptr);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
char			*ft_itoa(int n);
int				ft_printf(const char *str, ...);
int				ft_printchar(int c);
int				ft_formats(va_list args, const char format);
int				ft_printnbr(int n);
int				ft_printstr(char *str);
size_t			ft_strlen(const char *s);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(const char *s1, const char *s2);
char			**ft_split(const char *s, char c);
size_t			ft_strlen(const char *s);
int				ft_is_c(char *str, char c);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_putendl_fd(const char *s, int fd);
unsigned int	ft_atoi_base(const char *str, const char *base);
int				ft_toupper(int c);

#endif
