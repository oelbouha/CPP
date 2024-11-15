/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:51:44 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/16 12:01:13 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename data> data max(data x, data y)
{
	if (x > y)
		return (x);
	return (y);
}

template <typename data> data min(data x, data y)
{
	if (x > y)
		return (y);
	return (x);
}

template <typename data> void swap(data x, data y)
{
	data temp;

	temp = x;
	x = y;
	y = temp;
	cout << x << "   " << y << endl;
}

#endif