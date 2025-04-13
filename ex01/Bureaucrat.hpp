/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:00:54 by mganchev          #+#    #+#             */
/*   Updated: 2025/04/14 00:34:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Form;

class GradeTooLowException: public std::exception
{
    private:
        std::string _message;
        
    public:
        GradeTooLowException(const std::string& message);
        ~GradeTooLowException() throw() {}
        const char* what() const throw();
} ;

class GradeTooHighException: public std::exception
{
    private:
        std::string _message;
    public:
        GradeTooHighException(const std::string& message);
        ~GradeTooHighException() throw() {}
        const char* what() const throw();
} ;

class Bureaucrat
{
    private:
        const std::string _name;
        size_t _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, size_t grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();
        GradeTooHighException high_e;
        GradeTooLowException low_e;
        const std::string getName() const;
        size_t getGrade() const;
        friend std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
        void    increaseGrade();
        void    decreaseGrade();
        void    signForm(Form& form);
} ;


#endif