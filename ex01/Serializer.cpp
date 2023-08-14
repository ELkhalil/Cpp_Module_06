/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:42:08 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/14 13:48:46 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Serializer Constructors
Serializer::Serializer  ( void )
{
    std::cout << "Serializer Default constructor" << std::endl;
}

Serializer::Serializer  ( Serializer const& other )
{
    std::cout << "Serializer Copy constructor" << std::endl;
    (*this) = other;
}

Serializer& Serializer::operator=(Serializer const& other )
{
    // std::cout << "Serializer Copy Assignement operator" << std::endl;
    if (this != &other)
        std::cout << "Serializer Nothing to be copied" << std::endl;
    return *this;
}

Serializer::~Serializer ( void )
{
    std::cout << "Serializer Destructor" << std::endl;
}

// Serializer Methods
uintptr_t   Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*       Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}