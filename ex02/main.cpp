/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:48:45 by mganchev          #+#    #+#             */
/*   Updated: 2025/04/14 00:30:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat validBureaucrat("Alice", 50);
        std::cout << validBureaucrat << std::endl;

        validBureaucrat.increaseGrade();
        validBureaucrat.decreaseGrade();

        Bureaucrat highBureaucrat("Bob", 0);
    }
    catch (const GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat lowBureaucrat("Charlie", 151);
    }
    catch (const GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat original("Diana", 75);
        Bureaucrat copy(original);
        std::cout << copy << std::endl;

        Bureaucrat assigned = original;
        std::cout << assigned << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Testing Form functionality
    try
    {
        Form validForm("A", 50, 100);
        std::cout << validForm << std::endl;
        Form newForm("B", 50, 2);
        std::cout << newForm << std::endl;
        
        Bureaucrat signer("Eve", 40);
        signer.signForm(validForm);
        validForm.beSigned(signer);
        std::cout << validForm << std::endl;

        Bureaucrat lowRank("Frank", 51);
        newForm.beSigned(lowRank); // Should throw an exception
        lowRank.signForm(newForm);
        lowRank.increaseGrade();
        lowRank.signForm(newForm);
        newForm.beSigned(lowRank);
    }
    catch (const GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form invalidForm("Form B", 0, 100); // Should throw an exception
    }
    catch (const GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form anotherForm("Form C", 75, 50);
        Bureaucrat signer("Grace", 80);
        anotherForm.beSigned(signer); // Should throw an exception
    }
    catch (const GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}