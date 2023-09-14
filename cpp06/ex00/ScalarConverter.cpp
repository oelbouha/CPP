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

void	display(float nb)
{
	if (nb >= 32 && nb <= 126)
		cout <<  "char: " << "'" << (char)nb << "'" <<  endl;
	else
		cout <<  "char:  Non displayable" << endl;
	cout <<  "int: " << static_cast<int>(nb) << endl;
	cout <<  "float: " << nb << "f" <<  endl;
	cout <<  "double: " << static_cast<double>(nb) << endl;
}

int	isInf(string str)
{
	if (!strcmp(str.c_str(), "+inf") || !strcmp(str.c_str(), "-inf"))
		return (1);
	else if (!strcmp(str.c_str(), "+inff") || !strcmp(str.c_str(), "-inff"))
		return (1);
	return (0);
}

void	ScalarConverter::convert(string str)
{
	string		fractionString;
	int 		fractionLength;
	double		doublevalue;
	float		fraction;
	float		floatvalue;
	int			intvalue;
	int			type;
	int 		pos;

	type = getType(str);
	pos = str.find(".");
	fractionString = &str[pos + 1];
	if (type == DOUBLETYPE)
	{
		fractionLength = fractionString.length();
		fraction = ft_atoi(fractionString) * pow(10, - fractionLength);
		doublevalue = ft_atoi(str.substr(0, pos)) + fraction;
		display(doublevalue);
	}
	else if (type == FLOATTYPE)
	{
		fractionLength = fractionString.length() - 1;
		fraction = ft_atoi(fractionString) * pow(10, - fractionLength);
		floatvalue = ft_atoi(str.substr(0, pos)) + fraction;
		display(floatvalue);
	}
	else if (type == INTTYPE)
	{
		intvalue = ft_atoi(str);
		display(intvalue);
	}
	else if (type == CHARTYPE)
		display((int)str[0]);
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
	float 3.75

	0011.11
	1.111 * 2 ^ 1
	
	0 10000000 10000000000000000000

0
*/