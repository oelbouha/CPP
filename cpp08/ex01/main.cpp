/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:01:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/07 12:04:28 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp(10);
	Span s(10);

	try
	{
		sp.addNumbers();
		s.print();
		cout << "=============\n";
		sp.addNumbers();
	}
	catch(const char *error)
	{
		cout << error << endl;
	}
	
	cout << sp.shortestSpan() << endl;
	cout << sp.longestSpan() << endl;
	return 0;
}
