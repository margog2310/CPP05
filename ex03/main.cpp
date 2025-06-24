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
#include "Intern.hpp"
#include <iostream>
#include <string>

int main()
{
    try
    {
        // Test Intern
        std::cout << "Creating an Intern that we're about to exploit..." << std::endl;
        Intern intern;

        std::cout << "\nLet's see our Intern attempt to create some Forms..." << std::endl;
        // Attempt to create the form
        AForm* shrubForm = intern.makeForm("Shrubbery Creation", "Garden");
        AForm* robotForm = intern.makeForm("Robotomy Request", "Target A");
        AForm* presForm = intern.makeForm("Presidential Pardon", "Target B");
        
        std::cout << "\nNow let's see if our Intern is competent enough to create all these forms..." << std::endl;
        if (shrubForm)
        {
            std::cout << std::endl << *shrubForm << std::endl;

            // Test signing and executing the form
            std::cout << "\nGreat our Shrubbery Creation Form exists, let's create a Bureaucrat to sign and execute it!" << std::endl;
            Bureaucrat executor("Executor", 1); // High enough rank to sign and execute
            std::cout << executor << std::endl;
            executor.signForm(*shrubForm);
            shrubForm->beSigned(executor);
            executor.executeForm(*shrubForm);

            delete shrubForm; // Clean up dynamically allocated memory
        }

        if (robotForm)
        {
            std::cout << std::endl << *robotForm << std::endl;

            // Test signing and executing the form
            std::cout << "\nGreat our Robotomy Request Form exists, let's create a Bureaucrat to sign and execute it!" << std::endl;
            Bureaucrat executor("Executor", 1); // High enough rank to sign and execute
            std::cout << executor << std::endl;
            executor.signForm(*robotForm);
            robotForm->beSigned(executor);
            executor.executeForm(*robotForm);

            delete robotForm; // Clean up dynamically allocated memory
        }

        if (presForm)
        {
            std::cout << std::endl << *presForm << std::endl;
            
            // Test signing and executing the form
            std::cout << "\nGreat our Presidential Pardon Form exists, let's create a Bureaucrat to sign and execute it!" << std::endl;
            Bureaucrat executor("Executor", 1); // High enough rank to sign and execute
            std::cout << executor << std::endl;
            executor.signForm(*presForm);
            presForm->beSigned(executor);
            executor.executeForm(*presForm);
            
            delete presForm; // Clean up dynamically allocated memory
        }

        std::cout << "\nFinally let's see what happens if we tell out Intern to create an invalid Form:" << std::endl;
        AForm*  invalid = intern.makeForm("Invalid", "Target C");
        
        delete invalid;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
