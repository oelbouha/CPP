/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:20:58 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/06 20:55:36 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <exception>
#include <algorithm>
#include <list>
#include <sys/_types/_size_t.h>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::string;

class PmergeMe
{
	public:
		typedef	std::vector<int>						vector;
		typedef std::vector<vector>						vectorOfVectors;
		typedef std::vector<vector>::iterator			iterator_to_vecOfVectors;
		typedef	std::vector<int>::iterator				vector_iterator;
		typedef std::pair<vector, iterator_to_vecOfVectors>	pend_pair;
		typedef std::vector<std::pair<vector, iterator_to_vecOfVectors> >		pend;
		typedef std::vector<std::pair<vector, iterator_to_vecOfVectors> >::iterator	pend_iterator;

	public:
		vectorOfVectors	mainChain;
		vectorOfVectors	V_vec;
		pend 	pendChain;
		size_t	elementSize;
		long	odd_number;
		vector 	data;
		vector 	copy;
		vector 	rest;

	public:
		PmergeMe();
		~PmergeMe();

		vectorOfVectors		Sort_paires();
		vectorOfVectors		make_paires();
		vectorOfVectors		create_paires();
		void				insert_pend_to_main();
	
		void		sort_elements(vectorOfVectors& arr);
		void		flaten_data(vectorOfVectors& V_vec);
		void		insertion();
		void		sort_pair_elements(vector& vec);
		bool 		more_than_one_element(vectorOfVectors& arr);
		void		create_main_and_pend(vectorOfVectors& arr);

		void		is_double(int num);
		void		store_numbers(char **av);
		void		mergeSort();
		bool		is_odd();

		void		print(string str);
		void		print_array_vectors(vectorOfVectors arr, string str);
		void		print_pendCain();
		void		print_vector_elements(vector vec);
};

void	is_positive_number(string input);

#endif