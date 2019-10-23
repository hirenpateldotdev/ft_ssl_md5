/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:13:52 by hirenpat          #+#    #+#             */
/*   Updated: 2019/03/11 20:13:54 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PLUS '+'
# define MINUS '-'
# define SPACE ' '
# define ZERO '0'
# define HASHTAG '#'
# define ASTERISK '*'
# define H	1
# define HH 2
# define L	3
# define LL	4
# define UL	5
# define UU	6
# define J	7
# define Z	8
# define IS_NUM(x) (x >= '0' && x <= '9')
# define IS_NEG(x) (x < 0 ? 1 : 0)
# define ABS(x) (x < 0 ? -x : x)
# define MAX(x, y) (x < y ? y : x)
# define MIN(x, y) (x > y ? y : x)
# define ULLI(x) ((unsigned long long int)x)

# include "unistd.h"
# include "stdlib.h"
# include "stdarg.h"
# include "../libft/libft.h"

typedef struct			s_pf
{
	char				specifier;
	int					minus;
	int					plus;
	int					space;
	int					hashtag;
	int					zero;
	int					width;
	int					precision;
	int					length;
	int					valid;
	int					is_negative;
}						t_pf;
long long int			get_signed_int(t_pf *cache, va_list args);
unsigned long long int	get_unsigned_int(t_pf *cache, va_list args);
long double				get_double_int(t_pf *cache, va_list arg);
int						asterisk_int(int *nb, va_list args);
int						write_sign(t_pf *cache);
void					padding(t_pf *cache, int len, char c, int ret);
int						ft_printf(const char *format, ...);
int						cache_init(t_pf *cache, const char *f, va_list args);
int						handler(t_pf *cache, va_list arg);
int						ft_place_value(unsigned long long int nb, int base);
char					*ft_ullitoa(unsigned long long int nb);
char					*ft_ullitoa_base(unsigned long long int nb,
						int base, char s);
char					*ft_llitoa(long long int nb);
char					*ft_ldtoa(long double f_nb, int precision);
char					*ft_strjoinf(char *str_1, char *str_2);
long double				ft_round(long double d, int p);
int						cache_flags(t_pf *cache, const char *f);
int						cache_width(t_pf *cache, const char *f, va_list args);
int						cache_precision(t_pf *cache, const char *f,
						va_list args);
int						cache_length(t_pf *cache, const char *f);
int						cache_specifier(t_pf *cache, const char *f,
						char *specifier);
int						mod_handler(t_pf *cache, va_list args);
int						c_handler(t_pf *cache, va_list args);
int						s_handler(t_pf *cache, va_list args);
int						d_handler(t_pf *cache, va_list args);
int						u_handler(t_pf *cache, va_list args);
int						o_handler(t_pf *cache, va_list args);
int						x_handler(t_pf *cache, va_list args);
int						b_handler(t_pf *cache, va_list args);
int						no_case_x_handler(t_pf *cache, char *prefix,
						unsigned long long int nb, char *str_nb);
int						f_handler(t_pf *cache, va_list args);
int						p_handler(t_pf *cache, va_list args);
int						is_spe(char x);
char					*ft_strset(char **dest, char *src);
#endif
