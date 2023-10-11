/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:22:46 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/11 11:46:26 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool is_positive_number(string input)
{
	size_t	i;

	for(i = 0; input[i]; i++)
	{
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}

void init(char **av)
{
	PmergeMe merge;
	unsigned long value;
	size_t	i;
	

	for(i = 0; av[i]; i++)
	{
		if (is_positive_number(av[i]))
		{
			value = std::strtod(av[i], NULL);
			merge.data.push_back(value);
		}
		else
		{
			cout << "error: not a positive number " << endl;
			exit(1);
		}
	}
	merge.print();
}

int main(int c, char **av)
{
	if (c == 1)
	{
		cout << "error: No input found" << endl;
		return (1);
	}
	init(&av[1]);
	return 0;
}
