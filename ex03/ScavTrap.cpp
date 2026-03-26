/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:43:12 by alejandj          #+#    #+#             */
/*   Updated: 2026/03/26 17:08:39 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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

ScavTrap::ScavTrap(const ScavTrap& object): ClapTrap(object)
{
	std::cout << BLUE << "ScavTrap: Copy constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& object)
{
	std::cout << WHITE << "ScavTrap: Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
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
		std::cout << "ScavTrap <" << _name << "> can't attack, "
				  << RED << "is dead!" << RESET << std::endl;
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
				  << ", causing " << YELLOW << _attackDamage << RESET
				  << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap <" << _name <<  "> is now in Gate keeper mode" << std::endl;
}
