/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:41:33 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/05 00:47:19 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

using std::cout;
using std::string;
using std::endl;

class	Form
{
	private:
		const	string	name;
		bool			sign;
		const	int		gradeToSign;
		const	int		gradeToExecute;

	public:
		Form();
		Form(const string _name, const int grade, const int exec);
		Form(const Form& other);
		Form&	operator=(const Form& original);
		~Form();

		class	GradeTooHighException : public std::exception
		{
			public :
				const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public :
				const char* what() const throw();
		};
		string		getName() const;
		int			getGrade() const;
		int			getGradeToExecute() const;
		bool		getSign() const;
		void		beSigned(Bureaucrat& Bureaucrat);
};

std::ostream&	operator<<(std::ostream& COUT, Form& Form);

#endif