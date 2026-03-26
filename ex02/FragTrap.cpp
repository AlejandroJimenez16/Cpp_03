/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:37:26 by alejandj          #+#    #+#             */
/*   Updated: 2026/03/26 17:08:16 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << MAGENTA << "FragTrap: Default constructor called" << RESET << std::endl;
    _hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << MAGENTA << "FragTrap: Parameterized constructor called" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& object): ClapTrap(object)
{
	std::cout << BLUE << "FragTrap: Copy constructor called" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& object)
{
	std::cout << WHITE << "FragTrap: Copy assignment operator called" << RESET << std::endl;
	if (this != &object)
		ClapTrap::operator=(object);

	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap: Destructor called" << RESET << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap <" << _name << "> requests a high five! :)" << std::endl;
}
