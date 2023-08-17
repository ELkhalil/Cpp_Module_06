/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:00:42 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/17 12:03:47 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <sstream>

class   ScalarConverter
{
public:
    ScalarConverter     ( ScalarConverter const& other );
    ~ScalarConverter    ( void );
    ScalarConverter&    operator=(ScalarConverter const& other);

    class   EmptyInputException : public   std::exception
    {
        public:
            const char* what() const throw();
    };
    class   InvalidInputException : public   std::exception
    {
        public:
            const char* what() const throw();
    };

    static void     convert( std::string const& input );
    static void     printScalarConverterData( void );

private:
    ScalarConverter     ( void );

    static char     _charValue;
    static int      _intValue;
    static float    _floatValue;
    static double   _doubleValue;
    static bool     _charImpossible;
    static bool     _intImpossible;
    static bool     _floatImpossible;
    static bool     _doubleImpossible;
    
    static char     _parseType( std::string const& input );
    static bool     _isValidChar( std::string const& input );
    static bool     _isValidInt( std::string const& input );
    static bool     _isValidFloat( std::string const& input );
    static bool     _isValidDouble( std::string const& input );

    static bool     _isSpecialFloat( std::string const& input );
    static bool     _isSpecialDouble (std::string const& input );

    static void     _convertChar( std::string const& input );
    static void     _convertInt( std::string const& input );
    static void     _convertFloat( std::string const& input );
    static void     _convertDouble( std::string const& input );
};

// Conversion Functions
int     stringToInt( std::string const& input );
float   stringToFloat ( std::string const& input );
double  stringToDouble ( std::string const& input );
#endif
