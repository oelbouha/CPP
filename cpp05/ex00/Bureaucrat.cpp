/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:16:58 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/23 17:35:37 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	cout << "Bureaucrat copy constructor called" << endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	cout << "Bureaucrat copy assignment constructor called" << endl;
	if (this != &copy)
	{
		name = copy.name;
		grade = copy.grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat()
{
	cout << "Bureaucrat default constructor called" << endl;
	name = "Beareaucrat";
	grade = 0;
}

Bureaucrat::~Bureaucrat()
{
	cout << "Bureaucrat destructor called" << endl;
}

Bureaucrat::Bureaucrat(int grade, string name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
	this->name = name;
}

std::ostream&	operator << (std::ostream& COUT, Bureaucrat& crat)
{
	COUT << crat.getName() << ", bureaucrat grade " << crat.getGrade() << endl;
	return (COUT);
}

string	Bureaucrat::getName() const
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

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return  "grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return  "grade too low";
}