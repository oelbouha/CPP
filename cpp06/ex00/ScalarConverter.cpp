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

void	displayChar(char c)
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

void	displayInt(int nb)
{
	displayChar(nb);
	cout <<  "int: " << nb << endl;
	cout <<  "float: " << nb << ".0" << "f" << endl;
	cout <<  "double: " << nb << ".0" << endl;
}

int	isInf(string str)
{
	string arr[6] = {"+inf", "-inf", "inf", "+inff", "-inff", "inff"};
	for(int i = 0; i < 6; i++)
		if (str == arr[i])
			return (1);
	return (0);
}

void	ScalarConverter::convert(string str)
{
	int		type;

	type = getType(str);
	if (type == DOUBLE || type == FLOAT)
		displayNumbers(std::strtod(str.c_str(), NULL), str.length());
	else if (type == INT)
		displayInt(std::strtod(str.c_str(), NULL));
	else if (type == CHAR)
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

