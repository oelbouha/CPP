/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:43:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/08 22:06:47 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
	{
		
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

string getDate(string line, string delimetre)
{
	string 	date;
	int		pos;

	pos = line.find(delimetre);
	date = line.substr(0, pos);
	return (date);
}

void	BitcoinExchange::read_file(char *filename)
{	
	std::ifstream	file(filename);
	string 			line;
	string 			date;
	double			value;

	if (file.is_open() == false)
	{
		cout << "error: couldn't open file" << endl;
		exit(0);
	}
	while (std::getline(file, line) != NULL)
	{
		date = getDate(line, " ");
		if (parsing_file(line) == 0)
		{
			line = line.substr(line.find("|") +  2);
			value = std::strtod(line.c_str(), NULL);
			if (value >= 1000)
			{
				cout << "Error: too large a number." << endl;
				continue ;
			}
			it = database.find(date);
			if (it == database.end())
			{
				it = database.lower_bound(date);
				cout << date << " => " << value;
				cout << " = " << it->second * value << endl;
			}
			else
			{
				cout << date << " => " << value;
				cout << " = " << it->second * value << endl;
			}
		}
	}
}

void	BitcoinExchange::setupDatabase()
{	
	std::ifstream	database_file("data.csv");
	string			line;
	string			date;
	double			value;

	if (!database_file.is_open())
	{
		cout << "error: couldn't open file" << endl;
		exit(0);
	}
	while (std::getline(database_file, line))
	{
		date = getDate(line, ",");
		line = line.substr(line.find(",") + 1);
		value = std::strtod(line.c_str(), NULL);
		// cout << value << endl;
		database[date] = value;
	}
}