/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:15:36 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/07 13:16:27 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include "Serializer.hpp"

class	Data
{
	private:
		int value;
	public:
		Data(int value)
		{
			this->value = value;
		};
		void print()
		{
			cout << value << endl;
		}
};

#endif