/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:16:58 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/06 11:59:52 by oelbouha         ###   ########.fr       */
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
	name = "Beraucrat";
	grade = 0;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
	this->name = name;
}

std::ostream&	operator<<(std::ostream& COUT, Bureaucrat& crat)
{
	COUT << crat.getName() << ", bureaucrat grade " << crat.getGrade() << endl;
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

void	Bureaucrat::signForm(Form& form)
{
	if (form.getSign() == true)
		cout << name << " signed " << form.getName() <<  endl;
	else
		cout << name << " couldn’t sign " << form.getName() << "because he does not have enought grade" <<  std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return  "grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return  "grade too low";
}
