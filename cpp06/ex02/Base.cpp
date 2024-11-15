
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:16:58 by oelbouha          #+#    #+#             */
/*   Updated: 2023/08/26 15:30:07 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base(){}

Base::~Base(){}

void	free_array(Base **arr, int i)
{
	for(int j = 0; j < 3; j++)
	{
		if (j != i)
			delete arr[j];
	}
}

Base*	Base::generate(void)
{
	int		random_number;
	Base	*arr[3];
	
	arr[0] = new A();
	arr[1] = new B();
	arr[2] = new C();
	srand(time(0));
	random_number = rand() % 3;
	free_array(arr, random_number);
	return (arr[random_number]);
}

void	Base::identify(Base *p)
{
	string	names[3] = {"A", "B", "C"};
	Base 	*arr[3];
	int		i;

	arr[0] = dynamic_cast<A*>(p);
	arr[1] = dynamic_cast<B*>(p);
	arr[2] = dynamic_cast<C*>(p);
	for(i = 0; i < 3 && arr[i]; i++);
	cout << names[i] << endl;
}

void	Base::identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		cout << "A" << endl;
		return ;
		(void)a;
	}
	catch(std::bad_cast& e){}
	try
	{
		B &b = dynamic_cast<B&>(p);
		cout << "B" << endl;
		return ;
		(void)b;
	}
	catch(std::bad_cast& e){}
	try
	{
		C &c = dynamic_cast<C&>(p);
		cout << "C" << endl;
		(void)c;
	}
	catch(std::bad_cast& e){}
}