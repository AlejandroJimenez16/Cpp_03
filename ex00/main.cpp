/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:49:36 by alejandj          #+#    #+#             */
/*   Updated: 2026/03/30 12:36:08 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a;
	ClapTrap b("Marvin");
	ClapTrap c(a);

	std::cout << "\n================== Attacks ===================" << std::endl;
	a.attack("42");
	b.attack("42");
	c.attack("42");
	std::cout << std::endl;
	
	std::cout << "================== Damage ====================" << std::endl;
	a.takeDamage(11);
	b.takeDamage(9);
	c.takeDamage(0);
	std::cout << std::endl;

	std::cout << "================== Repairs ===================" << std::endl;
	a.beRepaired(5);
	b.beRepaired(5);
	c.beRepaired(5);
	std::cout << std::endl;

	std::cout << "================== No Energy =================" << std::endl;
	ClapTrap d("NoEnergy");
	for (int i = 0; i < 11; i++)
		d.attack("Target");
	d.beRepaired(5);
	
	std::cout << "=============================================================\n" << std::endl;
	return 0;
}
