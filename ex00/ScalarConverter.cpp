/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:15:59 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/16 19:38:18 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ScalarConverter constructors
ScalarConverter::ScalarConverter    ( void )
    : _charValue(0), _intValue(0), _floatValue(0), _doubleValue(0)
{
    // std::cout << "ScalarConverter Default Constructor" << std::endl;
    this->_intImpossible = false;
    this->_floatImpossible = false;
    this->_doubleImpossible = false;
    this->_charImpossible = false;
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
    {
        this->_charValue = other._charValue;
        this->_intValue = other._intValue;
        this->_floatValue = other._floatValue;
        this->_doubleValue = other._doubleValue;
        this->_charImpossible = other._charImpossible;
        this->_intImpossible = other._intImpossible;
        this->_floatImpossible = other._floatImpossible;
        this->_doubleImpossible = other._doubleImpossible;
    }
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

// Getters of ScalarConverter
char    ScalarConverter::getCharValue  ( void ) const { return  this->_charValue;}
int     ScalarConverter::getIntValue   ( void ) const { return  this->_intValue;}
float   ScalarConverter::getFloatValue ( void ) const { return  this->_floatValue;}
double  ScalarConverter::getDoubleValue( void ) const { return  this->_doubleValue;}

bool    ScalarConverter::getIsCharImpossible ( void ) const {return this->_charImpossible;}
bool    ScalarConverter::getIsIntImpossible ( void ) const {return this->_intImpossible;}
bool    ScalarConverter::getIsFloatImpossible ( void ) const {return this->_floatImpossible;}
bool    ScalarConverter::getIsDoubleImpossible ( void ) const {return this->_doubleImpossible;}

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
    catch(ScalarConverter::InvalidInputException e)
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
    catch(ScalarConverter::EmptyInputException e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    catch(ScalarConverter::InvalidInputException e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

// ScalarCOnverter Conversion Methods
void    ScalarConverter::_convertChar(std::string const& input) 
{
    this->_charValue = input[0];
    this->_intValue = static_cast<int>(_charValue);
    this->_floatValue = static_cast<float>(_charValue);
    this->_doubleValue = static_cast<double>(_charValue);
}
void    ScalarConverter::_convertInt( std::string const& input )
{
    try
    {
        this->_intValue = stringToInt(input);
        this->_charValue = static_cast<char>(this->_intValue);
        this->_floatValue = static_cast<float>(this->_intValue);
        this->_doubleValue = static_cast<double>(this->_intValue);
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
        this->_floatValue = std::numeric_limits<float>::quiet_NaN();
        if (input == "-inff")
            this->_floatValue = -std::numeric_limits<float>::infinity();
        else if (input == "+inff") 
            this->_floatValue = std::numeric_limits<float>::infinity();
        this->_charImpossible = true;
        this->_intImpossible = true;
        this->_doubleValue = static_cast<double>(this->_floatValue);
    }
    else
    {
        try
        {
            this->_floatValue = stringToFloat(input);
            this->_charValue = static_cast<char>(this->_floatValue);
            if (this->_floatValue < std::numeric_limits<int>::max()
                && this->_floatValue > std::numeric_limits<int>::min())
                this->_intValue = static_cast<int>(this->_floatValue);
            else
                this->_intImpossible = true;
            this->_doubleValue = static_cast<double>(this->_floatValue);
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
        this->_doubleValue = std::numeric_limits<double>::quiet_NaN();
        if (input == "-inf")
            this->_doubleValue = -std::numeric_limits<double>::infinity();
        else if (input == "+inf")
            this->_doubleValue = std::numeric_limits<double>::infinity();
        this->_charImpossible = true;
        this->_intImpossible = true;
        this->_floatValue = static_cast<float>(this->_doubleValue);
    }
    else
    {
        try
        {
            this->_doubleValue = stringToDouble(input);
            if (this->_doubleValue < std::numeric_limits<int>::max() 
                && this->_doubleValue > std::numeric_limits<int>::min())
                this->_intValue = static_cast<int>(this->_doubleValue);
            else
                this->_intImpossible = true;
            if (this->_doubleValue < std::numeric_limits<float>::max() ||
                this->_doubleValue > -std::numeric_limits<float>::max())
                this->_floatValue = static_cast<float>(this->_doubleValue);
            else
                this->_floatImpossible = true;
            this->_charValue = static_cast<char>(this->_doubleValue);
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
std::ostream& operator<<(std::ostream& out, ScalarConverter const& scalar)
{
    /*  Char Printing */
    if (scalar.getCharValue() >= ' ' && scalar.getCharValue() <= '~')
        out <<  "char: '" << scalar.getCharValue() << "'" << std::endl;
    else if (scalar.getIsCharImpossible())
        out <<  "char: impossible" << std::endl;
    else
        out <<  "char: Non displayable" << std::endl;

    /*  Int Printing */
    if (!scalar.getIsIntImpossible())
        out << "int: "    << scalar.getIntValue() << std::endl;
    else
        out << "int: impossible" << std::endl;

    /*  Float Printing */
    if (!scalar.getIsFloatImpossible())
    {
        if (scalar.getFloatValue() == static_cast<float>(scalar.getIntValue())) 
            out << "float: " << scalar.getFloatValue() << ".0f" << std::endl;
        else
            out << "float: " << scalar.getFloatValue() << "f" << std::endl;
    }
    else
        out << "float: impossible" << std::endl;

    /*  Double Printing */
    if (!scalar.getIsDoubleImpossible()) 
    {
        if (scalar.getDoubleValue() == static_cast<double>(scalar.getIntValue()))
            out << "double: " << scalar.getDoubleValue() << ".0" << std::endl;
        else
            out << "double: " << scalar.getDoubleValue() << std::endl;
    }
    else
        out << "double: impossible" << std::endl;
    return out;
}