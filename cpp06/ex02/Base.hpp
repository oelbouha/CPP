/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:35:13 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/02 13:15:22 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <string>
#include <iostream>


using std::cout;
using std::string;
using std::endl;

class	Base
{
	public:
		Base();
		virtual	~Base();
		Base*	generate(void);
		void	identify(Base* p);
		void 	identify(Base& p);
};



#endif


