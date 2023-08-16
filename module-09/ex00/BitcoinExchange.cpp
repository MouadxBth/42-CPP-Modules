/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:02:12 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/16 05:58:20 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
    loadDatabase("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& instance)
{
    *this = instance;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& instance)
{
    if (this != &instance)
    {
        std::map<unsigned int, double>::iterator start = instance.getPrices().begin();
        this->_prices.clear();

        while (start != instance.getPrices().end())
        {
            this->_prices[start->first] = start->second;
            start++;
        }
    }
    return (*this);
}

BitcoinExchange::BitcoinExchange(std::string database) : _database(database)
{
    if (database.empty() || (database.rfind(".csv") == std::string::npos))
    {
        std::cerr << "ERROR: The given database: "
            << database
            << " is not a csv file!"
            << std::endl;
        std::exit(EXIT_FAILURE);
    } 

    loadDatabase(database);
}

void    BitcoinExchange::loadDatabase(const std::string& database)
{
    std::ifstream file(database.c_str());
    
    if (!file) {
        std::cerr << "Error: could not open file: " << database << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    std::string date;
    int year, month, day;
    double exchangeRate;
    std::istringstream lineStream;

    while (std::getline(file, line))
    {
        if (line.empty() || line == "date,exchange_rate")
            continue; // Skip header or empty lines

        lineStream.clear();
        lineStream.str(line);

        if (!std::getline(lineStream, date, ','))
        {
            std::cerr << "Error: invalid input format => " 
                << line 
                << "\nFailed to extract date string up to the comma.\n"
                << "should be:\ndate,exchange_rate" 
                << std::endl;
            continue;
        }

        if (!(lineStream >> exchangeRate) || lineStream.fail() || !lineStream.eof())
        {
            std::cerr << "Error: invalid input format => " 
                << line 
                << "\nFailed to extract rate as a double.\n"
                << "should be:\ndate,exchange_rate" 
                << std::endl;
            continue;
        }

        if (!extractDateComponents(date, year, month, day))
        {
            std::cerr << "Error: invalid input format => " 
                << line 
                << "\nInvalid date format.\n"
                << "should be:\nYYYY-MM-DD" 
                << std::endl;
            continue;
        }

        if (!isValidDate(year, month, day))
        {
            std::cerr << "Error: invalid input => " 
                << line 
                << "\nInvalid date.\n"
                << std::endl;
            continue;
        }

        if (exchangeRate < 0.0)
        {
            std::cerr << "Error: exchange rate not a positive number. => " 
                << line 
                << std::endl;
            continue;
        }

        _prices[(year * 10000 + month * 100 + day)] = exchangeRate;
    }
}

void    BitcoinExchange::calculate(const std::string& fileName)
{
    if (fileName.empty() || (fileName.rfind(".csv") == std::string::npos))
    {
        std::cerr << "ERROR: The given file: "
            << fileName
            << " is not a csv file!"
            << std::endl;
        std::exit(EXIT_FAILURE);
    } 

    std::ifstream file(fileName.c_str());
    
    if (!file) {
        std::cerr << "Error: could not open file: " << fileName << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    std::string date;
    int year, month, day;
    double currentValue;
    std::istringstream lineStream;
    std::map<unsigned int, double>::iterator it;

    while (std::getline(file, line))
    {
        if (line.empty() || line == "date | value")
            continue; // Skip header or empty lines

        lineStream.clear();
        lineStream.str(line);

        if (!std::getline(lineStream, date, '|'))
        {
            std::cerr << "Error: bad input => " 
                << line 
                << std::endl;
            continue;
        }

        date = trimString(date);

        if (!(lineStream >> currentValue) || lineStream.fail() || !lineStream.eof())
        {
            std::cerr << "Error: bad input => " 
                << line 
                << std::endl;
            continue;
        }

        if (!extractDateComponents(date, year, month, day))
        {
            std::cerr << "Error: bad input => " 
                << line 
                << std::endl;
            continue;
        }

        if (!isValidDate(year, month, day))
        {
            std::cerr << "Error: bad input => " 
                << line 
                << std::endl;
            continue;
        }

        if (currentValue < 0.0 || currentValue > 1000.0)
        {
            if (currentValue < 0.0)
                std::cerr << "Error: not a positive number. " << std::endl;
            else
                std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        it = this->_prices.upper_bound(year * 10000 + month * 100 + day);

        std::cout << year << "-";
        if (month < 10)
            std::cout << "0" << month;
        else
            std::cout << month;
        std::cout << "-";
       
        if (day < 10)
            std::cout << "0" << day;
        else
            std::cout << day;
        std::cout << " => "
            << currentValue * (it != this->_prices.begin() ? (--it)->second : it->second)
            << std::endl;
    }    
}

std::string BitcoinExchange::trimString(const std::string& str)
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

bool BitcoinExchange::extractDateComponents(const std::string& date, int& year, int& month, int& day)
{
    if (date.empty())
        return (false);

    std::istringstream iss(date);

    char firstDelimiter, secondDelimiter;
    
    if ((iss >> year >> firstDelimiter >> month >> secondDelimiter >> day) 
        && (firstDelimiter == '-' && secondDelimiter == '-' && iss.eof()))
        return (true);
    return (false);  // Extraction or format is incorrect
}

bool BitcoinExchange::isValidDate(int year, int month, int day) {
    if (year < 0 || month < 1 || month > 12 || day < 1)
        return (false);

    static const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int daysInCurrentMonth = daysInMonth[month];

    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
        daysInCurrentMonth = 29;

    return (day <= daysInCurrentMonth);
}

std::map<unsigned int, double> BitcoinExchange::getPrices() const
{
    return (_prices);
}