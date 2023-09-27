/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:01:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/23 23:40:35 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> st;

	st.push(10);
	st.push(20);
	cout << st.size() << endl;
	cout << st.empty() << endl;

	MutantStack<int>::iterator it = st.begin();
	MutantStack<int>::iterator ite = st.end();
	++it;
	--it;
	while (it != ite)
	{
		cout << *it << endl;
		++it;
	}
	std::stack<int> s(st);
	return 0;
}
