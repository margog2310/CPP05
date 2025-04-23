/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:38:17 by mganchev          #+#    #+#             */
/*   Updated: 2025/04/23 21:55:22 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137), _target("No target specified") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy)
{
    *this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    _target = copy._target;
    setSigned(copy.isSigned());
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char* ShrubberyCreationForm::FileErrorException::what() const throw()
{
    return "Error while opening file.";
}

void    ShrubberyCreationForm::beExecuted(const Bureaucrat& executor) const
{
    std::ofstream file(_target + "_shrubbery");
    
    if (file)
    {
        file << "       _-_\n";
        file << "    /~~   ~~\\\n";
        file << " /~~         ~~\\\n";
        file << "{               }\n";
        file << " \\  _-     -_  /\n";
        file << "   ~  \\\\ //  ~\n";
        file << "_- -   | | _- _\n";
        file << "  _ -  | |   -_\n";
        file << "      // \\\\\n";
        file.close();
    }
    else
        throw ShrubberyCreationForm::FileErrorException();
}

