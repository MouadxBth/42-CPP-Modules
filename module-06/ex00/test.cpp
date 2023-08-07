/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 01:55:06 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/07 17:43:26 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <cfloat>
#include "ScalarConverter.hpp"

static std::string charToString(char c)
{
    std::stringstream ss;

    ss << c;
    return (ss.str());
}

static std::string intToString(int i)
{
    std::stringstream ss;

    ss << i;
    return (ss.str());
}

static std::string floatToString(float f)
{
    std::stringstream ss;

    ss << std::fixed << f << "f";
    return (ss.str());
}

static std::string doubleToString(double d)
{
    std::stringstream ss;
    
    ss << std::fixed << d;
    return (ss.str());
}

int main(int argc, char* argv[])
{
    bool c = false, i = false, f = false, d = false, s = false;

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <input_literal>" << std::endl;
        return 1;
    }

    c = (argv[1][0] == 'c');
    i = (argv[1][0] == 'i');
    f = (argv[1][0] == 'f');
    d = (argv[1][0] == 'd');
    s = (argv[1][0] == 's');

    {
        if (c) {
        std::string input[] = {
            "0", "a", "A", "", "\x20", "\0", "\x7F", "\xFF", "\xF4", "\x80", "\x81", "\x9F", "\xA0",
            charToString(std::numeric_limits<char>::max()), charToString(std::numeric_limits<char>::min())
        };

        std::cout << "Character tests:" << std::endl;

        for (size_t i = 0; i != sizeof(input) / sizeof(*input); i++)
        {
            std::cout << "\n\n=> Converting : " << static_cast<int>(input[i][0]) << "\n\n";
            ScalarConverter::convert(input[i] + "");
        }
        }
    }

    {
        if (i) {
        std::string input[] = {
            "40", "42", "2147483647", "-2147483648", "2147483648", "-2147483649",
            intToString(std::numeric_limits<int>::max()), intToString(std::numeric_limits<int>::min())
        };

        std::cout << "Integer tests:" << std::endl;

        for (size_t i = 0; i != sizeof(input) / sizeof(*input); i++)
        {
            std::cout << "\n\n=> Converting : " << input[i] << "\n\n";
            ScalarConverter::convert(input[i] + "");
        }
        }
    }

    {
        if (f) {
        std::string input[] = {
            "0.0.0",
            "0f", "1337f", "40.0f", "42.0f",
            "2147483647f", "-2147483648f", "2147483648f", "-2147483649f",
            "12345.6789f", "0.00000001f", ".1337f",
            "-3402823466385288598117041834845169254400.0000000000000000f",
            "-340282346638528859811704183484516925440.0000000000000000f",
            "3402823466385288598117041834845169254400.0000000000000000f",
            "340282346638528859811704183484516925440.0000000000000000f",
            floatToString(std::numeric_limits<float>::max()),
            floatToString(-std::numeric_limits<float>::max()),
        };
        std::cout << "Float tests:" << std::endl;

        for (size_t i = 0; i != sizeof(input) / sizeof(*input); i++)
        {
            std::cout << "\n\n=> Converting : " << input[i] << "\n\n";
            ScalarConverter::convert(input[i] + "");
        }
        }
    }

    {
        if (d) {
        std::string input[] = {
            "0", "1337", "40", "42",
            "0f", "1337f", "40.0f", "42.0f",
            "0.0", "1337.0", "40.0", "42.0",
            "2147483647.0", "-2147483648.0", "2147483648.0", "-2147483649.0",
            "12345.6789.0", "0.00000001", ".1337",
            "-3402823466385288598117041834845169254400.0000000000000000",
            "-340282346638528859811704183484516925440.0000000000000000",
            "3402823466385288598117041834845169254400.0000000000000000",
            "340282346638528859811704183484516925440.0000000000000000",
            "-1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583690.0000000000000000",
            "-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000",
            "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000",
            "1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583690.0000000000000000",
            doubleToString(std::numeric_limits<double>::max()), doubleToString(-std::numeric_limits<double>::max())
        };

        std::cout << "Double tests:" << std::endl;
        

        for (size_t i = 0; i != sizeof(input) / sizeof(*input); i++)
        {
            std::cout << "\n\n=> Converting : " << input[i] << "\n\n";
            ScalarConverter::convert(input[i] + "");
        }
        }
    }
    {
        if (s) {
        std::string input[] = {
            "inf", "+inf", "-inf",
            "inff", "+inff", "-inff",
            "nan", "nanf",
            "+nan", "-nan", "info"
        };

        std::cout << "Special tests:" << std::endl;

        for (size_t i = 0; i != sizeof(input) / sizeof(*input); i++)
        {
            std::cout << "\n\n=> Converting : " << input[i] << "\n\n";
            ScalarConverter::convert(input[i] + "");
        }
        }
    }

    return 0;
}