/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:13:46 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/05 22:49:01 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>

using std::cout;
using std::endl;
using std::string;

class BitcoinExchange
{
	private:
		std::map<string, long> database;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& original);
		~BitcoinExchange();
		long	getValue();
};

#endif