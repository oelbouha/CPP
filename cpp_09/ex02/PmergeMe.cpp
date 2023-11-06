/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:43:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/06 10:08:45 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <utility>

PmergeMe::PmergeMe(): index(0){
	odd_value = -1;
	elsize = true;
	index = 0;
}

PmergeMe::~PmergeMe(){}

PmergeMe::vec_of_pair_vector	PmergeMe::create_pairs(int size)
{
	vec_of_pair_vector	arr;
	vector_iterator		cur;
	pair_of_vector		pair;

	cur = data.begin();
	while (cur != data.end())
	{
		pair.first.clear();
		pair.second.clear();
		pair.first.push_back(*cur);
		pair.second.push_back(*(cur + 1));
		sort_pair_elements(pair);
		arr.push_back(pair);
		cur += size;
	}
	return (arr);
}

void	PmergeMe::mergeInsertion()
{
	vec_of_pair_vector	vec_arr;

	vec_arr.reserve(data.size());
	mergeSort(vec_arr);
}

void	PmergeMe::Sort_paires(vec_of_pair_vector& arr)
{
	iterator_to_pair_vector		cur;
	iterator_to_pair_vector		prev;
	vector_iterator				first;
	vector_iterator				second;
	pair_of_vector				temp;

	cur = arr.begin();
	while (cur != arr.end() - 1)
	{
		prev = cur;
		first = cur->second.end() - 1;
		cur++;
		second = cur->second.end() - 1;
		if (*first > *second)
		{
			temp.first = prev->first;
			temp.second = prev->second;
			prev->first = cur->first;
			prev->second = cur->second;
			cur->first = temp.first;
			cur->second = temp.second;
		}
	}
}

void	PmergeMe::make_paires(vec_of_pair_vector& arr)
{
	iterator_to_pair_vector cur;
	iterator_to_pair_vector	prev;
	vector					first;
	vector					second;
	pair_of_vector frst;
	pair_of_vector scnd;

	if (index == 1)
	{
		if (is_odd())
		{
			odd_value = *--data.end();
			data.pop_back();
		}
		arr = create_pairs(2);
		// data.clear();
	}
	if (arr.size() % 2)
	{
		cur = arr.end() - 1;
		rest = cur->first;
		rest.insert(rest.end(), cur->second.begin(), cur->second.end());
		arr.erase(cur);
	}
	cur = arr.begin();
	while (cur != arr.end())
	{
		first.clear();
		second.clear();
		prev = cur;
		first = cur->first;
		first.insert(first.end(),cur->second.begin(), cur->second.end());
		cur++;
		prev->first = first;
		second = cur->first;
		second.insert(second.end(),cur->second.begin(), cur->second.end());
		prev->second = second;
		arr.erase(cur);
	}
}

void	PmergeMe::split_paires(vec_of_pair_vector& arr)
{
	iterator_to_pair_vector	cur;
	vec_of_pair_vector		new_arr;
	pair_of_vector			pair1;
	pair_of_vector			pair2;
	size_t		size;

	cur = arr.begin();
	size = cur->first.size() / 2;
	if (cur->first.size() == 1)
		return ;
	while (cur != arr.end())
	{
		pair1.first.clear();
		pair1.second.clear();
		pair1.first.assign(cur->first.begin(), (cur->first.end() - size));
		pair1.second.assign((cur->first.end() - size), cur->first.end());
		new_arr.push_back(pair1);
		pair2.first.clear();
		pair2.second.clear();
		pair2.first.assign(cur->second.begin(), (cur->second.end() - size));
		pair2.second.assign((cur->second.end() - size), cur->second.end());
		new_arr.push_back(pair2);
		cur++;
	}
	if (mainchain_rest.size())
	{
		pair2.first.clear();
		pair2.second.clear();
		pair2.first.assign(mainchain_rest.begin(), (mainchain_rest.end() - size));
		pair2.second.assign((mainchain_rest.end() - size), mainchain_rest.end());
		new_arr.push_back(pair2);
		mainchain_rest.clear();
	}
	arr = new_arr;
}

void	PmergeMe::copy_mainChain_to_array(vec_of_pair_vector& arr)
{
	iterator_to_vector		cur;
	vector_iterator			it;
	pair_of_vector			pair;

	if (mainChain.size() % 2 )
	{
		mainchain_rest = mainChain[mainChain.size() - 1];
		printf("xyata :: --> \n");
		print_vector_elements(mainchain_rest);
		mainChain.erase(mainChain.end() - 1);
	}
	arr.clear();
	int size = mainChain.size();
	int i = 0;
	while (i < size)
	{
		pair.first = mainChain[i];
		pair.second = mainChain[i + 1];
		arr.push_back(pair);
		i += 2;
	}
	if (mainchain_rest.size())
	{
		// pair.first = mainchain_rest;
		// // pair.second = mainchain_rest;
		// arr.push_back(pair);
		// mainchain_rest.clear();
	}
}

void	PmergeMe::insertion()
{
	iterator_to_vec_of_vectors it;
	vector_iterator		pos;
	vector_iterator		ite;
	pend_iterator	pend_it;
	int num;

	// print_vector_elements(data);
	pend_it = pendChain.begin();
	while (pend_it != pendChain.end())
	{
		num = pend_it->first.back();
		pos = std::lower_bound(data.begin(), data.end(), num);
		insert_pend_to_data(pos, pend_it->first);
		pend_it++;
	}
	copy_data_to_mainchain(mainChain.begin()->size());
	// print_array_vectors(mainChain, "mainchain : ");
}

void	PmergeMe::create_mainChain(vec_of_pair_vector& arr)
{
	cout << "creating main and pend Chain .....\n\n";
	std::pair<vector, iterator_to_vec_of_vectors> pair;
	iterator_to_pair_vector 	it;
	iterator_to_vec_of_vectors	cur;
	iterator_to_vec_of_vectors	pend_it;
	vector		pend_vec;
	
	if (arr.size() == 1)
		return ;
	mainChain.clear();
	pendChain.clear();
	pendChain.reserve(1000);
	it = arr.begin();
	mainChain.push_back(it->first);
	mainChain.push_back(it->second);
	print_array(arr);
	it++;
	while (it != arr.end())
	{
		mainChain.push_back(it->second); // insert instead
		pair.first  = it->first;
		pair.second = mainChain.end() - 1;
		pendChain.push_back(pair);
		it++;
	}
	copy_mainchain_to_data();
	if (rest.size())
	{
		pair.first = rest;
		pair.second = mainChain.end() - 1;
		pendChain.push_back(pair);
		rest.clear();
	}
	if (odd_value != -1 )
	{
		cout << "od value : " << odd_value << endl;
		pair.first.clear();
		pair.second->clear();
		pair.first.push_back(odd_value);
		pair.second = mainChain.end() - 1;
		pendChain.push_back(pair);
		odd_value = -1;
	}
	// print_array(arr);
	// print_array_vectors(mainChain, "mainchain: -->");
	// print_pendCain();
	insertion();
	copy_mainChain_to_array(arr);
	// mainChain.clear();

	/*
		mainChain is a vector of vectors;
		--- inserted all pend to mainChain
			insert rest to the end of mainChain
			flatten and assign to data.
	*/
}


void	PmergeMe::mergeSort(vec_of_pair_vector& arr)
{
	if (arr.size() != 1)
	{
		index++;
		// cout << "***********-------- recursion ---------**********\n\n";
		make_paires(arr);
		Sort_paires(arr); // return a vec of vectors 
		
		// copy vec of vectors to data
		// if (les or equal to two elements)
		// 	return ;
		// cout << " ***********--   ------------------------    --**********\n\n";
		mergeSort(arr);
	}
	cout << "--------------------------- reverse recursion -------------------------\n\n";
	index--;
	// Sort_paires(arr);
	// split_paires(arr);
	create_mainChain(arr);
	cout << " ------------------------------------------------------------\n\n";
}