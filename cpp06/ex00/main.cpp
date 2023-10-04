/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:50:07 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/03 15:49:07 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	init(string str)
{
	ScalarConverter obj;

	obj.convert(str);
}

int main(int c, char **v)
{
	if (c == 2)
		init(v[1]);
	return (0);
}
