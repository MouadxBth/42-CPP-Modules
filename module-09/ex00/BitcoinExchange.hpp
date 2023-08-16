/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:49:02 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/16 05:38:23 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <map>

typedef struct s_date
{
    std::string stringFormat;
    int year;
    int month;
    int day;
}   Date;

class BitcoinExchange
{

private:
    std::map<unsigned int, double> _prices;
    const std::string _database;

    void    loadDatabase(const std::string& database);
    std::string    trimString(const std::string& input);
    bool extractDateComponents(const std::string& date, int& year, int& month, int& day);
    bool isValidDate(int year, int month, int day);
    

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& instance);
    BitcoinExchange& operator=(const BitcoinExchange& instance);

    BitcoinExchange(std::string database);

    std::map<unsigned int, double> getPrices() const;

    void    calculate(const std::string& file);
};
