/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:26:05 by alejandj          #+#    #+#             */
/*   Updated: 2026/03/30 13:30:41 by alejandj         ###   ########.fr       */
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
	_name = object._name;
	_hitPoints = object._hitPoints;
	_energyPoints = object._energyPoints;
	_attackDamage = object._attackDamage;
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
		std::cout << "ClapTrap <" << _name << "> can't attack, "
				  << RED << "is dead!" << RESET << std::endl;
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
				  << ", causing " << YELLOW << _attackDamage << RESET
				  << " points of damage!" << std::endl;  
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap <" << _name << "> "
				  << RED << "is already dead!!" << RESET << std::endl;
	}
	else if (amount >= _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap <" << _name << ">"
				  << " receives " << YELLOW << amount << RESET
				  << " points of damage!,"
				  << RED << " dead!!" << RESET << std::endl;
		return ;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap <" << _name << ">"
				  << " receives " << YELLOW << amount << RESET
				  << " points of damage!, HP left: "
				  << GREEN << _hitPoints << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap <" << _name << "> can't be repaired, " 
				  << RED << "is dead!" << RESET << std::endl;
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
				  << " hit points!, Current HP: "
				  << GREEN << _hitPoints << RESET << std::endl;
	}
}
