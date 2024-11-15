/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:50:07 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/27 10:05:48 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	init()
{
	try
	{
		Form form("FORM!", 10, 10);
		Bureaucrat p("hakim", 1);
		form.beSigned(p);
		cout << form << endl;;
		p.signForm(form);
	}
	catch (std::exception& execption)
	{
		cout << execption.what();
	}
}

int main(void)
{
	init();
	return (0);
}
