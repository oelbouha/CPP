/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:43:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 00:22:26 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	comparisonCount = 0;
	odd_number = -1;
	elementSize = 1;
}

PmergeMe::~PmergeMe(){}

bool compare(PmergeMe::vector first, PmergeMe::vector second)
{
	return (first.back() < second.back());
}

void	PmergeMe::update_pend(iterator_to_vecOfVectors it)
{
	pend_iterator P_it;

	P_it = pendChain.begin();
	for (; P_it != pendChain.end(); ++P_it)
	{
		if (P_it->second >= it)
			++P_it->second;
	}
}

void	PmergeMe::insert_pend_to_main()
{
	iterator_to_vecOfVectors	pos;
	iterator_to_vecOfVectors	it;
	pend_iterator	P_it;
	long int jcb_stl[] = {
        2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
        2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
        1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
        178956970, 357913942, 715827882, 1431655766, 2863311530, 5726623062,
        11453246122, 22906492246, 45812984490
    };
	int	idx = 0;
	while (pendChain.size())
	{
		pend_iterator	end = pendChain.begin();
		pend_iterator	start = pendChain.begin();

		for (int i = 0; i < jcb_stl[idx] - 1 && start != pendChain.end(); ++i)
			++start;

		if (start == pendChain.end())
			--start;
		// cout << idx << " " << pendChain.size() << endl;
		while (true)
		{
			// cout << "here " << " " << start->first.back() << endl;
			pos = std::lower_bound(mainChain.begin(), start->second, start->first, compare);
			it = mainChain.insert(pos, start->first);
			update_pend(it);
			pendChain.erase(start);
			if (start == end)
				break ;
			--start;
		}
		++idx;
	}
	if (rest.size())
	{
		mainChain.insert(mainChain.end(), rest);
		rest.clear();
	}
}

void	PmergeMe::insertion()
{
	elementSize /= 2;
	V_vec = make_paires();
	print_array_vectors(V_vec, "vector");
	create_main_and_pend(V_vec);
	// print_pendCain();
	insert_pend_to_main();
	flaten_data(mainChain);
}

void	PmergeMe::create_main_and_pend(vectorOfVectors& V_vec)
{
	iterator_to_vecOfVectors it;
	iterator_to_vecOfVectors cur;
	pend_pair	pair;
	size_t		V_size;
	size_t		i;

	if (V_vec.back().size() != V_vec.begin()->size())
	{
		rest = V_vec[V_vec.size() - 1];
		V_vec.pop_back();
	}
	pendChain.clear();
	mainChain.clear();
	pendChain.reserve(data.size());
	mainChain.reserve(data.size());
	mainChain.push_back(V_vec[0]);
	it = mainChain.insert(mainChain.end(), V_vec[1]);
	V_size = V_vec.size();
	for (i = 2; i < V_size; i++)
	{
		pair.first = V_vec[i];
		++i;
		it = mainChain.end();
		if (i < V_size)
			it = mainChain.insert(mainChain.end(), V_vec[i]);
		pair.second = it;
		pendChain.push_back(pair);	
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
			++comparisonCount;
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
	cout << "--------------------- recursion -----------------------\n";
	elementSize *= 2;
	V_vec = Sort_paires();
	print_array_vectors(V_vec, "vector");
	flaten_data(V_vec);
	cout << "-------------------------------------------------------\n\n";
	if (more_than_one_element(V_vec))
		mergeSort();
	cout << "---------------- reverse  recursion -------------------\n";
	insertion();
	cout << "-------------------------------------------------------\n\n";
}