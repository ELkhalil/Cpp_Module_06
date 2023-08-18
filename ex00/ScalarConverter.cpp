/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:15:59 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/18 16:23:12 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// init static members 
char    ScalarConverter::_charValue = 0;
int     ScalarConverter::_intValue = 0;
float   ScalarConverter::_floatValue = 0;
double  ScalarConverter::_doubleValue = 0;

bool    ScalarConverter::_intImpossible = false;
bool    ScalarConverter::_floatImpossible = false;
bool    ScalarConverter::_doubleImpossible = false;
bool    ScalarConverter::_charImpossible = false;

// ScalarConverter constructors
ScalarConverter::ScalarConverter    ( void )
{
    // std::cout << "ScalarConverter Default Constructor" << std::endl;
}

ScalarConverter::ScalarConverter    (ScalarConverter const& other)
{
    // std::cout << "ScalarConverter Copy Constructor" << std::endl;
    (*this) = other;
}

ScalarConverter::~ScalarConverter    (void)
{
    // std::cout << "ScalarConverter Destructor" << std::endl;
}

ScalarConverter& ScalarConverter::operator= (ScalarConverter const& other)
{
    // std::cout << "ScalarConverter Copy Assignement Operator" << std::endl;
    if (this != &other)
        std::cout << "ScalarConverter Copy Assignement Operator" << std::endl;
    return (*this);
}

// Exception Handling
const char* ScalarConverter::EmptyInputException::what() const throw()
{
    return ("Empty Input");
}
const char* ScalarConverter::InvalidInputException::what() const throw()
{
    return ("Invalid Input");
}

// ScalarConverter Methods
void    ScalarConverter::convert( std::string const& input )
{
    try
    {
        char    type = _parseType(input);
        if (type == 'c')
            _convertChar(input);
        else if (type == 'i')
            _convertInt(input);
        else if (type == 'f')
            _convertFloat(input);
        else if (type == 'd')
            _convertDouble(input);
        else
            throw(ScalarConverter::InvalidInputException());
    }
    catch(ScalarConverter::InvalidInputException& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}
char    ScalarConverter::_parseType( std::string const& input )
{
    try
    {
        if (input.empty())
            throw (ScalarConverter::EmptyInputException());
        else if (input.size() == 1 && !_isValidInt(input))
            return 'c';
        else if (_isValidInt(input) )
            return 'i';
        else if (!_isSpecialDouble(input) && (_isValidFloat(input) || _isSpecialFloat(input)))
            return 'f';
        else if (!_isSpecialFloat(input) && (_isValidDouble(input) || _isSpecialDouble(input)))
            return 'd';
        else
            throw(ScalarConverter::InvalidInputException());
    }
    catch(ScalarConverter::EmptyInputException& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    catch(ScalarConverter::InvalidInputException& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

// ScalarCOnverter Conversion Methods
void    ScalarConverter::_convertChar(std::string const& input) 
{
    ScalarConverter::_charValue = input[0];
    ScalarConverter::_intValue = static_cast<int>(_charValue);
    ScalarConverter::_floatValue = static_cast<float>(_charValue);
    ScalarConverter::_doubleValue = static_cast<double>(_charValue);
}
void    ScalarConverter::_convertInt( std::string const& input )
{
    try
    {
        ScalarConverter::_intValue = stringToInt(input);
        ScalarConverter::_charValue = static_cast<char>(ScalarConverter::_intValue);
        ScalarConverter::_floatValue = static_cast<float>(ScalarConverter::_intValue);
        ScalarConverter::_doubleValue = static_cast<double>(ScalarConverter::_intValue);
    }
    catch (std::overflow_error const& e)
    {
        std::cerr << e.what();
        exit(1);
    }
    catch (...)
    {
        std::cerr << "Error: During String To Int Conversion" << std::endl;
        exit(1);
    }
}
void    ScalarConverter::_convertFloat( std::string const& input )
{
    if (_isSpecialFloat(input)) 
    {
        ScalarConverter::_floatValue = std::numeric_limits<float>::quiet_NaN();
        if (input == "-inff")
            ScalarConverter::_floatValue = -std::numeric_limits<float>::infinity();
        else if (input == "+inff") 
            ScalarConverter::_floatValue = std::numeric_limits<float>::infinity();
        ScalarConverter::_charImpossible = true;
        ScalarConverter::_intImpossible = true;
        ScalarConverter::_doubleValue = static_cast<double>(ScalarConverter::_floatValue);
    }
    else
    {
        try
        {
            ScalarConverter::_floatValue = stringToFloat(input);
            ScalarConverter::_charValue = static_cast<char>(ScalarConverter::_floatValue);
            if (ScalarConverter::_floatValue < std::numeric_limits<int>::max()
                && ScalarConverter::_floatValue > std::numeric_limits<int>::min())
                ScalarConverter::_intValue = static_cast<int>(ScalarConverter::_floatValue);
            else
                ScalarConverter::_intImpossible = true;
            ScalarConverter::_doubleValue = static_cast<double>(ScalarConverter::_floatValue);
        }
        catch (std::overflow_error const& e)
        {
            std::cerr << e.what();
            exit(1);
        }
        catch (...)
        {
            std::cerr << "Error: During String To Float Conversion" << std::endl;
            exit(1);
        }
    }
}
void    ScalarConverter::_convertDouble( std::string const& input )
{
    if (_isSpecialDouble(input)) 
    {
        ScalarConverter::_doubleValue = std::numeric_limits<double>::quiet_NaN();
        if (input == "-inf")
            ScalarConverter::_doubleValue = -std::numeric_limits<double>::infinity();
        else if (input == "+inf")
            ScalarConverter::_doubleValue = std::numeric_limits<double>::infinity();
        ScalarConverter::_charImpossible = true;
        ScalarConverter::_intImpossible = true;
        ScalarConverter::_floatValue = static_cast<float>(ScalarConverter::_doubleValue);
    }
    else
    {
        try
        {
            ScalarConverter::_doubleValue = stringToDouble(input);
            if (ScalarConverter::_doubleValue < std::numeric_limits<int>::max() 
                && ScalarConverter::_doubleValue > std::numeric_limits<int>::min())
                ScalarConverter::_intValue = static_cast<int>(ScalarConverter::_doubleValue);
            else
                ScalarConverter::_intImpossible = true;
            if (ScalarConverter::_doubleValue < std::numeric_limits<float>::max() ||
                ScalarConverter::_doubleValue > -std::numeric_limits<float>::max())
                ScalarConverter::_floatValue = static_cast<float>(ScalarConverter::_doubleValue);
            else
                ScalarConverter::_floatImpossible = true;
            ScalarConverter::_charValue = static_cast<char>(ScalarConverter::_doubleValue);
        }
        catch (std::overflow_error const& e)
        {
            std::cerr << e.what();
            exit(1);
        }
        catch (...)
        {
            std::cerr << "Error: During String To Double Conversion" << std::endl;
            exit(1);
        }
    }
}

// ScalarConverter Parsing Helper Methods
bool    ScalarConverter::_isValidInt(const std::string& input) 
{
    try
    {
        stringToInt(input);
        return true;
    }
    catch (...)
    {
        return false;
    }
}
bool    ScalarConverter::_isValidFloat(const std::string& input) 
{
    if (!(!input.empty() && input[input.size() - 1] == 'f'))
        return false;
    try
    {
        stringToFloat(input);
        return true;
    }
    catch (std::invalid_argument const& e)
    {
        return false;
    }
    catch (...)
    {
        return true;
    }
}
bool    ScalarConverter::_isValidDouble(const std::string& input) 
{
    try
    {
        stringToDouble(input);
        return true;
    }
    catch (std::invalid_argument const& e)
    {
        return false;
    }
    catch (...)
    {
        return true;
    }
}

// Special Input checkers
bool    ScalarConverter::_isSpecialFloat(const std::string& input) 
{
    return input == "-inff" || input == "+inff" || input == "nanf";
}
bool    ScalarConverter::_isSpecialDouble(const std::string& input) 
{
    return input == "-inf" || input == "+inf" || input == "nan";
}

// Outputing Class data overload
void     ScalarConverter::printScalarConverterData( void )
{
    /*  Char Printing */
    if (ScalarConverter::_charValue >= ' ' && ScalarConverter::_charValue <= '~')
        std::cout <<  "char: '" << ScalarConverter::_charValue << "'" << std::endl;
    else if (ScalarConverter::_charImpossible)
        std::cout <<  "char: impossible" << std::endl;
    else
        std::cout <<  "char: Non displayable" << std::endl;

    /*  Int Printing */
    if (!ScalarConverter::_intImpossible)
        std::cout << "int: "    << ScalarConverter::_intValue << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    /*  Float Printing */
    if (!ScalarConverter::_floatImpossible)
    {
        if (ScalarConverter::_floatValue == static_cast<float>(ScalarConverter::_intValue)) 
            std::cout << "float: " << ScalarConverter::_floatValue << ".0f" << std::endl;
        else
            std::cout << "float: " << ScalarConverter::_floatValue << "f" << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;

    /*  Double Printing */
    if (!ScalarConverter::_doubleImpossible) 
    {
        if (ScalarConverter::_doubleValue == static_cast<double>(ScalarConverter::_intValue))
            std::cout << "double: " << ScalarConverter::_doubleValue << ".0" << std::endl;
        else
            std::cout << "double: " << ScalarConverter::_doubleValue << std::endl;
    }
    else
        std::cout << "double: impossible" << std::endl;
}