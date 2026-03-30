# CPP Module 03 - Inheritance

## Objective

The goal of `CPP Module 03` is to practice class inheritance in C++, understand multiple and virtual inheritance and explore how derived classes interact with base class attributes and methods.

## Project structure

```
CPP_Module_03/
├── ex00/          # Aaaaand... OPEN! - Implement base class ClapTrap
├── ex01/          # Serena, my love! - Implement derived class ScravTrap to practice inheritance
├── ex02/          # Repetitive work - Implement second derived class FragTrap
├── ex03/          # Now it’s weird! - Implement DiamondTrap to explore virtual inheritance
└── README.md      # This file 
```

## Exercises

### ex00: Aaaaand... OPEN!

**Description:**
This exercise consists of creating a `ClapTrap` class, which will serve as the base class for the following exercises.

**What you will learn:**
- How to define a C++ class
- How to create a class in canonical form
- How to declare attributes and methods
- How to set up a class that will serve as a base for inheritance

**Program functionality:**
- Create `ClapTrap objects` using default, parameterized, and copy constructors
- Each ClapTrap can **attack** a target, consuming energy points, or do nothing if it has no energy points or is dead
- Each ClapTrap can **receive damage**, losing hit points and possibly dying when HP reaches zero.
- Each ClapTrap can **repair itself**, restoring hit points if it has enough energy and is alive
- Output shows the current status of hit points, energy points, and actions performed by each ClapTrap.

**Class design:**

**ClapTrap**

*Private attributes:*
- `std::string _name`
- `int _hitPoints`
- `int _energyPoints`
- `int _attackDamage`

*Public methods:*
- `void attack(const std::string& target)`
- `void takeDamage(unsigned int amount)`
- `void beRepaired(unsigned int amount)`

*Operators:*
- `ClapTrap& operator=(const ClapTrap& object)`

**Example usage:**

```bash
$ ./clapTrap
# Output
Default constructor called
Parameterized constructor called
Copy constructor called

================== Attacks ===================
ClapTrap <Default> attacks 42, causing 0 points of damage!
ClapTrap <CT> attacks 42, causing 0 points of damage!
ClapTrap <Default> attacks 42, causing 0 points of damage!

================== Damage ====================
ClapTrap <Default> receives 11 points of damage!, dead!!
ClapTrap <CT> receives 9 points of damage!, HP left: 1
ClapTrap <Default> receives 5 points of damage!, HP left: 5

================== Repairs ===================
ClapTrap <Default> can't be repaired, is dead!
ClapTrap <CT> repairs itself for 5 hit points!, Current HP: 6
ClapTrap <Default> repairs itself for 5 hit points!, Current HP: 10

================== No Energy =================
Parameterized constructor called
ClapTrap <NoEnergy> attacks Target, causing 0 points of damage!
ClapTrap <NoEnergy> attacks Target, causing 0 points of damage!
ClapTrap <NoEnergy> attacks Target, causing 0 points of damage!
ClapTrap <NoEnergy> attacks Target, causing 0 points of damage!
ClapTrap <NoEnergy> attacks Target, causing 0 points of damage!
ClapTrap <NoEnergy> attacks Target, causing 0 points of damage!
ClapTrap <NoEnergy> attacks Target, causing 0 points of damage!
ClapTrap <NoEnergy> attacks Target, causing 0 points of damage!
ClapTrap <NoEnergy> attacks Target, causing 0 points of damage!
ClapTrap <NoEnergy> attacks Target, causing 0 points of damage!
ClapTrap <NoEnergy> can't attack, no energy!
ClapTrap <NoEnergy> can't be repaired, no energy!
=============================================================

Destructor called
Destructor called
Destructor called
Destructor called
```

---

### ex01: Serena, my love!

**Description:**
This exercise consists of creating a `ScavTrap` class which **inherits** from the previous `ClapTrap` class.

**What you will learn:**
- How to create a class that **inherits** from another class
- The differences between **public**, **protected**, and **private** inheritance/members
- How to **override inherited attributes and member functions**
- How constructors and destructors behave in derived classes
- How to call base class methods from a derived class

**Program functionality:**