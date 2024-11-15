/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:30:55 by oelbouha          #+#    #+#             */
/*   Updated: 2023/09/06 12:06:04 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		target = copy.target;
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 25, 5)
{
	target = "Shrubbery";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(string target): AForm("ShrubberyCreationForm", 25, 5)
{
	this->target = target;
}

void	ShrubberyCreationForm::ExecuteAction() const
{
	std::ofstream	file;

	file.open(target + "_shrubbery", std::ios::out);
	if (!file.is_open())
	{
		cout << "couldn't open the file" << endl;
		return ;
	}
	file << "         #\n\
        ###\n\
       #####\n\
      #######\n\
     #########\n\
    ###########\n\
   #############\n\
  ###############\n\
 #################\n\
         |\n\
         |\n" << endl;
	file.close();
}