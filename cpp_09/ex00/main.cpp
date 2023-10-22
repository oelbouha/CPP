/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:01:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/22 11:00:17 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void init(char *filename)
{
	BitcoinExchange btc;

	try
	{
		btc.setupDatabase();
		btc.read_file(filename);
	}
	catch(const char *error)
	{
		cout << error << endl;
	}
	catch(std::exception& e)
	{
		cout << e.what() << endl;
	}
}

int main(int c, char **v)
{
	if (c == 2)
		init(v[1]);
	cout << "error: No file found" << endl;
	return 0;
}
