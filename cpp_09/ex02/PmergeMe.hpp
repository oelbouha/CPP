/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:20:58 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/12 09:53:00 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::string;

class PmergeMe
{
	public:
		std::vector<int> data;
		std::vector<int>::iterator it;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& original);
		~PmergeMe();

		void	InsertionSort();
		void	is_double(int num);
		void	print(string str);
};


#endif