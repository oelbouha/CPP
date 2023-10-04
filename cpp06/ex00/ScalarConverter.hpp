/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:35:13 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/03 15:48:05 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::string;
using std::endl;

#define	FLOATTYPE 1
#define	DOUBLETYPE 2
#define	INTTYPE 3
#define	NOTANUMBER 4
#define	CHARTYPE 5

class	ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& original);
		~ScalarConverter();

		static void	convert(string str);
};

int	getType(string str);

#endif


