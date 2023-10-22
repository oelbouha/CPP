/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:22:46 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/12 22:33:45 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


void	is_positive_number(string input)
{
	size_t	i;

	for(i = 0; input[i]; i++)
	{
		if (!isdigit(input[i]))
			throw "Not a positive number";
	}
}

void init(char **av)
{
	PmergeMe 	merge;
	int			num;
	size_t		i;

	for(i = 0; av[i]; i++)
	{
		is_positive_number(av[i]);
		num = std::strtod(av[i], NULL);
		merge.is_double(num);
		merge.data.push_back(num);
	}
	merge.print("before");
	merge.mergeInsertion(merge.data, 0, merge.data.size() - 1);
	merge.print("after");
}

int main(int c, char **av)
{
	
	if (c == 1)
	{
		cout << "error: No input found" << endl;
		return (1);
	}
	try
	{
		init(&av[1]);
	}
	catch(const char *error)
	{
		cout << "error: " << error << endl;
	}
	return 0;
}

