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

    public:
        AForm(std::string name, unsigned int to_sign, unsigned int to_execute);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        virtual ~AForm();
        GradeTooHighException e_high;
        GradeTooHighException e_low;
        const std::string getName() const;
        friend std::ostream& operator<<(std::ostream& out, const AForm& AForm);
        bool isSigned() const;
        unsigned int getSignGrade() const;
        unsigned int getExecuteGrade() const;
        bool    beSigned(const Bureaucrat& bureaucrat);
        bool    execute(const Bureaucrat& executor) const;
        virtual void beExecuted(const Bureaucrat& executor) const = 0;
} ;

#endif