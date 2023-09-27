/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:01:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/20 12:57:22 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp(10);

	try
	{
		sp.addNumbers();
		cout << sp.shortestSpan() << endl;
		cout << sp.longestSpan() << endl;
	}
	catch(std::exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
