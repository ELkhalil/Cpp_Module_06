/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:42:03 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/13 15:51:57 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class   Serializer
{
public:
    Serializer  ( void );
    Serializer  ( Serializer const& other );
    ~Serializer ( void );
    Serializer& operator=(Serializer const& other );

    uintptr_t   serialize(Data* ptr);
    Data*       deserialize(uintptr_t raw);
};

#endif