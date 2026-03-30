/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:49:36 by alejandj          #+#    #+#             */
/*   Updated: 2026/03/30 13:10:44 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "ClapTrap creation:" << std::endl;
	ClapTrap a;
	ClapTrap b("CT");
	
	std::cout << "\nScavTrap creation:" << std::endl;
	ScavTrap c("ST");
	ScavTrap d(c);

	std::cout << "\n================== Attacks ===================" << std::endl;

	std::cout << "\nClapTrap objects:" << std::endl;
	a.attack("42");
	b.attack("42");
	
	std::cout << "\nScavTrap objects:" << std::endl;
	c.attack("42");
	d.attack("42");
	std::cout << std::endl;
	
	std::cout << "================== Damage ====================" << std::endl;

	std::cout << "\nClapTrap objects:" << std::endl;
	a.takeDamage(11);
	b.takeDamage(5);

	std::cout << "\nScavTrap objects:" << std::endl;
	c.takeDamage(100);
	d.takeDamage(50);
	std::cout << std::endl;

	std::cout << "================== Repairs ===================" << std::endl;
	
	std::cout << "\nClapTrap objects:" << std::endl;
	a.beRepaired(5);
	b.beRepaired(2);

	std::cout << "\nScavTrap objects:" << std::endl;
	c.beRepaired(50);
	d.beRepaired(25);
	std::cout << std::endl;

	std::cout << "================== Skills ====================\n" << std::endl;
	
	c.guardGate();
	
	std::cout << "\n=============================================================\n" << std::endl;
	return 0;
}
