/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:01:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/05 11:47:57 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// void	read_file(std::ifstream file)
// {
// 	string line;

// 	while (std::getline(file, line))
// 	{
// 		cout << line << endl;
// 	}
// }


int is_valid_number(string date)
{
	if (date[0] == '-')
	{
		cout << "Error: not a positive number." << endl;
		return (1);
	}
	for(size_t i = 0; i < date.length(); i++)
	{
		if (!isdigit(date[i]))
			return (1);
	}
	return (0);
}

int	parsing_file(string str)
{
	string 	year;
	string 	month;
	string 	day;
	int		pos;
	int		ret;

	ret = 0;
	pos = str.find("-");
	year = str.substr(0, pos);
	str = str.substr(pos + 1);
	pos = str.find("-");
	month = str.substr(0, pos);
	str = str.substr(pos + 1);
	pos = str.find(" ");
	day = str.substr(0, pos);
	str = str.substr(pos + 3);
	if (is_valid_number(year) || is_valid_number(month) || is_valid_number(day))
		ret = 1;
	if (day.length() != 2 || month.length() != 2)
		ret = 1;
	if (is_valid_number(str))
		return (1);
	if (ret)
		cout << "Error: bad input => " << year << "-" << month << "-" << day << endl;
	return (ret);
}


void	open_file(char *filename)
{	
	std::ifstream	file;
	string 			line;

	file.open(filename, std::ios::in);
	if (file.is_open() == false)
	{
		cout << "error: couldn't open file" << endl;
		exit(0);
	}
	while (std::getline(file, line))
	{
		cout << line << endl;
		parsing_file(line);
		/*
		*/
	}
}

void init(char *filename)
{
	open_file(filename);
}

int main(int c, char **v)
{
	if (c != 2)
		return (1);
	init(v[1]);	
	return 0;
}
