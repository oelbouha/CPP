/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:50:07 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/27 10:24:43 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

void	init()
{
	try
	{
		Intern someRandomIntern;

		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomdsdsdsy request", "Bender");
		
		AForm* r;
		r = someRandomIntern.makeForm("robotomy request", "Bender");
		
		delete rrf;
		delete r;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}

int main(void)
{
	init();
	return (0);
}
