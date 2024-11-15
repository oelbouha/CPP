/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:30:55 by oelbouha          #+#    #+#             */
/*   Updated: 2023/08/20 23:32:36 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
	{
		target = copy.target;
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 145, 137)
{
	target = "PresidentialPardonForm";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(string target): AForm("PresidentialPardonForm", 145, 137)
{
	this->target = target;
}

void	PresidentialPardonForm::ExecuteAction() const
{
	cout << target << " has been pardoned by Zaphod Beeblebrox." << endl;
}