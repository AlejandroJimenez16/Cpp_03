/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:49:36 by alejandj          #+#    #+#             */
/*   Updated: 2026/03/30 13:48:24 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "ClapTrap creation:" << std::endl;
	ClapTrap a("CT");

	std::cout << "\nScavTrap creation:" << std::endl;
	ScavTrap b("ST");

	std::cout << "\nFragTrap creation:" << std::endl;
	FragTrap c("FT");

	std::cout << "\nDiamondTrap creation:" << std::endl;
	DiamondTrap d("DT");
	

	std::cout << "\n================== Attacks ===================" << std::endl;

	std::cout << "\nClapTrap object:" << std::endl;
	a.attack("42");
	
	std::cout << "\nScavTrap object:" << std::endl;
	b.attack("42");
	
	std::cout << "\nFragTrap object:" << std::endl;
	c.attack("42");

	std::cout << "\nDiamondTrap object:" << std::endl;
	d.attack("42");
	std::cout << std::endl;
	
	std::cout << "================== Damage ====================" << std::endl;

	std::cout << "\nClapTrap object:" << std::endl;
	a.takeDamage(11);

	std::cout << "\nScavTrap object:" << std::endl;
	b.takeDamage(90);
	b.takeDamage(10);

	std::cout << "\nFragTrap object:" << std::endl;
	c.takeDamage(99);

	std::cout << "\nDiamondTrap object:" << std::endl;
	d.takeDamage(50);
	std::cout << std::endl;

	std::cout << "================== Repairs ===================" << std::endl;
	
	std::cout << "\nClapTrap object:" << std::endl;
	a.beRepaired(5);

	std::cout << "\nScavTrap object:" << std::endl;
	b.beRepaired(10);

	std::cout << "\nFragTrap object:" << std::endl;
	c.beRepaired(50);

	std::cout << "\nDiamondTrap object:" << std::endl;
	d.beRepaired(10);
	std::cout << std::endl;

	std::cout << "================== Skills ====================" << std::endl;
	
	std::cout << "\nScavTrap:" << std::endl;
	b.guardGate();

	std::cout << "\nFragTrap:" << std::endl;
	c.highFivesGuys();

	std::cout << "\nDiamondTrap:" << std::endl;
	d.guardGate();
	d.highFivesGuys();
	d.whoAmI();
	
	std::cout << "=============================================================\n" << std::endl;
	return 0;
}
