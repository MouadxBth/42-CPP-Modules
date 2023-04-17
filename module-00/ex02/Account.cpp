#include <iostream>
#include <iomanip>
#include <time.h>
#include "Account.hpp"

int Account::_nbAccounts = 0;

int Account::_totalAmount = 0;

int Account::_totalNbDeposits = 0;

int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
    char		buffer[22];
    struct tm 	t_struct;
    time_t	now = time(0);
	
	
	t_struct = *localtime(&now);
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", &t_struct);
	std::cout << buffer;
}

int Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";"
              << "total:" << Account::_totalAmount << ";"
              << "deposits:" << Account::_totalNbDeposits << ";"
              << "withdrawals:" << Account::_totalNbWithdrawals 
              << std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts++),
                                        _amount(initial_deposit),
                                        _nbDeposits(0),
                                        _nbWithdrawals(0)
{
    Account::_displayTimestamp();
    Account::_totalAmount += initial_deposit;

    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << initial_deposit << ";"
              << "created"
              << std::endl;
}
Account::~Account(void)
{
    Account::_displayTimestamp();
    Account::_nbAccounts--;

    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "closed"
              << std::endl;
}

void Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();

    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << this->_amount << ";"
              << "deposit:" << deposit << ";";

    this->_amount += deposit;
    this->_nbDeposits++;

    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;

    std::cout << "amount:" << this->_amount << ";"
              << "nb_deposits:" << this->_nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();

    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << this->_amount << ";";

    if (this->_amount < withdrawal)
        return (std::cout << "withdrawal:refused" << std::endl, false);

    this->_amount -= withdrawal;
    this->_nbWithdrawals++;

    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;

    std::cout << "withdrawal:" << withdrawal << ";"
              << "amount:" << this->_amount << ";"
              << "nb_withdrawals:" << this->_nbWithdrawals
              << std::endl;
    return (true);
}

int Account::checkAmount(void) const
{
    return (this->_amount > 0);
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();

    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "deposits:" << this->_nbDeposits << ";"
              << "withdrawals:" << this->_nbWithdrawals
              << std::endl;
}