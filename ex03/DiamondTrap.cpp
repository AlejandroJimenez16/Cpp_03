/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:10:12 by alejandj          #+#    #+#             */
/*   Updated: 2026/03/29 20:28:13 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << MAGENTA << "DiamondTrap: Default constructor called" << RESET << std::endl;
	_name = "Default";
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << MAGENTA << "DiamondTrap: Parameterized constructor called" << RESET << std::endl;
	_name = name;
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& object): ClapTrap(object), ScavTrap(object), FragTrap(object)
{
	std::cout << BLUE << "DiamondTrap: Copy constructor called" << RESET << std::endl;
	*this = object;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& object)
{
	std::cout << WHITE << "DiamondTrap: Copy assignment operator called" << RESET << std::endl;	
	if (this != &object)
	{
		ClapTrap::operator=(object);
		ScavTrap::operator=(object);
		FragTrap::operator=(object);
		_name = object._name;
	}

	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap: Destructor called" << RESET << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap: My name is " << this->_name
			  << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
