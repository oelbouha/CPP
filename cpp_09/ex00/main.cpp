/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:01:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/08 22:05:44 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int is_valid_number(string date)
{
	int	check;

	check = 0;
	if (date[0] == '-')
		return (1);
	for(size_t i = 0; i < date.length(); i++)
	{
		if (date[i] == '.')
			check += 1;
		if (!isdigit(date[i]) && check != 1)
			return (1);
	}
	return (0);
}

int valid_date(string month, string day, string year)
{
	int		dy;
	int		m;

	if (day.length() != 2 || month.length() != 2 || year.length() != 4)
		return (0);
	if (is_valid_number(year) || is_valid_number(month) || is_valid_number(day))
		return (0);
	dy = std::strtod(month.c_str(), NULL);
	m = std::strtod(day.c_str(), NULL);
	if (m > 12 || dy > 12)
		return (0);
	return (1);
}

int	parsing_file(string str)
{
	string 	year;
	string 	month;
	string 	day;
	int		pos;

	pos = str.find("-");
	year = str.substr(0, pos);
	str = str.substr(pos + 1);
	pos = str.find("-");
	month = str.substr(0, pos);
	str = str.substr(pos + 1);
	pos = str.find(" ");
	day = str.substr(0, pos);
	str = str.substr(pos + 3);
	if (!valid_date(month, day, year))
	{
		cout << "Error: bad input => " << year << "-" << month << "-" << day << endl;
		return (1);
	}
	if (is_valid_number(str))
	{
		cout << "Error: not a positive number." << endl;
		return (1);
	}
	return (0);
}


void init(char *filename)
{
	BitcoinExchange btc;

	btc.setupDatabase();
	btc.read_file(filename);
}

int main(int c, char **v)
{
	if (c != 2)
	{
		cout << "error: No file found" << endl;
		return (1);
	}
	init(v[1]);	
	return 0;
}
