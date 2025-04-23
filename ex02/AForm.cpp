/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 22:14:07 by root              #+#    #+#             */
/*   Updated: 2025/04/14 00:38:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, unsigned int to_sign, unsigned int to_execute): _name(name), _signed(false), _to_sign(to_sign), _to_execute(to_execute)
{
    if (to_sign < 1 || to_execute < 1)
        throw AForm::GradeTooHighException();
    else if (to_sign > 150 || to_execute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy): _name(copy._name), _signed(copy._signed), _to_sign(copy._to_sign), _to_execute(copy._to_execute) {}

AForm& AForm::operator=(const AForm& copy)
{
    if (this != &copy)
        this->_signed = copy._signed;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "Form " << form.getName()
        << " (To Sign: " << form.getSignGrade()
        << ", To Execute: " << form.getExecuteGrade()
        << (form.isSigned() ? ", Signed)" : ", Not signed)");
    return out;
}

AForm::~AForm() {}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low.";
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high.";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form can't be executed because it hasn't been signed.";
}

const std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::isSigned() const
{
    return this->_signed;
}

unsigned int AForm::getSignGrade() const
{
    return this->_to_sign;
}

unsigned int AForm::getExecuteGrade() const
{
    return this->_to_execute;
}

void    AForm::setSigned(bool isSigned)
{
    _signed = isSigned;
}

bool AForm::beSigned(const Bureaucrat& bureaucrat)
{  
    if (_signed)
    {
        std::cout << "Form is already signed." << std::endl;
        return false;
    }
    if (bureaucrat.getGrade() > _to_sign)
        throw Bureaucrat::GradeTooLowException();
    else
        _signed = true;
    return _signed;
}

void    AForm::execute(const Bureaucrat& executor) const
{
    if (!_signed)
        throw AForm::FormNotSignedException();
    if (_signed && executor.getGrade() > _to_execute)
        throw Bureaucrat::GradeTooLowException();
    beExecuted;
}