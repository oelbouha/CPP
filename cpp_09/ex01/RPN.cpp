/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:43:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/11 11:18:59 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	result = 0;
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& copy)
{
	if (this != &copy)
	{
		
	}
	return (*this);
}

RPN::~RPN(){}

void	RPN::execute_operation(string str)
{
	int	n1;
	int	n2;

	if (stack.size() == 1)
	{
		cout << "error: not a valid input" << endl;
		exit(0);
	}
	it = stack.end();
	n1 = *--it;
	n2 = *--it;
	if (str == "+")
		result = n1 + n2;
	else if (str == "-")
		result = n2 - n1;
	else if (str == "*")
		result = n2 * n1;
	else if (str == "/")
		result = n2 / n1;
	stack.erase(it);
	stack.erase(++it);
	stack.push_back(result);
}

int	RPN::valid_input(string input)
{
	size_t	i;

	for(i = 0; i < input.length() - 1; i++)
	{
		if (isdigit(input[i]) && isdigit(input[i + 1]))
			return (0);
		else if (strchr(" */-+", input[i]) == NULL && !isdigit(input[i]))
			return (0);
	}
	return (1);
}

void	RPN::reverseNotation(string input)
{
	string	str;
	int		last;
	int		value;

	input = input.substr(skip_spaces(input));
	last = input.length();
	if (input[last - 1] == ' ')
		last = input.find_last_not_of(" \t");
	input = input.substr(0, last + 1);
	while (input.length())
	{
		str = input.substr(0, 1);
		input = input.substr(1);
		input = input.substr(skip_spaces(input));
		if (is_number(str))
		{
			value = std::strtod(str.c_str(), NULL);
			stack.push_back(value);
		}
		else
			execute_operation(str);
	}
}

int	RPN::getResult()
{
	return (result);
}

int	RPN::stack_size()
{
	return (stack.size());
}

