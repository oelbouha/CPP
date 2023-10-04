/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:51:44 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/03 16:47:24 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

using std::cout;
using std::endl;

template <class T>
class Array
{
	private:
		T *arr;
		int arr_size;
	public:
		Array()
		{
			cout << "default constructor called" << endl;
			arr_size = 10;
			arr = new T[arr_size];
		};
		Array(unsigned int n)
		{
			arr = new T[n];
			
			arr_size = n;
		};
		Array(const Array& copy)
		{
			cout << "copy constructor called" << endl;
			this->arr = new T[copy.arr_size];
			*this = copy;
		};
		Array& operator=(const Array& other)
		{
			cout << "copy  assignment constructor called" << endl;
			for (int i = 0; i < arr_size; i++)
			{
				arr[i] = other.arr[i];
			}
			return (*this);
		};
		~Array(){
			cout << "destructor called" << endl;
		};
		int	size() const
		{
			return (arr_size);
		};
		void	print() const
		{
			cout << arr_size<< endl;
			for(int i = 0; i < arr_size; i++)
				cout << arr[i];
			cout << endl;
		};
};


#endif