/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:20:58 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/21 12:59:17 by oelbouha         ###   ########.fr       */
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
		static const int	insertion = 10;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& original);
		~PmergeMe();

		void	InsertionSort(std::vector<int>& data, int left, int right);
		void	mergeInsertion(std::vector<int>& data, int left, int right);
		void	is_double(int num);
		void	print(string str);
		// PmergeMe data(size);
};


#endif