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

AForm::AForm(std::string name, unsigned int to_sign, unsigned int to_execute): _name(name), _signed(false), _to_sign(to_sign), _to_execute(to_execute), e_high("Form grade too high."), e_low("Form grade too low.")
{
    if (to_sign < 1 || to_execute < 1)
        throw e_high;
    else if (to_sign > 150 || to_execute > 150)
        throw e_low;
}

AForm::AForm(const AForm& copy): _name(copy._name), _signed(copy._signed), _to_sign(copy._to_sign), _to_execute(copy._to_execute), e_high(copy.e_high), e_low(copy.e_low) {}

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

bool AForm::beSigned(const Bureaucrat& bureaucrat)
{  
    if (_signed)
    {
        std::cout << "Form is already signed." << std::endl;
        return false;
    }
    if (bureaucrat.getGrade() > _to_sign)
        _signed = false;
    else
        _signed = true;
    return _signed;
}

bool    AForm::execute(const Bureaucrat& executor) const
{
    if (!_signed)
        std::cout << *this << " hasn't been signed. Please sign before executing." << std::endl;
    if (_signed && executor.getGrade() < _to_execute)
        return true;
    return false;
}