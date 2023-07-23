/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:01:21 by simajnoo          #+#    #+#             */
/*   Updated: 2023/07/22 12:28:20 by simajnoo         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "header.h"
int ft_atoi(char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;
    int count = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            count++;
        i++;
    }
    if (count % 2 != 0)
        sign = -1;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return sign * result;
}
