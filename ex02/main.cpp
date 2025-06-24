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
        std::cout << "Creating a Shrubbery Creation Form..." << std::endl;

        ShrubberyCreationForm shrubberyForm("Garden");
        std::cout << shrubberyForm << std::endl;

        std::cout << "\nCreating some Bureaucrats that may or may not be able to sign/execute Form..." << std::endl;
        Bureaucrat lowRank("Frank", 150); // Too low to sign or execute
        Bureaucrat midRank("Alice", 140); // Can sign but not execute
        Bureaucrat highRank("Bob", 1);    // Can sign and execute
        std::cout << lowRank << std::endl << midRank << std::endl << highRank << std::endl;

        // Attempt to sign and execute with low-rank bureaucrat
        std::cout << "\nAttempting to sign/execute with a Bureaucrat that can't do either..." << std::endl;
        lowRank.signForm(shrubberyForm);
        lowRank.executeForm(shrubberyForm);

        // Sign with mid-rank bureaucrat
        std::cout << "\nAttempting to sign/execute with a Bureaucrat that can sign but can't execute..." << std::endl;
        midRank.signForm(shrubberyForm);
        midRank.executeForm(shrubberyForm);

        // Execute with high-rank bureaucrat
        std::cout << "\nAttempting to sign/execute with a Bureaucrat that can both sign and execute..." << std::endl;
        highRank.signForm(shrubberyForm);
        highRank.executeForm(shrubberyForm);

        std::cout << "\nShowing that Shrubbery Creation Form was executed successfully:" << std::endl;
        std::string fileName = "./" + shrubberyForm.getTarget() + "_shrubbery";
        std::ifstream file(fileName.c_str());
        if (!file.is_open())
            std::cerr << "Error: File doesn't exist or can't be opened." << std::endl;
        else
        {
            std::string line;
            while(std::getline(file, line))
                std::cout << line << std::endl;
        }
        file.close();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        // Test RobotomyRequestForm
        std::cout << "\nCreating a Robotomy Request Form..." << std::endl;

        RobotomyRequestForm robotomyForm("Target A");
        std::cout << robotomyForm << std::endl;

        std::cout << "\nCreating some Bureaucrats that may or may not be able to sign/execute Form..." << std::endl;
        Bureaucrat signer("Eve", 72); // Can sign but not execute
        Bureaucrat executor("Charlie", 45); // Can execute
        std::cout << signer << std::endl << executor << std::endl;

        // Sign and execute the form
        std::cout << "\nAttempting to sign/execute with a Bureaucrat that can sign but not execute..." << std::endl;
        signer.signForm(robotomyForm);
        signer.executeForm(robotomyForm);

        std::cout << "\nAttempting to sign/execute with a Bureaucrat that can both sign and execute..." << std::endl;
        executor.signForm(robotomyForm);
        executor.executeForm(robotomyForm);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        // Test PresidentialPardonForm
        std::cout << "\nCreating a Presidential Pardon Form..." << std::endl;
        PresidentialPardonForm pardonForm("Target B");
        std::cout << pardonForm << std::endl;

        std::cout << "\nCreating some Bureaucrats that may or may not be able to sign/execute Form..." << std::endl;
        Bureaucrat signer("Grace", 25); // Can sign but not execute
        Bureaucrat executor("Diana", 5); // Can execute
        std::cout << signer << std::endl << executor << std::endl;

        // Sign and execute the form
        std::cout << "\nAttempting to sign/execute with a Bureaucrat that can sign but not execute..." << std::endl;
        signer.signForm(pardonForm);
        signer.executeForm(pardonForm);

        std::cout << "\nAttempting to sign/execute with a Bureaucrat that can both sign and execute..." << std::endl;
        executor.signForm(pardonForm);
        executor.executeForm(pardonForm);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
