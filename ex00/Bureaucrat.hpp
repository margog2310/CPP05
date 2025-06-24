/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margo <margo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:00:54 by mganchev          #+#    #+#             */
/*   Updated: 2025/06/12 17:40:04 by margo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>


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
        
        const std::string getName() const;
        size_t getGrade() const;
        
        void    increaseGrade();
        void    decreaseGrade();
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
        
} ;

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif