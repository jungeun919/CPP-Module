/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:25:43 by jungeun           #+#    #+#             */
/*   Updated: 2023/02/28 23:59:58 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Account.hpp"
# include <iostream>
# include <ctime>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_displayTimestamp();

	std::cout << " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";created"
		<< std::endl;
}

Account::~Account(void)
{
	this->_totalAmount -= this->_amount;
	this->_totalNbDeposits -= this->_nbDeposits;
	this->_totalNbWithdrawals -= this->_nbWithdrawals;

	Account::_displayTimestamp();

	std::cout << " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed"
		<< std::endl;
}

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();

	std::cout << " accounts:" << Account::getNbAccounts()
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals()
		<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		now;
	struct tm	*t;

	now = time(NULL);
	t = localtime(&now);
	std::cout << "[" << t->tm_year + 1900 << t->tm_mon + 1 << t->tm_mday << "_"
		<< t->tm_hour << t->tm_min << t->tm_sec << "]";
}

void	Account::makeDeposit(int deposit)
{
	int	temp;
	
	temp = this->_amount + deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	this->_totalAmount += deposit;

	Account::_displayTimestamp();

	std::cout << " index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";deposit:" << deposit
		<< ";amount:" << temp
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl;

	this->_amount = temp;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	temp;

	temp = this->_amount - withdrawal;
	
	Account::_displayTimestamp();

	if (temp < 0)
	{
		std::cout << " index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";withdrawal:refused" << std::endl;
		
		return false;
	}
	else
	{
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		this->_totalAmount -= withdrawal;
		
		std::cout << " index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << temp
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
		
		this->_amount = temp;
		
		return true;
	}
}

int	Account::checkAmount(void) const
{	
	return _amount;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();

	std::cout << " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl; 
}
