/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:03:05 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 01:51:03 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include "utils.hpp"

class PmergeMeList
{
	public:
		typedef	std::list<int>							list;
		typedef std::list<list>							listOflists;
		typedef std::list<list>::iterator				ite_to_lstOflists;
		typedef	std::list<int>::iterator				list_iterator;
		typedef std::pair<list, ite_to_lstOflists>		pend_pair;
		typedef std::list<std::pair<list, ite_to_lstOflists> >				pend;
		typedef std::list<std::pair<list, ite_to_lstOflists> >::iterator	pend_iterator;

	public:
		listOflists			mainChain;
		listOflists			V_vec;
		list 				data;
		list 				copy;
		list 				rest;
		size_t				elementSize;
		size_t				comparisonCount;
		pend 				pendChain;
		long				odd_number;

	public:
		PmergeMeList();
		~PmergeMeList();

		listOflists		Sort_paires();
		listOflists		make_paires();
		listOflists		create_paires();
	
		void		insert_pend_to_main();
		void		sort_elements(listOflists& arr);
		void		flaten_data(listOflists& V_vec);
		void		insertion();
		void		sort_pair_elements(list& vec);
		bool 		more_than_one_element(listOflists& arr);
		void		create_main_and_pend(listOflists& arr);
		void		is_double(int num);
		void		store_numbers(char **av);
		void		mergeSort();

		void		print(string str);
		void		print_array_vectors(listOflists arr, string str);
		void		print_pendCain();
		void		print_vector_elements(list vec);
};


#endif