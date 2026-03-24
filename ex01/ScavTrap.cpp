/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:43:12 by alejandj          #+#    #+#             */
/*   Updated: 2026/03/24 13:32:35 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Call de ClapTrap constructor {_name = "Default", _hitPoints = 10, _energyPoints = 10, _attackDamage = 0}
// But overwrite the values _hitPoints, _energyPoints, _attackDamage
ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << MAGENTA << "ScavTrap: Default constructor called" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << MAGENTA << "ScavTrap: Parameterized constructor called" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

// Call ClapTrap copy constructor to copy the base (common) part of ScavTrap
ScavTrap::ScavTrap(const ScavTrap& object): ClapTrap(object)
{
	std::cout << BLUE << "ScavTrap: Copy constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& object)
{
	std::cout << WHITE << "ScavTrap: Copy assignment operator called" << RESET << std::endl;
	ClapTrap::operator=(object);

	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap: Destructor called" << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap <" << _name << "> can't attack, dead!" << std::endl;
		return ;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap <" << _name << "> can't attack, no energy!" << std::endl;
		return ;
	}
	else
	{
		_energyPoints--; 
		std::cout << "ScavTrap <" << _name << ">"
				  << YELLOW << " attacks " << RESET << target 
				  << ", causing " << BOLD << YELLOW << _attackDamage << RESET
				  << " points of damage!" << std::endl;  
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
