/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:30:55 by oelbouha          #+#    #+#             */
/*   Updated: 2023/08/20 23:32:36 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
	{
		target = copy.target;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
	target = "robot";
}

RobotomyRequestForm::RobotomyRequestForm(string target): AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void	RobotomyRequestForm::ExecuteAction() const
{
	if (time(NULL) % 2)
		cout << this->target << " has been robotomized successfully 50% of the time. " << endl;
	else
		cout << "robotomy failed." << endl;
}