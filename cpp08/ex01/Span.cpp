/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:36:18 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/20 14:02:34 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(const Span& copy)
{
	arr = new int[copy.arr_length];
	*this = copy;
}

Span& Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < copy.arr_length; i++)
			arr[i] = copy.arr[i];
		arr_length = copy.arr_length;
		index = copy.arr_length;
	}
	return (*this);
}

Span::Span()
{
	arr = NULL;
	arr_length = 0;
	index = 0;
}

Span::~Span()
{
	delete[] arr;
}

Span::Span(unsigned int n)
{
	arr = new int[n];
	arr_length = n;
	index = 0;
}

void	Span::addNumber(int num)
{
	if (index > arr_length)
		throw Span::Exec();
	this->arr[index] = num;
	index++;
}

void	Span::addNumbers()
{
	for(int i = 0; i < arr_length; i++)
		addNumber(i);
}

int	Span::shortestSpan()
{
	int	max_distance;
	int	diff;

	if (index <= 1)
		throw Exec();
	std::sort(arr, arr + index, std::greater<int>());
	max_distance = arr[0] - arr[1];
	for(int i = 0; i < index; i++)
	{
		for(int j = i; j < index; j++)
		{
			diff = arr[i] - arr[j];
			if (diff < max_distance && diff > 0)
				max_distance = diff;
		}
	}
	return (max_distance);
}

int	Span::longestSpan()
{
	int	max_distance;

	if (index <= 1)
		throw Exec();
	std::sort(arr, arr + index);
	max_distance = 0;
	for(int i = 0; i < index; i++)
	{
		for(int j = i; j < index; j++)
		{
			if (arr[j] - arr[i] > max_distance)
				max_distance = arr[j] - arr[i];
		}
	}
	return (max_distance);
}

const char * Span::Exec::what() const throw()
{
	return "array is full";
}