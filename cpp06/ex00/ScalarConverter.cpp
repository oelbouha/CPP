/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:16:58 by oelbouha          #+#    #+#             */
/*   Updated: 2023/08/19 14:30:15 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	if (this != &copy)
	{
		
	}
	return (*this);
}

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

void	displayChar(int c)
{
	if (c >= 32 && c <= 126)
	{
		cout <<  "char: " << "'" << c << "'" <<  endl;
		return ;
	}
	cout <<  "char:  Non displayable" << endl;
}

void	displayNumbers(double nb, int precision)
{
	displayChar(nb);
	cout << std::setprecision(precision);
	cout <<  "int: " << static_cast<int>(nb) << endl;
	cout <<  "float: " << nb << "f" <<  endl;
	cout <<  "double: " << nb << endl;
}

void	displayInt(double nb)
{
	displayChar(nb);
	cout <<  "int: " << static_cast<int>(nb) << ".0" << endl;
	cout <<  "float: " << nb << ".0" << "f" << endl;
	cout <<  "double: " << nb << ".0" << endl;
}

int	isInf(string str)
{
	if (str == "+nf" || str == "-inf" || str == "inf")
		return (1);
	else if (str == "+inff" || str == "-inff")
		return (1);
	return (0);
}

void	ScalarConverter::convert(string str)
{
	float		floatvalue;
	int			type;

	type = getType(str);
	if (type == DOUBLETYPE)
		displayNumbers(std::strtod(str.c_str(), NULL), str.length());
	else if (type == FLOATTYPE)
	{
		str[str.length() - 1] = '0';
		floatvalue = std::strtod(str.c_str(), NULL);
		displayNumbers(floatvalue, 0);
	}
	else if (type == INTTYPE)
		displayInt(std::strtod(str.c_str(), NULL));
	else if (type == CHARTYPE)
		displayNumbers((int)str[0], 0);
	else if (isInf(str))
	{
		cout <<  "char: imposible" << endl;
		cout <<  "int: " << str << endl;
		cout <<  "float: " << str << endl;
		cout <<  "double: " << str << endl;
	}
	else
	{
		cout <<  "char: imposible" << endl;
		cout <<  "int: imposible" <<  endl;
		cout <<  "float: nanf" << endl;
		cout <<  "double: nan" <<  endl;
	}
}

/*
	float nb = 3.75

	int n = (int)nb;

	0011.11
	1.111 * 2^1
	
3.75 ==>	0 10000000 11100000000000000000000

1/ remove the fraction part
	
	0 10000000
	

*/
