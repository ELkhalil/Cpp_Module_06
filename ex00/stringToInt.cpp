/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringToInt.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:01:38 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/16 12:51:07 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int stringToInt(const std::string& input)
{
    std::istringstream iss(input);
    long value;

    iss >> value;

    if (iss.fail() || !iss.eof())
        throw std::invalid_argument("Int: Invalid characters in input");
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        throw std::overflow_error("int: Overflow/Underflow during conversion");
    int result = static_cast<int>(value);
    return result;
}