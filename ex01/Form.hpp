/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:57:27 by root              #+#    #+#             */
/*   Updated: 2025/04/14 00:34:57 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const unsigned int _to_sign;
        const unsigned int _to_execute;

    public:
        Form();
        Form(std::string name, unsigned int to_sign, unsigned int to_execute);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();

        const std::string getName() const;
        bool isSigned() const;
        unsigned int getSignGrade() const;
        unsigned int getExecuteGrade() const;
        bool    beSigned(const Bureaucrat& bureaucrat);
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

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif