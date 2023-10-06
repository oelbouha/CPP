/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:01:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/06 18:13:50 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void	init()
{
	Array<int> arr(5);
	Array<int> arr1(5);

	arr1 = arr;
	try
	{
		arr.push(10);
		arr.push(1);
		arr.push(11);
		arr.push(15550);
		cout << arr[0] << endl;
	}
	catch (const char *error)
	{
		cout << error << endl;
	}
	cout << "arr size :=> " << arr.size() << endl;
}

int main(void)
{	
	init();
	return 0;
}
