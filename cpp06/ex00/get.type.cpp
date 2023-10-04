/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.type.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:49:29 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/03 15:50:39 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	getType(string str)
{
	int	type;

	type = 0;
	if (str.length() == 1 && !isdigit(str[0]))
		return (CHARTYPE);
	else if (str[0] == '-' || str[0] == '+')
		str = str[1];
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == str.length() - 1 && str[i] == 'f')
		{
			if (type != NOTANUMBER)
				return (FLOATTYPE);
			return (NOTANUMBER);
		}
		else if (str[i] == '.')
			type = DOUBLETYPE;
		else if (!isdigit(str[i]) && str[i] != '.')
			type = NOTANUMBER;
	}
	if (type == 0)
		type = INTTYPE;
	return (type);
}
