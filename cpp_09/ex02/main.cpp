/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:22:46 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/07 15:15:56 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


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
	PmergeMe 	merge;

	try
	{
		merge.store_numbers(av);
		merge.copy = merge.data;
		merge.mergeSort();
		cout << "before  : ";
		merge.print_vector_elements(merge.copy);
		cout << "\nafter   : ";
		merge.print_vector_elements(merge.data);
		cout << "\nnumber of comparisons : "<< merge.comparisonCount << endl;
		cout << "data size : "<< merge.data.size() << endl;
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



