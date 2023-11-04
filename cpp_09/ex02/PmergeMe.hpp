/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:20:58 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/04 10:44:32 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <exception>
#include <algorithm>
#include <list>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::string;

class PmergeMe
{
	public:
		typedef	std::vector<int>									vector;
		typedef std::vector<vector>									vector_of_vectors;
		typedef std::vector<vector>::iterator						iterator_to_vec_of_vectors;
		typedef std::vector<vector>::iterator 						iterator_to_vector;
		typedef	std::vector<int>::iterator							vector_iterator;
		typedef	std::pair<std::vector<int>, std::vector<int> >		pair_of_vector;
		typedef std::vector<std::pair<vector, vector> >				vec_of_pair_vector;
		typedef std::vector<std::pair<vector, vector> >::iterator	iterator_to_pair_vector;
		typedef std::vector<std::pair<vector, iterator_to_vec_of_vectors> > pend;
		typedef std::vector<std::pair<vector, iterator_to_vec_of_vectors> >::iterator pend_iterator;

	public:
		vector_of_vectors	mainChain;
		pend 				pendChain;
		int		index;
		bool	odd;
		long	odd_value;
		vector 	data;
		pair_of_vector 	rest;

	public:
		PmergeMe();
		~PmergeMe();

		vec_of_pair_vector	create_pairs(int size);
		void		insertion();
		void		copy_mainchain_to_data();
		void		copy_data_to_mainchain(int size);
		void		copy_mainChain_to_array(vec_of_pair_vector& arr);
		void		insert_pend_to_data(vector_iterator pos, vector vec);
		void		setup_mdata(vec_of_pair_vector& arr);
		void		make_new_array(vec_of_pair_vector& arr);
		void		make_paires(vec_of_pair_vector& arr);
		void		split_paires(vec_of_pair_vector& arr);
		void		create_mainChain(vec_of_pair_vector& arr);
		void		Sort_paires(vec_of_pair_vector& arr);
		void		sort_each_pair(pair_of_vector& vec);
		void		InsertionSort(vector data);
		void		mergeInsertion(vector vec, int left, int right);
		void		is_double(int num);
		void		store_numbers(char **av);
		void		mergeSort(vec_of_pair_vector& arr);
		bool		is_odd();

/*********************************   debug functions ***********************************/

		void		print(string str);
		void		print_array(vec_of_pair_vector& arr);
		void		print_array_vectors(vector_of_vectors arr, string str);
		void		print_pendCain();
		void		print_vector_elements(vector vec);
};

void	is_positive_number(string input);

#endif