/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:50:07 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/14 22:40:33 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void	init()
{
	Data *data = new Data;
	uintptr_t p;

	data->value = 100;
	cout << "before: " << data->value << endl;
	p = Serializer::serialize(data);
	data = Serializer::deserialize(p);
	cout << "after: " << data->value << endl;
	delete data;
}

int main()
{
	init();
	return (0);
}
