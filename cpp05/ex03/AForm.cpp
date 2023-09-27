/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:16:58 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/23 17:41:43 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const AForm& other): name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	*this = other;
}

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
	{
		sign = copy.sign;
	}
	return (*this);
}

AForm::AForm() : name("DefaultForm"), gradeToSign(0), gradeToExecute(0){}

AForm::~AForm(){}

const char *AForm::GradeTooHighException::what() const throw()
{
	return  "grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return  "grade too low";
}

AForm::AForm(const string name, const int grade, const int execute) : name(name), gradeToSign(grade), gradeToExecute(execute){
}

string	AForm::getName() const
{
	return name;
}

bool	AForm::getSign() const
{
	return sign;
}

int	AForm::getGradeToSign() const
{
	return gradeToSign;
}

int	AForm::getGrdeToexecute() const
{
	return gradeToExecute;
}

void	AForm::beSigned(Bureaucrat& Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	sign = true;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (this->getGrdeToexecute() < executor.getGrade() || this->getSign() == false)
		throw AForm::GradeTooLowException();
	this->ExecuteAction();
}
