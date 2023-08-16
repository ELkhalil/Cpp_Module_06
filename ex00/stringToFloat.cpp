/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringToFloat.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:03:21 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/16 13:07:57 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

float stringToFloat(const std::string& input)
{
    /* Removed the f(float) from the string */
    std::string cleanedInput = input;
    if (!cleanedInput.empty() && cleanedInput[cleanedInput.size() - 1] == 'f') 
            cleanedInput.erase(cleanedInput.size() - 1);

    std::istringstream iss(cleanedInput);
    double result = 0.0;

    iss >> result;
    if (iss.fail() || !iss.eof() )
        throw (std::invalid_argument("Float: Invalid input during conversion"));

    if (result > std::numeric_limits<float>::max() ||
        result < -std::numeric_limits<float>::max())
    {
        throw std::overflow_error("Float: Overflow/Underflow during conversion");
    }

    float final_result = result;
    return final_result;
}
