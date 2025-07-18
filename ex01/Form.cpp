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

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Unnamed"), _signed(false), _to_sign(150), _to_execute(150) {}

Form::Form(std::string name, unsigned int to_sign, unsigned int to_execute): _name(name), _signed(false), _to_sign(to_sign), _to_execute(to_execute)
{
    if (to_sign < 1 || to_execute < 1)
        throw Form::GradeTooHighException();
    else if (to_sign > 150 || to_execute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& copy): _name(copy._name), _signed(copy._signed), _to_sign(copy._to_sign), _to_execute(copy._to_execute) {}

Form& Form::operator=(const Form& copy)
{
    if (this != &copy)
    {
        this->~Form();
        new (this) Form(copy);
        if (_to_sign < 1 || _to_execute < 1)
            throw Form::GradeTooHighException();
        else if (_to_sign > 150 || _to_execute > 150)
            throw Form::GradeTooLowException();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form " << form.getName()
        << " (To Sign: " << form.getSignGrade()
        << ", To Execute: " << form.getExecuteGrade()
        << (form.isSigned() ? ", Signed)" : ", Not signed)");
    return out;
}

Form::~Form() {}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low.";
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high.";
}

const std::string Form::getName() const
{
    return this->_name;
}

bool Form::isSigned() const
{
    return this->_signed;
}

unsigned int Form::getSignGrade() const
{
    return this->_to_sign;
}

unsigned int Form::getExecuteGrade() const
{
    return this->_to_execute;
}

bool Form::beSigned(const Bureaucrat& bureaucrat)
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