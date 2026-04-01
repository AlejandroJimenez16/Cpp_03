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
- Create `ClapTrap` objects using default, parameterized, and copy constructors
- Each `ClapTrap` can **attack** a target, consuming energy points, or do nothing if it has no energy points or is dead
- Each `ClapTrap` can **receive damage**, losing hit points and possibly dying when HP reaches zero.
- Each `ClapTrap` can **repair itself**, restoring hit points if it has enough energy and is alive
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
- How to declare a **virtual destructor** in a base class to ensure that derived class objects are destroyed correctly

**Program functionality:**
- Create `ClapTrap` and `ScavTrap` objects using default, parameterized, and copy constructors
- Each `ClapTrap` and `ScavTrap` can **attack** a target, consuming energy points, or do nothing if it has no energy points or is dead
- Each `ClapTrap` and `ScavTrap` can **receive damage**, losing hit points and possibly dying when HP reaches zero.
- Each `ClapTrap` and `ScavTrap` can **repair itself**, restoring hit points if it has enough energy and is alive
- `ScavTrap` objects have an additional ability: **guardGate()**, demonstrating class-specific behavior
- Output shows the current status of hit points, energy points, and actions performed by each object, validating the correct behavior of constructors and destructors, including the order of creation and destruction

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

**ScavTrap**

*Inherited attributes:*
- All attributes from `ClapTrap`

*Inherited methods:*
- `void takeDamage(unsigned int amount)`
- `void beRepaired(unsigned int amount)`

*Public methods:*
- `void attack(const std::string& target)` – overrides ClapTrap::attack() with ScavTrap-specific behavior
- `void guardGate()`

*Operators:*
- `ScavTrap& operator=(const ScavTrap& object)`

**Example usage:**

```bash
$ ./scavTrap
# Output
ClapTrap creation:
ClapTrap: Default constructor called
ClapTrap: Parameterized constructor called

ScavTrap creation:
ClapTrap: Parameterized constructor called
ScavTrap: Parameterized constructor called
ClapTrap: Copy constructor called
ScavTrap: Copy constructor called

================== Attacks ===================

ClapTrap objects:
ClapTrap <Default> attacks 42, causing 0 points of damage!
ClapTrap <CT> attacks 42, causing 0 points of damage!

ScavTrap objects:
ScavTrap <ST> attacks 42, causing 20 points of damage!
ScavTrap <ST> attacks 42, causing 20 points of damage!

================== Damage ====================

ClapTrap objects:
ClapTrap <Default> receives 11 points of damage!, dead!!
ClapTrap <CT> receives 5 points of damage!, HP left: 5

ScavTrap objects:
ClapTrap <ST> receives 100 points of damage!, dead!!
ClapTrap <ST> receives 50 points of damage!, HP left: 50

================== Repairs ===================

ClapTrap objects:
ClapTrap <Default> can't be repaired, is dead!
ClapTrap <CT> repairs itself for 2 hit points!, Current HP: 7

ScavTrap objects:
ClapTrap <ST> can't be repaired, is dead!
ClapTrap <ST> repairs itself for 25 hit points!, Current HP: 75

================== Skills ====================

ScavTrap <ST> is now in Gate keeper mode

=============================================================

ScavTrap: Destructor called
ClapTrap: Destructor called
ScavTrap: Destructor called
ClapTrap: Destructor called
ClapTrap: Destructor called
ClapTrap: Destructor called
```

---

### ex02: Repetitive work

**Description:**
This exercise consists of creating a `FragTrap` class which **inherits** from the previous `ClapTrap` class.

**What you will learn:**
- How to create a class that **inherits** from another class
- The differences between **public**, **protected**, and **private** inheritance/members
- How to **override inherited attributes and member functions**
- How constructors and destructors behave in derived classes
- How to call base class methods from a derived class
- How to declare a **virtual destructor** in a base class to ensure that derived class objects are destroyed correctly.

**Program functionality:**
- Create `ClapTrap`, `ScavTrap` and `FragTrap` objects using default constructors
- Each object can **attack** a target, consuming energy points, or do nothing if it has no energy points or is dead
- Each object can **receive damage**, losing hit points and possibly dying when HP reaches zero.
- Each object can **repair itself**, restoring hit points if it has enough energy and is alive
- `ScavTrap` objects have an additional ability: **guardGate()**
- `FragTrap` objects have an additional ability: **highFivesGuys()**
- Output shows the current status of hit points, energy points, and actions performed by each object, validating the correct behavior of constructors and destructors, including the order of creation and destruction

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

**ScavTrap**

*Inherited attributes:*
- All attributes from `ClapTrap`

*Inherited methods:*
- `void takeDamage(unsigned int amount)`
- `void beRepaired(unsigned int amount)`

*Public methods:*
- `void attack(const std::string& target)` – overrides ClapTrap::attack() with ScavTrap-specific behavior
- `void guardGate()`

*Operators:*
- `ScavTrap& operator=(const ScavTrap& object)`

**FragTrap**

*Inherited attributes:*
- All attributes from `ClapTrap`

*Inherited methods:*
- All methods from `ClapTrap`

*Public methods:*
- `void highFivesGuys(void)`

*Operators:*
- `FragTrap& operator=(const FragTrap& object)`

**Example usage:**

```bash
$ ./fragTrap
# Output
ClapTrap creation:
ClapTrap: Parameterized constructor called

ScavTrap creation:
ClapTrap: Parameterized constructor called
ScavTrap: Parameterized constructor called

FragTrap creation:
ClapTrap: Parameterized constructor called
FragTrap: Parameterized constructor called

================== Attacks ===================

ClapTrap object:
ClapTrap <CT> attacks 42, causing 0 points of damage!

ScavTrap object:
ScavTrap <ST> attacks 42, causing 20 points of damage!

FragTrap object:
ClapTrap <FT> attacks 42, causing 30 points of damage!

================== Damage ====================

ClapTrap object:
ClapTrap <CT> receives 11 points of damage!, dead!!

ScavTrap object:
ClapTrap <ST> receives 90 points of damage!, HP left: 10
ClapTrap <ST> receives 10 points of damage!, dead!!

FragTrap object:
ClapTrap <FT> receives 99 points of damage!, HP left: 1

================== Repairs ===================

ClapTrap object:
ClapTrap <CT> can't be repaired, is dead!

ScavTrap object:
ClapTrap <ST> can't be repaired, is dead!

FragTrap object:
ClapTrap <FT> repairs itself for 50 hit points!, Current HP: 51

================== Skills ===================

ScavTrap:
ScavTrap <ST> is now in Gate keeper mode

FragTrap:
FragTrap <FT> requests a high five! :)
=============================================================

FragTrap: Destructor called
ClapTrap: Destructor called
ScavTrap: Destructor called
ClapTrap: Destructor called
ClapTrap: Destructor called
```

---

### ex03: Now it’s weird!

**Description:**
This exercise consists of creating a DiamondTrap class which inherits from both ScavTrap and FragTrap classes (demonstrating multiple inheritance).

**What you will learn:**
- How to **inherit from two base classes** (multiple inheritance)
- How constructors and destructors behave in multiple inheritance
- How to call base class methods from a derived class when multiple inheritance is involved
- How to use **virtual inheritance** to ensure that multiple derived classes share a single base class object and avoid ambiguities
- How to override inherited methods in a class that has multiple base classes

**Program functionality:**
- Create `ClapTrap`, `ScavTrap`, `FragTrap` and `DiamondTrap` objects using default constructors
- Each object can **attack**, **receive damage**, and **repair itself**, following the rules defined in their respective classes
- `ScavTrap` objects have an additional ability: **guardGate()**
- `FragTrap` objects have an additional ability: **highFivesGuys()**
- `DiamondTrap` can use the special abilities of its base classes and has an additional ability: **whoAmI()**
- Output shows the current status of hit points, energy points, and actions performed by each object, validating the correct behavior of constructors and destructors, including the order of creation and destruction

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

**ScavTrap**

*Inherited attributes:*
- All attributes from `ClapTrap`

*Inherited methods:*
- `void takeDamage(unsigned int amount)`
- `void beRepaired(unsigned int amount)`

*Public methods:*
- `void attack(const std::string& target)` – overrides ClapTrap::attack() with ScavTrap-specific behavior
- `void guardGate()`

*Operators:*
- `ScavTrap& operator=(const ScavTrap& object)`

**FragTrap**

*Inherited attributes:*
- All attributes from `ClapTrap`

*Inherited methods:*
- All methods from `ClapTrap`

*Public methods:*
- `void highFivesGuys(void)`

*Operators:*
- `FragTrap& operator=(const FragTrap& object)`

**DiamondTrap**

*Private attributes:*
- `std::string _name`

*Inherited attributes:*
- `ClapTrap::_name`
- `FragTrap::_hitPoints`
- `ScavTrap::_energyPoints`
- `FragTrap::_attackDamage`

*Inherited methods:*
- `void attack(const std::string& target)` - Use ScavTrap::attack
- `void takeDamage(unsigned int amount)`
- `void beRepaired(unsigned int amount)`

*Public methods:*
- `void whoAmI()`

*Operators:*
- `DiamondTrap& operator=(const DiamondTrap& object)`

**Example usage:**

```bash
$ ./diamondTrap
# Output
ClapTrap creation:
ClapTrap: Parameterized constructor called

ScavTrap creation:
ClapTrap: Parameterized constructor called
ScavTrap: Parameterized constructor called

FragTrap creation:
ClapTrap: Parameterized constructor called
FragTrap: Parameterized constructor called

DiamondTrap creation:
ClapTrap: Parameterized constructor called
ScavTrap: Parameterized constructor called
FragTrap: Parameterized constructor called
DiamondTrap: Parameterized constructor called

================== Attacks ===================

ClapTrap object:
ClapTrap <CT> attacks 42, causing 0 points of damage!

ScavTrap object:
ScavTrap <ST> attacks 42, causing 20 points of damage!

FragTrap object:
ClapTrap <FT> attacks 42, causing 30 points of damage!

DiamondTrap object:
ScavTrap <DT_clap_name> attacks 42, causing 30 points of damage!

================== Damage ====================

ClapTrap object:
ClapTrap <CT> receives 11 points of damage!, dead!!

ScavTrap object:
ClapTrap <ST> receives 90 points of damage!, HP left: 10
ClapTrap <ST> receives 10 points of damage!, dead!!

FragTrap object:
ClapTrap <FT> receives 99 points of damage!, HP left: 1

DiamondTrap object:
ClapTrap <DT_clap_name> receives 50 points of damage!, HP left: 50

================== Repairs ===================

ClapTrap object:
ClapTrap <CT> can't be repaired, is dead!

ScavTrap object:
ClapTrap <ST> can't be repaired, is dead!

FragTrap object:
ClapTrap <FT> repairs itself for 50 hit points!, Current HP: 51

DiamondTrap object:
ClapTrap <DT_clap_name> repairs itself for 10 hit points!, Current HP: 60

================== Skills ====================

ScavTrap:
ScavTrap <ST> is now in Gate keeper mode

FragTrap:
FragTrap <FT> requests a high five! :)

DiamondTrap:
ScavTrap <DT_clap_name> is now in Gate keeper mode
FragTrap <DT_clap_name> requests a high five! :)
DiamondTrap: My name is DT and my ClapTrap name is DT_clap_name
=============================================================

DiamondTrap: Destructor called
FragTrap: Destructor called
ScavTrap: Destructor called
ClapTrap: Destructor called
FragTrap: Destructor called
ClapTrap: Destructor called
ScavTrap: Destructor called
ClapTrap: Destructor called
ClapTrap: Destructor called
```