/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:22:46 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/03 10:30:57 by oelbouha         ###   ########.fr       */
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
	PmergeMe::vector_iterator it;

	try
	{
		merge.store_numbers(av);
		PmergeMe::vec_of_pair_vector arr = merge.create_pairs(2);
		merge.mergeInsertion(merge.data, 0, merge.data.size() - 1);
		// merge.print_array(arr);
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



