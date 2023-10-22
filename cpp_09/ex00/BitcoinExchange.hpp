/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:13:46 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/22 10:39:02 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class BitcoinExchange
{
	private:
		typedef std::map<string, double>::iterator iterator;
		std::map<string, double> database;
		string	date;
		double	value;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& original);
		~BitcoinExchange();

		string	getDate(string line, string delimetre);
		void	read_file(char *filename);
		void	parsing_file(string str);
		void	parsing_line(string line);
		void	setupDatabase();
};

void	is_valid_number(string date);
void	valid_date(string month, string day, string year);
void	is_valid_format(string str, string substr);

#endif