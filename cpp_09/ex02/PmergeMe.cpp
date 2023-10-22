/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:43:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/12 21:49:11 by oelbouha         ###   ########.fr       */
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
	for(it = data.begin(); it != data.end(); it++)
		if (*it == num)
			throw "There is double";
}

void PmergeMe::print(string str)
{
	cout << str << ": ";
	for(it = data.begin(); it != data.end(); it++)
		cout << *it << " ";
	cout << endl;
}

void	PmergeMe::mergeInsertion(std::vector<int>& data, int left, int right)
{
	int midle;

	midle = (left + right) / 2;
	cout << "midle: " << midle << data[1] << endl;
	if (length <= insertion)
		InsertionSort(data, data.size());
	else
	{
		// mergeInsertion(data, midle);
		// mergeInsertion(data[midle + 1], midle + 1);
	}
}

void PmergeMe::InsertionSort(std::vector<int>& data, int left, int right)
{
	std::vector<int>::iterator previous;
	std::vector<int>::iterator prev;
	std::vector<int>::iterator cur;
	int	temp;
	int	idx;
	int	iteration;

	prev = data.begin();
	for(it = prev + 1, idx = 1; it != data.end(); it++, idx++, prev++)
	{
		if (idx >= length)
			break ;
		cur = it;
		temp = *it;
		previous = prev;
		for(iteration = idx; iteration; iteration--)
		{
			if (temp < *previous)
			{
				data.erase(cur);
				data.insert(cur - 1, temp);
				previous--;
				cur--;
			}
		}
	}	
}
