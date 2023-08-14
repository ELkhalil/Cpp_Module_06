/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:25:22 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/14 13:58:06 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main( void )
{
    {
        Serializer  serializer;
        Data        data = {10, 50, 'D', true};

        uintptr_t   serializedPtr = serializer.serialize(&data);
        Data        *deserializedPtr = serializer.deserialize(serializedPtr);

        if (deserializedPtr == &data)
            std::cout << "Serialization and deserialization successfully.." << std::endl;
        else
            std::cout << "Serialization and deserialization failed!" << std::endl;
    }
    {
        std::cout << "Checking Serialization: " << std::endl;
        Serializer  serializer;
        Data        data = {5, 10, 'X', true};

        uintptr_t   serializedPtr = serializer.serialize(&data);
        std::cout << "Address of Data is: " << &data << std::endl;
        std::cout << "serializer.serialize() : 0x" << std::hex << serializedPtr << std::endl;

        Data        *dataPtr = serializer.deserialize(serializedPtr);
    
        std::cout << "Data.x = " << dataPtr->x << std::endl;
        std::cout << "Data.y = " << dataPtr->y << std::endl;
        std::cout << "Data.c = " << dataPtr->c << std::endl;
        std::cout << "Data.flag = " << (dataPtr->flag ? "true" : "false") << std::endl;
    }
    return 0;
}