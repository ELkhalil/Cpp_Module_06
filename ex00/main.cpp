/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:00:36 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/13 15:27:14 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char *av[]) 
{
    if (ac != 2)
    {
        std::cerr << "Error: Invalid Program Arguments" << std::endl;
        return(1);
    }
    try
    {
        std::string arg = av[1];
        ScalarConverter scalar;

        scalar.convert(arg);
        std::cout << scalar << std::endl;
    }
    catch( std::exception const& e)
    {
        std::cerr << "Exception: ";
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
