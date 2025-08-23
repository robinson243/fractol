/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:08:49 by romukena          #+#    #+#             */
/*   Updated: 2025/08/24 00:10:22 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;
	ssize_t	ret;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ret = write(fd, &s[i], 1);
		if (ret == -1)
			return ;
		i++;
	}
}

double	ft_atod(const char *str)
{
	double	result;
	double	sign;
	double	dec;
	int		i;

	result = 0.0;
	sign = 1.0;
	dec = 1.0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1.0;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
	{
		while (str[++i] >= '0' && str[i] <= '9')
		{
			dec /= 10.0;
			result += (str[i] - '0') * dec;
		}
	}
	return (result * sign);
}

int	get_color(int iter)
{
	static int	color[5];

	color[0] = 0xCDB4DB;
	color[1] = 0xFFC8DD;
	color[2] = 0xFFAFCC;
	color[3] = 0xBDE0FE;
	color[4] = 0xA2D2FF;
	if (iter == MAX_ITER)
		return (0x000000);
	return (color[iter % 5]);
}
