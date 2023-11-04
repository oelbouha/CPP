/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:43:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/04 12:44:41 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): index(0){
	odd_value = -1;
}

PmergeMe::~PmergeMe(){}

bool	PmergeMe::is_odd(){
	return (data.size() % 2 ? true : false);
}

void	PmergeMe::store_numbers(char **av)
{
	long	num;

	for(int i = 0; av[i]; i++)
	{
		is_positive_number(av[i]);
		num = std::strtod(av[i], NULL);
		is_double(num);
		data.push_back(num);
	}
	if (is_odd())
	{
		odd_value = *--data.end();
		data.pop_back();
	}
}

void	PmergeMe::is_double(int num)
{
	vector_iterator it;

	it = std::find(data.begin(), data.end(), num);
	if (it != data.end())
		throw std::invalid_argument("There is double");
}

void	PmergeMe::sort_each_pair(PmergeMe::pair_of_vector& vec)
{
	vector_iterator	first;
	vector_iterator	second;
	int		temp;

	first = vec.first.begin();
	second = vec.second.begin();
	if (*first > *second)
	{
		temp = *first;
		vec.first[0] = *second;
		vec.second[0] = temp;
	}
}

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
		sort_each_pair(pair);
		arr.push_back(pair);
		cur += size;
	}
	return (arr);
}

void	PmergeMe::mergeInsertion(vector vec, int left, int right)
{
	vec_of_pair_vector	vec_arr;
	(void)vec;

	int mid = (right + left) / 2;
	(void)mid;
	vec_arr = create_pairs(2);
	mergeSort(vec_arr);
}

void	PmergeMe::Sort_paires(vec_of_pair_vector& arr)
{
	iterator_to_pair_vector		cur;
	iterator_to_pair_vector		prev;
	vector_iterator				first;
	vector_iterator				second;
	vector						temp_first;
	vector						temp_second;

	cur = arr.begin();
	while (cur != arr.end() - 1)
	{
		prev = cur;
		first = cur->second.end() - 1;
		cur++;
		second = cur->second.end() - 1;
		if (*first > *second)
		{
			temp_first = prev->first;
			temp_second = prev->second;
			prev->first = cur->first;
			prev->second = cur->second;
			cur->first = temp_first;
			cur->second = temp_second;
			cur = arr.begin();
		}
	}
}

void	PmergeMe::make_paires(vec_of_pair_vector& arr)
{
	iterator_to_pair_vector cur;
	iterator_to_pair_vector	prev;
	vector					first;
	vector					second;

	if (arr.size() == 1)
		return ;
	if (arr.size() % 2)
	{
		cur = arr.end() - 1;
		rest.first = cur->first;
		rest.second = cur->second;
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
	if (cur->first.size() == 1)
		return ;
	while (cur != arr.end())
	{
		size = cur->first.size() / 2;
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
	arr = new_arr;
}

void	PmergeMe::copy_mainChain_to_array(vec_of_pair_vector& arr)
{
	iterator_to_vector		cur;
	vector_iterator			it;
	pair_of_vector			pair;

	arr.clear();
	cur = mainChain.begin();
	while (cur != mainChain.end())
	{
		pair.first.clear();
		pair.second.clear();
		for (it = cur->begin(); it != cur->end(); it++)
			pair.first.push_back(*it);
		cur++;
		if (cur == mainChain.end())
			break ;
		for (it = cur->begin(); it != cur->end(); it++)
			pair.second.push_back(*it);
		arr.push_back(pair);
		cur++;
	}
}

void	PmergeMe::copy_mainchain_to_data()
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

void	PmergeMe::insert_pend_to_data(vector_iterator pos, vector vec)
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

void	PmergeMe::copy_data_to_mainchain(int size)
{
	iterator_to_vec_of_vectors main;
	vector_iterator it;
	vector temp;

	mainChain.clear();
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
}

void	PmergeMe::insertion()
{
	iterator_to_vec_of_vectors it;
	vector_iterator		pos;
	vector_iterator		ite;
	pend_iterator	pend_it;
	int num;

	copy_mainchain_to_data();
	pend_it = pendChain.begin();
	while (pend_it != pendChain.end())
	{
		if (pend_it->first.size())
			num = pend_it->first[0];
		else
		 	num = *pend_it->first.begin();
		cout << " Inserting number ---> " << num << endl;
		pos = std::lower_bound(data.begin(), data.end(), num);
		insert_pend_to_data(pos, pend_it->first);
		pend_it++;
	}
	copy_data_to_mainchain(mainChain.begin()->size());
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
	it = arr.begin();
	mainChain.push_back(it->first);
	mainChain.push_back(it->second);
	it++;
	cur = mainChain.begin();
	while (it != arr.end())
	{
		mainChain.push_back(it->second);
		pair.first  = it->first;
		pair.second = mainChain.end() - 1;
		pendChain.push_back(pair);
		it++;
	}
	if (odd_value != -1 && arr.begin()->first.size() == 1)
	{
		printf("first ......\n");
		pair.first.clear();
		pair.second->clear();
		pair.first.push_back(odd_value);
		pair.second = mainChain.end() - 1;
		pendChain.push_back(pair);
		odd_value = -1;
	}
	// print_array(arr);
	insertion();
	// print_pendCain();
	copy_mainChain_to_array(arr);
	// print_array_vectors(mainChain, "mainChain");
}


void	PmergeMe::mergeSort(vec_of_pair_vector& arr)
{
	if (arr.size() != 1)
	{
		Sort_paires(arr);
		make_paires(arr);
		mergeSort(arr);
	}
	cout << "***********-------- reverse recursion ---------**********\n\n";
	// setup_mdata(arr);
	// print_vector_elements(data);
	split_paires(arr);
	// create_mainChain(arr);
	print_array(arr);
	cout << " ***********--   ------------------------    --**********\n\n";
}

void PmergeMe::InsertionSort(vector data)
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

// void	PmergeMe::setup_mdata(vec_of_pair_vector& arr)
// {
// 	iterator_to_vector	cur;
// 	vector_iterator 	it;
// 	iterator_to_pair_vector ite;

// 	// data.clear();
// 	// for (cur = mainChain.begin(); cur != mainChain.end(); cur++)
// 	// 	for(it = cur->begin(); it != cur->end(); it++)
// 	// 		data.push_back(*it);
// 	ite = arr.begin();
// 	int size = ite->first.size() / 2;
// 	cout << "size : " << size << endl;
// 	vec_of_pair_vector	new_arr;
// 	pair_of_vector		pair;

// 	printf("here -------> \n");
// 	print_vector_elements(data);
// 	it = data.begin();
// 	while (it != data.end())
// 	{
// 		pair.first.clear();
// 		pair.second.clear();
// 		for (int i = size; i; i--, it++)
// 			pair.first.push_back(*it);
// 		for (int i = size; i; i--, it++)
// 			pair.second.push_back(*it);
// 		// sort_each_pair(pair);
// 		new_arr.push_back(pair);
// 		// it += size;
// 	}
// 	arr = new_arr;
// 	print_array(new_arr);
// 	printf("here -------> \n");
// }