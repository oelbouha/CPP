/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.utils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:57:45 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/05 21:52:03 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::print_array(PmergeMe::vec_of_pair_vector& arr)
{
	iterator_to_pair_vector	it;
	vector_iterator			first;
	vector_iterator			second;

	it = arr.begin();
	while (it != arr.end())
	{
		cout << "first: { ";
		for(first = it->first.begin(); first != it->first.end(); first++)
		{
			if (first != it->first.end() - 1)
				cout << *first << ", ";
			else
				cout << *first;
		}
		cout << " }" << endl;
		cout << "second: { ";
		for(first = it->second.begin(); first != it->second.end(); first++)
			{
			if (first != it->second.end() - 1)
				cout << *first << ", ";
			else
				cout << *first;
		}
		cout << " }" << endl;
		cout << "------------- \n";
		it++;
	}
}

void	PmergeMe::print_vector_elements(vector vec)
{
	vector_iterator cur;

	// printf("----------------------------------------------------------------\n");
	cout << "vec: { ";
	cur = vec.begin();
	while (cur != vec.end())
	{
		cout << *cur << " ";
		cur++;	
	}
	cout << " } " << endl;
	// printf("----------------------------------------------------------------\n");
}

void	PmergeMe::print_array_vectors(vector_of_vectors vec, string str)
{
	iterator_to_vector	cur;
	vector_iterator 	it;
	vector	temp;

	printf("	--++++++++++++++++++++++++++++--    \n");
	cout << str << ": \n{\n";
	cur = vec.begin();
	while (cur != vec.end())
	{
		cout << "vec { ";
		for(it = cur->begin(); it != cur->end(); it++)
				cout << *it << " ";
		cout << "}" << endl;
		cur++;	
	}
	cout << "}" << endl;
	printf("	--++++++++++++++++++++++++++++-- \n");
}

void	PmergeMe::print_pendCain()
{
	iterator_to_vec_of_vectors scnd;
	pend_iterator it;
	vector_iterator cur;

	printf("	--++++++++++++++++++++++++++++--    \n");
	cout << "pendChain" << ": \n{ \n";
	it = pendChain.begin();
	while (it != pendChain.end())
	{
		cout << "vec: { ";
		cur = it->first.begin();
		for(; cur != it->first.end(); cur++)
				cout << *cur << " ";
		cout << "}" << endl;
		// if (it->second)
		it++;
	}
	cout << "}" << endl;
	printf("	--++++++++++++++++++++++++++++-- \n");
}

void PmergeMe::print(string str)
{
	vector_iterator it;

	cout << str << ": ";
	for(it = data.begin(); it != data.end(); it++)
		cout << *it << " ";
	cout << endl;
}