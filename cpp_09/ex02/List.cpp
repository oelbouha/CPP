/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:57:17 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 01:53:31 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"

void	PmergeMeList::is_double(int num)
{
	list_iterator	it;

	it = std::find(data.begin(), data.end(), num);
	if (it != data.end())
		throw std::invalid_argument("There is double");
}

bool	PmergeMeList::more_than_one_element(listOflists& arr)
{
	ite_to_lstOflists cur;

	cur = arr.begin();
	if (cur->size() == elementSize)
		++cur;
	if (cur->size() == elementSize)
		++cur;
	while (cur != arr.end())
	{
		if (cur->size() == elementSize)
		{
			++cur;
			if (cur->size() == elementSize)
				return true;
		}
		++cur;
	}
	return false;
}

void	PmergeMeList::store_numbers(char **av)
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

PmergeMeList::PmergeMeList()
{
	comparisonCount = 0;
	odd_number = -1;
	elementSize = 1;
}

PmergeMeList::~PmergeMeList(){}

bool compare(PmergeMeList::list first, PmergeMeList::list second)
{
	return (first.back() < second.back());
}

void	PmergeMeList::sort_pair_elements(list& vec)
{
	list_iterator	it;
	list_iterator	next;
	list_iterator	cur;
	int				temp;

	it = vec.begin();
	next = vec.begin();
	++next;
	cur = it;
	while (it != vec.end() && next != vec.end())
	{
		if (*it > *next)
		{
			++comparisonCount;
			std::iter_swap(it, next);
			temp = *it;
			it = vec.begin();
			next = vec.begin();
			++next;
		}
		else
		{
			++it;
			++next;
		}
	}
}

PmergeMeList::listOflists	PmergeMeList::create_paires()
{
	list_iterator	it;
	listOflists		V_vec;
	list			vec;
	size_t			i;

	it = data.begin();
	while (it != data.end())
	{
		i = -1;
		while (++i < elementSize && it != data.end())
		{
			vec.push_back(*it);
			++it;
		}
		sort_pair_elements(vec);
		V_vec.push_back(vec);
		vec.clear();
	}
	return (V_vec);
}

PmergeMeList::listOflists	PmergeMeList::make_paires()
{
	ite_to_lstOflists		it;
	listOflists				V_vec;
	list					temp;

	if (data.size() % 2)
	{
		odd_number = data.back();
		data.pop_back();
	}
	V_vec = create_paires();
	if (odd_number != -1)
	{
		temp.push_back(odd_number);
		V_vec.push_back(temp);
		odd_number = -1;
	}
	return (V_vec);
}

void	PmergeMeList::sort_elements(listOflists& arr)
{
	ite_to_lstOflists cur;
	ite_to_lstOflists next;
	list	temp;
	list	second;
	list	first;

	next = arr.begin();
	++next;
	for (cur = arr.begin(); cur != arr.end() && next != arr.end(); ++cur)
	{
		if (next->size() != elementSize)
			break ;
		if (cur->back() > second.back())
			std::swap(cur, next);
	}
}

PmergeMeList::listOflists	PmergeMeList::Sort_paires()
{
	ite_to_lstOflists	cur;
	listOflists			V_vec;
	listOflists			it;
	
	V_vec = make_paires();
	sort_elements(V_vec);
	return (V_vec);
}

void	PmergeMeList::flaten_data(PmergeMeList::listOflists& V_vec)
{
	ite_to_lstOflists	V_it;
	list_iterator 		it;

	data.clear();
	for (V_it = V_vec.begin(); V_it != V_vec.end(); ++V_it)
	{
		for (it = V_it->begin(); it != V_it->end(); ++it)
			data.push_back(*it);
	}
}


void	PmergeMeList::create_main_and_pend(listOflists& V_vec)
{
	list				temp;
	ite_to_lstOflists	it;
	ite_to_lstOflists	cur;
	pend_pair			pair;

	if (V_vec.back().size() != V_vec.begin()->size())
	{
		rest = V_vec.back();
		V_vec.pop_back();
	}
	pendChain.clear();
	mainChain.clear();
	mainChain.push_back(V_vec.front());
	V_vec.pop_front();
	it = mainChain.insert(mainChain.end(), V_vec.front());
	V_vec.pop_front();
	while (V_vec.size())
	{
		pair.first = V_vec.front();
		V_vec.pop_front();
		it = mainChain.end();
		if (!V_vec.empty())
			it = mainChain.insert(mainChain.end(), V_vec.front());
		pair.second = it;
		pendChain.push_back(pair);
		if (V_vec.size())
			V_vec.pop_front();
	}
}

void	PmergeMeList::insert_pend_to_main()
{
	ite_to_lstOflists	pos;
	ite_to_lstOflists	it;
	pend_iterator		P_it;
	pend_iterator		end;
	pend_iterator		start;
	int		idx;

	long int jcb_stl[] = {
        2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
        2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
        1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
        178956970, 357913942, 715827882, 1431655766, 2863311530, 5726623062,
        11453246122, 22906492246, 45812984490
    };
	idx = 0;
	while (pendChain.size())
	{
		end = pendChain.begin();
		start = pendChain.begin();
		for (int i = 0; i < jcb_stl[idx] - 1 && start != pendChain.end(); ++i)
			++start;
		if (start == pendChain.end())
			--start;
		while (true)
		{
			pos = std::lower_bound(mainChain.begin(), start->second, start->first, compare);
			it = mainChain.insert(pos, start->first);
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

void	PmergeMeList::insertion()
{
	elementSize /= 2;
	V_vec = make_paires();
	create_main_and_pend(V_vec);
	insert_pend_to_main();
	flaten_data(mainChain);
}

void	PmergeMeList::mergeSort()
{
	cout << "--------------------- recursion -----------------------\n";
	elementSize *= 2;
	V_vec = Sort_paires();
	// print_array_vectors(V_vec, "list");
	flaten_data(V_vec);
	cout << "-------------------------------------------------------\n\n";
	if (more_than_one_element(V_vec))
		mergeSort();
	cout << "---------------- reverse  recursion -------------------\n";
	insertion();
	cout << "-------------------------------------------------------\n\n";
}



void	PmergeMeList::print_vector_elements(list vec)
{
	list_iterator cur;

	cur = vec.begin();
	while (cur != vec.end())
	{
		cout << *cur << " ";
		cur++;	
	}
}

void	PmergeMeList::print_array_vectors(listOflists vec, string str)
{
	ite_to_lstOflists	cur;
	list_iterator 	it;
	list	temp;

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





