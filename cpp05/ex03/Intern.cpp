/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:16:58 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/13 22:29:12 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor called" << endl;
	*this = other;
}

Intern& Intern::operator=(const Intern& copy)
{
	std::cout << "Intern copy assignment constructor called" << endl;
	if (this != &copy)
	{
	
	}
	return (*this);
}

Intern::Intern()
{
	std::cout << "Intern default constructor called" << endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << endl;
}

void	delete_forms(AForm **forms, int i)
{
	for(int j = 0; j < 3; j++)
	{
		if (j != i)
			delete forms[j];
	}
}

AForm*	Intern::makeForm(string name, string target)
{
	AForm*	forms[3] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};
	string	names[3] = {"presidential pardon", "robotomy request", "shrubberycreation"};
	int		i;

	for (i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			cout << "Intern creates " << name << endl;
			delete_forms(forms, i);
			return (forms[i]);
		}
	}
	cout << "Intern couldn't creates " << name << endl;
	delete_forms(forms, i);
	return (NULL);
}
