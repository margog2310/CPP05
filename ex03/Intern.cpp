/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margo <margo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:21:41 by mganchev          #+#    #+#             */
/*   Updated: 2025/06/24 19:27:42 by margo            ###   ########.fr       */
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

AForm*  Intern::makeShrubbery(const std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm*  Intern::makeRobotomy(const std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm*  Intern::makePardon(const std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string forms[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
    AForm *(Intern::*functions[])(const std::string target) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePardon};
    
    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return ((this->*functions[i])(target));
        }    
    }
    
    std::cout << "Intern can't create a " << name << " Form." << std::endl;
    return (NULL);
}