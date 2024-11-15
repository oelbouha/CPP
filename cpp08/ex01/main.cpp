/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:01:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/20 12:08:26 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp(10);
	Span s(10);
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(30);
	try
	{
		sp.addNumbers(vec);
		sp.addNumber(100);
		sp.print();
		cout << "shortest distance: " << sp.shortestSpan() << endl;
		cout << "longest distance : " << sp.longestSpan() << endl;
	}
	catch(const char *error)
	{
		cout << error << endl;
	}
	return 0;
}
