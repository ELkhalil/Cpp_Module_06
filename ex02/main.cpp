/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:01:45 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/14 16:37:07 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main( void )
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 5; i++)
    {
        Base    *testBase = generate();
        Base    &testbaseRef = *testBase;
        identify(testBase);
        identify(testbaseRef);
        delete testBase;
        std::cout << "-----------------" << std::endl;
    }
    return 0;
}