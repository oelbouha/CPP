/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:43:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/06 23:54:41 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <sys/_types/_size_t.h>
#include <utility>

PmergeMe::PmergeMe()
{
	odd_number = -1;
	elementSize = 1;
}

PmergeMe::~PmergeMe(){}

bool compare(PmergeMe::vector first, PmergeMe::vector second)
{
	return (first.back() < second.back());
}

void	PmergeMe::insert_pend_to_main()
{
	iterator_to_vecOfVectors	pos;
	pend_iterator	P_it;
	
	P_it = pendChain.begin();
	// print_array_vectors(mainChain, "\nmainchain before insertion ");
	while (P_it != pendChain.end())
	{
		pos = std::lower_bound(mainChain.begin(), mainChain.end() - 1, P_it->first, compare);
		// cout << "inserting number --> " << P_it->first.back() << endl;
		// cout << "pos number --> " << pos->back() << endl;
		if (P_it->first.back() > pos->back())
			mainChain.insert(pos + 1, P_it->first);
		else
			mainChain.insert(pos, P_it->first);
		P_it++;
	}
	if (rest.size())
	{
		mainChain.insert(mainChain.end(), rest);
		rest.clear();
	}
	// print_array_vectors(mainChain, "\nmainchain after insertion ");
}

void	PmergeMe::insertion()
{
	elementSize /= 2;
	V_vec = make_paires();
	print_array_vectors(V_vec, "vector after : ");
	create_main_and_pend(V_vec);
	// print_array_vectors(mainChain, "\nmainchain before insertion ");
	// print_pendCain();
	insert_pend_to_main();
	// print_array_vectors(mainChain, "\nmainchain after insertion -- > ");
	flaten_data(mainChain);
	// print_vector_elements(data);
}

void	PmergeMe::create_main_and_pend(vectorOfVectors& V_vec)
{
	iterator_to_vecOfVectors it;
	iterator_to_vecOfVectors cur;
	vectorOfVectors main;
	pend_pair	pair;
	size_t		V_size;
	size_t		i;

	if (V_vec.back().size() != V_vec.begin()->size())
	{
		// printf("start ........ elsement size --> %lu\n", elementSize);
		rest = V_vec[V_vec.size() - 1];
		V_vec.pop_back();
	}
	pendChain.clear();
	mainChain.clear();
	pendChain.reserve(300);
	mainChain.reserve(300);
	mainChain.push_back(V_vec[0]);
	it = mainChain.insert(mainChain.end(), V_vec[1]);
	V_size = V_vec.size();
	for (i = 2; i < V_size;)
	{
		pair.first = V_vec[i];
		i++;
		if (i == V_size)
		{
			it = mainChain.end();
			pendChain.push_back(pair);
			break ;
		}
		it = mainChain.insert(mainChain.end(), V_vec[i]);
		pair.second = it;
		pendChain.push_back(pair);
		i++;
	}
}

void	PmergeMe::sort_elements(vectorOfVectors& arr)
{
	vector	temp;
	vector	second;
	vector	first;
	int		size;

	size = arr.size();
	for (int i = 0; i < size - 1; i++)
	{
		first = arr[i];
		second = arr[i + 1];
		if (second.size() != elementSize)
			break ;
		if (first.back() > second.back())
		{
			temp = first;
			arr[i] = second;
			arr[i + 1] = temp;
		}
	}
}

PmergeMe::vectorOfVectors	PmergeMe::Sort_paires()
{
	iterator_to_vecOfVectors	cur;
	vectorOfVectors				V_vec;
	vector_iterator				it;
	
	V_vec = make_paires();
	sort_elements(V_vec);
	return (V_vec);
}

PmergeMe::vectorOfVectors	PmergeMe::create_paires()
{
	vectorOfVectors		V_vec;
	vector_iterator		it;
	vector		vec;
	size_t		i;

	it = data.begin();
	while (it != data.end())
	{
		i = -1;
		while (++i < elementSize && it != data.end())
		{
			vec.push_back(*it);
			it++;
		}
		sort_pair_elements(vec);
		V_vec.push_back(vec);
		vec.clear();
	}
	return (V_vec);
}

PmergeMe::vectorOfVectors	PmergeMe::make_paires()
{
	vectorOfVectors		V_vec;
	vector_iterator		it;

	if (data.size() % 2)
	{
		odd_number = data.back();
		data.pop_back();
	}
	V_vec = create_paires();
	if (odd_number != -1)
	{
		vector temp;
		temp.push_back(odd_number);
		V_vec.push_back(temp);
		odd_number = -1;
	}
	return (V_vec);
}

void	PmergeMe::flaten_data(vectorOfVectors& V_vec)
{
	iterator_to_vecOfVectors	V_it;
	vector_iterator 	it;

	data.clear();
	V_it = V_vec.begin();
	for (; V_it != V_vec.end(); V_it++)
	{
		for (it = V_it->begin(); it != V_it->end(); it++)
			data.push_back(*it);
	}
}

void	PmergeMe::mergeSort()
{
	cout << "---------------- recursion -------------------\n";
	elementSize *= 2;
	V_vec = Sort_paires();
	flaten_data(V_vec);
	// print_array_vectors(V_vec, "vec of vectors : ");
	cout << "------------------------------------------------\n\n";
	if (more_than_one_element(V_vec))
		mergeSort();
	cout << "---------------- reverse  recursion -------------------\n";
	insertion();
	cout << "------------------------------------------------\n\n";
}