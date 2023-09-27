/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:51:44 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/24 12:35:29 by oelbouha         ###   ########.fr       */
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
	private:
		std::stack<T> mystack;

	public:
		MutantStack(){};
		MutantStack(const MutantStack& copy){
			(void)copy;
		};
		MutantStack& operator=(const MutantStack& copy){
			(void)copy;
		};
		virtual ~MutantStack(){};
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin(){
			return (this->c.begin());
		};
		iterator end(){
			return (this->c.end());
		};
};

#endif