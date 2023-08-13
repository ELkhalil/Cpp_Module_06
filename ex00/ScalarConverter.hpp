/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:00:42 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/13 15:32:54 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <iostream>

class   ScalarConverter
{
public:
    ScalarConverter     ( void );
    ScalarConverter     ( ScalarConverter const& other );
    ~ScalarConverter    ( void );
    ScalarConverter&    operator=(ScalarConverter const& other);
    void                convert( std::string const& input );
    
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

    char         getCharValue( void ) const;
    int          getIntValue( void ) const;
    float        getFloatValue( void ) const;
    double       getDoubleValue( void ) const;

    bool         getIsCharImpossible ( void ) const;
    bool         getIsIntImpossible ( void ) const;
    bool         getIsFloatImpossible ( void ) const;
    bool         getIsDoubleImpossible ( void ) const;

private:
    char         _charValue;
    int          _intValue;
    float        _floatValue;
    double       _doubleValue;

    bool         _charImpossible;
    bool         _intImpossible;
    bool         _floatImpossible;
    bool         _doubleImpossible;

    char         _parseType( std::string const& input );
    bool         _isValidChar( std::string const& input );
    bool         _isValidInt( std::string const& input );
    bool         _isValidFloat( std::string const& input );
    bool         _isValidDouble( std::string const& input );

    bool         _isSpecialFloat( std::string const& input );
    bool         _isSpecialDouble (std::string const& input );

    void         _convertChar( std::string const& input );
    void         _convertInt( std::string const& input );
    void         _convertFloat( std::string const& input );
    void         _convertDouble( std::string const& input );
};

std::ostream& operator<<(std::ostream& out, ScalarConverter const& scalar);

#endif