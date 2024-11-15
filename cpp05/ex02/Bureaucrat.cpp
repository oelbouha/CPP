/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:16:58 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/06 12:04:55 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
	{
		name = copy.name;
		grade = copy.grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat()
{
	name = "bureaucrat";
	grade = 0;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
	this->name = name;
}

std::ostream&	operator << (std::ostream& COUT, Bureaucrat& bereaucrat)
{
	COUT << bereaucrat.getName() << ", bureaucrat grade " << bereaucrat.getGrade() << endl;
	return (COUT);
}

std::string Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::incrementGrade()
{
	grade--;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	grade++;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(AForm& form)
{
	if (form.getSign() == true)
		cout << name << " signed " << form.getName() <<  endl;
	else
		cout << name << " couldn’t sign " << form.getName() << "because he does not have enought grade" <<  std::endl;
}

void	Bureaucrat::executeForm(AForm const& form)
{
	try
	{
	 	form.execute(*this);
		cout << this->name << " executed " << form.getName() << endl;
	}
	catch(std::exception& e)
	{
		cout << e.what() << endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return  "grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return  "grade too low";
}
