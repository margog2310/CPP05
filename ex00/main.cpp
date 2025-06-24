/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margo <margo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:48:45 by mganchev          #+#    #+#             */
/*   Updated: 2025/06/12 17:47:38 by margo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "Creating a Bureaucrat..." << std::endl << std::endl;
        
        Bureaucrat validBureaucrat("Alice", 50);
        std::cout << validBureaucrat << std::endl;
        
        std::cout << "\nLet's try to modify the Bureaucrat's grade..." << std::endl << std::endl;
        
        validBureaucrat.increaseGrade();
        validBureaucrat.decreaseGrade();

        std::cout << "\nTrying to create a Bureaucrat with an invalid grade..." << std::endl << std::endl;
        
        Bureaucrat highBureaucrat("Bob", 0);
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what();
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what();
    }

    try
    {
        std::cout << "\nTrying to create another Bureaucrat with an invalid grade..." << std::endl << std::endl;
        
        Bureaucrat lowBureaucrat("Charlie", 151);
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what();
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what();
    }

    try
    {
        std::cout << "\nCreating some more Bureaucrats by copying them..." << std::endl << std::endl;
        
        Bureaucrat original("Diana", 75);
        Bureaucrat copy(original);
        std::cout << copy << std::endl;

        Bureaucrat assigned = original;
        std::cout << std::endl << assigned << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what();
    }   
    return 0;
}