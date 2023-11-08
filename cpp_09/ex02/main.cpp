/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:22:46 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 01:53:00 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "List.hpp"


void	is_positive_number(string input)
{
	for(int i = 0; input[i]; i++)
	{
		if (!isdigit(input[i]))
			std::invalid_argument("Not a positive number");
	}
}

void init(char **av)
{
	PmergeMeList 	list;

	try
	{
		list.store_numbers(av);
		list.copy = list.data;
		list.mergeSort();
		cout << "list size --> " << list.data.size() << endl;
		cout << "before : ";
		list.print_vector_elements(list.copy);
		cout << "\nafter  : ";
		list.print_vector_elements(list.data);
	}
	catch(const std::exception& e)
	{
		cout << e.what() << endl;
	}
}

int main(int c, char **av)
{
	if (c != 1)
		init(&av[1]);
	else
		cout << "error: No input found" << endl;
	return 0;
}


