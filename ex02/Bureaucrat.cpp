/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:02:01 by mganchev          #+#    #+#             */
/*   Updated: 2025/04/14 02:29:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

GradeTooHighException::GradeTooHighException(const std::string& message): _message(message) {}

GradeTooLowException::GradeTooLowException(const std::string& message): _message(message) {}

const char* GradeTooLowException::what() const throw()
{
    return _message.c_str();
}

const char* GradeTooHighException::what() const throw()
{
    return _message.c_str();
}

Bureaucrat::Bureaucrat(): _name("Unnamed"), _grade(0), high_e("Bureaucrat grade too high"), low_e("Bureaucrat grade too low") {}

Bureaucrat::Bureaucrat(const std::string name, size_t grade): _name(name), high_e("Bureaucrat grade too high"), low_e("Bureaucrat grade too low")
{
    if (grade < 1)
        throw high_e;
    else if (grade > 150)
        throw low_e;
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name), high_e(copy.high_e), low_e(copy.low_e)
{  
    if (copy._grade < 1)
        throw high_e;
    else if (copy._grade > 150)
        throw low_e;
    else
        _grade = copy._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    if (this != &copy)
    {
        _grade = copy._grade;
        high_e = copy.high_e;
        low_e = copy.low_e;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << " (Grade: " << bureaucrat.getGrade() << ")";
    return out;
}

const std::string Bureaucrat::getName() const
{
    return this->_name;
}

size_t Bureaucrat::getGrade() const
{
    return this->_grade;
}

void    Bureaucrat::increaseGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException("Exception: Maximum grade, can't increase.\n");
    else
        this->_grade -= 1;
    
    std::cout << _name << "'s grade has increased. Current grade: " << _grade << std::endl;
}

void    Bureaucrat::decreaseGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException("Exception: Minimum grade, can't decrease\n");
    else
        this->_grade += 1;

    std::cout << _name << "'s grade has decreased. Current grade: " << _grade << std::endl;
}

void    Bureaucrat::signForm(AForm& form)
{
    if (form.isSigned())
    {
        std::cout << *this << " couldn't sign " << form << " because it's already signed." << std::endl;
        return ;
    }
    else if (form.beSigned(*this))
        std::cout << *this << " signed " << form << std::endl;
    else
        std::cout << *this << " couldn't sign " << form << " because bureaucrat grade is too low." << std::endl;
}

void    Bureaucrat::executeForm(const AForm& form)
{
    if (form.execute(*this))
    {
        form.beExecuted(*this);
        std::cout << *this << " executed " << form << std::endl;
    }
    else
        std::cout << *this << " couldn't sign " << form << std::endl;
}