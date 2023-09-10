/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:35:13 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/07 11:11:50 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>  

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
	private:


	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& original);
		~ScalarConverter();

		static void	convert(string str);
};


int	ft_atoi(string str);
int	getType(string str);

#endif


