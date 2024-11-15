/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:51:44 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/20 12:08:45 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

class Span
{
	private:
		typedef std::vector<int>::const_iterator iterator;
		std::vector<int>	arr;
		size_t	max_length;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& copy);
		Span& operator=(const Span& copy);
		~Span();

		void	addNumber(int num);
		void	addNumbers(std::vector<int> vec);
		void	print();
		int		shortestSpan();
		int		longestSpan();
};

#endif