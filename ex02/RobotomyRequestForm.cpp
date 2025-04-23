/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:00:17 by mganchev          #+#    #+#             */
/*   Updated: 2025/04/23 22:50:10 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request Form", 72, 45), _target("No target specified") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy)
{
    *this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    _target = copy._target;
    setSigned(copy.isSigned());
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const char* RobotomyRequestForm::RobotomyFailedException::what() const throw()
{
    return "Robotomy failed ://";
}

void RobotomyRequestForm::beExecuted() const
{
    std::cout << "* VRRRRRRRR... BZZZZZZZZ... KRRRRRRRRRRR *" << std::endl;
    
    std::srand(std::time(0));
    int random = std::rand() % 2;

    if (random == 0)
        std::cout << _target << " has been robotomised succesfully!" << std::endl;
    else
        throw RobotomyRequestForm::RobotomyFailedException();
}