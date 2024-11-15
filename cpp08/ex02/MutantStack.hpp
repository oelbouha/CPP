/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:51:44 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/20 13:26:01 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <vector>

using std::cout;
using std::endl;

template <typename T> 
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename MutantStack<T>::iterator ite;

		MutantStack(){};
		MutantStack(MutantStack& copy){
			*this = copy;
		};
		MutantStack& operator=(MutantStack& copy)
		{
			if (this == &copy)
				return (*this);
			for (ite it = copy.begin(); it != copy.end(); it++)
				this->push(*it);
			return (*this);
		};
		virtual ~MutantStack(){};
		iterator begin() {
			return (this->c.begin());
		};
		iterator end(){
			return (this->c.end());
		};
		void print()
		{
			for (ite  it = this->begin(); it != this->end(); it++)
				cout << "data: " << *it << endl;	
		};
 };

#endif