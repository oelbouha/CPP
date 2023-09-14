/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:16:58 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/11 11:44:00 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(const Serializer& other)
{
	cout << "Serializer copy constructor called" << endl;
	*this = other;
}

Serializer& Serializer::operator=(const Serializer& copy)
{
	cout << "Serializer copy assignment constructor called" << endl;
	if (this != &copy)
	{
		
	}
	return (*this);
}

Serializer::Serializer()
{
	cout << "Serializer Default constructor called" << endl;
}

Serializer::~Serializer()
{
	cout << "Serializer Destructor called" << endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast <uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast <Data *>(raw));
}
