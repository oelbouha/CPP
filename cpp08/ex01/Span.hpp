/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:51:44 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/06 17:32:20 by oelbouha         ###   ########.fr       */
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
		std::vector<int> arr;
		std::vector<int>::iterator it;
		size_t	max_length;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& copy);
		Span& operator=(const Span& copy);
		~Span();

		void	addNumber(int num);
		void	addNumbers();
		int		shortestSpan();
		int		longestSpan();
		void	print(){
			it = arr.begin();
			while (it != arr.end())
			{
				cout << *it << endl;
				++it;
			}
		};
};

#endif