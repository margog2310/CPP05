/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:57:27 by root              #+#    #+#             */
/*   Updated: 2025/04/14 00:34:57 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const unsigned int _to_sign;
        const unsigned int _to_execute;
        virtual void beExecuted() const = 0;

    public:
        AForm(std::string name, unsigned int to_sign, unsigned int to_execute);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        virtual ~AForm();
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
        class FormNotSignedException: public std::exception
        {
            public:
                const char* what() const throw ();
        } ;
        friend std::ostream& operator<<(std::ostream& out, const AForm& AForm);
        const std::string getName() const;
        bool isSigned() const;
        unsigned int getSignGrade() const;
        unsigned int getExecuteGrade() const;
        void    setSigned(bool isSigned);
        bool    beSigned(const Bureaucrat& bureaucrat);
        void    execute(const Bureaucrat& executor) const;
} ;

#endif