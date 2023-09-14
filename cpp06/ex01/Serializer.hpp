/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:35:13 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/11 11:43:56 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
  
using std::cout;
using std::string;
using std::endl;

#include "Data.hpp"
class Data;

class	Serializer
{
	private:
		
	public:
		Serializer();
		Serializer(const Serializer& other);
		Serializer&	operator=(const Serializer& original);
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};



#endif


