/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:26:05 by alejandj          #+#    #+#             */
/*   Updated: 2026/03/24 13:02:32 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << MAGENTA << "ClapTrap: Default constructor called" << RESET << std::endl;
	_name = "Default";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << MAGENTA << "ClapTrap: Parameterized constructor called" << RESET << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& object)
{
	std::cout << BLUE << "ClapTrap: Copy constructor called" << RESET << std::endl;
	*this = object;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& object)
{
	std::cout << WHITE << "ClapTrap: Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
	{
		_name = object._name;
		_hitPoints = object._hitPoints;
		_energyPoints = object._energyPoints;
		_attackDamage = object._attackDamage;
    }
    
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap: Destructor called" << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap <" << _name << "> can't attack, dead!" << std::endl;
		return ;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap <" << _name << "> can't attack, no energy!" << std::endl;
		return ;
	}
	else
	{
		_energyPoints--; 
		std::cout << "ClapTrap <" << _name << ">"
				  << YELLOW << " attacks " << RESET << target 
				  << ", causing " << BOLD << YELLOW << _attackDamage << RESET
				  << " points of damage!" << std::endl;  
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap <" << _name << "> "
				  << BOLD << RED << "is already dead!!" << std::endl;
	}
	else if (amount >= _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap <" << _name << ">"
				  << BOLD << RED << " dead!!" << RESET << std::endl;
		return ;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap <" << _name << ">"
				  << " receives " << amount
				  << " points of damage!, HP left: "
				  << BOLD << GREEN << _hitPoints << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap <" << _name << "> can't be repaired, dead!" << std::endl;
		return ;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap <" << _name << "> can't be repaired, no energy!" << std::endl;
		return ;
	}
	else
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap <" << _name << ">"
				  << GREEN << " repairs" << RESET << " itself for " << amount
				  << " hit points!, Current HP: " << BOLD << GREEN << _hitPoints << RESET << std::endl;
	}
}
