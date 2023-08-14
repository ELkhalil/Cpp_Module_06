/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:28:08 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/14 16:45:24 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base   ( void )
{
    std::cout << "Virtual Base Destructor" << std::endl;
}

Base*   generate(void)
{
    int choice = std::rand() % 3;

    switch (choice)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return new A();;
}

void    identify(Base* p)
{
    A*  aType = dynamic_cast<A*>(p);
    B*  bType = dynamic_cast<B*>(p);
    C*  cType = dynamic_cast<C*>(p);

    std::cout << "the actual type of the object pointed to by p is: ";
    if (aType)
        std::cout << "A" << std::endl;
    else if (bType)
        std::cout << "B" << std::endl;
    else if (cType)
        std::cout << "C" << std::endl;
    else
        std::cout << "NULL" << std::endl;
}

void identify(Base& p) 
{
    std::cout << "the actual type of the object pointed to by p is: ";
    try 
    {
        A   &tmp = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)tmp;
    }
    catch ( std::bad_cast const& ) 
    {
        try 
        {
            B   &tmp = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            (void)tmp;
        } 
        catch ( std::bad_cast const& ) 
        {
            try 
            {
                C   &tmp = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                (void)tmp;
            } catch ( std::bad_cast const& ) 
            {
                std::cout << "NULL" << std::endl;
            }
        }
    }
}