/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:50:07 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/11 11:38:23 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

void	init()
{
	Serializer obj;

	Data *ptr = new Data(10);
	ptr->print();

	ptr = obj.deserialize(obj.serialize(ptr));
	ptr->print();

	delete ptr;
}

int main()
{
	init();
	return (0);
}
