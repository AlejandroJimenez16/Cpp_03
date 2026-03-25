/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:49:36 by alejandj          #+#    #+#             */
/*   Updated: 2026/03/25 17:49:20 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap a("Marvin");
	ScavTrap b;
	FragTrap c("R2-D2");

	std::cout << "\n================== Attacks ==================" << std::endl;

	std::cout << "\nClapTrap object:" << std::endl;
	a.attack("42");
	
	std::cout << "\nScavTrap object:" << std::endl;
	b.attack("42");
	
	std::cout << "\nFragTrap object:" << std::endl;
	c.attack("42");
	std::cout << std::endl;
	
	std::cout << "================== Damage ===================" << std::endl;

	std::cout << "\nClapTrap object:" << std::endl;
	a.takeDamage(11);

	std::cout << "\nScavTrap object:" << std::endl;
	b.takeDamage(90);
	b.takeDamage(10);

	std::cout << "\nFragTrap object:" << std::endl;
	c.takeDamage(99);
	std::cout << std::endl;

	std::cout << "================== Repairs ===================" << std::endl;
	
	std::cout << "\nClapTrap object:" << std::endl;
	a.beRepaired(5);

	std::cout << "\nScavTrap object:" << std::endl;
	b.beRepaired(10);

	std::cout << "\nFragTrap object:" << std::endl;
	c.beRepaired(50);
	std::cout << std::endl;

	b.guardGate();
	std::cout << std::endl;
	c.highFivesGuys();
	
	std::cout << "=============================================================\n" << std::endl;
	return 0;
}
