/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:02:01 by mganchev          #+#    #+#             */
/*   Updated: 2025/04/23 22:47:40 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("Unnamed"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, size_t grade): _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name)
{  
    if (copy._grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (copy._grade > 150)
        throw  Bureaucrat::GradeTooLowException();
    else
        _grade = copy._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    if (this != &copy)
    {
        _grade = copy._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low.";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high.";
}

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
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade -= 1;
    
    std::cout << _name << "'s grade has increased. Current grade: " << _grade << std::endl;
}

void    Bureaucrat::decreaseGrade()
{
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
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
    try
    {
        form.beSigned(*this);
    }
    catch (const std::exception& e)
    {
        std::cout << *this << " couldn't sign " << form.getName() << " because " 
                  << e.what() << std::endl;
        return ;
    }
    std::cout << *this << " signed " << form.getName() << std::endl;
}

void    Bureaucrat::executeForm(const AForm& form)
{
    try 
    {
        form.execute(*this);
    }
    catch (const std::exception& e)
    {
        std::cout << *this << " couldn't execute " << form.getName() << " because "
                  << e.what() << std::endl;
        return ;
    }
    std::cout << *this << " executed " << form << std::endl;
}