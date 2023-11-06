/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:07:02 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/05 21:43:50 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool
PmergeMe::is_odd(){
	return (data.size() % 2 ? true : false);
}

void
PmergeMe::sort_pair_elements(PmergeMe::pair_of_vector& vec)
{
	int	temp;

	if (vec.first > vec.second)
	{
		temp = vec.first[0];
		vec.first[0] = vec.second[0];
		vec.second[0] = temp;
	}
}

void
PmergeMe::is_double(int num)
{
	vector_iterator it;

	it = std::find(data.begin(), data.end(), num);
	if (it != data.end())
		throw std::invalid_argument("There is double");
}

void
PmergeMe::store_numbers(char **av)
{
	long	num;

	for(int i = 0; av[i]; i++)
	{
		is_positive_number(av[i]);
		num = std::strtod(av[i], NULL);
		is_double(num);
		data.push_back(num);
	}
}

void
PmergeMe::copy_data_to_mainchain(int size)
{
	iterator_to_vec_of_vectors main;
	vector_iterator it;
	vector temp;

	// cout << "size to copy : " << size << endl;
	mainChain.clear();
	// print_vector_elements(data);
	for(it = data.begin(); it != data.end(); )
	{
		for(int i = size; i; i--)
		{
			temp.push_back(*it);
			it++;
		}
		mainChain.push_back(temp);
		temp.clear();
	}
	// print_array_vectors(mainChain, "mainchain : -->");
}

void
PmergeMe::insert_pend_to_data(vector_iterator pos, vector vec)
{
	vector_iterator it;

	it = vec.begin();
	while (it != vec.end())
	{
		data.insert(pos, *it);
		pos++;
		it++;
	}
}

void
PmergeMe::copy_mainchain_to_data()
{
	iterator_to_vector	cur;
	vector_iterator 	it;

	data.clear();
	cur = mainChain.begin();
	while (cur != mainChain.end())
	{
		for(it = cur->begin(); it != cur->end(); it++)
			data.push_back(*it);
		cur++;	
	}
}

void
PmergeMe::InsertionSort(vector data)
{
	vector_iterator previous;
	vector_iterator prev;
	vector_iterator cur;
	vector_iterator it;
	int	temp;
	int	idx;
	int	iteration;

	prev = data.begin();
	for(it = prev + 1, idx = 1; it != data.end(); it++, idx++, prev++)
	{
		cur = it;
		temp = *it;
		previous = prev;
		for(iteration = idx; iteration; iteration--)
		{
			if (temp < *previous)
			{
				data.erase(cur);
				data.insert(cur - 1, temp);
				previous--;
				cur--;
			}
		}
	}	
}

/*

	2 11  1 55   0  120  10 140 
	
	0  120
	2 11  
	1 55  
	10 140 

	0  1
	2 10 
	120 11 
	55 140

	0 1 2 10 11 120 140
*/

/*
	its___titimarh
	alaouisana02
	0613068849
*/