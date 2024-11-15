/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:43:28 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/06 11:49:19 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("defaultForm"), sign(0), gradeToSign(0), gradeToExecute(0){}

Form::Form(const Form& other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	*this = other;
}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
	{
		sign = copy.sign;
	}
	return (*this);
}

Form::~Form(){}

Form::Form(const string name, const int grade, const int exec) : name(name), gradeToSign(grade), gradeToExecute(exec)
{
	if (gradeToSign > 150)
		throw Form::GradeTooLowException();
	else if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	sign = 0;
}

void	Form::beSigned(Bureaucrat& Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->getGrade())
		throw Form::GradeTooLowException();
	sign = true;
}

bool	Form::getSign() const{
	return sign;
}

string	Form::getName() const{
	return (name);
}

int	Form::getGrade() const{
	return (gradeToSign);
}

int	Form::getGradeToExecute() const{
	return (gradeToExecute);
}

std::ostream&	operator << (std::ostream& COUT, Form& form)
{
	COUT <<  "name: " << form.getName() << endl;
	COUT <<  "gradeToSign: " << form.getGrade() << endl;
	COUT <<  "sign: " << (form.getSign()? "true" : "false") << endl;
	COUT <<  "gradeToExecute: " << form.getGradeToExecute() << endl;
	return (COUT);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return  "grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return  "grade too low";
}