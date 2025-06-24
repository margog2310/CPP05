/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margo <margo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:48:45 by mganchev          #+#    #+#             */
/*   Updated: 2025/06/24 15:45:56 by margo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        std::cout << "Creating some valid Bureaucrats..." << std::endl << std::endl;
        
        Bureaucrat validBureaucrat("Alice", 50);
        std::cout << validBureaucrat << std::endl;
        
        std::cout << "\nTesting changing the level of a Bureaucrat..." << std::endl << std::endl;
        
        validBureaucrat.increaseGrade();
        validBureaucrat.decreaseGrade();

        std::cout << "\nTrying to create a Bureaucrat with a level, that's too high..." << std::endl << std::endl;
        
        Bureaucrat highBureaucrat("Bob", 0);
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "\nTrying to create a Bureaucrat with a level, that's too low..." << std::endl << std::endl;
        
        Bureaucrat lowBureaucrat("Charlie", 151);
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "\nCreating some more Bureaucrats by copying them..." << std::endl << std::endl;
        
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
        std::cout << "\nCreating some Forms..." << std::endl << std::endl;
        
        Form validForm("A", 50, 100);
        std::cout << validForm << std::endl;
        Form newForm("B", 50, 2);
        std::cout << newForm << std::endl;
        
        std::cout << "\nCreating a Bureaucrat to sign the Forms..." << std::endl << std::endl;
        
        Bureaucrat signer("Eve", 40);
        std::cout << signer << std::endl
                  << "Signing Form..." << std::endl;
        signer.signForm(validForm);
        std::cout << "\nTrying to sign Form again..." << std::endl;
        validForm.beSigned(signer);
        std::cout << validForm << std::endl;

        std::cout << "\nCreating a new Bureaucrat..." << std::endl;
        Bureaucrat lowRank("Frank", 51);
        std::cout << lowRank << std::endl;
        
        std::cout << "\nThe new Bureaucrat tries to sign a Form that he's not qualified to sign..." << std::endl << std::endl;
        lowRank.signForm(newForm);
        newForm.beSigned(lowRank); // Should throw an exception
    }    
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {        
        Bureaucrat lowRank("Frank", 51);
        Form newForm("B", 50, 2);
        
        std::cout << "\nLet's modify the Bureaucrat's level so he can sign his Form!" << std::endl;
        lowRank.increaseGrade();
        lowRank.signForm(newForm);
        newForm.beSigned(lowRank);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;   
    }
    
    try
    {
        std::cout << "\nCreating an invalid Form..." << std::endl;
        
        Form invalidForm("Form B", 0, 100); // Should throw an exception
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}