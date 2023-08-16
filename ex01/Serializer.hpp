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

#if !defined(_UINTPTR_T) && !defined(_UINTPTR_T_DEFINED) && !defined(__uintptr_t_defined) && !defined(uintptr_t)
    typedef unsigned long int uintptr_t;
#endif

#include "Data.hpp"

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