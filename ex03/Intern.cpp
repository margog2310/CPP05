/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:21:41 by mganchev          #+#    #+#             */
/*   Updated: 2025/04/24 17:58:08 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy)
{
    *this = copy;
}

Intern& Intern::operator=(const Intern& copy)
{
    if (this == &copy) 
        return *this;
    return *this;
}

Intern::~Intern() {}

const char* Intern::NoSuchFormException::what() const throw()
{
    return "Unknown form type.";
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    // try switch statement with std::map
    AForm* newForm = NULL;
    
    std::map<std::string, int> forms;

    forms["Shrubbery Creation"] = 1;
    forms["shrubbery creation"] = 1;
    forms["Robotomy Request"] = 2;
    forms["robotomy request"] = 2;
    forms["Presidential Pardon"] = 3;
    forms["presidential pardon"] = 3;
    
    try
    {        
        switch (forms.at(name))
        {
            case (1):
                newForm = new ShrubberyCreationForm(target);
                break ;
            case (2):
                newForm = new RobotomyRequestForm(target);
                break ;
            case (3):
                newForm = new PresidentialPardonForm(target);
                break ;
            default:
                throw Intern::NoSuchFormException();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Form coulnd't be created because " << e.what() << std::endl;
    }
    if (newForm)
        std::cout << "Intern creates " << newForm->getName() << std::endl;
    return (newForm);
}