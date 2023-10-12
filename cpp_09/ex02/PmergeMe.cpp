/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:43:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/12 11:18:20 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		
	}
	return (*this);
}

PmergeMe::~PmergeMe(){}

void	PmergeMe::is_double(int num)
{
	it = --data.begin();
	while (++it != data.end())
		if (*it == num)
			throw "There is double";
}

void PmergeMe::print(string str)
{
	cout << str << ": ";
	it = --data.begin();
	while (++it != data.end())
		cout << *it << " ";
	cout << endl;
}

void PmergeMe::InsertionSort()
{
	std::vector<int>::iterator previous;
	std::vector<int>::iterator prev;
	std::vector<int>::iterator cur;
	int	temp;
	int	index;
	int	iteration;

	it = ++data.begin();
	prev = data.begin();
	index = 1;
	while (it != data.end())
	{
		cur = it;
		temp = *it;
		previous = prev;
		if (temp < *previous)
		{
			iteration = index + 1;
			while (--iteration)
			{
				if (temp < *previous)
				{
					data.erase(cur);
					data.insert(cur - 1, temp);
					cur--;
					previous--;
				}
			}
		}
		it++;
		index++;
		prev++;
	}	
}
