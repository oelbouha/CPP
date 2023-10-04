/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:01:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/03 16:23:03 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<std::string> arr1;
	
	cout << arr1.size() << endl;
	Array<std::string> arr2(arr1);
	
	arr1.print();
	return 0;
}
