/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:36:18 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/06 17:42:27 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(const Span& copy)
{
	*this = copy;
}

Span& Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		arr.clear();
		arr = copy.arr;
		max_length = copy.max_length;
	}
	return (*this);
}

Span::Span()
{
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

void	Span::addNumbers()
{
	for(size_t i = 1; i < max_length ; i++)
		addNumber(i);
}

int	Span::shortestSpan()
{
	int	max_distance;
	int	diff;

	if (arr.size() <= 1)
		throw "There is only one or zero element in the array";
	std::sort(arr.begin(), arr.end());
	it = arr.begin();
	while(it != arr.end() - 1)
	{
		diff = *(it + 1) - *it;
		if (diff < max_distance && diff > 0)
			max_distance = diff;
		it++;
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
