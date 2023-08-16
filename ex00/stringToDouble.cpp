/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringToDouble.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:08:18 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/16 13:16:33 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

double  stringToDouble ( std::string const& input )
{
    long double         result = 0.0;
    double              final_result = 0.0;
    std::istringstream  ss(input);

    ss >> result;

    if (ss.fail() || !ss.eof() )
        throw (std::invalid_argument("Double: Invalid input during conversion"));
    
    if (result > std::numeric_limits<double>::max() ||
        result < -std::numeric_limits<double>::max())
    {
        throw std::overflow_error("Double: Overflow/Underflow during conversion");
    }
    final_result = static_cast<double>(result);
    return final_result;
}