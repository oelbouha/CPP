/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:51:44 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/20 14:02:23 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string_view>

using std::cout;
using std::endl;

class Span
{
	private:
		int	*arr;
		int	index;
		int	arr_length;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& copy);
		Span& operator=(const Span& copy);
		~Span();
		
		class Exec : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		void	addNumber(int num);
		void	addNumbers();
		int		shortestSpan();
		int		longestSpan();
};

#endif