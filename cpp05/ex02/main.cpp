/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:50:07 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/27 10:20:26 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

void	init()
{
	try
	{
		Bureaucrat p1("othman", 15);
		cout << p1 << endl;

		cout << " -===========================- " << endl; 
		AForm *form1 = new RobotomyRequestForm("robot");
		form1->beSigned(p1);
		form1->execute(p1);

		cout << " -===========================- " << endl; 
		AForm *form2 = new PresidentialPardonForm("PresidentialPardonForm");
		form2->beSigned(p1);
		form2->execute(p1);
		cout << endl;
		p1.executeForm(*form2);

		cout << " -===========================- " << endl; 
		AForm *form3 = new ShrubberyCreationForm("ShrubberyCreationForm");
		form3->beSigned(p1);
		form3->execute(p1);

		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}
}

int main(void)
{
	init();
	return (0);
}
