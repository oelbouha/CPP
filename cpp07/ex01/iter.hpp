/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:51:44 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/17 22:05:44 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

using std::cout;
using std::endl;

template <typename data> void add(data x)
{
	cout << "data : " << x << endl;
}

template <typename data, typename T> void iter(data *arr, int arr_length, void (*func)(T))
{
	for(int i = 0; i < arr_length; i++)
		func(arr[i]);
}

#endif