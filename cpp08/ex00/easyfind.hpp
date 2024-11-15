/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:51:44 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/20 10:31:52 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using std::cout;
using std::endl;

template <typename T> void easyfind(T container, int num)
{
	typename T::iterator pos;

	pos = std::find(container.begin(), container.end(), num);
	if (*pos == num)
		cout << "found occurence of: " << num << endl;
	else
		cout << "couldn't find occurence of: " << num << endl;
};

#endif