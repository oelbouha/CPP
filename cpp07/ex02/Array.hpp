/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:51:44 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/06 18:14:05 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

template <class T>
class Array
{
	private:
		T	*arr;
		int	arr_size;
		int	index;
	public:
		Array(){
			arr = NULL;
			arr_size = 0;
			index = 0;
		};
		Array(unsigned int n){
			arr = new T[n];
			arr_size = n;
			index = 0;
		};
		Array(const Array& copy){
			this->arr = new T[copy.arr_size];
			for (int i = 0; i < copy.arr_size; i++)
				arr[i] = copy.arr[i];
			arr_size = copy.arr_size; 
		};
		Array& operator=(const Array& copy){
			delete[] arr;
			arr = new T[copy.arr_size];
			for (int i = 0; i < copy.arr_size; i++)
				arr[i] = copy.arr[i];
			arr_size = copy.arr_size; 
			return (*this);
		};
		T& operator[](int index){
			if (index > arr_size)
				throw "index is biger than arr size";
			return (arr[index]);
		};
		~Array(){
			delete[] arr;
		};
		int	size() const{
			return (arr_size);
		};
		void	push(T data){
			if (index >= arr_size)
				throw "Array is full";
			arr[index] = data;
			index++;
		}
};


#endif