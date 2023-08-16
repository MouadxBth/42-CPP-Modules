/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:49:27 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/07 18:58:45 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <limits>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& instance)
{
    (void) instance;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& instance)
{
    (void) instance;
    return (*this);
}

static void printImpossible()
{
    std::cout << "char: impossible\n"
            << "int: impossible\n" 
            << "float: impossible\n" 
            << "double: impossible" 
            << std::endl;
}

static std::string trim(const std::string& str)
{
    if (str.length() == 1)
        return (str);
    size_t start = 0;
    size_t end = str.length() - 1;

    while (start <= end && std::isspace(str[start])) 
        start++;

    while (end >= start && std::isspace(str[end]))
        end--;

    return (str.substr(start, end - start + 1));
}

static bool isValidInteger(const std::string& input)
{
    size_t  index;

    if (input.empty())
        return (false);
    index = 0;
    if (input[index] == '+' || input[index] == '-')
        index++;
    if (index >= input.length() || !std::isdigit(input[index]))
        return (false);
    while (index < input.length())
    {
        if (!std::isdigit(input[index]))
            return (false);
        index++;
    }
    return (true);
}

static bool isValidFloatingPoint(const std::string& input)
{
    size_t  index;

    if (input.empty())
        return (false);
    index = 0;
    if (input[index] == '+' || input[index] == '-')
        index++;

    while (index < input.length() && std::isdigit(input[index]))
        index++;

    if (index < input.length() && input[index++] != '.')
        return (false);

    while (index < input.length() && std::isdigit(input[index]))
        index++;

    return (index == input.length() || ((index + 1) == input.length() 
        && (std::isdigit(input[index]) || input[index] == 'f' || input[index] == 'F')));
}

static bool isSpecial(const std::string& input)
{
    return (input == "-inff"
        || input == "+inff"
        || input == "nanf"
        || input == "-inf"
        || input == "+inf"
        || input == "nan");
}

static void printChar(const std::string& input)
{
    char c;
    int i;
    float f;
    double d;

    
    c = input[0];
    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);

    std::cout << std::fixed
        << std::setprecision(1)
        << "char: " << (std::isprint(c) ? std::string("\'") + c + "\'" : "Non displayable")
        << "\nint: " << i
        << "\nfloat: " << f << "f"
        << "\ndouble: " << d
        << std::endl;
}

static void printInt(const std::string& input)
{
    char c;
    int i;
    float f;
    double d;

    std::istringstream iss(input);

    iss >> i;
    if (iss.fail() || !iss.eof())
        return (printImpossible());
    c = static_cast<char>(i);
    f = static_cast<float>(i);
    d = static_cast<double>(i);

    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << "char: impossible ";
    else
        std::cout << "char: " << (std::isprint(c) ? std::string("\'") + c + "\'" : "Non displayable");
    
    std::cout << std::fixed
        << std::setprecision(1) 
        << "\nint: " << i 
        << "\nfloat: " << f << "f"
        << "\ndouble: " << d
        << std::endl;
}

static void printFloat(const std::string& input)
{
    char c;
    int i;
    float f;
    double d;

    std::istringstream iss(input);

    iss >> f;
    if (iss.fail())
        return (printImpossible());
    c = static_cast<char>(f);
    i = static_cast<int>(f);
    d = static_cast<double>(f);

    if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
        std::cout << "char: impossible";
    else
        std::cout << "char: " << (std::isprint(c) ? std::string("\'") + c + "\'" : "Non displayable");
    
    if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
        std::cout << "\nint: impossible";
    else
        std::cout << "\nint: " << i;

    std::cout << std::fixed
            << std::setprecision(1)
            << "\nfloat: " << f << "f"
            << "\ndouble: " << d << std::endl;
}

static void printDouble(const std::string& input)
{
    char c;
    int i;
    float f;
    double d;

    std::istringstream iss(input);

    iss >> d;
    if (iss.fail() || !iss.eof())
        return (printImpossible());
    c = static_cast<char>(d);
    i = static_cast<int>(d);
    f = static_cast<float>(d);

    if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
        std::cout << "char: impossible";
    else
        std::cout << "char: " << (std::isprint(c) ? std::string("\'") + c + "\'" : "Non displayable");
    
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "\nint: impossible";
    else
        std::cout << "\nint: " << i;

    if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
        std::cout << "\nfloat: impossible";
    else
        std::cout << std::fixed << std::setprecision(1) << "\nfloat: " << f << "f";

    std::cout << std::fixed 
        << std::setprecision(1) 
        << "\ndouble: " << d 
        << std::endl; 
}

static void printSpecial(const std::string& input)
{
    std::cout << "char: impossible\nint: impossible\n";
    if (input == "nan" || input == "nanf")
        std::cout << "float: nanf\ndouble: nan";
    else if (input == "+inf" || input == "+inff")
        std::cout << "float: +inff\ndouble: +inf";
    else if (input == "-inf" || input == "-inff")
        std::cout << "float: -inff\ndouble: -inf";
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
    std::string input = trim(str);

    if (input.length() > 1 
        && !isValidInteger(input)
        && !isValidFloatingPoint(input)
        && !isSpecial(input))
        return printImpossible();

    if (isSpecial(input))
        return printSpecial(input);

    if (input.length() <= 1)
        return printChar(input);
    if (isValidInteger(input))
        return printInt(input);
    if (isValidFloatingPoint(input) && input.find_first_of('f') != std::string::npos)
        printFloat(input);
    else
        printDouble(input);
}