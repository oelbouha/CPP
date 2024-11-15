/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:36:18 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/20 12:02:34 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

Span::Span(const Span& copy)
{
	*this = copy;
}

Span& Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		arr = copy.arr;
		max_length = copy.max_length;
	}
	return (*this);
}

Span::Span(){
	max_length = 0;
}

Span::~Span(){}

Span::Span(unsigned int n)
{
	arr.reserve(n);
	max_length = n;
}

void	Span::addNumber(int num)
{
	if (arr.size() >= max_length)
		throw "array is full";
	arr.push_back(num);
}

void	Span::addNumbers(std::vector<int> vec)
{
	iterator it;

	for(it = vec.begin(); it != vec.end(); it++)
		addNumber(*it);
}

int	Span::shortestSpan()
{
	iterator	it;
	int			max_distance;
	int			diff;

	if (arr.size() <= 1)
		throw "There is only one or zero element in the array";
	max_distance = INT_MAX;
	std::sort(arr.begin(), arr.end());
	for (it = arr.begin(); it != arr.end() - 1; it++)
	{
		diff = *(it + 1) - *it;
		if (diff < max_distance)
			max_distance = diff;
	}
	return (max_distance);
}

int	Span::longestSpan()
{
	if (arr.size() <= 1)
		throw "There is only one or zero element in the array";
	std::sort(arr.begin(), arr.end());
	return (*(--arr.end()) - *arr.begin());
}

void	Span::print()
{
	iterator it;

	for(it = arr.begin(); it != arr.end(); it++)
		cout << "data: " << *it << endl;
};
