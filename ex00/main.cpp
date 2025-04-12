/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganchev <mganchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:48:45 by mganchev          #+#    #+#             */
/*   Updated: 2025/04/12 23:53:25 by mganchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
        std::cerr << e.what();
    }
    catch (const GradeTooLowException& e)
    {
        std::cerr << e.what();
    }

    try
    {
        Bureaucrat lowBureaucrat("Charlie", 151);
    }
    catch (const GradeTooHighException& e)
    {
        std::cerr << e.what();
    }
    catch (const GradeTooLowException& e)
    {
        std::cerr << e.what();
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
        std::cerr << e.what();
    }

    
    return 0;
}