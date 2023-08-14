/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:42:03 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/14 13:39:17 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

    /*
        Serialization refers to the process of converting a complex data structure 
        or object (such as an instance of a class) into a format that can be easily stored, 
        transmitted, or reconstructed later.
        Serialization involves converting the object's state into a sequence of bytes or a 
        standardized format that can be saved to a file, sent over a network, or otherwise persisted.
    */
class   Serializer
{
public:
    Serializer  ( void );
    Serializer  ( Serializer const& other );
    ~Serializer ( void );
    Serializer& operator=(Serializer const& other );

    uintptr_t   serialize(Data* ptr); //unsigned integer type that can hold a pointer's value
    Data*       deserialize(uintptr_t raw);
};

#endif