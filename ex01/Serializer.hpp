/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:42:03 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/17 12:07:25 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class   Serializer
{
public:
    Serializer          ( Serializer const& other );
    ~Serializer         ( void );
    Serializer&         operator=(Serializer const& other );

    static uintptr_t    serialize(Data* ptr);
    static Data*        deserialize(uintptr_t raw);
private:
    Serializer  ( void );
};

#endif