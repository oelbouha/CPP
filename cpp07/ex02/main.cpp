/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:01:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/17 23:44:07 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void	init()
{
	Array<int> arr(5);

	cout << "array size ==> " << arr.size() << endl;
	try
	{
		arr.push(10);
		arr.push(1);
		arr.push(11);
		arr.push(10);
		for(int i = 0; i < arr.size(); i++)
			cout << "data: " << arr[i] << endl;
	}
	catch (const char *error)
	{
		cout << error << endl;
	}
}

int main(void)
{	
	init();
	return 0;
}