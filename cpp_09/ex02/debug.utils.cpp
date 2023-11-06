/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.utils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:57:45 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/06 21:55:55 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

void	PmergeMe::print_array_vectors(vectorOfVectors vec, string str)
{
	iterator_to_vecOfVectors	cur;
	vector_iterator 	it;
	vector	temp;

	cout << str << ": \n{";
	cur = vec.begin();
	while (cur != vec.end())
	{
		cout << "[";
		for(it = cur->begin(); it != cur->end(); it++)
			cout << *it << " ";
		cout << "]";
		cur++;	
	}
	cout << "}" << endl;
}

void	PmergeMe::print_pendCain()
{
	iterator_to_vecOfVectors scnd;
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