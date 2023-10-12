/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:01:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/12 10:07:06 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	is_number(string str)
{
	size_t i;

	for(i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	skip_spaces(string str)
{
	size_t i;
	for(i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (i);	
	}
	return (0);
}

void init(char *input)
{
	RPN rpn;

	rpn.valid_input(input);
	rpn.reverseNotation(input);
	if (rpn.stack_size() == 1)
		cout << "result ==> " << rpn.getResult() << endl;
	else
	{
		cout << "error: not a valid input" << endl;
	}
}

int main(int c, char **v)
{
	if (c != 2)
	{
		cout << "error: No input found" << endl;
		return (1);
	}
	try
	{
		init(v[1]);	
	}
	catch(const char *error)
	{
		cout << "error: " << error << endl;
	}
	return 0;
}
