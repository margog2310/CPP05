/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:00:54 by mganchev          #+#    #+#             */
/*   Updated: 2025/07/11 19:03:45 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class AForm;

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
        class GradeTooLowException: public std::exception
        {
            public:
                const char* what() const throw();
        } ;

        class GradeTooHighException: public std::exception
        {
            public:
                const char* what() const throw();
        } ;
        const std::string getName() const;
        size_t getGrade() const;
        void    increaseGrade();
        void    decreaseGrade();
        void    signForm(AForm& form);
        void    executeForm(const AForm& form);
} ;

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif