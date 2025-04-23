/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:48:45 by mganchev          #+#    #+#             */
/*   Updated: 2025/04/14 00:30:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        // Test ShrubberyCreationForm
        ShrubberyCreationForm shrubberyForm("Garden");
        Bureaucrat lowRank("Frank", 150); // Too low to sign or execute
        Bureaucrat midRank("Alice", 140); // Can sign but not execute
        Bureaucrat highRank("Bob", 1);    // Can sign and execute

        std::cout << shrubberyForm << std::endl;

        // Attempt to sign and execute with low-rank bureaucrat
        lowRank.signForm(shrubberyForm);
        lowRank.executeForm(shrubberyForm);

        // Sign with mid-rank bureaucrat
        midRank.signForm(shrubberyForm);
        shrubberyForm.beSigned(midRank);

        // Execute with high-rank bureaucrat
        highRank.executeForm(shrubberyForm);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        // Test RobotomyRequestForm
        RobotomyRequestForm robotomyForm("Target A");
        Bureaucrat signer("Eve", 72); // Can sign but not execute
        Bureaucrat executor("Charlie", 45); // Can execute

        std::cout << robotomyForm << std::endl;

        // Sign and execute the form
        signer.signForm(robotomyForm);
        robotomyForm.beSigned(signer);

        executor.executeForm(robotomyForm);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        // Test PresidentialPardonForm
        PresidentialPardonForm pardonForm("Target B");
        Bureaucrat signer("Grace", 25); // Can sign but not execute
        Bureaucrat executor("Diana", 5); // Can execute

        std::cout << pardonForm << std::endl;

        // Sign and execute the form
        signer.signForm(pardonForm);
        pardonForm.beSigned(signer);

        executor.executeForm(pardonForm);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        // Test invalid form creation
        ShrubberyCreationForm invalidForm("Invalid");
        Bureaucrat lowRank("Frank", 150); // Too low to sign or execute

        std::cout << invalidForm << std::endl;

        // Attempt to sign and execute with low-rank bureaucrat
        lowRank.signForm(invalidForm);
        lowRank.executeForm(invalidForm);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
